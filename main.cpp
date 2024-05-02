#include <iostream>
#include <vector>
#include "architecture/Parser.h"
#include "architecture/Architecture.h"
#include "architecture/Executor.h"

int main() {


    Executor foo = Executor("RISC");
    std::cout << foo.getExecutorArchitectureName() << std::endl;
    for(int i=0; i < foo.getExecutorRegisters().size(); i++){
        std::cout << "Register: " << foo.getExecutorRegisters()[i].getRegisterName() << " Register Value : " << foo.getExecutorRegisters()[i].getRegisterValue() << std::endl;
        foo.setExecutorRegister(foo.getExecutorRegisters()[i].getRegisterName(), i+1);
        std::cout << "Register: " << foo.getExecutorRegisters()[i].getRegisterName() << " Register Value : " << foo.getExecutorRegisters()[i].getRegisterValue() << std::endl;
    }
    std::cout << "After" << std::endl;


    for( auto& reg_name: foo.getExecutorRegisters()){
        std::cout << "Register: " << reg_name.getRegisterName() << " Register Value: " << reg_name.getRegisterValue() << std::endl;
    }



    /*
     * ---- register is good
    RegisterWrapper foo = RegisterWrapper("RO");
    std::cout << foo.getRegisterName() << std::endl;
    std::cout << foo.getRegisterValue() << std::endl;
    foo.setRegisterValue(100);
    std::cout << foo.getRegisterValue() << std::endl;
    */

    /*
    // ---- Architecture is good -- base test!
    ArchitectureWrapper foo = ArchitectureWrapper("RISC");
    std::cout << foo.getArchName() << std::endl;
    for(int i=0; i < foo.getArchRegisters().size() ; i++){
        std::cout << "Register: " << foo.getArchRegisters()[i].getRegisterName() << " Value: " << foo.getArchRegisters()[i].getRegisterValue() << std::endl;
        foo.getArchRegisters()[i].setRegisterValue(i+1);
    }
    std::cout << "After" << std::endl;

    for( auto& reg_name: foo.getArchRegisters()){
        std::cout << "Register: " << reg_name.getRegisterName() << " Register Value: " << reg_name.getRegisterValue() << std::endl;
    }
    */

    /* ---- Architecture is good -- reg value test!
    ArchitectureWrapper bar = ArchitectureWrapper("RISC2");
    for(int i=0; i < bar.getArchRegisters().size() ; i++){
        std::cout << "Register: " << bar.getArchRegisters()[i].getRegisterName() << " Value: " << bar.getArchRegisters()[i].getRegisterValue() << std::endl;
        bar.getArchRegisters()[i].setRegisterValue(i+1);
    }
    std::cout << bar.getRegisterWithValue("R5") << std::endl;
    bar.selRegisterWithValue("R5",1000);
    std::cout << bar.getRegisterWithValue("R5") << std::endl;
     */

    /*
    std::string sampleIns1 = "LOADI R0, #10";
    Parser obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    std::vector<std::string> tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;

    sampleIns1 = "ADDRR R1, R2, R3";
    obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;

    sampleIns1 = "ADDRI R1, #10";
    obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;

    sampleIns1 = "EQUAL R4, R5, R6";
    obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;


    sampleIns1 = "NQUAL R7, R5, R6";
    obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;

    sampleIns1 = "CLOSE";
    obj = Parser(sampleIns1);
    std::cout << "Original Instruction: " << obj.getOrigInstruction() << std::endl;
    // check tokens
    tmp = obj.getTokenInstructions();
    // parse the vector of tokens
    for(const auto& token: tmp){
        std::cout << token << std::endl;
    }
    std::cout << "OPCODE: " << obj.getBinaryInstructions().opCode << std::endl;
    std::cout << "DEST_REG: " << obj.getBinaryInstructions().destReg << std::endl;
    std::cout << "FIRST_REG: " << obj.getBinaryInstructions().firstReg << std::endl;
    std::cout << "SECOND_REG: " << obj.getBinaryInstructions().secondReg << std::endl;
    std::cout << "UNUSED: " << obj.getBinaryInstructions().unused << std::endl;
    std::cout << "OFFSET: " << obj.getBinaryInstructions().offset << std::endl;
    std::cout << "COMPLETE BINARY INSTRUCTION: " << obj.getRawBinaryInstructions()  << std::endl;


    */

    return 0;
}
