#include <iostream>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

public: 
    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices]; //New 2d array
        for (int i = 0;i < vertices;++i) //Initialize each sub array
            points[i] = new Point();
    }

    ~Shape () {
        for(int i = 0;i <= vertices;i++) 
            delete[] points[i]; //Delete sub arrays
        delete[] points;        //Delete entire array
    }

    void addPoints (Point* pts) {
        for (int i = 0; i < vertices; i++) 
            *points[i] = pts[i];        //Old pts replace with vals of old array
    }

    double area () {
        int temp = 0;
        for (int i = 0; i < vertices; i++) {
            int j = (i + 1) % vertices; // Wrap around to the first point
            int lhs = points[i]->x * points[j]->y;
            int rhs = points[j]->x * points[i]->y;
            temp += (lhs - rhs);
        }
        double area = (abs(temp) / 2.0);
        return area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    Point tri1{0, 0};
    Point tri2 = {1 ,2};
    Point tri3(2,0);

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape tri(3);
    tri.addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    Point quad1(0, 0);
    Point quad2(0, 2);
    Point quad3(2, 2);
    Point quad4(2, 0);

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape quad(4);
    quad.addPoints(quadPts);

    // FIXME: print out area of tri and area of quad
    std::cout << "Area of triangle: " << tri.area() << std::endl;
    std::cout << "Area of quadrilateral: " << quad.area() << std::endl;

    return 0;
}