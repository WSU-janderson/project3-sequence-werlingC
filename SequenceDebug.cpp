/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include "Sequence.h"


using namespace std;


int main() {

    //tests an empty sequence
    Sequence s = Sequence();
    //tests if the size() and empty() functions correctly identify an empty function
    cout << "Sequence size: " << s.size();
    if (s.empty())
    {
        cout << "\nEmpty sequence";
    }else
    {
        cout << "\nNon-empty sequence";
    }
    //Tests for error throwing, since front() and back() can't operate on an empty sequence
    //NEEDS TO BE COMMENTED OUT WHEN NOT TESTING FOR ERROR CATCHING
    /*
    cout << "Front value is:  " << s.front();
    cout << "Back value is:  " << s.back();
    */

    //tests for adding elements to the sequence  by adding four nodes whose values are strings of the names of various fruits
    s.push_back("Apple");
    s.push_back("Banana");
    s.push_back("Peach");
    s.push_back("Pineapple");

    cout << "\n\npush_back() test" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //tests insert() by  inserting an element at index 1
    s.insert(1, "Grape");
    cout << "\n\nInsert test" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //test pop_back by removing the last node in the sequence which contains the value "pineapple"
    s.pop_back();
    cout << "\n\npop_back() test" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //tests they = operator
    Sequence s2 = Sequence();
    s2 = s;
    cout << "\n\n= operator test" << endl << "Sequence 2 contains: ";
    for (size_t i = 0; i < s2.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s2[i];
    }

    //Follow-up test that ensures that s and s2 are separate sequences by modifying sequence 2
    s2.pop_back();
    s2.insert(1, "Durian");

    cout << "\n\n= operator part 2 test" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }
    cout << endl << "\nSequence 2 contains: ";
    for (size_t i = 0; i < s2.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s2[i];
    }


    //tests the front(), back(), empty(), and size() methods on a Sequence that has elements
    cout << "\n\nFirst element contains: " << s.front() << endl;
    cout << "Last element contains: " << s.back() << endl;
    cout << "The sequence contains " << s.size() << " elements";
    if (s.empty())
    {
        cout << "\nEmpty sequence";
    }else
    {
        cout << "\nNon-empty sequence";
    }

    //tests the bracket operators
    s[2] = "Pomegranate";
    cout << "\n\n= []operator test" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //tests the copy constructor by copying s2 and then editing s3 to show that they were initialy identical, but seperate
    Sequence s3 = Sequence(s2);
    cout << "\n\n= copy constructor test" << endl << "Sequence 3 contains: ";
    for (size_t i = 0; i < s3.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s3[i];
    }

    //edits the contents of s2 to show that s2 and s3 are separate
    s2.pop_back();
    s2.pop_back();
    cout << "\n\n= copy constructor test part 2" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s3.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s3[i];
    }

    //tests the erase functions
    s.push_back("Orange");
    s.push_back("Lemon");
    s.push_back("Lime");
    s.push_back("Strawberry");
    s.push_back("Starfruit");

    //confirms that the new elements have been added
    cout << "\n\nConfirming additions" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //Removes Banana individually and lemon - strawberry
    s.erase(2);
    s.erase(4,3);

    //confirms the removals
    cout << "\n\nConfirming removals" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    //tests the clear() function
    s.clear();
    cout << "\n\nConfirming removals" << endl << "Sequence contains: ";
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << endl << i + 1 << ".) " << s[i];
    }

    return 0;
}