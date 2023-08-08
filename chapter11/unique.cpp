
#include "algostuff.hpp"

using namespace std;

bool diffOne(int lhs, int rhs)
{
    return lhs + 1 == rhs || lhs - 1 == rhs;
}

bool bothSpaces(char lhs, int rhs)
{
    return lhs == ' ' && rhs == ' ';
}

int main()
{
    //source data
    int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};

    list<int> coll;

    copy(begin(source), end(source), back_inserter(coll));
    PRINT_ELEMENTS(coll, "list coll: ");

    auto pos = unique(coll.begin(), coll.end());
    copy(coll.begin(), pos, ostream_iterator<int>(cout, " "));
    cout << endl;

    //reinitialize coll with elements from source
    copy(begin(source), end(source), coll.begin());
    PRINT_ELEMENTS(coll, "list coll: ");

    //remove elements if there was a previous greater element
    coll.erase(unique(coll.begin(), coll.end(), greater<int>()), coll.end());
    PRINT_ELEMENTS(coll, "coll: ");

    //copy和unique的组合
    list<int> coll2;
    copy(begin(source), end(source), back_inserter(coll2));
    PRINT_ELEMENTS(coll2);
    cout << endl;

    //print elements without consecutive entries 
    //that differ by one
    cout << "unique copy diffOne: " << endl;
    unique_copy(coll2.cbegin(), coll2.cend(), ostream_iterator<int>(cout, " "), diffOne);
    cout << endl;

    //压缩空白序列
    //don't skip leading whitespaces by default
    cin.unsetf(ios::skipws);

    //copy standard input to standard out while compressing spaces
    cout << "input some strings, please: " << endl;
    unique_copy(istream_iterator<char>(cin), istream_iterator<char>(),
                ostream_iterator<char>(cout), bothSpaces);

    system("pause");
    return 0;
}
