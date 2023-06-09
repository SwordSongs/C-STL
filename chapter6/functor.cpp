#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//simple function object that prints the passed argument
class PrintInt 
{
public:
    void operator() (int i) const 
    {
        cout << i << " ";
    }
};

//funciton object that adds the value with which it is initialized
class AddValue
{
private:
    int theValue;    //the value to add
public:
    AddValue(int v) : theValue(v) {}
    
    void operator() (int &elem)
    {
        elem += theValue;
    }
};

int main()
{
    vector<int> coll = {1, 2, 3, 4, 5};

    //print all elements
    for_each(coll.cbegin(), coll.cend(), PrintInt());
    cout << endl;

    cout << "after adding 10: " << endl;
    for_each(coll.begin(), coll.end(), AddValue(10));
    for_each(coll.cbegin(), coll.cend(), PrintInt());
    cout << endl;

    cout << "after adding 50: " << endl;
    for_each(coll.begin(), coll.end(), AddValue(50));
    for_each(coll.cbegin(), coll.cend(), PrintInt());
    cout << endl;


    system("pause");
    return EXIT_SUCCESS;
}

