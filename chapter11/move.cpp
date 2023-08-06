#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<string> coll1 = {"Hello", "this", "is", "an", "example"};
    list<string> coll2;
    vector<string> coll3;

    //copy elements of coll1 into coll2
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));

    //print elements of coll2
    cout << "list coll2: " << endl;
    move(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;

    //copy elements of coll1 into coll2 inverse corder and print elements of coll2
  /*  move(coll1.crbegin(), coll1.crend(), coll2.begin());
    cout << "list coll2: " << endl;
    move(coll2.cbegin(), coll2.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;*/
    coll3.resize(10);
    move_backward(coll1.cbegin(), coll1.cend(), coll3.end());
   
    PRINT_ELEMENTS(coll3, "vecotor coll3: ");
    cout << endl;

    system("pause");
    return 0;
}
