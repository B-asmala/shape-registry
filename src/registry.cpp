#include "registry.hpp"


bool Registry::registerShape(std::string shapeName, std::function<std::unique_ptr<Shape>(std::vector<int> parameters)> factory){

    auto& registryMap = Registry::getRegistryMap();
    auto it = registryMap.find(shapeName);
    if(it == registryMap.end()){
        registryMap[shapeName] = std::move(factory);
        return true;
    }else{
        return false;
    }
}

std::unique_ptr<Shape> Registry::createShapeInstance(std::string shapeName, std::vector<int> parameters){
    auto& registryMap = Registry::getRegistryMap();
    auto it = registryMap.find(shapeName);

    if(it != registryMap.end()){
        // shape already registered
        return it->second(parameters);
    }else{
        return nullptr;
    }
}

