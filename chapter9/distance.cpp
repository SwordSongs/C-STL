#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

template<typename T>
void swap_wd(T& lhs, T& rhs)
{
    T temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}

template<typename ForwardIterator>
void print(ForwardIterator beg, ForwardIterator end)
{
    typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;

    while (beg != end)
    {
        value_type tmp(*beg);
        cout << tmp << " ";
        ++beg;
    }

    cout << endl;
}

template<typename BinIterator>
void foo(BinIterator beg, BinIterator end, std::bidirectional_iterator_tag)
{
    cout << "Container uses BinIterator" << endl;
}

template<typename RandIterator>
void foo(RandIterator beg, RandIterator end, std::random_access_iterator_tag)
{
    cout << "Container uses RandIterator" << endl;
}


template<typename Iterator>
inline void foo(Iterator beg, Iterator end)
{
    foo(beg, end, std::iterator_traits<Iterator>::iterator_category());
}


//general distance()
template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance_wd(Iterator pos1, Iterator pos2)
{
    return distance_wd(pos1, pos2,
        std::iterator_traits<Iterator>::iterator_category());
}

//distance() for random-access iterators
template<typename RandIterator>
typename std::iterator_traits<RandIterator>::difference_type
distance_wd(RandIterator pos1, RandIterator pos2,
    std::random_access_iterator_tag)
{
    return pos2 - pos1;
}

//distance() for input, forward and bidirectional iterators
template<typename InIterator>
typename std::iterator_traits<InIterator>::difference_type
distance_wd(InIterator pos1, InIterator pos2,
    std::input_iterator_tag)
{
    typename std::iterator_traits<InIterator>::difference_type d;
    for (d = 0; pos1 != pos2; ++pos1)
    {
        ++d;
    }

    return d;
}


int main()
{   
    list<int> el = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> ev = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 100 };    

   /* print(el.begin(), el.end());
    print(ev.begin(), ev.end());*/

    //string a = "hello", b = "world";
    //cout << "&a: " << &a << " , &b: " << &b << endl;
    //a = std::move(b);

    //cout << "a: " << a << " , b: " << b << endl;
    //cout << "&a: " << &a << " , &b: " << &b << endl;

    //b = "nihao";
    //cout << "a: " << a << " , b: " << b << endl;
    //cout << "&a: " << &a << " , &b: " << &b << endl;

    //foo(ev.begin(), ev.end());
    //foo(el.begin(), el.end());

    cout << "list distrance_wd: " << distance_wd(el.begin(), el.end()) << endl;
    cout << "vector distrance_wd: " << distance_wd(ev.begin(), ev.end()) << endl;


    system("pause");
    return EXIT_SUCCESS;
}

