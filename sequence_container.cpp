#include<iostream>
#include<vector>
#include<deque>
#include<array>
#include<list>
#include<forward_list>
#include<string>
using namespace std;


int main()
{
    vector<int> vec; //vector container for integer elements

    //append elements
    for (int i = 1; i <= 6; ++i)
    {
        vec.push_back(i);
    }

    //print all elements
    cout << "vector: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    deque<float> deq;

    for (int i = 0; i <= 6; ++i)
    {
        deq.push_front(i*1.1F);
    }

    cout << "deque: ";
    for (size_t i = 0; i < deq.size(); ++i)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    //static array
    array<string, 5> ary = { "hello", "world" };

    cout << "array: " << endl;
    for (size_t i = 0; i < ary.size(); ++i)
    {
        cout << i << " : " << ary[i] << endl;
    }
    cout << endl;

    list<char> doubly_list;

    for (char c = 'a'; c < 'z'; ++c)
    {
        doubly_list.push_back(c);
    }

    //foreach
    cout << "list : ";
    for (auto &element : doubly_list)
    {
        cout << element << " ";
    }
    cout << endl;

    //print and remove the first element
    cout << "list : ";
    while (!doubly_list.empty())
    {
        cout << doubly_list.front() << " ";
        doubly_list.pop_front();
    }

    cout << endl;
    cout<<(doubly_list.empty() ? "list is empty " : "list is not empty ")<<endl;

    forward_list<long> singly_list = { 2,3,5,7,11,13,17 };
    singly_list.resize(10, 99);

    cout << "singly list: ";
    for (auto &element : singly_list)
    {
        cout << element << " ";
    }

    cout << endl;

    system("pause");
    return EXIT_SUCCESS;
}