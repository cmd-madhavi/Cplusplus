#include <fstream>
#include <iostream>
int main()
{
    std::ofstream fileWrite("newFile.txt");

    std::string line;
    while(fileWrite)
    {
        std::getline(std::cin, line);
        if (line == "-1")
        break;
        fileWrite << line << "\n";
        
    }

    fileWrite.close();

    std::ifstream fileOpen("newFile.txt");
    
    std::string line2, line3, line4;
    fileOpen >> line >> line2 >> line3 >> line4;
    
    std::cout <<" line "<< line << " " << line2 << " "<< line3 << " "<< line4 << std::endl;
    fileOpen.close();
}