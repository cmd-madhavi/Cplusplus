#include <iostream>

struct Point{
    int x;
    int y;
};
int main()
{
    int n = 1;
    double db = *(double *)(&n);
    std::cout << "addr n "<< &n << "   " << typeid(&n).name() << " type fo &n " << typeid(&db).name() << " addr "<<(double*)(&n);

    Point p = {4,5};
    std::cout << "point x "<< p.x << std::endl;
    int arr[2];
    arr[0] = *(int*)(&p);
    arr[1] = *((int*)(&p)+1);

//(&p+1) moves the pointer to address of p + Person bytes, and if we do (&p+sizefo(int)) , then it is not a correct pointer arithemetic
//since we should add in multiples of size of Person bytes, so what it will actually do will 4Person objects size
    std::cout <<"array elements "<<arr[0] << " "<<arr[1] <<std::endl;
}