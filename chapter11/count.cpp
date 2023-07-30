#include "algostuff.hpp"

using namespace std;



int main()
{
    vector<int> coll;
    int num;
    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "vector coll: ");

    //count elements with value 4
    num = count(coll.begin(), coll.end(), 4);
    cout << "number of elements equal to 4: " << num << endl;

    //count elements with even value
    num = count_if(coll.begin(), coll.end(), [](int elem) { return elem % 2 == 0;   });
    cout << "number of elements with even value: " << num << endl;

    //count elements that are greater than value 4
    num = count_if(coll.cbegin(), coll.cend(), [](int elem) { return elem > 4; });
    cout << "number of elements greater than 4: " << num << endl;

    //cout elements that are less than value 4
    num = count_if(coll.cbegin(), coll.cend(), bind(less<int>(), placeholders::_1, 4));
    cout << "number of elements less than 4: " << num << endl;

    system("pause");
    return 0;
}
