#include "algostuff.hpp"
#include <cstdlib>

using namespace std;


int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    INSERT_ELEMENTS(coll, 1, 9);

    //PRINT_ELEMENTS(coll, "list coll:");

    //find first element with value 4
    list<int>::iterator pos1;
    pos1 = find(coll.begin(), coll.end(), 4);

    //find second element with value 4
    list<int>::iterator pos2;
    pos2 = find(next(pos1, 1), coll.end(), 4);

    //print all elements from first to second 4 (both included)
    //while(pos1 != coll.end() && pos1 != next(pos2, 1))
    //{
    //    cout << *(pos1++) << " ";
    //}

    if (pos1 != coll.end() && pos2 != coll.end())
    {
        //copy(pos1, next(pos2, 1), ostream_iterator<int>(cout, " "));
        //cout << endl;
    }

    vector<int> ev;
    vector<int>::iterator pos;

    INSERT_ELEMENTS(ev, 1, 9);
    PRINT_ELEMENTS(ev, "ev: ");

    //find first element greater than 3
    pos = find_if(ev.begin(), ev.end(), bind(greater<int>(), placeholders::_1, 3));

    //print its position
    cout << "the " << distance(ev.begin(), pos) + 1 << " element is the first greater than 3." << endl;

    //find first element divisble by 3
    pos = find_if(ev.begin(), ev.end(), [](int elem) {    return elem % 3 == 0; });

    cout << "the " << distance(ev.begin(), pos) + 1 << " element is the first divisble by 3." << endl;

    //find first element not < 5
    pos = find_if_not(ev.begin(), ev.end(), bind(less<int>(), placeholders::_1, 5));

    cout << "the " << distance(ev.begin(), pos) + 1 << " element is the first not less than 5." << endl;

    system("pause");
    return 0;
}
