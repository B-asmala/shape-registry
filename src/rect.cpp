#include <string>
#include "rect.hpp"
#include "registry.hpp"

bool Rect::registered = Registry::registerShape("rect", Rect::createRect);

Rect::Rect(std::vector<int> parameters){
    this->description = "A rectangle has 4 sides broken into 2 side pairs of equal length and are parallel.\n";
    this->requiredParametersCount = 2;

    this->parameters = parameters;
}

std::unique_ptr<Shape> Rect::createRect(std::vector<int> parameters){
    return std::make_unique<Rect>(parameters);
}

std::string Rect::getDescription() const {
    return description;

}

bool Rect::parametersAvailable() const {
    return (parameters.size() == requiredParametersCount); 
}

std::string Rect::getCalculations() const {
    std::string calcs = "";
    
    calcs += "the perimeters is " + std::to_string(getPerimeter()) + ' ';
    calcs += "the area is " + std::to_string(getArea());
    calcs += '\n';
    return calcs;
}

std::string Rect::getOverallDescription() const {
    std::string desc = "";

    desc += getDescription();

    if(parametersAvailable()){
        desc += getCalculations();
    }

    return desc;

}


int Rect::getPerimeter() const {
    return (parameters[0] + parameters[1]) * 2;
}

int Rect::getArea() const {
    return parameters[0] * parameters[1];
}
