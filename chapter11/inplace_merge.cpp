#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    list<int> coll;

    //insert two sorted sequences
    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(coll, 1, 8);
    PRINT_ELEMENTS(coll);

    //find beginning of second part (element after 7)
    auto pos = find(coll.begin(), coll.end(), 7);
    ++pos;

    //merage into one sorted range, 原地
    inplace_merge(coll.begin(), pos, coll.end());
    PRINT_ELEMENTS(coll, "coll:    ");

    system("pause");
    return 0;
}
