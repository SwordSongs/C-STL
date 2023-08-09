#include "algostuff.hpp"

using namespace std;


int main()
{
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "vector coll: ");

    //reverse order of elements
    reverse(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "vector coll: ");

    //reverse order from second to last element but one
    reverse(coll.begin()+1, coll.end()-1);
    PRINT_ELEMENTS(coll, "vector coll: ");

    //print all of them in reverse order
    cout << "print coll elements: " << endl;
    reverse_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    system("pause");
    return 0;
}
