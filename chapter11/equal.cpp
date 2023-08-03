#include "algostuff.hpp"

using namespace std;

bool bothEvenOrOdd(int elem1, int elem2)
{
    return elem1 % 2 == elem2 % 2;
}

int main()
{
    vector<int> coll1;
    list<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 7);
    INSERT_ELEMENTS(coll2, 1, 7);

    PRINT_ELEMENTS(coll1, "vector coll1: ");
    PRINT_ELEMENTS(coll2, "list coll2: ");

    if (equal(coll1.begin(), coll1.end(), coll2.begin()))
    {
        cout << "coll1 == coll2 " << endl;
    }
    else
    {
        cout << "coll1 != coll2 " << endl;
    }
    
    if (equal(coll1.begin(), coll1.end(), coll2.begin(), bothEvenOrOdd))
    {
        cout << "even and odd elements correspond " << endl;    //ÆæÅ¼ÐÔÒ»ÖÂ
    }
    else
    {
        cout << "even and odd elements do not correspond " << endl;
    }

    system("pause");
    return 0;
}
