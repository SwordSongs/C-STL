#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

//general distance()
template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type
distance_wd(Iterator pos1, Iterator pos2)
{
    return distance_wd(pos1, pos2, 
	               std::iterator_traits<Iterator>::iterator_category());
}

//distance() for random-access iterators
template<typename RandIterator>
typename std::iterator_traits<RandIterator>::difference_type
distance_wd(RandIterator pos1, RandIterator pos2, 
		std::random_access_iterator_tag)
{
    return pos2 - pos1;
}


int main()
{
   vector<int> ev = {1, 2, 3, 4};

   cout<<"distrance_wd: "<<distance_wd(ev.begin(), ev.end());


    return 0;
}
