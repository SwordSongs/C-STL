#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{   
    vector<int> coll;

    //insert elements from -3 to 9
    for (int i = -3; i < 10; ++i)
    {
        coll.push_back(i);
    }

    //print number of elements by processing the distance between beginning and end
    //use operator- from iterators
    cout << "distance: " << coll.end() - coll.begin() << endl;

    //print all elements
    //use operator < instead of operator !=
    for (auto pos = coll.begin(); pos < coll.end(); ++pos)
    {
        cout << *pos << "  ";
    }
    cout << endl;

    //print all elements
    //use operator[] instead operator*
    for (int i = 0; i < coll.size(); ++i)
    {
        cout << coll[i] << "  ";
    }
    cout << endl;

    //print every second element
    //use operator+=
    for (auto pos = coll.begin(); pos < coll.end()-1; pos += 2)
    //for (auto pos = coll.begin(); pos < coll.end(); pos += 2)    //error: pos += 2, 将迭代器位移至end()之后
    {
        cout << *pos << " ";
    }
    cout << endl;


    system("pause");
    return EXIT_SUCCESS;
}