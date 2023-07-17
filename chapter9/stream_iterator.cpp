#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

int main()
{   
    //create ostream iterator for stream cout
    ostream_iterator<int> intWriter(cout, " ");

    //write elements with the usual iterator interface
    *intWriter++ = 42;    //等同cout<<42;
    *intWriter++ = 77;
    *intWriter++ = -5;

    cout << endl;

    //create collection with elements from 1 to 9
    vector<int> coll = { 1,2,3,4,5,6,7,8,9 };
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    //create istream iterator that reads integers from cin
    //istream_iterator<string> intReader(cin);

    //create end-of-stream iterator
    //istream_iterator<string> intReaderEOF;

    //while able to read tokens with istream iterator
    //while (intReader != intReaderEOF)
    //{
    //    cout << "once: " << *intReader << endl;         //等同cin>>
    //    cout << "once again: " << *intReader << endl;
    //    ++intReader;                                    //返回cin
    //}

    //两种迭代器
    istream_iterator<string> cinPos(cin);
    istream_iterator<string> cinEOF;
    ostream_iterator<string> coutPos(cout, " ");

    cout << "input & output: " << endl;
    while (cinPos != cinEOF)
    {
        //ignore the following two streings
        advance(cinPos, 2);

        //read and write the third string
        if (cinPos != cinEOF)
        {
            *coutPos++ = *cinPos++;
        }
    }
    cout << "eof." << endl;

    system("pause");
    return EXIT_SUCCESS;
}