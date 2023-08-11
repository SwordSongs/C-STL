#include "algostuff.hpp"

using namespace std;

vector<int> squareSort(vector<int> &v)
{
    vector<int> result;
    result.resize(v.size());

    int i = 0, j = v.size()-1, k = result.size()-1;

    while (i <= j)
    {
        if (v[i] * v[i] < v[j] * v[j])
        {
            result[k--] = v[j] * v[j];
            --j;
        }
        else
        {
            result[k--] = v[i] * v[i];
            ++i;
        }
    }

    return result;

}

int main()
{
    //vector<int> coll;

    //INSERT_ELEMENTS(coll, 1, 9);
    //PRINT_ELEMENTS(coll, "coll:    ");

    ////rotate one elements to the left
    //rotate(coll.begin(), coll.begin()+1, coll.end());
    //PRINT_ELEMENTS(coll, "one left:    ");

    ////rotate two elements to the right
    //rotate(coll.begin(), coll.end()-2, coll.end());
    //PRINT_ELEMENTS(coll, "two right: ");

    ////rotate so that element with value 4 is the beginning
    //rotate(coll.begin(), find(coll.begin(), coll.end(), 4), coll.end());
    //PRINT_ELEMENTS(coll, "4 first: ");

  /*  vector<int> v = { -5, 3, 2, 1, 2 ,3, 4 };
    vector<int> result = squareSort(v);

    PRINT_ELEMENTS(result, "vector result: ");*/

    set<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "vector coll: ");

    //print elements rotated one element to the left
    auto pos = next(coll.cbegin());
    cout << "rotated vector coll: " << endl;
    rotate_copy(coll.begin(), pos, coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //print elements ratated two elements to the right
    pos = coll.cend();
    advance(pos, -2);
    cout << "rotated vector coll: " << endl;
    rotate_copy(coll.begin(), pos, coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //print elements ratated so that element with value 4 is the beginning
    cout << "rotated vector coll: " << endl;
    rotate_copy(coll.begin(), coll.find(4), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    system("pause");
    return 0;
}
