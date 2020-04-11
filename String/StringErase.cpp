#include <string>
#include <iostream>
using namespace std;

void eraseAll(string &input)
{
    input.erase(); //erase all elements in a string
}

void eraseFromIndex(string &inputString, int index)
{
    inputString.erase(index); //remove characters starting at index to end;
}

void eraseFromIndexUptoLength(string &inputString, int index, int length)
{
    inputString.erase(index, length); //remove given length characters starting from index;
}

void eraseSingleCharacterAtGivenIndexUsingIterator(string &inputString, int index)
{
    string::iterator itr = inputString.begin();
    advance(itr, index);    //iterator at pointing at index
    inputString.erase(itr); //remove single character pointed by the iterator;
}

void eraseFromOneIndexToAnotherIndex(string &inputString, int startingIndex, int endIndex)
{

    string::iterator start = next(inputString.begin(), startingIndex);
    string::iterator end = next(inputString.begin(), endIndex);

    inputString.erase(start, end); //remove from startingindex to endIndex;
}
int main()
{

    string test = "RemoveAllCharacters";
    eraseFromOneIndexToAnotherIndex(test, 1, 5);
    cout << test;
    return 0;
}