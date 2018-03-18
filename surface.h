// surface.h
//   surface library.
// History:
// 2017/01/09  Hao Xu  First release

#ifndef SURFACE_H
#define SURFACE_H

//#include <stdexcept>
#include <iostream>
#include <cmath>
#include "node.h"
#include "edge.h"
//#include "../mathLib/r1Tensor.h"


struct surface {
    int index, n_nodes, n_edges;	   
    r1Tensor<node*> nodes;  
    r1Tensor<edge> edges;
    double area;
    int kind;

    surface(): index(0), n_nodes(0), n_edges(0),nodes(), edges(), area(0.), kind(0){cout << "1" << endl;}

    surface(int n, r1Tensor<node> & nodeLists): index(n), 
        n_nodes(nodeLists.size()), n_edges(nodeLists.size())
    {
        cout << " size " << nodeLists.size() << endl;
        nodes.resize(n_nodes);
        for (int i=0;i<n_nodes;i++)
        { nodes[i] = &nodeLists[i];}
        
        edges.resize(n_edges);
        for (int i=0;i<n_nodes;i++) {
            r1Tensor<node*> nodeTemp(2);
            nodeTemp[0] = &(nodeLists[i]);
            cout << " nodeTemp[0].index " << nodeTemp[0]->index << endl;
            if (i==n_nodes-1) {
                nodeTemp[1] = &(nodeLists[0]);
            } else {  
                nodeTemp[1] = &(nodeLists[i+1]);
            }
            edges[i].reassign(i,*(nodeTemp[0]));
            cout << " edges: " << edges[0].nodes[0]->index << endl;
        }
        switch (n_nodes) {
            case 3:
                kind = 5;
                area_surf1();
                break;
            case 4:
                kind = 9;
                break;
            default:
                kind = 7;
                break;
        } 

    }  	// initialization
/*
    surface(int n, node & node0, node & node1, node & node2, node & node3): 
        index(n), n_nodes(4), n_edges(4),node_0(&node0), node_1(&node1), node_2(&node2), node_3(&node3),
        edge_0(0,node0,node1), edge_1(1,node1,node2), edge_2(2,node2,node3), 
        edge_3(3,node3,node0),kind(4) {
        area_surf2();
    }  	// initialization

    surface(const surface &rhs): 
        index(rhs.index), n_nodes(rhs.n_nodes), n_edges(rhs.n_edges),
        node_0(rhs.node_0), node_1(rhs.node_1), node_2(rhs.node_2), node_3(rhs.node_3),
        edge_0(rhs.edge_0), edge_1(rhs.edge_1), edge_2(rhs.edge_2), edge_3(rhs.edge_3),
        area(rhs.area), kind(rhs.kind) {

    }  	// copy constructor

    void copy(const surface &rhs){ 
        index = rhs.index;
        n_nodes = rhs.n_nodes;
        n_edges = rhs.n_edges;
        node_0 = rhs.node_0;
        node_1 = rhs.node_1; 
        node_2 = rhs.node_2;
        node_3 = rhs.node_3;
        edge_0.copy(rhs.edge_0);
        edge_1.copy(rhs.edge_1);
        edge_2.copy(rhs.edge_2);
        edge_3.copy(rhs.edge_3);
        area = rhs.area;
        kind = rhs.kind;

    }  	// copy method


    void area_surf2(){
        double a = edge_0.dist;
        double b = edge_1.dist;
        double c = edge_2.dist;
        double d = edge_3.dist;
        edge line4 (4, *node_0, *node_2);
        edge line5 (5, *node_1, *node_3);
        
        double e = line4.dist;
        double f = line5.dist;
        area = 0.25*sqrt(4.*e*e*f*f-(b*b+d*d-a*a-c*c)*(b*b+d*d-a*a-c*c));                          
    }
*/   

    void area_surf1(){
        double a = edges[0].dist;
        double b = edges[1].dist;
        double c = edges[2].dist;
        double s = 0.5*(a+b+c); 
        area = sqrt(s*(s-a)*(s-b)*(s-c));                          
    } 
};

// surface definitions

#endif /* SURFACE_H */
