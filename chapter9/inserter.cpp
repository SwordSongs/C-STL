#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

template<typename T>
void print(T container)
{
    for (auto i : container)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> coll;

    //create back inserter for coll
    //inconvenient way
    back_insert_iterator<vector<int>> back_iter(coll);

    *back_iter++ = 1;
    *back_iter++ = 2;
    *back_iter++ = 3;
    print(coll);

    //convenient way
    back_inserter(coll) = 44;
    back_inserter(coll) = 55;
    print(coll);

    //use back inserter to append all elements again
    coll.reserve(2 * coll.size());
    copy(coll.begin(), coll.end(), back_inserter(coll));
    print(coll);  

    list<int> el;
    //create front inserter for el
    //inconvenient way
    front_insert_iterator<list<int>> front_iter(el);

    *front_iter++ = 1;
    *front_iter++ = 2;
    *front_iter++ = 3; 
    cout << "list: " << endl;
    print(el);

    //convenient way
    front_inserter(el) = 44;
    front_inserter(el) = 55;
    cout << "list: " << endl;
    print(el);

    //use front inserter to append all elements again
    copy(el.begin(), el.end(), front_inserter(el));
    cout << "list: " << endl;
    print(el);

    set<int> es;
    //create insert iterator for es
    //inconvenient way
    insert_iterator<set<int>> insert_iter(es, es.begin());

    //insert elements with the usual iterator interface
    *insert_iter++ = 1;
    *insert_iter++ = 2;
    *insert_iter++ = 3;

    cout << "set: " << endl;
    print(es);

    //convenient way
    inserter(es, es.end()) = 44;   //位置信息作为提示，实际插入位置以比较准则为准
    inserter(es, es.end()) = 55;
    cout << "set: " << endl;
    print(es);

    //use inserter to insert all elements into a list
    list<int> el2;
    copy(es.begin(), es.end(), inserter(el2, el2.begin()));
    cout << "list: " << endl;
    print(el2);

    //use inserter to reinsert all elements into the list before the second element
    copy(es.begin(), es.end(), inserter(el2, ++el2.begin()));
    cout << "list: " << endl;
    print(el2);

    inserter(el2, el2.begin()) = 100;
    cout << "list: " << endl;
    print(el2);


    system("pause");
    return EXIT_SUCCESS;
}