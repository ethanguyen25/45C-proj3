//HashMap.cpp

#include "HashMap.hpp"
#include <iostream>
#include <string>


namespace
{
    unsigned int defaultHF(const std::string& characters)
    {
        int hashNum = 0;
        for (int n = 0; n < characters.length(); ++n)
        {
            hashNum += hashNum * 101 + int(characters[n]);
            //std::cout << hashNum << std::endl;
        }
        //hashNum = hashNum % HashMap::INITIAL_BUCKET_COUNT;
        return hashNum;
    }
}


HashMap::HashMap()
    : hashFunction{defaultHF}, sz{0}, 
      numOfBuckets{HashMap::INITIAL_BUCKET_COUNT}
      //hashTable{initNulls}
{
    initNulls();
}


HashMap::HashMap(HashFunction hashFunction)
    : hashFunction{hashFunction}, sz{0}, 
      numOfBuckets{HashMap::INITIAL_BUCKET_COUNT}
{
    initNulls();
}

//The Big 3

HashMap::~HashMap()
{
    properDelete();
}

HashMap::HashMap(const HashMap& hm)
    : hashFunction{hm.hashFunction}, sz{hm.size()},
      numOfBuckets{hm.bucketCount()}
{
    initNulls();
    properCopy(hashTable, hm);
}

HashMap& HashMap::operator=(const HashMap& hm)
{
    Node** newHashTable = new Node*[hm.bucketCount()];
    properCopy(newHashTable, hm);

    hashFunction = hm.hashFunction;
    sz = hm.size();
    numOfBuckets = hm.bucketCount();

    properDelete();

    hashTable = newHashTable;
    return *this;
}

void HashMap::add(const std::string& key, const std::string& value)
{
    if (contains(key) == true)
    {
    }
    else
    {
        unsigned int index = (hashFunction(key) % numOfBuckets);
        Node* temp = hashTable[index];
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        if (temp == nullptr)
        {
            hashTable[index] = newNode;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        sz += 1;
        double loadfactor = loadFactor();
        if (loadfactor > .8)
        {
            rehash();
        }
    }
}

bool HashMap::remove(const std::string& key)
{
    if (contains(key))
    {
        unsigned int index = (hashFunction(key) % numOfBuckets);
        Node* temp = hashTable[index];
        Node* previous;

        if (temp->key == key and temp->next == nullptr)
        {
            hashTable[index] = nullptr;
        }
        else if (temp->key == key and temp->next != nullptr)
        {
            previous = temp->next;
            hashTable[index] = previous;
        }
        else
        {
            while (temp->key != key and temp != nullptr)
            {
                previous = temp;
                temp = temp->next;
            }
            previous->next = temp->next;
            hashTable[index] = previous;
        }
        delete temp;
        sz -= 1;
        return true;
    }
    return false;
}

bool HashMap::contains(const std::string& key) const
{
    unsigned int index = (hashFunction(key) % numOfBuckets);
    Node* current = hashTable[index];
    
    if (current != nullptr)
    {
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return true;
            }
            else
            {
                current = current->next;
            }
        }
    }
    return false;
}

std::string HashMap::value(const std::string& key) const
{
    if (contains(key))
    {
        unsigned int index = (hashFunction(key) % numOfBuckets);
        Node* current = hashTable[index];
        while(current->key != key)
        {
            current = current->next;
        }
        return current->value;
    }
    std::string empty;
    return empty;
}

unsigned int HashMap::size() const
{
   return sz;
}

unsigned int HashMap::bucketCount() const
{
    return numOfBuckets;
}

double HashMap::loadFactor() const
{
    return (double(sz)/double(numOfBuckets));
}

unsigned int HashMap::maxBucketSize() const
{
    unsigned int max = 0;
    unsigned int count = 0;
    for (int n = 0; n < numOfBuckets; ++n)
    {
        if (hashTable[n] == nullptr)
        {
        }
        else
        {
            Node* checker = hashTable[n];
            while (checker != nullptr)
            {
                count += 1;
                checker = checker->next;
            }
            if (count > max)
            {
                max = count;
            }
        }
        count = 0;
    }
    return max;
}

//Added Helper Functions

unsigned int HashMap::getBucketNumber(const std::string& key) const
{
    return (hashFunction(key) % numOfBuckets);
}

void HashMap::initNulls()
{
    hashTable = new Node*[numOfBuckets];
    for (int n = 0; n < numOfBuckets; ++n)
    {
        hashTable[n] = nullptr;
    }
}

void HashMap::rehash()
{
    Node** tempHT = hashTable;
    unsigned int tempNum = bucketCount();
    //printHashTable();
    //std::cout << "TEMPNUM " << tempNum << std::endl; 
    numOfBuckets = (numOfBuckets * 2) + 1;
    
    initNulls();
    std::string tempKey;
    unsigned int tempIndex;
    
    for (int n = 0; n < tempNum; ++n)
    {
        Node* current = tempHT[n];
        while (current != nullptr)
        {
            Node* next = current->next;
            tempKey = current->key;
            //std::cout << "TEMPKEY " << tempKey << std::endl;
            tempIndex = (hashFunction(tempKey) % numOfBuckets);
            current->next = nullptr;
            //std::cout << "HFKEY " << hashFunction(tempKey) << std::endl;
            //std::cout << "TEMPINDEX " << tempIndex << std::endl;
            Node* temp = hashTable[tempIndex];
        
            if (temp == nullptr)
            {
                hashTable[tempIndex] = current;
            }
            else
            {
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = current;
                
            }
            current = next;
        }
    }
    delete[] tempHT;
    
}

void HashMap::printHashTable()
{
    for (int n = 0; n < numOfBuckets; ++n)
    {
        Node* temp = hashTable[n];
        if (temp == nullptr)
        {
            std::cout << n << std::endl;
        }
        else
        {
            std::cout << n << " ";
            while(temp != nullptr)
            {
                std::cout << "[" << temp->key; 
                std::cout << "|" << temp->value << "]" << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
}

void HashMap::properDelete()
{
    //int count = 0;
    for (int n = 0; n < numOfBuckets; n++)
    {
        Node* current = hashTable[n];
        Node* temp;
        while (current != nullptr)
        {
            //count += 1;
            temp = current;
            current = current->next;
            delete temp;
            temp = nullptr;
        }
    }
    //std::cout << "Count " << count << std::endl;

    delete[] hashTable;

}

void HashMap::clear()
{
    properDelete();
    initNulls();
    sz = 0;
}


void HashMap::properCopy(Node** hashTable, const HashMap& hm)
{
    for (int n = 0; n < numOfBuckets; ++n)
    {
        hashTable[n] = nullptr;
    }
    for (int n = 0; n < numOfBuckets; ++n)
    {
        Node* newHT = hashTable[n];
        Node* oldHT = hm.hashTable[n];
        if (oldHT == nullptr)
        {
        }
        else
        {
            while (oldHT != nullptr)
            {
                Node* copyNode = new Node;
                copyNode->key = oldHT->key;
                copyNode->value = oldHT->value;
                copyNode->next = oldHT->next;
                if (newHT == nullptr)
                {
                    hashTable[n] = copyNode;
                    newHT = copyNode;
                }
                else
                {
                    newHT->next = copyNode;
                }
                oldHT = oldHT->next;
            }
        }
    }
}

























