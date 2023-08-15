#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll);

    //process sum of elements
    cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), 0) << endl;
    cout << "sum: " << accumulate(coll.cbegin(), coll.cend(), -100) << endl;
    cout << "1 as initial value, product: " << accumulate(coll.cbegin(), coll.cend(), 1, multiplies<int>())<<endl;
    //process product of elements (use 0 as initial value)
    cout << "0 as initial value, product: " << accumulate(coll.cbegin(), coll.cend(), 0, multiplies<int>())<<endl;

    system("pause");
    return 0;
}
