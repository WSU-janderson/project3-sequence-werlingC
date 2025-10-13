
#include <string>
#include "SequenceNode.h"
#include <cstddef>

class Sequence
{
private:
    //points to the head node in the list
    SequenceNode* headNode;
    //points to the tail node of the list
    SequenceNode* tailNode;
    //keeps track of the size of the node
    size_t listSize;

public:
    // Creates an empty sequence (numElts == 0) or a sequence of numElts items indexed from 0 ... (numElts - 1).
    Sequence(size_t sz = 0);

    // Creates a (deep) copy of sequence s
    Sequence(const Sequence& s);

    // Destroys all items in the sequence and release the memory associated with the sequence
    ~Sequence();

    // The current sequence is released and replaced by a (deep) copy of sequence s. A reference to the copied sequence is returned (return *this;).
    Sequence& operator=(const Sequence& s);

    // The position satisfies ( position >= 0 && position <= last_index() ).
    // The return value is a reference to the item at index position in the
    // sequence. Throws an exception if the position is outside the bounds
    // of the sequence
    std::string& operator[](size_t position);


    // The value of item is appended to the sequence.
    void push_back(std::string item);

    // The item at the end of the sequence is deleted and size of the sequence is
    // reduced by one. If sequence was empty, throws an exception
    void pop_back();

    // The position satisfies ( position >= 0 && position <= last_index() ). The value of item is inserted at position and the size of sequence is increased by one.
    // Throws an exception if the position is outside the bounds of the sequence
    void insert(size_t position, std::string item);

    // Returns the first element in the sequence. If the sequence is empty, throw an
    // exception.
    std::string front() const;

    // Return the last element in the sequence. If the sequence is empty, throw an
    // exception.
    std::string back() const;

    // Return true if the sequence has no elements, otherwise false.
    bool empty() const;

    // Return the number of elements in the sequence.
    size_t size() const;


};