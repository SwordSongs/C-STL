#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
using namespace std;

int main()
{
    list<int> coll;

    for (int i = 1; i <= 6; ++i)
    {
        coll.push_back(i);
        coll.push_front(i);
    }

    cout << "pre:    ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove all elements with value 3
    list<int>::iterator new_end = remove(coll.begin(), coll.end(), 3);

    //cend,size无变化，只是删除值被后续元素覆盖掉
    cout << "post:   ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "number of removed elements: "
        << distance(new_end, coll.end()) << endl;

    //打印删除掉3的逻辑集合
    cout << "逻辑上， post: ";
    copy(coll.begin(), new_end, ostream_iterator<int>(cout, " "));
    cout << endl;

    //真实删除“removed”元素
    cout << "执行真实删除..." << endl;
    coll.erase(new_end, coll.end());

    //打印删除掉3的逻辑集合
    cout << "实际删除removed元素后， post new: ";
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return EXIT_SUCCESS;
}