#include <iterator>
#include <iostream>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

void print(int elem)
{
    cout << elem << " ";
}

int main()
{
    list<int> coll;

    //insert elements
    for (int i = 0; i < 10; ++i)
    {
        coll.push_back(i);
    }

    auto  pos = coll.begin();

    //print actual element
    cout << *pos << endl;

    //step three elements forward
    advance(pos, 3);

    //print actual element
    cout << *pos << endl;

    //step one element backward
    advance(pos, -1);

    //print actual element
    cout << *pos << endl;

    cout << "pos+2: " << *(next(pos, 2)) << endl;
    cout << "pos-2: " << *(prev(pos, 2)) << endl;
    cout << "pos: " << *pos << endl;

    cout << distance(coll.begin(), coll.end()) << endl;

    //print all elements
    cout << "list: " << endl;
    for (int i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    //swap first and last value
    iter_swap(coll.begin(), prev(coll.end()));

    //print all elements
    cout << "list: " << endl;
    for (int i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    list<int> coll2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //print all elements in normal order
    cout << "list coll2: " << endl;
    for_each(coll2.begin(), coll2.end(), print);
    cout << endl;

    //print all elements in reverse order
    cout << "reverse list coll2: " << endl;
    for_each(coll2.rbegin(), coll2.rend(), print);
    cout << endl;


    list<int> coll3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto index = find(coll.begin(), coll.end(), 5);

    cout << "index: " << *index << endl;    //print 5
    list<int>::const_reverse_iterator rindex(index);

    cout << "rindex: " << *rindex << endl;  //print 4, reverse iterator value 为指向元素的前一个

    //create deque with elements from 1 to 9
    deque<int> coll4 = { 1,2,3,4,5,6,7,8,9 };

    //find position of element with value 2
    auto pos_d = find(coll4.begin(), coll4.end(), 2);

    //find position of element with value 7
    auto pos_d1 = find(coll4.begin(), coll4.end(), 7);

    //print all elements in range[pos_d, pos_d1)
    cout << "deque: " << endl;
    for_each(pos_d, pos_d1, print);
    cout << endl;

    deque<int>::const_reverse_iterator rpos_d(pos_d);
    deque<int>::const_reverse_iterator rpos_d1(pos_d1);

    cout << "reverse deque: " << endl;
    for_each(rpos_d1, rpos_d, print);
    cout << endl;

    list<int> coll5 = { 1,2,3,4,5,6,7,8,9 };

    index = find(coll5.begin(), coll5.end(), 5);

    //print value of element
    cout << "index: " << *index << endl;    //5
    list<int>::const_reverse_iterator cr_index(index);

    //print value of element
    cout << "rindex: " <<*cr_index << endl;

    list<int>::const_iterator crr_index = cr_index.base();

    //print value of element
    cout << "rrindex: " << *crr_index << endl;


    system("pause");
    return EXIT_SUCCESS;
}