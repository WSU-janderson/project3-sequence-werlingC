#include "Sequence.h"
#include <string>
#include "SequenceNode.h"

using namespace std;

// Creates an empty sequence (numElts == 0) or a sequence of numElts items indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz)
{
    sz = 0;
    headNode = nullptr;
    tailNode = nullptr;
    listSize = sz;
}

//TODO: Finish the copy function once functions for adding and removing nodes are created
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s)
{
    headNode = s.headNode;
    tailNode = s.tailNode;
    for (int i =0; i < (listSize - 1); i++)
    {

    }
}


void Sequence::push_back(string item)
{
    //creates a new node that's previous pointer will be the tailNode and next pointer will be null
    SequenceNode* newNode = new SequenceNode(item);
    newNode->prev = tailNode;
    newNode->next = nullptr;

    //if the sequence is empty, the node will be both the head and tail
    if (empty())
    {
        headNode = newNode;
    }else
    {
        //sets the tail old tail node's next node to newNode
        tailNode->next = newNode;
    }

    //set the new tail node to newNode
    tailNode = newNode;
    listSize++;

}

//returns true if there are no nodes in the sequence
bool Sequence::empty() const
{
    if (listSize == 0)
    {
        return true;
    }
}



