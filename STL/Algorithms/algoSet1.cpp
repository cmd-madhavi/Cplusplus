#include <algorithm>
#include <vector>
#include <iostream>
bool is_odd(int i)
{
    return i%2;
}

void add2(int i)
{
    std::cout << i + 2 << std::endl;
}
int main()
{
    std::vector<int> vec{4,2,5,1,3,9};
    auto itr = min_element(vec.begin(), vec.end());

//algorithm always process ranges in half open way [begin, end)
    std::sort(vec.begin(), itr); //2,4,5,1,3,9
    std::reverse(itr, vec.end());//2 4 5 9 3 1

    std::vector<int> vec2(3);
    std::copy(itr, vec.end(),//source from itr to vec.end()
    vec2.begin());//destination 

    //another way is
    vec2.insert(vec2.end(), itr, vec.end());
    for (auto val : vec2)
    {
        std::cout << val << std::endl;
    }

    auto itr2 = std::find_if(vec.begin(), vec.end(), is_odd);
    std::for_each(vec.begin(), vec.end(), add2);
}