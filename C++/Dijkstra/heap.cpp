#include <iostream>
#include <string>
#include "heap.h"
#include "hash.h"


heap::node::node(node &&node) //move constructor
{
    id = std::move(node.id);
    key = node.key;
    node.key = 0;
    pData = node.pData;
    node.pData = nullptr;
}

heap::node& heap::node::operator=(node &&node) //move copy 
{
    id = std::move(node.id);
    key = node.key;
    node.key = 0;
    pData = node.pData;
    node.pData = nullptr;

    return *this;
}

heap::heap(int capacity): capacity{capacity}, filled{0}, mapping{capacity * 2}//default constructor
    {data.resize(capacity + 1);}

void heap::percolateUp(int pos) //percolate up to help with insert etc
{
    data[0] = std::move(data[pos]); //move in temp location

    for(; data[0].key < data[pos/2].key; pos /= 2) //while not in correct spot percolate up
    {
        data[pos] = std::move(data[pos/2]); 
        mapping.setPointer(data[pos].id, &data[pos]);
    }

    data[pos] = std::move(data[0]); //move tmp into correct spot
    mapping.setPointer(data[pos].id, &data[pos]); //set the pointer as it changed 
}

void heap::percolateDown(int pos) //percolate down to help with deletions etc
{
    int child{0};
    data[0] = std::move(data[pos]); //put into tmp

    for(; pos * 2 <= filled; pos = child) //while not in correct position
    {
        child = pos * 2;
        if(child != filled && data[child+1].key < data[child].key)
            ++child;
        if(data[child].key < data[0].key)
        {
            data[pos] = std::move(data[child]);
            mapping.setPointer(data[pos].id, &data[pos]);
        }
        else
            break;
    }

    data[pos] = std::move(data[0]); //move tmp into proper position
    mapping.setPointer(data[pos].id, &data[pos]);//set the pointer as it changed
}

int heap::getPos(node *pn)  //pointer arithmetic to get position
{
    int pos = pn - &data[0];
    return pos;
}

int heap::insert(const std::string &id, int key, void *pv)
{
    if(filled == capacity) //can't add more items
        {return 1;}

    if(mapping.contains(id)) //if already inside return
        {return 2;}

    int pos = ++filled;
    data[pos].id = id; //set the id 
    data[pos].key = key; //set the key

    if(pv) //if optional pointer provided set it
        {data[pos].pData = pv;}

    mapping.insert(id, &data[pos]); //insert into hashtable
    percolateUp(pos); //put the new value in the right position

    return 0;
}

int heap::setKey(const std::string &id, int key)
{
    if(!mapping.contains(id)) //if not in hashtable, return 
        {return 1;}

    int pos = getPos(static_cast<node*>(mapping.getPointer(id))); //get the position of item
    data[pos].key = key; //set the key

    if( pos != 1 && data[pos].key < data[pos/2].key) //determine which way to percolate
        {percolateUp(pos);}
    else
        {percolateDown(pos);}

    return 0;
}

int heap::deleteMin(std::string *pId, int *pKey, void *ppData) //delete the minimum item 
{

    if(filled == 0) //if no item return 
        {return 1;}

    if(pId) //if pid, set the pid
        {*pId = data[1].id;}

    if(pKey) //if pkey set pkey
        {*pKey = data[1].key;}

    if(ppData) //if ppdata set ppdata
        {*(static_cast<void **> (ppData)) = data[1].pData;}

    node tmp = std::move(data[1]); //these three lines to perform a swap 
    data[1] = std::move(data[filled]);
    data[filled] = std::move(tmp);

    mapping.setPointer(data[1].id, &data[1]); //set the pointer of new "min"
    mapping.setPointer(data[filled].id, &data[filled]); 

    mapping.remove(data[filled].id); //remove last item which is where we swapped to
    --filled;
    percolateDown(1); //get the new "min" to the right position

    return 0;
}

int heap::remove(const std::string &id, int *pKey, void *ppData) //delete a specific item, same code as deletemin
{
    if(!mapping.contains(id))
        {return 1;}

    int pos = getPos(static_cast<node*>(mapping.getPointer(id)));

    if(pKey)
        {*pKey = data[pos].key;}

    if(ppData)
        {*(static_cast<void **> (ppData)) = data[pos].pData;}


    node tmp = std::move(data[pos]); //only difference is here, where we use the pos as the index
    data[pos] = std::move(data[filled]);
    data[filled] = std::move(tmp);

    mapping.setPointer(data[pos].id, &data[pos]);
    mapping.setPointer(data[filled].id, &data[filled]);

    mapping.remove(data[filled].id);
    --filled;

    if(pos != 1 && data[pos].key < data[pos/2].key)
        {percolateUp(pos);}
    else
        {percolateDown(pos);}

    return 0;
}