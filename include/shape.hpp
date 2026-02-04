#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <vector>

//base class that all shapes inherit from

class Shape{
protected:
    std::vector<int> parameters;
    unsigned int requiredParametersCount;
    std::string description;
    
    
public:
    virtual ~Shape() = default;

    virtual std::string getDescription() const = 0; //get description string
    virtual bool parametersAvailable() const = 0; // check if required parameters were provided
    virtual std::string getCalculations() const = 0; // calculate properties of this shape
    virtual std::string getOverallDescription() const = 0; // description string + calculations if available

};

#endif
