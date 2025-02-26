#include <tuple>
#include <iostream>
#include <string>

int main()
{
    std::tuple<int, std::string> myTuple(8, "myName");
    std::cout << std::get<0>(myTuple);
    auto newTuple = std::make_tuple(56, "new");
    std::tuple_cat(newTuple, myTuple);
    std::tuple_size<decltype(newTuple)>::value;
    using tupleType = std::tuple<int, std::string>;
    using type = std::tuple_element<0, tupleType>::type;
}