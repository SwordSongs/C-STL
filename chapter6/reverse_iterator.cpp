#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;


int main()
{
    vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    //print all element in reverse order
    copy(coll.crbegin(), coll.crend(), ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return EXIT_SUCCESS;
}