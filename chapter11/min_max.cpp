#include "algostuff.hpp"
#include <cstdlib>

using namespace std;

bool absLess(int elem1, int elem2)
{
    return abs(elem1) < abs(elem2);
}

int main()
{
    deque<int> coll;

    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, -3, 6);

    PRINT_ELEMENTS(coll);

    //process and print minimum and maximum
    cout << "minimum: "
        << *min_element(coll.cbegin(), coll.cend())
        << endl;
    cout << "maximum: "
        << *max_element(coll.cbegin(), coll.cend())
        << endl;

    //print min and max and their distance using mainmax_element
    auto mm = minmax_element(coll.cbegin(), coll.cend());   
    //最大最小值出现多次时， mm.first指向第一个， mm.second指向最后一个
    //If more than one equivalent element has the smallest value, the first iterator points to the first of such elements.
    //If more than one equivalent element has the largest value, the second iterator points to the last of such elements.

    cout << "min: " << *(mm.first) << endl;
    cout << "max: " << *(mm.second) << endl;
    cout << "distance: " << distance(mm.first, mm.second) << endl;

    //process and print minimum and maximum of absolute values
    cout << "minimum of absolute values: "
         << *min_element(coll.cbegin(), coll.cend(), absLess) << endl;
    cout << "maximum of absolute values: "
        << *max_element(coll.cbegin(), coll.cend(), absLess) << endl;

    system("pause");
    return 0;
}
