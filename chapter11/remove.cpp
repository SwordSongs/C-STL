#include "algostuff.hpp"

using namespace std;



int main()
{
    //1.ÒÆ³ý
    vector<int> coll;

    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, 4, 9);
    INSERT_ELEMENTS(coll, 1, 7);
    PRINT_ELEMENTS(coll, "vector coll: ");

    //remove all elements with value 5
    auto pos = remove(coll.begin(), coll.end(), 5);
    PRINT_ELEMENTS(coll, "size not changed: ");

    //erase the "removed" elelments in the container
    coll.erase(remove_if(coll.begin(), coll.end(), [](int elem) { return elem < 4;  }), coll.end());
    PRINT_ELEMENTS(coll, "<4 removed: ");

    //2.¿½±´Ê±ÒÆ³ý
    list<int> coll1;
    INSERT_ELEMENTS(coll1, 1, 6);
    INSERT_ELEMENTS(coll1, 1, 9);
    PRINT_ELEMENTS(coll1, "vector coll1: ");

    //print elements without those having a value greater than 4
    cout << "greater than 4 removed: " << endl;
    remove_copy_if(coll1.cbegin(), coll1.cend(), ostream_iterator<int>(cout, " "), [](int elem) { return elem > 4; });
    cout << endl;

    //copy all elements not less than 4 into a multiset
    multiset<int> emset;
    remove_copy_if(coll1.cbegin(), coll1.cend(), inserter(emset, emset.end()), bind(less<int>(), placeholders::_1, 4));
    PRINT_ELEMENTS(emset, "multiset emset: ");

    system("pause");
    return 0;
}
