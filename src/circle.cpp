#include <string>
#include "circle.hpp"
#include "registry.hpp"

double PI = 3.1415926;

bool Circle::registered = Registry::registerShape("circle", Circle::createCircle);

Circle::Circle(std::vector<int> parameters){
    this->description = "A circle has a radius.\n";
    this->requiredParametersCount = 1;

    this->parameters = parameters;
}

std::unique_ptr<Shape> Circle::createCircle(std::vector<int> parameters){
    return std::make_unique<Circle>(parameters);
}

std::string Circle::getDescription() const {
    return description;

}

bool Circle::parametersAvailable() const {
    return (parameters.size() == requiredParametersCount); 
}

std::string Circle::getCalculations() const {
    std::string calcs = "";
    
    calcs += "the perimeters is " + std::to_string(getPerimeter()) + ' ';
    calcs += "the area is " + std::to_string(getArea());
    calcs += '\n';
    return calcs;
}

std::string Circle::getOverallDescription() const {
    std::string desc = "";

    desc += getDescription();

    if(parametersAvailable()){
        desc += getCalculations();
    }

    return desc;

}


double Circle::getPerimeter() const {
    return 2 * PI * parameters[0];
}

double Circle::getArea() const {
    return parameters[0] * parameters[0] * PI;
}
