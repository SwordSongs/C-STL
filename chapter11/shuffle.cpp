#include "algostuff.hpp"
#include <ctime>
#include <cstdlib>
#include <random>
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

int myrandom(int i) 
{
    return rand()%i;
}

int main()
{
    std::srand(unsigned(time(0)));
    vector<int> coll;
    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:    ");

    //shuffle all elements randomly
    random_shuffle(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "coll shuffled:    ");

    //sort them again
    sort(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "coll sorted: ");

    //shuffle elements with default engine
    default_random_engine dre;
    shuffle(coll.begin(), coll.end(), dre);
    //random_shuffle(coll.begin(), coll.end(), myrandom);

    PRINT_ELEMENTS(coll, "coll shuffled:    ");

    system("pause");
    return 0;
}
