//
// Created by Mikhail Zhuravlev on 12.12.2021.
//

#include "Grid.h"


void    Grid::onRender() {
    glTranslatef(0, 0, zoom);

    glRotated(angleX, 1, 0, 0);
    glRotated(angleY, 0, 1, 0);
    glRotated(angleZ, 0, 0, 1);

    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex3d(-1 * abs(zoom), 0, 0);
    glVertex3d(1 * abs(zoom), 0, 0);

    glColor3f(0, 1, 0);
    glVertex3d(0, -1 * abs(zoom), 0);
    glVertex3d(0, 1 * abs(zoom), 0);

    glColor3f(0, 0, 1);
    glVertex3d(0, 0, -1 * abs(zoom));
    glVertex3d(0, 0, 1 * abs(zoom));
    glEnd();

    glColor3f(1, 1, 1);

    if (figure) {
        drawFigure("e");
        if (outerSurfaces) {
            drawFigure("i");
        }
    }

    glColor3f(0, 0.25, 0.5);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);
    glEnable(GL_POLYGON_OFFSET_LINE);
    glPolygonOffset(-1, -1);

    drawFigure("e");

    glEnd();
    glDisable(GL_POLYGON_OFFSET_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void    Grid::drawFigure(std::string location) {
    glBegin(GL_TRIANGLES);

    double biasZ;

    double biasX;
    double biasY;

    if (getMax('z') > 0 && getMin('z') < 0)
        biasZ = (getMax('z') - abs(getMin('z'))) / 2;
    else biasZ = (getMax('z') - getMin('z')) / 2;

    if (getMax('x') > 0 && getMin('x') < 0)
        biasX = (getMax('x') - abs(getMin('x'))) / 2;
    else biasX = (getMax('x') - getMin('x')) / 2;

    if (getMax('y') > 0 && getMin('y') < 0)
        biasY = (getMax('y') - abs(getMin('x'))) / 2;
    else biasY = (getMax('y') - getMin('y')) / 2;

    int temp;


    for (int i = 0; i < faces_.size(); i++) {
        if (locations_[i] == location) {
            if (faces_[i].one < 0) {
                temp = abs(faces_[i].one) - 1;
                glVertex3f(transform(vertices_[edges_[temp].two].x, biasX, 'x'), transform(vertices_[edges_[temp].two].y, biasY, 'y'),
                           transform(vertices_[edges_[temp].two].z, biasZ, 'z'));
                glVertex3f(transform(vertices_[edges_[temp].one].x, biasX, 'x'), transform(vertices_[edges_[temp].one].y, biasY, 'y'),
                           transform(vertices_[edges_[temp].one].z, biasZ, 'z'));
            }
            else {
                glVertex3f(transform(vertices_[edges_[faces_[i].one].one].x, biasX, 'x'), transform(vertices_[edges_[faces_[i].one].one].y, biasY, 't'),
                           transform(vertices_[edges_[faces_[i].one].one].z, biasZ, 'z'));
                glVertex3f(transform(vertices_[edges_[faces_[i].one].two].x, biasX, 'x'), transform(vertices_[edges_[faces_[i].one].two].y, biasY, 'y'),
                           transform(vertices_[edges_[faces_[i].one].two].z, biasZ, 'z'));
            }

            if (faces_[i].two < 0) {
                temp = abs(faces_[i].two) - 1;
                glVertex3f(transform(vertices_[edges_[temp].one].x, biasX, 'x'), transform(vertices_[edges_[temp].one].y, biasY, 'y'),
                           transform(vertices_[edges_[temp].one].z, biasZ, 'z'));
            }
            else {
                glVertex3f(transform(vertices_[edges_[faces_[i].two].two].x, biasX, 'x'), transform(vertices_[edges_[faces_[i].two].two].y, biasY, 'y'),
                           transform(vertices_[edges_[faces_[i].two].two].z, biasZ, 'z'));
            }
        }
    }
    glEnd();
}

#include <iostream>

double   Grid::transform(double value, double bias, char axis) {
    double  transform = 0;

    if (vertices_.size() == 45)
    {
        if (axis == 'z') {
            transform = (value - bias) / 3.5;
        }
        else
        {
            transform = (value - bias + 2.5) / 3.5;
        }
    }
    else if (vertices_.size() == 8)
    {
        transform = (value - bias) / 0.6;
    }
    else if (vertices_.size() == 2912)
    {
        if (axis == 'z') {
            transform = (value - bias);
        }
        else
        {
            transform = (value - bias + 0.75);
        }
    }

    return transform;
}
