#include "algostuff.hpp"

using namespace std;

int main()
{
    stack<int> st;

    //push three elements into the stack
    st.push(1);
    st.push(2);
    st.push(3);

    //pop and print two elements from the stack
    cout << st.top() << " ";
    st.pop();

    cout << st.top() << " ";
    st.pop();

    //modify top element
    st.top() = 77;

    //push two new elements
    st.push(4);
    st.push(5);

    //pop one element without processing it
    cout << endl << "pop top 5" << endl;
    st.pop();

    //pop and print remaining elements
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    //c++11, std::move() / emplace()
    stack<pair<string, string>> st1;
    auto p = make_pair("hello","world");
    st1.push(std::move(p));
    st1.emplace("Jay", "Chou");

    //pop and print remaining elements
    while (!st1.empty())
    {
        cout << st1.top().first << " "<<st1.top().second << " |-| ";
        st1.pop();
    }
    cout << endl;


   
    system("pause");
    return 0;
}
