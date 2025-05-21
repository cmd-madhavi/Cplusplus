#include "Inline.h"

void AnotherFunction();
void InlineVarFunc()
{
    SomeFunction();
}

int main()
{
   // h = 9;
    std::cout << " H "<< h << std::endl;
    InlineVarFunc();
    AnotherFunction();
    return 0;
}