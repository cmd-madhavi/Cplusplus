#include <iostream>

int SIZE = 5;
void function1D(int *arr)
{
    for (int i = 0; i<SIZE; i++)
    {
       *(arr+i) = i;
    }
}

void Print1DArr(int *arr)
{
    for (int i = 0; i<SIZE; i++)
    {
        std::cout << *(arr+i) << "   ";
    }
}
int main()
{
   // int arr[5] = {1,2,3,4,5};
    int *arr = new int[5];

    function1D(arr);
    Print1DArr(arr);

    int **arr2D = new int*[5];

    for (int i = 0 ; i<SIZE; i++)
    {
        *(arr2D+i) = new int[SIZE];
    }

    for (int i = 0; i<SIZE; i++)
    {
        *(arr2D+i)[0] = 5;
        std::cout << "arr i = " << i << " j is 0, arr2D[i][j] is "<< arr2D[i][0]<< std::endl; 
    }
}