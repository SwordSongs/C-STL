#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "list coll:    ");

    //check existence of element with value 5
    if (binary_search(coll.cbegin(), coll.cend(), 5))
    {
        cout << "5 is present " << endl;
    }
    else
    {
        cout << "5 is not present " << endl;
    }

    if (binary_search(coll.cbegin(), coll.cend(), 42))
    {
        cout << "42 is present " << endl;
    }
    else
    {
        cout << "42 is not present " << endl;
    }

    system("pause");
    return 0;
}
