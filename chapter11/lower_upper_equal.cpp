#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    list<int> coll;
    INSERT_ELEMENTS(coll, 1, 9);
    INSERT_ELEMENTS(coll, 1, 9);

    coll.sort();
    PRINT_ELEMENTS(coll, "list coll:    ");

    //print first and last position 5 could get inserted
    auto lower = lower_bound(coll.cbegin(), coll.cend(), 5);
    auto upper = upper_bound(coll.cbegin(), coll.cend(), 5);

    cout << "5 could get position "
         << distance(coll.cbegin(), lower) + 1
         << " up to "
         << distance(coll.cbegin(), upper) + 1
         << " without breaking the sorting " << endl;
        
    coll.insert(lower_bound(coll.cbegin(), coll.cend(), 3), 3);
    coll.insert(upper_bound(coll.cbegin(), coll.cend(), 7), 7);

    PRINT_ELEMENTS(coll, "after inserted, list coll:    ");

    //lower & upper， wd mark
    pair<list<int>::const_iterator, list<int>::const_iterator> range = equal_range(coll.cbegin(), coll.cend(), 5);

    cout << "5 could get position "
         << distance(coll.cbegin(), range.first) + 1
         << " up to "
         << distance(coll.cbegin(), range.second) + 1
         << " without breaking the sorting " << endl;

    system("pause");
    return 0;
}
