#include<algorithm>
#include<array>
#include<iostream>
#include<iterator>
#include<functional>
#include<numeric>
using namespace std;

template<typename T>
void print(const T& container)
{
    for (auto elem : container) 
    {
        cout << elem << "  ";
    }
    cout << endl;
}

int main()
{
    //create array with 10 ints
    array<int, 10> a = {11, 22, 33, 44};

    print(a);

    //modify last two elements
    a.back() = 999999;
    a[a.size() - 2] = 42;

    print(a);

    //process sum of all elements
    cout << "sum:    "
        << accumulate(a.begin(), a.end(), 0)
        << endl;

    //negate all elements
    transform(a.begin(), a.end(), a.begin(), negate<int>());

    print(a);
   
    system("pause");
    return EXIT_SUCCESS;
}