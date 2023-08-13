#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll = {1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5};
    PRINT_ELEMENTS(coll, "vector coll:    ");

    //destination collections
    vector<int> evenColl;
    vector<int> oddColl;

    //copy all elements partitioned accordingly into even and odd elements
    partition_copy(coll.cbegin(), coll.cend(), 
                   back_inserter(evenColl), back_inserter(oddColl),
                       [](int elem) { return elem % 2 == 0;  });

    PRINT_ELEMENTS(evenColl, "evenColl:    ");    //copy_if()
    PRINT_ELEMENTS(oddColl, "oddColl:    ");      //remove_copy_if()

    system("pause");
    return 0;
}
