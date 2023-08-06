#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    //赋值算法
    //1.赋值相同元素
    //print ten times 7.7
    fill_n(ostream_iterator<float>(cout, " "), 10, 7.7F);
    cout << endl;

    list<string> coll;
    //insert "hello" nine times
    fill_n(back_inserter(coll), 9, "hello");
    PRINT_ELEMENTS(coll, "list coll: ");

    //overwirte all elements with "again"
    fill(coll.begin(), coll.end(), "again");
    PRINT_ELEMENTS(coll, "list coll: ");

    //replace all but two elements with "hi"
    fill_n(coll.begin(), coll.size()-2, "hi");
    PRINT_ELEMENTS(coll, "list coll: ");

    //replace the second and up to the last element but one with "hmm"
    fill(next(coll.begin(), 1), prev(coll.end(), 1), "hmm");
    PRINT_ELEMENTS(coll, "list coll: ");

    //2.赋予新生值
    list<int> coll2;

    //insert five random numbers
    generate_n(back_inserter(coll2), 5, rand);
    PRINT_ELEMENTS(coll2, "list coll2: ");

    //overwrite with five net random numbers
    generate(coll2.begin(), coll2.end(), rand);
    PRINT_ELEMENTS(coll2, "new list coll2: ");

    //3.赋予一系列递增值
    array<int, 10> coll3;
    iota(coll3.begin(), coll3.end(), 100);
    PRINT_ELEMENTS(coll3, "array coll3: ");


    system("pause");
    return 0;
}
