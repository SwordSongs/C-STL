#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<iterator>
#include<string>
using namespace std;

template<typename T>
void echo(vector<T> &vec)
{
    //read all words from the standard input
    //source:: all string until EOF(ctrl+z) or error
    //destination: dest_vec inserting
    copy(istream_iterator<T>(cin),
        istream_iterator<T>(),     //default constructor constructs an end-of-stream istream iterator
        back_inserter(vec));

    //sort elements
    sort(vec.begin(), vec.end());

    //print all elements without duplicates
    //source: vec
    //destination: standard output
    unique_copy(vec.cbegin(), vec.cend(),
        ostream_iterator<T>(cout, " "));

    cout << endl;
}

int main()
{
    vector<string> vec_str;
    vector<int> vec_int;

    //echo(vec_str);
    echo(vec_int);

    system("pause");
    return EXIT_SUCCESS;
}