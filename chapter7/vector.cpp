#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;

template<typename T>
void print(const T& container)
{
    for (auto elem : container) 
    {
        cout << elem << "  ";
    }
    cout << endl;
}

int main()
{
    //create empty vector for string
    vector<string> sentence;
    
    //reserve memory for five elements to aviod reallocation, only capacity change
    sentence.reserve(5);

    cout << "size: " << sentence.size() << " , capacity: " << sentence.capacity() << endl;

    //size & capacity change
    sentence.resize(10);
    cout << "size: " << sentence.size() << " , capacity: " << sentence.capacity() << endl;

    //append some elements
    sentence.push_back("Hello,");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});

    //print elements separated with spaces
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout,  " "));

    cout << endl;

    //print" technical data "
    cout << "max_size: " << sentence.max_size() << endl;
    cout << "size: " << sentence.size() << endl;
    cout << "capacity: " << sentence.capacity() << endl;

    //swap second and fourth element
    swap(sentence[1], sentence[3]);

    //insert "always" before element "?"
    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

    //assign "!" to the last element
    sentence.back() = "!";

    //print elements separated with spaces
    copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));

    cout << endl;

    //print" technical data "
    cout << "max_size: " << sentence.max_size() << endl;
    cout << "size: " << sentence.size() << endl;
    cout << "capacity: " << sentence.capacity() << endl;

    //delete last two elements
    sentence.pop_back();
    sentence.pop_back();
    //shrink capacity
    sentence.shrink_to_fit();

    //print" technical data "
    cout << "max_size: " << sentence.max_size() << endl;
    cout << "size: " << sentence.size() << endl;
    cout << "capacity: " << sentence.capacity() << endl;

    system("pause");
    return EXIT_SUCCESS;
}