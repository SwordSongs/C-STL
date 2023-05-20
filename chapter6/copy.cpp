#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<deque>
using namespace std;

int main()
{
    list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> coll2;
    deque<int> coll3(coll1.size());

    //runtime error, overwrites nonexisting element in the destination
    coll2.resize(coll1.size());
    copy(coll1.cbegin(), coll1.cend(), coll2.begin());

    for (auto &i : coll2)
    {
        cout << i << " ";
    }
    cout << endl;

    copy(coll1.cbegin(), coll1.cend(), coll3.begin());

    for (auto &i : coll3)
    {
        cout << i << " ";
    }

    system("pause");
    return EXIT_SUCCESS;
}