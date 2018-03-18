/**
 * \file shapeFunctioniFactory.h
 * \author Hao Xu
 * \date created on 2018/02/09
 */
#ifndef SHAPEFUNCTIONFACTORY_H
#define SHAPEFUNCTIONFACTORY_H

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include "shapeFunction.h"

// Factory class
class shapeFunctionFactory {
public:
    typedef std::unordered_map<std::string, std::function<shapeFunction*()>> registry_map;

    // use this to instantiate the proper Derived class
    static shapeFunction * instantiate(const std::string& name) {
    
        auto it = shapeFunctionFactory::registry().find(name);
        return it == shapeFunctionFactory::registry().end() ? nullptr : (it->second)();
    }

    static registry_map & registry() {
        static registry_map impl;
        return impl;
    }

};

template<typename T> struct shapeFunctionFactoryRegister {

shapeFunctionFactoryRegister(std::string name) {
    
    shapeFunctionFactory::registry()[name] = []() { return new T; };
    std::cout << "Registering class '" << name << "'\n";
}
};

#endif
