#include <string>
#include "square.hpp"
#include "registry.hpp"

bool Square::registered = Registry::registerShape("square", Square::createSquare);

Square::Square(std::vector<int> parameters){
    this->description = "A square has four sides that are of equal length.\n";
    this->requiredParametersCount = 1;

    this->parameters = parameters;
}

std::unique_ptr<Shape> Square::createSquare(std::vector<int> parameters){
    return std::make_unique<Square>(parameters);
}

std::string Square::getDescription() const {
    return description;

}

bool Square::parametersAvailable() const {
    return (parameters.size() == requiredParametersCount); 
}

std::string Square::getCalculations() const {
    std::string calcs = "";
    
    calcs += "the perimeters is " + std::to_string(getPerimeter()) + ' ';
    calcs += "the area is " + std::to_string(getArea());
    calcs += '\n';
    return calcs;
}

std::string Square::getOverallDescription() const {
    std::string desc = "";

    desc += getDescription();

    if(parametersAvailable()){
        desc += getCalculations();
    }

    return desc;

}


int Square::getPerimeter() const {
    return parameters[0] * 4;
}

int Square::getArea() const {
    return parameters[0] * parameters[0];
}
