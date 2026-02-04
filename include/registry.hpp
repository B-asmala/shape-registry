#ifndef REGISTRY_HPP
#define REGISTRY_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <functional>
#include "shape.hpp"


// manages a static map between shape names and shape factory functions


class Registry {
public:
    static auto& getRegistryMap(){
        static std::unordered_map<std::string, std::function<std::unique_ptr<Shape>(std::vector<int> parameters)>> registryMap;
        return registryMap;
    }
    static bool registerShape(std::string, std::function<std::unique_ptr<Shape>(std::vector<int> parameters)>);
    static std::unique_ptr<Shape> createShapeInstance(std::string, std::vector<int> parameters);

};


#endif
