//
// Created by Mikhail Zhuravlev on 12.12.2021.
//

#include "Grid.h"


int Grid::readFile(char *fileName) {
    std::ifstream   fileStream(fileName);

    if (!fileStream) {
        return 1;
    }

    std::string str;
    std::string temp;

    int         count;

    for (int i = 0; i < 6; i++) {
        fileStream >> str;
    }

    while (fileStream >> str) {
        if (str == "Vertices" || str == "Edges" || str == "Faces" || str == "Locations") {
            fileStream >> temp >> count >> temp >> temp;
            if (str == "Vertices") {
                double  one, two, three;
                vertices_.reserve(count);
                for (int i = 0; i < count; i++) {
                    fileStream >> one >> two >> three;
                    vertices_.emplace_back(one, two, three);
                }
            }
            else if (str == "Edges") {
                int one, two;
                edges_.reserve(count);
                for (int i = 0; i < count; i++) {
                    fileStream >> one >> two;
                    edges_.emplace_back(one, two);
                }
            }
            else if (str == "Faces") {
                int one, two, three;
                faces_.reserve(count);
                for (int i = 0; i < count; i++) {
                    fileStream >> str;
                    if (str == "TRI") {
                        fileStream >> one >> two >> three;
                        faces_.emplace_back(one, two, three);
                    }
                    else {
                        std::cout << "WARN: Invalid type on line " << i << " \'" << str << "\'" << std::endl;
                        fileStream >> str >> str >> str >> str;
                    }
                }
            }
            else if (str == "Locations") {
                locations_.reserve(count);
                for (int i = 0; i < count; i++) {
                    fileStream >> str;
                    locations_.push_back(str);
                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "INFO: " << "Minimal value on the axis \'x\': " << getMin('x') << std::endl;
    std::cout << "INFO: " << "Maximum value on the axis \'x\': " << getMax('x') << std::endl;
    std::cout << "INFO: " << "Minimal value on the axis \'y\': " << getMin('y') << std::endl;
    std::cout << "INFO: " << "Maximum value on the axis \'y\': " << getMax('y') << std::endl;
    std::cout << "INFO: " << "Minimal value on the axis \'z\': " << getMin('z') << std::endl;
    std::cout << "INFO: " << "Maximum value on the axis \'z\': " << getMax('z') << std::endl;

    return 0;
}