#include "hash.h"
#include <iostream>

using namespace std; 
//set up primes table
unsigned int hashTable::primes[] = {49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};

//returns the next largest prime greater than size
unsigned int hashTable::getPrime(int size)
{
    int idx{0}; 
    while(size > primes[idx])
    { 
        ++idx; //at the end of the loop, the index is at the prime > size
    }
    return primes[idx]; 
}
//contructor that intializes values from given size
hashTable::hashTable(int size): capacity{static_cast<int>(getPrime(size))}, filled{0} 
{
    data.resize(getPrime(size)); 
}

//hash function that returns an index into the array
int hashTable::hash(const std::string &key)
{
    unsigned int hash = 0;
    for (int i = 0; i < key.length(); i++) 
    {
        hash = hash*101 + key[i];
    }
    return hash % capacity;
}

//rehahs for when size exceeds the limit
bool hashTable::rehash()
{
    std::vector<hashItem> tmp = data; 
    capacity = getPrime(1 + capacity); 
    filled = 0; 
    data.clear(); 
    try
    {
        data.resize(capacity); 
    }
    catch(const std::bad_alloc &error)//if we don't have enough memory
    {
        return false;
    }    
    for (const auto &item : tmp)//put items into data if they are valid items
    {
        if (item.isOccupied && !item.isDeleted)
            insert(std::move(item.key), item.pv); 
    }

    return true; 
}

bool hashTable::contains(const std::string &key)
{
    if(findPos(key) == -1)//use pos to see if the hash table contains the item
        {return false;}
    else
        {return true;}
}

int hashTable::insert(const std::string &key, void *pv)
{
    if (!contains(key))
    {
         //if filled is equal to capacity, rehash 
        if (.5 <= static_cast<double>(++filled)/capacity)
        {
            bool ret = rehash(); 
            if (!ret)
            {
                return 2; 
            }
        }

        int hash_val = hash(key); //new hash values after rehashing
        while (data[hash_val].isOccupied) //linear probe
        {
            hash_val = (hash_val + 1) % capacity; 
        }
        data[hash_val].key = key; 
        data[hash_val].isOccupied = true; 
        data[hash_val].isDeleted = false; 

        if(pv)
            {data[hash_val].pv = pv;}
        else
            {data[hash_val].pv = nullptr;}

        return 0; 
    }
    else 
    {
        return 1; 
    }
}

int hashTable::findPos(const std::string &key)
{
    int hash_val = hash(key); 
    while (data[hash_val].isOccupied && data[hash_val].key != key)//probe until we get where we want
       {hash_val = (hash_val + 1) % capacity;}
    if (data[hash_val].key == key && !data[hash_val].isDeleted)//if we're at the key, return hash
        {return hash_val;}
    else 
        {return -1;}
}

bool hashTable::remove(const std::string &key)
{
    int hash_val{findPos(key)};

    if(hash_val == -1)//not in the table
        {return false;}
    else
    {
        data[hash_val].isDeleted = true;
        return true;
    }
}

void* hashTable::getPointer(const std::string &key, bool* b)
{
    int hash_val{findPos(key)};

    if(hash_val == -1)
    {
        if(b)
        {*b = false;} 
        return nullptr;
    }
    else
    {
        if(b)
        {*b = true;}
        return data[hash_val].pv;
    }

}

int hashTable::setPointer(const std::string &key, void *pv)
{
    int hash_val{findPos(key)};

    if(hash_val == -1)
        {return 1;}
    else
    {
        data[hash_val].pv = pv;
        return 0;
    }
}