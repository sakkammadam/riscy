//
// Created by vinee on 5/1/2024.
//

#include "Executor.h"

// initialize Constructor with Architecture name
Executor::Executor(std::string arch_name) {
    this->simpleRISC = ArchitectureWrapper(arch_name);
}

std::string Executor::getExecutorArchitectureName() {
    return this->simpleRISC.getArchName();
}

std::vector<RegisterWrapper> Executor::getExecutorRegisters() {
    return this->simpleRISC.getArchRegisters();
}

void Executor::setExecutorRegister(std::string registerName, int value){
    this->simpleRISC.selRegisterWithValue(registerName, value);
}