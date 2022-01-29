//
// Created by Mikhail Zhuravlev on 12.12.2021.
//

#ifndef GLUT_3D_GRID_GRID_H
#define GLUT_3D_GRID_GRID_H

#define GL_SILENCE_DEPRECATION 1
#include "GLUT/glut.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "structs.h"


class Grid {
public:
    std::vector<Vertex>         vertices_;
    std::vector<Edge>            edges_;
    std::vector<Face>           faces_;
    std::vector<std::string>    locations_;

    float  angleX = 30;
    float  angleY = 0;
    float  angleZ = -30;

    float zoom = -5;

    bool    outerSurfaces = false;
    bool    figure = false;

public:
    int readFile(char* fileName);

    void    onRender();
    void    drawFigure(std::string location);
    void    drawGrid();

    double   transform(double value, double bias, char axis);

private:
    double  getMin(char axis);
    double  getMax(char axis);
};


#endif //GLUT_3D_GRID_GRID_H
