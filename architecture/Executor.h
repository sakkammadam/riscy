#ifndef HW2_INSTRUCTION_H
#define HW2_INSTRUCTION_H

#include "../nlohmann/json.hpp"
#include "Registers.h"
#include "Stack.h"
#include "Parser.h"
#include "Architecture.h"
#include <vector>
#include <map>
#include <stack>
#include <string>

class Executor {
private:
    // declare Architecture Wrapper
    ArchitectureWrapper simpleRISC;
    // current raw binary Instruction
    std::string curRawBinaryInstruction;
    // binary Wrapper
    binaryPrep curBinaryInstruction;
    // all raw binary Instructions
    std::vector<std::string> allRawBinaryInstructions;
    // all wrapper binary Instructions
    std::vector<binaryPrep> allBinaryInstructions;
    // program counter
    int programCounter;
    // program completion
    bool programComplete=false;

public:
    // Constructor to set the Architecture
    Executor(std::string arch_name);
    // Getter - return the architecture name
    std::string getExecutorArchitectureName();
    // Getter - return the corresponding registers
    std::vector<RegisterWrapper> getExecutorRegisters();
    // Setter
    void setExecutorRegister(std::string registerName, int value);


};


#endif //HW2_INSTRUCTION_H
