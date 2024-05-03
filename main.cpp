#include <fstream>
#include <iostream>
#include <vector>
#include "architecture/Parser.h"
#include "architecture/Architecture.h"
#include "architecture/Executor.h"
#include "nlohmann/json.hpp"

int main() {
    // Use filestream to open a JSON native file
    std::fstream jsonFile;
    // Set the location
    std::string fileLocation = R"(C:\Users\vinee\Documents\sakkamma\CIS655\hw2\tests\instructions.json)";
    jsonFile.open(fileLocation.c_str(), std::ios::in);
    // Check if the file opened successfully
    if (!jsonFile.is_open()) {
        // Handle error opening file
        return 1;
    }
    // parse the filestream as JSON using nlohmann library
    nlohmann::json jsonData = nlohmann::json::parse(jsonFile);
    // declare a vector of all assembly instructions!
    std::vector<assemblyPrep> allAssemblyInstructions;
    // declare a vector of all binary instructions!
    std::vector<binaryPrep> allBinaryInstructions;
    // declare a vector of all raw binary instructions!
    std::vector<std::string> allRawBinaryInstructions;

    // let's iterate over jsonData using an iterator container and load into the vector - acmeBagVector
    for(auto & it : jsonData){
        std::cout << it.at("instruction") <<  std::endl;
        Parser obj = Parser(it.at("instruction"));
        // Load Assembly instructions
        allAssemblyInstructions.emplace_back(obj.getAssemblyInstructions());
        // Load Binary instructions
        allBinaryInstructions.emplace_back(obj.getBinaryInstructions());
        // Load Raw Binary instructions
        allRawBinaryInstructions.emplace_back(obj.getRawBinaryInstructions());
    }

    // Close the file
    jsonFile.close();

    // let's invoke the Executor
    Executor operatingRISC = Executor(
            "RISC",
            allAssemblyInstructions,
            allBinaryInstructions,
            allRawBinaryInstructions
            );
    // let's run the entry method
    operatingRISC.executeAllInstructions();

    return 0;
}
