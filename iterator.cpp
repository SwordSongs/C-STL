#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<char> coll;

    //append elements 
    for (char c = 'a'; c <= 'z'; ++c)
    {
        coll.push_back(c);
    }

    //print all elements, iterate over all elements
    cout << "list: "<<endl;
    //const_iterator, read only
    //iterator 
    for (list<char>::iterator it = coll.begin(); it != coll.end(); ++it)   // it++, ok, but slightly slower 
    {
        *it = toupper(*it);
        cout << *it << " ";
    }
    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}