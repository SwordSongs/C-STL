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
    vector<int> ev;
    INSERT_ELEMENTS(ev, 1, 3);
    PRINT_ELEMENTS(ev, "vector ev: ");

    //permute elements until they are sorted
    //runs through all permutations because the elements are sorted now
    while (next_permutation(ev.begin(), ev.end()))
    {
        PRINT_ELEMENTS(ev, "after next_permutation, vector ev: ");  
    }
    PRINT_ELEMENTS(ev, "afterward:     ");
    
    //permute until descending sorted
    //this is the next permutation after ascending sorting
    //so the loop ends immediately
    while (prev_permutation(ev.begin(), ev.end()))
    {
        PRINT_ELEMENTS(ev, "after prev_permutation, vector ev: ");
    }
    PRINT_ELEMENTS(ev, "now:     ");

    //permute elements until the are sorted in descending order
    while (prev_permutation(ev.begin(), ev.end()))
    {
        PRINT_ELEMENTS(ev, "after prev_permutation, vector ev: ");
    }
    PRINT_ELEMENTS(ev, "afterward:     ");

    system("pause");
    return 0;
}
