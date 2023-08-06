#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll1;
    deque<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 9);
    INSERT_ELEMENTS(coll2, 11, 23);

    PRINT_ELEMENTS(coll1, "vector coll1: ");
    PRINT_ELEMENTS(coll2, "deque coll2: ");

    auto pos = swap_ranges(coll1.begin()+3, coll1.begin()+7, coll2.begin());

    PRINT_ELEMENTS(coll1, "vector coll1: ");
    PRINT_ELEMENTS(coll2, "deque coll2: ");

    system("pause");
    return 0;
}
