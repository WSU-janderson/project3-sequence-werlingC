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



