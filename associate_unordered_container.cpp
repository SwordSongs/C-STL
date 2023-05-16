#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<set>
#include<unordered_set>
#include<string>
#include<map>
using namespace std;

int main()
{
    multiset<string> cities = {"BeiJing", "TianJin", "ShiJiaZhuang", "BeiJing"};
    unordered_multiset<string> unordered_cities= {  "TianJin",  "BeiJing", "ShiJiaZhuang", "BeiJing" };

    //multiset:
    cout << "multiset: ";
    for (auto &element : cities) 
    {
        cout << element << " ";
    }
    cout << endl;

    //unordered_multiset:
    cout << "unordered_multiset: ";
    for (auto &element : unordered_cities)
    {
        cout << element << " ";
    }
    cout << endl;

    //insert additional values:
    cities.insert({"ShangHai", "ChongQing", "XiAn"});
    unordered_cities.insert({ "ShangHai", "ChongQing", "XiAn" });

    //multiset:
    cout << "multiset: ";
    for (auto &element : cities)
    {
        cout << element << " ";
    }
    cout << endl;

    //unordered_multiset:
    cout << "unordered_multiset: ";
    for (auto &element : unordered_cities)
    {
        cout << element << " ";
    }
    cout << endl;

    unordered_cities.insert({ "ChengDu", "ShenYang", "Guilin" });

    //unordered_multiset:
    cout << "unordered_multiset: ";
    for (auto &element : unordered_cities)
    {
        cout << element << " ";
    }
    cout << endl;

    unordered_cities.insert({ "ZhengZhou", "NanJing", "HeiLongJiang"});  //插入引发rehashing, 改变之前相对顺序

    //unordered_multiset:
    cout << "unordered_multiset: ";
    for (auto &element : unordered_cities)
    {
        cout << element << " ";
    }
    cout << endl;


    multimap<int, string> coll;

    coll = { {5, "tagged"}, {2, "a"}, {1, "this"}, {4, "of"}, {6, "strings"}, {1, "is"}, {3, "multimap"}};

    cout << "mltimap: ";

    for (auto &element : coll)
    {
        cout << element.second << " ";
    }


    system("pause");
    return EXIT_SUCCESS;
}

