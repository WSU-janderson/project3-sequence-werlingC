#include "Sequence.h"

#include <iostream>
#include <string>
#include "SequenceNode.h"
#include <stdexcept>

using namespace std;

// Creates an empty sequence (numElts == 0) or a sequence of numElts items indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz)
{
    sz = 0;
    headNode = nullptr;
    tailNode = nullptr;
    listSize = sz;
}

//destructor of the Sequence class that deletes all nodes in the sequence when the sequence itself is deleted
Sequence::~Sequence()
{
    //removes all nodes from the list
    while (!empty())
    {
        pop_back();
    }
}

//TODO: Finish the copy function once functions for adding and removing nodes are created
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s)
{
    headNode = s.headNode;
    tailNode = s.tailNode;
    for (int i =0; i < (s.listSize - 1); i++)
    {

    }
}


//adds a new node to the end of a Sequence
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
    }else{
        //sets the tail old tail node's next node to newNode
        tailNode->next = newNode;
    }

    //set the new tail node to newNode
    tailNode = newNode;
    listSize++;

}

//Removes the last element in the Sequence
void Sequence::pop_back()
{
    //checks to make sure the sequence is not empty to prevent errors
    if (empty())
    {
        cout<<"No values to remove";
    }else
    {
        SequenceNode* temp = tailNode;

        //checks if the list will become empty after this removal, meaning both the head and tail will be null
        if (listSize == 1)
        {
            headNode  = nullptr;
            tailNode = nullptr;
        }else{
            //if the list isn't about to be empty then tailNode reference needs to be updated and the new tail itself needs it next pointer to be null
            tailNode = tailNode->prev;
            tailNode->next = nullptr;
        }

        //removes the last node in the sequence and updates the listSize to be one less
        delete temp;
        listSize--;
    }
}

//returns the value in stored in the first node of the sequence
string Sequence::front() const
{
    //checks if the sequence is empty and throws an exception if so
    if (empty())
    {
        throw out_of_range("front() can not be called on an empty sequence");
    }
    return headNode->item;
}

//returns the value stored in the last node of the sequence
string Sequence::back() const
{
    //checks if the sequence is empty and throws an exception if so
    if (empty())
    {
        throw out_of_range("back() can not be called on an empty sequence");
    }
    return tailNode->item;
}

//returns true if there are no nodes in the sequence
bool Sequence::empty() const
{
    if (listSize == 0)
    {
        return true;
    }else{
        return false;
    }
}

//returns the list's size
size_t Sequence::size() const
{
    return listSize;
}



