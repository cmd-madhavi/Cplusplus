#include <iostream>
#include <string>
#include <vector>

class People {
    std::string m_name;

public:
    // Default constructor
    People() {
        std::cout << "Default constructor" << std::endl;
    }

    // Parameterized constructor
    People(std::string name) : m_name(std::move(name)) {
        std::cout << "Parameterized constructor" << std::endl;
    }

    // Copy constructor
    People(const People& other) : m_name(other.m_name) {
        std::cout << "Copy constructor" << std::endl;
    }

    // Move constructor
    People(People&& other) noexcept : m_name(std::move(other.m_name)) {
        std::cout << "Move constructor" << std::endl;
    }

    // Copy assignment operator
    People& operator=(const People& other) {
        std::cout << "Copy assignment operator" << std::endl;
        if (this != &other) {
            m_name = other.m_name;
        }
        return *this;
    }

    // Move assignment operator
    People& operator=(People&& other) noexcept {
        std::cout << "Move assignment operator" << std::endl;
        if (this != &other) {
            m_name = std::move(other.m_name);
        }
        return *this;
    }

    // Destructor
    ~People() {
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    std::vector<People> peopleV;

    peopleV.reserve(4);
    // Using push_back with a temporary object (move)
    peopleV.push_back(People("Madhavi"));

    // Using emplace_back to construct in place
    peopleV.emplace_back("Madhavi");

    return 0;
}
