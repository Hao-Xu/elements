// node.h
//   node library.
// History:
// 2017/01/06  Hao Xu  First release

#ifndef NODE_H
#define NODE_H

//#include <stdexcept>
//#include <iostream>
//#include "errInfo.h"
#include "../mathLib/r1Tensor.h"

//using namespace std;

struct node {
    int index;	   
    double xx, yy, zz;  // coordinates

        //node(){}
	node(int n = 0, double x = 0., double y = 0., double z = 0.) : index(n),
             xx(x), yy(y),zz(z)    {}	// initialization
	node(int n, r1Tensor<double> & coord) : index(n),
             xx(coord[0]), yy(coord[1]),zz(coord[2])    {}	// initialization
        node(const node &rhs): index(rhs.index),
             xx(rhs.xx), yy(rhs.yy),zz(rhs.zz) {}  //copy constructor
        void copy(const node &rhs){
            index = rhs.index;
            xx = rhs.xx;
            yy = rhs.yy;
            zz = rhs.zz;
        }  //copy constructor
};

// node definitions



#endif /* NODE_H */
