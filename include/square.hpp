#ifndef SQUARE_HPP 
#define SQUARE_HPP

#include <string>
#include <memory>
#include "shape.hpp"

class Square final : public Shape {
public:
    Square(std::vector<int> parameters);

    static std::unique_ptr<Shape> createSquare(std::vector<int> parameters);

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
