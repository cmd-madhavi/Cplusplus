//these are always sorted
//underlying structur is binary tree

//since containers are always sorted push_back ,push_front does not make sense
#include <set> 
#include <map>

int main()
{
    //SETS are READ ONLY, as it corrupts the data structure if we rewrite it, it won't be sorted anymore
    //set has no duplicates
    std::set<int> mySet;
    mySet.insert(1); //O(logn)

    auto itr = mySet.find(1);//O(logn)
    std::pair<std::set<int>::iterator, bool> ret = mySet.insert(4);

    auto itr2 = ret.first;
    mySet.insert(itr2, 9); //the iterator here can be used as hint to store the 9, making the insertion faster if you provide good hint
    mySet.erase(itr2);

    std::multiset<int> mySet2;//duplicates are allowed

    //IN MAPS Keys cannot be modified
}