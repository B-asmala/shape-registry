#ifndef CIRCLE_HPP 
#define CIRCLE_HPP

#include <string>
#include <memory>
#include "shape.hpp"

class Circle final : public Shape {
public:
    Circle(std::vector<int> parameters);

    static std::unique_ptr<Shape> createCircle(std::vector<int> parameters);

    std::string getDescription() const override;
    bool parametersAvailable() const override;
    std::string getCalculations() const override;
    std::string getOverallDescription() const override;

    double getPerimeter() const;
    double getArea() const;
private:
    static bool registered;
    
};


#endif
