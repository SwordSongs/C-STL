#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 6);
    PRINT_ELEMENTS(coll);
    
    //0 + 1*1 + 2*2 + ... + 6*6
    cout << "inner product: "
        << inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 0) << endl;

    //0 + 1*6 + 2*5 +...+ 6*1
    cout << "inner reverse product: "
        << inner_product(coll.cbegin(), coll.cend(), coll.crbegin(), 0) << endl;
    
    //process product of all sums
    //1*(1+1)*(2+2)...*(6+6)
    cout << "product of sums: "
        << inner_product(coll.cbegin(), coll.cend(), coll.cbegin(), 1,
            multiplies<int>(),     //outer op
            plus<int>())            //inner op
        << endl;         
    system("pause");
    return 0;
}
