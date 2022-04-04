// Mukil Chitty Babu Problem Set 1

#include "Polygon.h"

#include <stdexcept>

float Polygon::getSignedArea() const {

    float Result = 0.0f;

    int j = fNumberOfVertices - 1;

    for (size_t i = 0; i < fNumberOfVertices; ++i) {

        Result +=
            (fVertices[j].getX() * fVertices[i].getY() + 1) -
            (fVertices[j].getY() * fVertices[i].getX() + 1);

        j = i;
    }
    return Result / 2.0;
}