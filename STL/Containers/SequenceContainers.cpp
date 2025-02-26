#include <iostream>
#include <vector>
#include <deque>
#include <list>
int main()
{
    //FAST INSERT OR REMOVE  at the end O(1)
    //SLOW insert or remove in the middle  or beginning O(N)
    //SLOW search O(N)
    std::vector<int> vec{1,2,34};
    vec[0]; //no range check - undefined behavior
    vec.at(0); //throws range_error exception of out of range

    int *ptr = &vec[0];

    std::vector<int> vec2(vec);
    std::vector<int> vec3{3,5,6};
    vec2.swap(vec3);

    std::deque<int> dq(5); //WE ALSO HAVE QUEUE

    //DEQUE have random access, not as fast as vector, it comes with some overhead since memory is not contiguosus
    //deque is smaller arrays linked together, it is a seqeunce of blocks of memory,
    //it has buffer of pointers that points to these blocks of arrays



    std::list<int> list1{5,2,9}; //FAST insert or remove at any point
    std::list<int> list2{4,7,8,9,10,11};
    auto itr = list1.begin();
    auto itr2 = list2.begin();
    itr2 = itr2++;
    list1.splice(itr, list2, list2.begin(),itr2); //this is from second list from range itr1 to itr2 , 
    //we can add this to list1 in O(1) and none of hte container can do this
    //but no random access

    //WE have forward_list which is sinlgy linked list


    std::vector<int> myVec{1,2};
    int *ptr2 = &myVec[1];
    myVec.insert(myVec.begin(), 0);
    std::cout << *ptr2 << std::endl;
}