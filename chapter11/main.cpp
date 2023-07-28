#include "algostuff.hpp"

using namespace std;

void print(int elem)
{
    cout << elem << ' ';
}

int main()
{
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9, "vector inserts [1, 9]");

    //call print() for each element
    cout << "for_each prints vector." << endl;
    for_each(coll.begin(), coll.end(), [](const int &elem) {cout << elem << ' '; });
    cout << endl;

    cout << "for_each prints vector, by function." << endl;
    for_each(coll.begin(), coll.end(), print);
    cout << endl;

    cout << "for_each , by reference." << endl;
    for_each(coll.begin(), coll.end(), [](int &elem) {  elem += 10;  });
    PRINT_ELEMENTS(coll);
    
    for_each(coll.begin(), coll.end(), [=](int &elem) { elem += *coll.begin(); });
    PRINT_ELEMENTS(coll);

    for_each(coll.begin(), coll.end(), [&](int &elem) { elem += *coll.begin(); });
    PRINT_ELEMENTS(coll);




    system("pause");
    return 0;
}
