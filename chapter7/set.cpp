#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>
#include<functional>
using namespace std;

int main()
{
    set<int> c;

    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);
    //c.insert(5);
    c.insert(6);

    cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
    cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
    cout << "equal_range(3): " << *c.equal_range(3).first << " "
                               << *c.equal_range(3).second << endl;

    cout << endl;
    cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
    cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
    cout << "equal_range(5): " << *c.equal_range(5).first << " "
                               << *c.equal_range(5).second << endl;   //*first == *second, 同值区间无元素
    
    //descending order
    set<int, greater<int>> coll1;
    coll1.insert({4,3,5,1,6,2});
    coll1.insert(5);

    for (int elem : coll1) 
    {
        cout << elem << " ";
    }
    cout << endl;

    auto status = coll1.insert(4);
    if (status.second)
    {
        cout << " 4 inserted as element "
            << distance(coll1.begin(), status.first) + 1 << endl;
    }
    else
    { 
        cout << " 4 already exists" << endl;
    }

    //ascending order
    set<int> coll2(coll1.begin(), coll1.end());

    //print
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    coll2.erase(coll2.begin(), coll2.find(3));

    size_t num = 0;
    num = coll2.erase(5);
    cout << num << " element(s) removed"<<endl;

    //print
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;



    system("pause");
    return EXIT_SUCCESS;
}