#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll1;
    list<int> coll2;


    //transform第一种调用
    INSERT_ELEMENTS(coll1, 1, 9);
    //negate all ellments in coll1
    PRINT_ELEMENTS(coll1, "vector coll1: ");
    transform(coll1.cbegin(), coll1.cend(), coll1.begin(), negate<int>());
    PRINT_ELEMENTS(coll1, "vector coll1 negated: ");

    //transform elements of coll1 into coll2 with ten times their value
    transform(coll1.cbegin(), coll1.cend(), back_inserter(coll2), bind(multiplies<>(), placeholders::_1, 10));
    PRINT_ELEMENTS(coll2, "list coll2: ");

    //print coll2 negatively and in reverse order
    transform(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "), [](int elem) { return -elem; });
    cout << endl;

    //transform第二种调用
    vector<int> coll3;
    list<int> coll4;

    INSERT_ELEMENTS(coll3, 1, 9);
    PRINT_ELEMENTS(coll3, "coll3: ");

    //square each element
    transform(coll3.cbegin(), coll3.cend(), coll3.cbegin(), coll3.begin(), multiplies<int>());
    PRINT_ELEMENTS(coll3, "coll3 squared: ");

    //add each element traversed forward with each element traversed backard and insert result into coll4
    transform(coll3.cbegin(), coll3.cend(),  coll3.crbegin(), back_inserter(coll4), plus<int>());
    PRINT_ELEMENTS(coll4, "coll4： ");

    //print differences of two corresponding elements
    cout << "diff: " << endl;
    transform(coll3.cbegin(), coll3.cend(), coll4.cbegin(), ostream_iterator<int>(cout, " "), minus<int>());
    cout << endl;

    system("pause");
    return 0;
}
