#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Item {
private:
    string name;
    float price;
public:
    Item(const string &n, float p = 0) : name(n), price(p) {
    }

    string getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    void setName(const string &n)
    {
        name = n;
    }

    void setPrice(float p) {
        price = p;
    }
};

template <typename coll>
void printItems(const string& msg, const coll& coll)
{
    cout << msg << endl;
    for (const auto& elem : coll) {
        cout << " " << elem->getName() << " : " << elem->getPrice() << endl;
    }
}



int main()
{   
   //two different collections sharing Items
    typedef shared_ptr<Item> ItemPtr;
    set<ItemPtr> allItems;
    deque<ItemPtr> bestsellers;

    //insert objects into the collections
    //bestsellers are in both collections

    bestsellers = { ItemPtr(new Item("Kong Yize", 20.1F)),
                    ItemPtr(new Item("A Midsummer Night's Dream", 14.99F)),
                    ItemPtr(new Item("The Maltese Falcon", 9.88F))};

    allItems = {ItemPtr(new Item("Water", 0.44F)), 
                ItemPtr(new Item("Pizza", 2.22F))};

    allItems.insert(bestsellers.begin(), bestsellers.end());

    //print contents of both collections
    printItems("bestsellers: ", bestsellers);
    printItems("all: ", allItems);

    //double price of bestsellers
    for_each(bestsellers.begin(), bestsellers.end(), 
        [](shared_ptr<Item>& elem) {
            elem->setPrice(elem->getPrice() * 2);
        });

    printItems("bestsellers: ", bestsellers);
    printItems("all: ", allItems);

    //replace second bestseller by first item with name "Pizza"
    bestsellers[1] = *(find_if(allItems.begin(), allItems.end(),
        [](ItemPtr elem) { return elem->getName() == "Pizza";}));

    printItems("bestsellers: ", bestsellers);
    printItems("all: ", allItems);

    //reference wrapper, 容器存在，被指向的元素一定存在
    vector<reference_wrapper<Item>> books;
    Item f("Faust", 12.99);
    books.push_back(f);   //insert book by reference

    for (const auto& book : books) {
        cout << book.get().getName() << " : " << book.get().getPrice() << endl;
    }

    f.setPrice(9.99);
    cout << books[0].get().getPrice() << endl;

    for (const auto& book : books) {
        cout << book.get().getName() << " : " << book.get().getPrice() << endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}