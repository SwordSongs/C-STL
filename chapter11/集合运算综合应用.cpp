#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> c1 = { 1,2,2,4,6,7,7,9 };
    deque<int>  c2 = { 2,2,2,3,6,6,8,9 };

    //print source ranges
    cout << "vector c1:    ";
    copy(c1.cbegin(), c1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "deque c2:    ";
    copy(c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //sum the ranges by using merge
    cout << "merge:    ";
    merge(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //unite the range by using set_union
    cout << "set_union    ";
    set_union(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //interset the ranges by using set_intersection
    cout << "set_intersection:    ";
    set_intersection(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //determine elements of first range without elements of second range
    cout << "set_difference:    ";
    set_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //determine difference the ranges with set_symmetric_difference
    cout << "set_symmetric_difference:    ";
    set_symmetric_difference(c1.cbegin(), c1.cend(), c2.cbegin(), c2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    system("pause");
    return 0;
}
