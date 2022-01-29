//
// Created by Mikhail Zhuravlev on 12.12.2021.
//

#include "Grid.h"


double  Grid::getMin(char axis) {
    double  min;

    if (axis == 'x') {
        min = vertices_[0].x;
    }
    else if (axis == 'y') {
        min = vertices_[0].y;
    }
    else if (axis == 'z') {
        min = vertices_[0].z;
    }
    else {
        std::cout << "ERROR: Invalid axis on getMin function call: \'" << axis << "\'" << std::endl;
        return 0;
    }

    for (int i = 0; i < vertices_.size(); i++) {
        if (axis == 'x' && min > vertices_[i].x) {
            min = vertices_[i].x;
        }
        else if (axis == 'y' && min > vertices_[i].y) {
            min = vertices_[i].y;
        }
        else if (min > vertices_[i].z){
            min = vertices_[i].z;
        }
    }

    return min;
}

double  Grid::getMax(char axis) {
    double  max = 0;

    if (axis == 'x') {
        max = vertices_[0].x;
    }
    else if (axis == 'y') {
        max = vertices_[0].y;
    }
    else if (axis == 'z') {
        max = vertices_[0].z;
    }
    else {
        std::cout << "ERROR: Invalid axis on getMax() function call: \'" << axis << "\'" << std::endl;
        return 0;
    }

    for (int i = 0; i < vertices_.size(); i++) {
        if (axis == 'x' && max < vertices_[i].x) {
            max = vertices_[i].x;
        }
        else if (axis == 'y' && max < vertices_[i].y) {
            max = vertices_[i].y;
        }
        else if (max < vertices_[i].z){
            max = vertices_[i].z;
        }
    }

    return max;
}