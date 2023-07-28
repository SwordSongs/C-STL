#ifndef ALGOSTUFF_HPP
#define ALGOSTUFF_HPP

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>

using namespace std;

//INSERT_ELEMENTS(collection, first, last)
//-fill values from first to last into the collection
//-Note: NO half-open range
template<typename T>
void INSERT_ELEMENTS(T& coll, int first, int last, const string& info = "")
{
    cout << info << endl;
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

//PRINT_ELEMENTS()
//prints all elements of the collection
//-separated by spaces
template<typename T>
void PRINT_ELEMENTS(const T& coll, const string& info = "")
{
    cout << info << endl;;
    for (const auto &elem : coll)
    {
        cout << elem << " ";
    }
    cout << endl;
}

//PRINT_MAPPED_ELEMENTS()
//prints elements of the key/value collection coll
//separated by spaces
template<typename T>
void PRINT_MAPPED_ELEMENTS(const T&coll, const string& info = "")
{
    cout << info << endl;
    for (const auto &elem : coll)
    {
        cout << '[' << elem.first << ',' << elem.second << '] ';
    }
    cout << endl;
}

#endif