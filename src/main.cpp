#include <iostream>
#include <string>
#include <vector>
#include "shape.hpp"
#include "registry.hpp"



int main(int argc, char* argv[]){

    if(argc < 2){
        std::cout << "shape name not provided\n";
        return 1; 
    }

    std::string shapeName = argv[1];
    std::vector<int> parameters;


    for(int i = 2; i < argc; i ++){
        parameters.push_back(std::stoi(argv[i]));
    }
    
    std::unique_ptr<Shape> x = Registry::createShapeInstance(shapeName, parameters);

    if(x){
        std::cout << x->getOverallDescription();
    }else{
        std::cout << "shape not available\n";
    }

    return 0;
}


