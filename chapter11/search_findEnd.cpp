#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

bool checkEven(int elem, bool even)
{
    if (even)
    {
        return elem % 2 == 0;
    }
    else
    {
        return elem % 2 == 1;
    }
}

int main()
{
    deque<int> coll;
    coll = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
    PRINT_ELEMENTS(coll);

    //find three consecutive elements with value 7
    deque<int>::iterator pos;
    pos = search_n(coll.begin(), coll.end(), 3, 7);

    if (pos != coll.end())
    {
        cout << "three consecutive elements with value 7 start with "
            << distance(coll.begin(), pos) + 1
            << " element" << endl;
    }
    else
    {
        cout << "three consecutive elements with value 7 are not exist."
             << endl;
            
    }

    //find four consecutive odd elements
    pos = search_n(coll.begin(), coll.end(),
                   4, 0,  //0 value is useless 
                   [](int elem, int value) {return elem % 2 == 1; });

    //print result
    if (pos != coll.end())
    {
        cout << "first four consecutive odd elements are: ";
        for(int i=0; i<4; ++i, ++pos)
        {
            cout << *pos << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "no four consecutive element with value > 3." << endl;
    }

    //search first subrange
    deque<int> ed;
    list<int> sub_ed;

    INSERT_ELEMENTS(ed, 1, 7);
    INSERT_ELEMENTS(ed, 1, 7);
    INSERT_ELEMENTS(sub_ed, 3, 6);

    PRINT_ELEMENTS(ed, "deque ed: ");
    PRINT_ELEMENTS(sub_ed, "list sub_ed: ");

    auto pos1 = search(ed.begin(), ed.end(), sub_ed.begin(), sub_ed.end());

    //loop while sub_ed fond as subranger of 
    while(pos1 != ed.end())
    {
         //print position of first element
        cout << "sub_ed found starting with element "
            << distance(ed.begin(), pos1) + 1 << endl;
    
        //search next occurence of sub_ed
        pos1 = search(++pos1, ed.end(), sub_ed.begin(), sub_ed.end());
    }

    //subrange
    vector<int> coll2;

    INSERT_ELEMENTS(coll2, 1, 9);
    PRINT_ELEMENTS(coll2, "vector coll2: ");

    bool checkEvenArgs[3] = { true, false, true };

    //search first subrange in coll2
    auto pos2 = search(coll2.begin(), coll2.end(), checkEvenArgs, checkEvenArgs+3, checkEven);

    //loop while subrange found
    while (pos2 != coll2.end())
    {
        cout << "subrange found starting with element: "
            << distance(coll2.begin(), pos2) + 1 << endl;

        pos2 = search(++pos2, coll2.end(), checkEvenArgs, checkEvenArgs + 3, checkEven);
    }

    deque<int> coll3;
    list<int> sub_coll3;

    INSERT_ELEMENTS(coll3, 1, 7);
    INSERT_ELEMENTS(coll3, 1, 7);
    INSERT_ELEMENTS(sub_coll3, 3, 6);

    //search last occurrence of subcoll in coll
    auto pos3 = find_end(coll3.begin(), coll3.end(), sub_coll3.begin(), sub_coll3.end());

    auto end = coll3.end();

    while (pos3 != end)
    {
        cout << "subcoll3 found starting with element "
            << distance(coll3.begin(), pos3) + 1
            << endl;

        end = pos3;

        pos3 = find_end(coll3.begin(), end, sub_coll3.begin(), sub_coll3.end());
    }

    system("pause");
    return 0;
}
