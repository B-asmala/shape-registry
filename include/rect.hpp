#ifndef RECT_HPP
#define RECT_HPP

#include <string>
#include <memory>
#include "shape.hpp"

class Rect final : public Shape {
public:
    Rect(std::vector<int> parameters);

    static std::unique_ptr<Shape> createRect(std::vector<int> parameters);

    std::string getDescription() const override;
    bool parametersAvailable() const override;
    std::string getCalculations() const override;
    std::string getOverallDescription() const override;

    int getPerimeter() const;
    int getArea() const;
private:
    static bool registered;
    
};


#endif
