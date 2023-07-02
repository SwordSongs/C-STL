#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
#include<map>
#include<iterator>
#include<iomanip>
using namespace std;

int main()
{
    //map<string, float> coll;
    //coll["otto"] = 7.7F;

    //deque<pair<string, float>> d;
    //d.push_front({"otto", 1.1F});
    //d.push_front({ "ott01", 1.2F });

    //const map<string, float> coll2(d.begin(), d.end());

    //for (decltype(coll2)::value_type ele : coll2)
    //{
    //    cout << ele.first << " , " << ele.second << endl;
    //}

    //cout << coll2["otto"] << endl;  //error, 只有Non-const map 提供了subscript操作符

    //使用算法
    map<string, double> coll{ {"tim", 9.9}, {"struppi", 11.77}};
    //square the value of each element
    for_each(coll.begin(), coll.end(), [](pair<const string, double> &elem) { elem.second *= elem.second; });

    //print each element
    for_each(coll.begin(), coll.end(), [](const decltype(coll)::value_type &elem) { cout << elem.first << " , " << elem.second << endl; });

    //将Map作为关联数组
    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks;

    //insert some elements
    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.5;
    stocks["Daimler"] = 819,0;
    stocks["BMW"] = 834.0;
    stocks["Siemens"] = 842.2;
    
    //print all elements
    StringFloatMap::iterator pos;
    cout << left;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first << " , price: " << pos->second << endl;
    }
    cout << endl;

    //boom
    for_each(stocks.begin(), stocks.end(), [](decltype(stocks)::value_type &elem) {  elem.second *= 2;  });

    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first << " , price: " << pos->second << endl;
    }
    cout << endl;

    //rename key from "VW"
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    //print all
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << setw(12) << pos->first << " , price: " << pos->second << endl;
    }


    system("pause");
    return EXIT_SUCCESS;
}

