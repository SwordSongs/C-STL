#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 6);
    PRINT_ELEMENTS(coll, "vector coll:    ");

    //print all partial sums
    partial_sum(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //print all partial products
    partial_sum(coll.cbegin(), coll.cend(), 
                ostream_iterator<int>(cout, " "),
                multiplies<int>());
    cout << endl;
     
    system("pause");
    return 0;
}
