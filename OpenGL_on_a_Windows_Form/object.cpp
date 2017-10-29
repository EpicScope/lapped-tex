#include <ifstream>
#include <iostream>

/
class Point {

    // the three coordinates of a point
    double x, y, z;

public:
    // empty constructor, sets points to zero values
    Point() : x(0), y(0), z(0) {
    }

    // easy-to-use constructor for easy initializations
    Point(double m, double n, double l) : x(m), y(n), z(l) {
    }

    // operator overloading for the use of [] as coordinate
    // accessing operator. index begins at 0
    // (0 for x, 1 for y, 2 for z)
    // (useful if there is more than one value to process)
    double& operator[](int& i) {
        if (i==0) return x;
        else if (i==1) return y;
        else if (i==2) return z;
        else error("wrong use of operator [] (index overflow)");
    }
}

class

istream& operator>>(istream& ist, Mesh& m) {
    // insert checks of the correctness of the stream here
    // [...]

    // getting input from the stream
    char c;
    while (ist >> c) {
        if (c =='v') {
            double n; int i=0; // index
            while (ist >> n && i<3) {
                p[i] = n; i++;
            }
            // insert checks here
            // [...]
        }
        if (c=='f') {

        }
    }

}

class Mesh {
    //private members
    vector<Point> vp; // the vector containing all the points
    vector<Point> vf; // the vector containing the facets (

public:
    //default constructor: initializes an object
    Mesh() {

    }

    void add_point(double x, double y, double z) {
        vp.push_back(Point(x,y,z));
    }

    void add_facet(int x, int y, int z) {
        vf.push_back(Point
}




