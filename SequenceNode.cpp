//
// Created by carma on 10/8/2025.
//

#include "SequenceNode.h"
#include <string>

using namespace std;

//Constructor with parameters
SequenceNode::SequenceNode(string item)
{
    this->item = item;
    next = nullptr;
    prev = nullptr;
}