#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 2,  7);
    INSERT_ELEMENTS(coll, 4,  9);
    PRINT_ELEMENTS(coll, "coll: ");

    //替换序列内元素
    //replace all elements with value 6 with 100
    replace(coll.begin(), coll.end(), 6, 100);
    PRINT_ELEMENTS(coll, "coll: ");

    //replace all elements with value less than 5 with 0
    replace_if(coll.begin(), coll.end(), [](int elem) { return elem < 5; }, 0);
    PRINT_ELEMENTS(coll, "coll: ");

    //复制并替换元素， repalce与copy的组合
    list<int> coll2;

    INSERT_ELEMENTS(coll2, 2, 7);
    INSERT_ELEMENTS(coll2, 4, 9);
    PRINT_ELEMENTS(coll2, "coll2: ");

    //print all elements with value 5 repalced with 55
    replace_copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "), 5, 55);
    cout << endl;

    //print all elements with a value less than 6 repalced with 0
    replace_copy_if(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "), 
                   bind(less<int>(), placeholders::_1, 5), 0);
    cout << endl;

    //print each element while each odd element is replaced with -100
    replace_copy_if(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "),
        [](int elem) { return elem % 2 == 1; }, -100);
    cout << endl;
    


    system("pause");
    return 0;
}
