/**
 * \file shapeFunctionManager.h
 * \author Hao Xu
 * \date created on 2018/02/09
 */

#ifndef SHAPEFUNCTION_H
#define SHAPEFUNCTION_H
#include <iostream>
//#include <unordered_map>
//#include <functional>
//#include <vector>
#include <string>

// Base class
class shapeFunction {

public:
    shapeFunction() { std::cout << " construct shape function " << std::endl; }
    virtual ~shapeFunction() { std::cout << " delete shape function " << std::endl; }
    virtual void initialize() {}
    virtual void update() {}
    virtual void printVariables() { 
        std::cout << " material base " << std::endl; }
    virtual void draw() = 0;

private:
    std::string name;
    int mm, nn;

protected:
    std::string protected_name;
    int protected_mm, protected_nn;
    bool elastic;
};

#endif
