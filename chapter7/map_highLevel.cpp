#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

//function object to compare strings
class RuntimeStringCmp
{
public:
    //comparison criterion
    enum cmp_mode {normal, nocase};
    RuntimeStringCmp(cmp_mode m = normal) : mode(m) {
    
    }

    //the comparison
    bool operator()(const string& s1, const string& s2) const {
        if (mode == normal) {
            return s1 < s2;
        }
        else {
            return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), nocase_compare);
        }
    }

private:
    const cmp_mode mode;

    static bool nocase_compare(char c1, char c2) {
        return toupper(c1) < toupper(c2);
    }

};

typedef map<string, string, RuntimeStringCmp> StringStringMap;
void fillAndPrint(StringStringMap& coll)
{
    //insert elements
    coll["Deitschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";

    //print elements
    cout.setf(ios::left, ios::adjustfield);
    for (const auto& elem : coll) {
        cout << setw(15) << elem.first << " "
            << elem.second << endl;
    }
    cout << endl;
}

int main()
{
    StringStringMap coll1;
    fillAndPrint(coll1);

    //create an object for case-insensitive comparisons
    RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

    //create a container with the case-insensitive comparisons criterion
    StringStringMap coll2(ignorecase);
    fillAndPrint(coll2);

    system("pause");
    return EXIT_SUCCESS;
}