#include<forward_list>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<string>
using namespace std;

void printLists(const string& s, const forward_list<int>& l1, const forward_list<int>& l2)
{
    cout << s << endl;
    cout << "list1: " << endl;
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "list2: " << endl;
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
}


int main()
{
   //create two forward lists
    forward_list<int> l1 = {1, 2, 3, 4};
    forward_list<int> l2 = { 77, 88, 99 };

    l2.insert_after(l2.before_begin(), 66);
    l2.push_front(11);
    l2.insert_after(l2.before_begin(), {11, 22, 33, 44});
    printLists("insert new elements: ", l1, l2);

    //insert all elements of l2 at beginning of l1
    l1.insert_after(l1.before_begin(), l2.begin(), l2.end());
    printLists("l2 into l1: ", l1, l2);

    l2.erase_after(l2.begin());  //2nd element
    l2.erase_after(find(l2.begin(), l2.end(), 99), l2.end());
    printLists("delete element of l2: ", l1, l2);

    l1.sort();
    l2 = l1;
    l2.unique();
    printLists("sorted and unique: ", l1, l2);

    //merge both sorted list
    l1.merge(l2);
    printLists("merged: ", l1, l2);

    system("pause");
    return EXIT_SUCCESS;
}