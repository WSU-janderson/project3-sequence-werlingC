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

//overloads the equals operators so that sequences can be set equal to other sequences
Sequence& Sequence::operator=(const Sequence& s)
{
    //check to make sure a self-assignment is not happening
    if (this == &s)
    {
        return *this;
    }

    //clears the sequence
    while (!empty())
    {
        pop_back();
    }

    //copys the elements from the sequence s into the sequence calling this function
    SequenceNode* current = s.headNode;
    for (int i  = 0; i < s.size(); i++)
    {
        push_back(current->item);
        current = current->next;
    }
}

//Overloads the [] operator to return a reference to a string at the given position
string& Sequence::operator[](size_t position)
{
    //makes sure that they requested position is within bounds of the sequence
    if (position > size() || position < 0)
    {
        throw out_of_range("Index is out of bounds!");
    }

    SequenceNode* current = headNode;
    for (int i  = 0; i < size(); i++)
    {
        if (i == position)
        {
            return current->item;
        }else
        {
            current = current->next;
        }
    }
}

Sequence::Sequence(const Sequence& s)
{
    //starts the current node as the headNode of s
    SequenceNode* current = s.headNode;
    //loops through the sequence s and uses push_back() to put the value in current into the new sequence
    //then changes current to be the next node until the whole list has been gone through
    for (int i=0; i < (s.size() - 1); i++)
    {
        push_back(current->item);
        current = current->next;
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

//Adds an element to the Sequence at a specified position
void Sequence::insert(size_t position, string value)
{
    //checks to make sure the specified position is within bounds
    if (position > size() || position < 0)
    {
        throw out_of_range("Index is out of range");
    }

    //checks if the insert position is at the end of a list and does a pushback if so
    if (position == size())
    {
        push_back(value);
        return;
    }

    //checks if the node is at the beginning of the list and makes it the new head node if so
    if (position == 0)
    {
        SequenceNode* newNode = new SequenceNode(value);
        newNode->next = headNode;
        headNode->prev = newNode;
        headNode = newNode;
    }else
    {
        //finds the target position and places the new node there
        SequenceNode* current = headNode;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        //makes a new node and links it the the next and previous nodes
        SequenceNode* newNode = new SequenceNode(value);
        newNode->prev = current->prev;
        newNode->next = current;
        //links the nodes before and after the insertion location to the new node
        current->prev->next = newNode;
        current->prev = newNode;
    }
    listSize++;
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



