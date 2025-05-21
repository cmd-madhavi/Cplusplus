#include <iostream>

union Point{
    double x;
    int y;
};
int main()
{
    Point u = {4.0};
    std::cout << " u "<< u.x << " " << u.y << std::endl;
    std::cout << "addr of u "<< &u.x << " "<< &u.y <<  std::endl;
}