#include "algostuff.hpp"

using namespace std;



int main()
{
   //下列算法始自c++11， 检验某个给定区间是否符合某条件
   //检验是否排序(或局部排序)
    vector<int> coll1;
    INSERT_ELEMENTS(coll1, 1, 9);
    coll1.insert(coll1.begin(), 1);
    PRINT_ELEMENTS(coll1, "vector coll1: ");

    //check whether coll1 is sorted
    if (is_sorted(coll1.begin(), coll1.end()))
    {
        cout << "coll1 is sorted" << endl;
    }
    else
    {
        cout << "coll1 is not sorted" << endl;
    }

    map<int, string> coll2;
    coll2 = { {1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"} };
    PRINT_MAPPED_ELEMENTS(coll2, "map coll2: ");

    //define predicate to compare names
    auto compareName = [](const pair<int, string> &e1, const pair<int, string> &e2) {    return e1.second < e2.second;    };

    //check whether the names in coll2 are sorted
    if (is_sorted(coll2.begin(), coll2.end(), compareName))
    {
        cout << "names in coll2 are sorted" << endl;
    }
    else
    {
        cout << "names in coll2 are not sorted" << endl;
    }

    //print first unsorted name
    auto pos = is_sorted_until(coll2.begin(), coll2.end(), compareName);

    if (pos != coll2.end())
    {
        cout << "first unsorted name: " << pos->second << endl;
    }
    else
    {
        cout << "first unsorted name is not finded " << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    vector<int> coll3 = {5, 3, 9, 1, 3, 4, 8, 2, 6};
    PRINT_ELEMENTS(coll3, "vector coll3");

    //define predicate: check whether element is odd
    auto isOdd = [](int elem) {    return elem % 2 == 1; };

    //check whether coll3 is partitioned in odd and even elments
    if (is_partitioned(coll3.begin(), coll3.end(), isOdd))
    {
        cout << "coll3 is partitioned" << endl;

        //find first even number
        auto evenPos = partition_point(coll3.begin(), coll3.end(), isOdd);
        cout << "first even number: " << *evenPos << endl;
    }
   