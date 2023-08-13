#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int erase(vector<int> &v, int val)
{
    int fast = 0, slow = 0;

    for (fast = 0; static_cast<size_t>(fast) < v.size(); ++fast)
    {
        if (val != v[fast])
            v[slow++] = v[fast];
    }

    return slow;
}

int main()
{

    //vector<int> v = {1, 2, 3, 4, 5, 3};

    //cout << "size :" << erase(v, 3) << endl;

    //for (int i : v)
    //{
    //    cout << i << " ";
    //}
    //cout << endl;

    vector<int> coll1;
    vector<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 9);
    INSERT_ELEMENTS(coll2, 1, 9);

    PRINT_ELEMENTS(coll1, "vector coll1: ");
    PRINT_ELEMENTS(coll2, "vector coll2: ");
    cout << endl;

    //move all even elementsw to the front
    auto pos1 = partition(coll1.begin(), coll1.end(), [](int elem) { return elem % 2 == 0; });
    auto pos2 = stable_partition(coll2.begin(), coll2.end(), [](int elem) { return elem % 2 == 0; });

    //print collections and first odd element
    PRINT_ELEMENTS(coll1, "vector coll1: ");
    cout << "first odd element: " << *pos1 << endl;

    PRINT_ELEMENTS(coll2, "vector coll2: ");
    cout << "first odd element: " << *pos2 << endl;

    system("pause");
    return 0;
}
