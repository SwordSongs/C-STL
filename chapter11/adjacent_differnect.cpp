#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 6);
    PRINT_ELEMENTS(coll, "vector coll:    ");

    //print all difference between elements
    adjacent_difference(coll.cbegin(), coll.cend(), 
                        ostream_iterator<int>(cout, " "));
    cout << endl;

    //print all sums with the predecessors
    adjacent_difference(coll.cbegin(), coll.cend(), 
                ostream_iterator<int>(cout, " "),
                plus<int>());
    cout << endl;

    //print allproducts between elements
    cout << "adjacent_difference mutiplies:    " << endl;
    adjacent_difference(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "),
        multiplies<int>());
    cout << endl;

    cout << "partial_sum mutiplies:    " << endl;
    partial_sum(coll.cbegin(), coll.cend(),
        ostream_iterator<int>(cout, " "),
        multiplies<int>());
    cout << endl;

    vector<int> coll1 = {17, -3, 22, 13, 13, -9};
    PRINT_ELEMENTS(coll1, "vector coll1:    ");

    //convert into relative values
    adjacent_difference(coll.cbegin(), coll.cend(), coll.begin());
    PRINT_ELEMENTS(coll1, "relative:    ");

    //convert into absolute values
    partial_sum(coll.cbegin(), coll.cend(), coll.begin());
    PRINT_ELEMENTS(coll1, "absolute:    ");

    system("pause");
    return 0;
}
