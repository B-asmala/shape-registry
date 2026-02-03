#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <vector>

class Shape{
protected:
    std::vector<int> parameters;
    unsigned int requiredParametersCount;
    std::string description;
    
    
public:
    virtual ~Shape() = default;

    virtual std::string getDescription() const = 0;
    virtual bool parametersAvailable() const = 0;
    virtual std::string getCalculations() const = 0;
    virtual std::string getOverallDescription() const = 0; 

};

#endif
