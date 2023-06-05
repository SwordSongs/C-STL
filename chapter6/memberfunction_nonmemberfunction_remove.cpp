#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    list<int> coll;

    for (int i = 1; i < 6; ++i)
    {
        coll.push_back(i);
        coll.push_front(i);
    }

    for (int i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    coll.erase(remove(coll.begin(), coll.end(), 3), coll.end());    //poor performance
    coll.remove(4);    //good performance

    for (int i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}