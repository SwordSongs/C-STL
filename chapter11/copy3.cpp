#include "algostuff.hpp"
#include <cstdlib>
#include <windows.h>

using namespace std;

int main()
{
    cout << "echo: " << endl;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
    system("pause");
    return 0;
}
