#include "algostuff.hpp"

using namespace std;


int main()
{
    vector<int> coll;
    list<int> search_coll;

    INSERT_ELEMENTS(coll, 1 ,11);
    INSERT_ELEMENTS(search_coll, 3, 5);

    PRINT_ELEMENTS(coll, "coll: ");
    PRINT_ELEMENTS(search_coll, "search_coll: ");

    //search first occurrence of an element of search_coll in coll
    auto pos = find_first_of(coll.begin(), coll.end(), search_coll.begin(), search_coll.end());
    cout << "first element of search_coll in coll is element " << distance(coll.begin(), pos) + 1 << endl;

    //search last occurrence of an element of search_coll in coll
    auto rpos = find_first_of(coll.rbegin(), coll.rend(), search_coll.begin(), search_coll.end());
    cout << "*rpos: " << *rpos << endl;   //返回得是range1中的InputIterator
    cout << "first element of search_coll in coll is element " << distance(coll.begin(), rpos.base()) << endl;
    
    system("pause");
    return 0;
}
