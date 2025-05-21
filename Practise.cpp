#include <iostream>

int main()
{
    int x = 8;
int *ptre = new int(5);
int **pt = &ptre;
ptre[0] = 50;
std::cout << ptre <<std::endl;
*pt = new int(10);

std::cout << *pt << "  " << ptre<<std::endl;
}