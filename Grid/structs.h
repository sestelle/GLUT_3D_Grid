//
// Created by Mikhail Zhuravlev on 12.12.2021.
//

#ifndef GLUT_3D_GRID_STRUCTS_H
#define GLUT_3D_GRID_STRUCTS_H

struct Vertex {
    float  x, y, z;
    Vertex(float x = 0, float y = 0, float z = 0): x(x), y(y), z(z) {}
};

struct Edge {
    int one, two;
    Edge(int one = 0, int two = 0): one(one), two(two) {}
};

struct Face {
    int one, two, three;
    Face(int one = 0, int two = 0, int three = 0): one(one), two(two), three(three) {}
};

#endif //GLUT_3D_GRID_STRUCTS_H
