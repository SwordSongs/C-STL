#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    list<int> coll1;
    set<int> coll2;

    //fill both collections with some sorted elements
    INSERT_ELEMENTS(coll1, 1, 6);
    INSERT_ELEMENTS(coll2, 3, 8);

    PRINT_ELEMENTS(coll1, "list coll1:    ");
    PRINT_ELEMENTS(coll2, "set coll2:    ");

    //print merged sequence
    cout << "meraged:    ";
    merge(coll1.cbegin(), coll1.cend(),
          coll2.cbegin(), coll2.cend(), 
          ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return 0;
}
