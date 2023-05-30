#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<iterator>
using namespace std;


int main()
{
    list<int> src_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //copy the elements of coll1 into coll2 by appending them
    vector<int> dest_vec;
    copy(src_list.begin(), src_list.end(), back_inserter(dest_vec));     //call push_back: vector,deque, list, string

    cout << "vec: " << endl;
    for (int i : dest_vec)
    {
        cout << i << " , ";
    }
    cout << endl;

    deque<int> dest_deq;
    copy(src_list.begin(), src_list.end(), front_inserter(dest_deq));    //call push_front: deque，list, front_list

    cout << "deq: " << endl;
    for (int i : dest_deq)
    {
        cout << i << " , ";
    }
    cout << endl;

    set<int> dest_set;
    copy(src_list.begin(), src_list.end(), inserter(dest_set, dest_set.begin()));  //call insert, insert before the position parameter

    cout << "set: " << endl;
    for (int i : dest_set)
    {
        cout << i << " , ";
    }
    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}