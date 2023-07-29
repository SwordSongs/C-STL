#include "algostuff.hpp"

using namespace std;

void print(int elem)
{
    cout << elem << ' ';
}

template<typename T>
class AddValue {
public:
    AddValue(const T& v) : theValue(v)
    {
    
    }

    void operator() (T& elem) const
    {
        elem += theValue;
    }
private:
    T theValue;    
};

class MeanValue {
public:
    MeanValue() : num(0), sum(0) {}
    void operator() (int elem)
    {
        ++num;
        sum += elem;
    }

    double mean()
    {
        return static_cast<double>(sum) / static_cast<double>(num);
    }
private:
    long num;
    long sum;
};

int main()
{
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9, "vector inserts [1, 9]");

    //call print() for each element
    cout << "for_each prints vector." << endl;
    for_each(coll.begin(), coll.end(), [](const int &elem) { cout << elem << ' '; });
    cout << endl;

    cout << "for_each prints vector, by function." << endl;
    for_each(coll.begin(), coll.end(), print);
    cout << endl;

    cout << "for_each , by reference." << endl;
    for_each(coll.begin(), coll.end(), [](int &elem) {  elem += 10;  });
    PRINT_ELEMENTS(coll);

    for_each(coll.begin(), coll.end(), [=](int &elem) { elem += *coll.begin(); });
    PRINT_ELEMENTS(coll);

    for_each(coll.begin(), coll.end(), [&](int &elem) { elem += *coll.begin(); });
    PRINT_ELEMENTS(coll);

    cout << "for_each, +10, by functor." << endl;
    for_each(coll.begin(), coll.end(), AddValue<int>(10));
    PRINT_ELEMENTS(coll);

    cout << "for_each, +头元素" << endl;
    for_each(coll.begin(), coll.end(), AddValue<int>(*coll.begin()));
    PRINT_ELEMENTS(coll);

    cout << "使用transform，同样功能." << endl;
    transform(coll.begin(), coll.end(), coll.begin(), [](int elem) {   return elem += 10; });
    PRINT_ELEMENTS(coll);

    cout << "使用transform，同样功能." << endl;
    transform(coll.begin(), coll.end(), coll.begin(), [=](int elem) {   return elem += *coll.begin(); });
    PRINT_ELEMENTS(coll);

    cout << "capacity: " << coll.capacity() << ", size: " << coll.size() << endl;
    coll.clear();\
    cout << "capacity: " << coll.capacity() << ", size: " << coll.size() << endl;
    INSERT_ELEMENTS(coll, 1, 100, "vector inserts [1, 100]");
    cout << "the meanValue is " << for_each(coll.begin(), coll.end(), MeanValue()).mean() << " , ranged in [" << *coll.begin() << " , " << *(coll.end() - 1) << "]." << endl;

    system("pause");
    return 0;
}
