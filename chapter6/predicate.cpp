#include<algorithm>
#include<list>
#include<deque>
#include<string>
#include<cstdlib>  //for abs()
#include<iostream>
using namespace std;

class Person 
{
public:
    Person(string first, string last) : firstname(first), lastname(last)
    {}

    ~Person() {}

    string firstname;
    string lastname;
};

//unary predicate, which returns whether an integer is a prime number
bool isPrime(int number)
{
    //ignore negative sign
    number = abs(number);

    //0 and 1 are not prime numbers
    if (number == 0 || number == 1)    return false;

    int divisor;
    for (divisor = number / 2; number%divisor != 0; --divisor) 
    {
        
    }

    return divisor == 1;
}

//binary predicate
bool personCompare(const Person& p1, const Person& p2)
{
    return p1.lastname < p2.lastname || (p1.lastname == p2.lastname && p1.firstname < p2.firstname);
}

int main()
{
    list<int>  coll;

    //insert elements
    for (int i = 24; i <= 30; ++i)
    {
        coll.push_back(i);
    }

    auto pos = find_if(coll.cbegin(), coll.cend(), isPrime);

    if (pos != coll.end())
    {
        cout << *pos << " is first prime number found." << endl;
    }
    else
    {
        //not found
        cout << " no prime number found" << endl;
    }

    deque<Person> personDeq;

    personDeq.push_back(Person("Jay", "Chou"));
    personDeq.push_back(Person("Eson", "Chen"));
    personDeq.push_back(Person("Jack", "Ma"));

    sort(personDeq.begin(), personDeq.end(), personCompare);

    for (auto p : personDeq)
    {
        cout << "[" << p.firstname << " . " << p.lastname << "]"<<endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}