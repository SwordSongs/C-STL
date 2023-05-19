#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> coll = {2, 5, 4, 1, 6, 3};

    //find and print minimum and maximum elements
    auto minpos = min_element(coll.cbegin(), coll.cend());
    cout << " min : " << *minpos << endl;

    auto maxpos = max_element(coll.cbegin(), coll.cend());
    cout << " max: " << *maxpos << endl;

    //sort all elements
    sort(coll.begin(), coll.end());

    for (int &i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    //find the first element with value 3
    auto pos3 = find(coll.begin(), coll.end(), 3);

    //reverse the order of the found element and all following elements
    reverse(pos3, coll.end());

    for (int &i : coll)
    {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}

