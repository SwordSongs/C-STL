#include "algostuff.hpp"

using namespace std;

int main()
{
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9, "vector inserts [1, 9]");

    //call print() for each element
    cout << "for_each prints vector." << endl;
    for_each(coll.begin(), coll.end(), [](const int &elem) {cout << elem << ' '; });
    cout << endl;
    
    system("pause");
    return 0;
}
