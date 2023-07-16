#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //create multimap as string/string dictionary
    multimap<string, string> dict;

    //insert some elements in random order
    dict.insert(
        { {"day", "tag"}, { "strange", "fremd" },
          { "car", "Auto" }, { "smart", "elegant" },
          { "trait", "Merkmal" }, {"strange", "seltsam"},
          { "smart", "raffiniert" }, { "smart", "klug" },
          { "clever", "raffiniert" }, }
    );

    //print all elements
    cout.setf(ios::left, ios::adjustfield);
    cout << " " << setw(10) << "english " << "german " << endl;
    cout << setfill('-') << setw(20) << "" << setfill(' ') << endl;
    for (const auto& elem : dict) {
        cout << ' ' << setw(10) << elem.first << elem.second << endl;
    }
    cout << endl;

    //print all values for key "smart"
    string word("smart");
    cout << word << ": " << endl;
    for (auto pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos) {
        cout << "    " << pos->second << endl;
    }

    //print all keys for value "raffiniert"
    word = "raffiniert";
    cout << word << ": " << endl;
    for (const auto& elem : dict) {
        if (elem.second == word) {
            cout << "    " << elem.second << endl;
        }
    }

    //search an element with key "smart"
    auto posKey = dict.find("smart");
    if (posKey != dict.end()) {
        cout << "key smart found ("
             << posKey->first << " : "
             << posKey->second << ")" << endl;
    }

    //search an element with value raffiniert (linear complexity)
    auto posVal = find_if(dict.begin(), dict.end(), [](const pair<const string, string>& elem) {return elem.second == "raffiniert"; });
    if (posVal != dict.end()) {
        cout << "value raffiniert found ("
             << posVal->first << ":"
             << posVal->second << ")" << endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}