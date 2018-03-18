// edge.h
//   edge library.
// History:
// 2017/01/06  Hao Xu  First release

#ifndef EDGE_H
#define EDGE_H

//#include <stdexcept>
#include<cmath>
#include "node.h"
#include "../mathLib/r1Tensor.h"

struct edge {
    int index, n_nodes;
    r1Tensor<node*> nodes;
    double dist;    

    edge(): index(0),n_nodes(0), nodes(),dist(0.){}

    edge(int n, r1Tensor<node*> & nodeLists ): index(n),
        n_nodes(nodeLists.size()){
        nodes.resize(n_nodes);
        for (int i=0;i<n_nodes;i++)
        { nodes[i] = &nodeLists[i];}
        distance();
    }

    /*
    edge(int n, node & node0, node & node1): index(n),n_nodes(2){
        nodes.resize(n_nodes);
        nodes[0] = &node0;
        nodes[1] = &node1;
        distance();
    }  	// initialization
    */

   edge(const edge &rhs): index(rhs.index),n_nodes(rhs.n_nodes),
        dist(rhs.dist){
        nodes.resize(rhs.n_nodes);
        nodes = rhs.nodes;
    }  	// copy constructor

    void copy(const edge &rhs){
        index = rhs.index;
        n_nodes = rhs.n_nodes;
        nodes.resize(rhs.n_nodes);
        nodes = rhs.nodes;
        dist = rhs.dist;
    }  	// copy constructor

    void distance(){
        double x_dist = nodes[0]->xx - nodes[n_nodes-1]->xx;
        double y_dist = nodes[0]->yy - nodes[n_nodes-1]->yy;
        double z_dist = nodes[0]->zz - nodes[n_nodes-1]->zz;
        dist = sqrt(x_dist*x_dist+y_dist*y_dist+z_dist*z_dist);
    }

    void reassign(int n, r1Tensor<node> & nodeLists ){
        index = n;
        n_nodes = nodeLists.size();
        nodes.resize(n_nodes);
        for (int i=0;i<n_nodes;i++)
        { nodes[i] = &nodeLists[i];}
        distance();
    }  	// reassignn


};

// edge definitions

#endif /* EDGE_H */
