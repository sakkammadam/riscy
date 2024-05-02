#ifndef HW2_ARCHITECTURE_H
#define HW2_ARCHITECTURE_H

#include "Registers.h"
#include "Stack.h"
#include <vector>
#include <map>
#include <stack>
#include <string>

class ArchitectureWrapper {
private:
    // Name
    std::string ArchName;
    // Vector of Registers
    std::vector<RegisterWrapper> ArchRegisters;
    // Single stack
    StackWrapper ArchStack;

public:
    // Default Constructor
    ArchitectureWrapper();
    // Constructor to create with name
    ArchitectureWrapper(std::string name);
    // Create a Stack using StackWrapper
    void createStack();
    // Create a vector of Registers using RegisterWrapper
    void createRegisters();

    // Getter - return the ArchName
    std::string getArchName();
    // Getter - return the vector of Registers
    std::vector<RegisterWrapper>& getArchRegisters();
    // Getter - return the Stack
    StackWrapper& getArchStack();

    // Display registers
    void displayRegisters();
    // Display stack
    void displayStack();
    // Display entire architecture
    void displayArch();

    // Setter - set Register with a value
    void selRegisterWithValue(std::string register_name, int value);
    // Getter
    int getRegisterWithValue(std::string register_name);


};


#endif //HW2_ARCHITECTURE_H
