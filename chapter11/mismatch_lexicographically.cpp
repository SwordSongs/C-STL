#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

void printCollection(const list<int> &l)
{
    PRINT_ELEMENTS(l, "list: ");
}

bool lessForCollection(const list<int> &l1, const list<int> &l2)
{
    return lexicographical_compare(l1.cbegin(), l1.cend(), l2.cbegin(), l2.cend());
}

int main()
{
    vector<int> coll1;
    INSERT_ELEMENTS(coll1, 1, 6);

    list<int> coll2 = {1, 2, 4, 8, 16, 3};

    PRINT_ELEMENTS(coll1, "vector coll1: ");
    PRINT_ELEMENTS(coll2, "list coll2: ");

    //find first mismatch
    auto values = mismatch(coll1.begin(), coll1.end(), coll2.begin());

    if (values.first == coll1.end())
    {
        cout << "no mismatch " << endl;
    }
    else
    {
        cout << "first mismatch: " << *values.first << " and " << *values.second << endl;
    }

    //find first position where the element of coll1 is not less than the corresponding element of coll2
    values = mismatch(coll1.begin(), coll1.end(), coll2.begin(), less_equal<int>());

    if (values.first == coll1.end())
    {
        cout << "always less-or-equal " << endl;
    }
    else
    {
        cout << "not less-or-equal " << *values.first << " and " << *values.second << endl;
    }

    list<int> c1, c2, c3, c4;
    //fill all collections with the same starting values
    INSERT_ELEMENTS(c1, 1, 5);
    c4 = c3 = c2 = c1;

    //and now some differences
    c1.push_back(7);    //1, 2, 3, 4, 5, 7
    c3.push_back(2);    //1, 2, 3, 4, 5, 2, 0
    c3.push_back(0);
    c4.push_back(2);    //1, 2, 3, 4, 5, 2

    vector<list <int>> cc;
    cc.insert(cc.begin(), {c1, c2 ,c3, c4, c3, c1, c4, c2});

    //print all collections
    for_each(cc.cbegin(), cc.cend(), printCollection);
    cout << endl;

    //sort collection lexicographically
    sort(cc.begin(), cc.end(), lessForCollection);
    cout << "***********************" << endl;
    for_each(cc.cbegin(), cc.cend(), printCollection);
    cout << endl;


    system("pause");
    return 0;
}
