#ifndef DEF_MESH
#define DEF_MESH // to prevent infinite inclusions

#include <fstream>
#include <iostream>
#include <vector>

/** contains VMPoints with double values x(), y(), z() */
class VMPoint {
public:
    // empty constructor, sets VMPoints to zero values
    VMPoint();
    ~VMPoint();

    // easy-to-use constructor for easy initializations
    VMPoint(double,double,double);

    // accessors for the coordinates (copies are returned)
    double  getx();
    double  gety();
    double  getz();

    // set fucntions for the coordinates
    void  setx(double);
    void  sety(double);
    void  setz(double);

private:
    // the private three coordinates of a VMPoint
    double  x, y, z;

}; // VMPoint class


/** object for TRIANGULAR VMFacets with integer values x(), y(), z() */
class VMFacet {  
public:
    // empty constructor, sets VMPoints to zero values
    VMFacet();
    ~VMFacet();

    /* obvious and easy-to-use constructor for easy initialization */
    VMFacet(int,int,int);

    /* accessors for the indexes (return copies, unsigned ints) */
    int  getx();
    int  gety();
    int  getz();

    /* set functions for the indexes (return error codes) */
    int  setx(int);
    int  sety(int);
    int  setz(int);

private:
    // the three indexes of a VMFacet (2 billions (2^31 int) possible values)
    int  x, y, z;   
}; // VMFacet class


class Mesh {
public:
    /* default constructor: initializes an object */
    Mesh();
    ~Mesh();

    /* adding a new VMPoint to the vector of vertexes vp */
    int  add_point(double,double,double);

    /* adding a new VMFacet to the vector of VMFacets vf */
    int  add_facet(int,int,int);

    /* read function: puts the coordinates from the stream (file) in the mesh
    returns an error code (0: OK, 1: bad read, 2: failed read, 3: empty file) */
    int read_file(char*);

    /* processing function that initializes the gravity center of the mesh
    returns a VMPoint that is the newly calculated gravity VMPoint of the mesh */
    VMPoint  gravity();

    /* accessor to n-th VMPoint in the vector
    returns a copy of the VMPoint, or 0 if out-of-bounds index */
    VMPoint  get_point(int n);

    /* accessor to n-th VMPoint in the vector
    returns a copy of the VMFacet, or 0 if out-of-bounds index */
    VMFacet  get_facet(int n);

    /* accessor to the gravity point of the mesh
    returns a copy of the center point */
    VMPoint  get_gravity();

    /* accessor to the number of vertexes in the mesh i.e. vp size
    returns an int value */
    int  p_count();

    /* accessor to the number of VMFacets in the mesh i.e. vf size
    returns an int value */
    int  f_count();

    /* resetting function */
    int reset();

private:
    //private members
    std::vector<VMPoint>  vp; // the vector containing all the VMPoints
    std::vector<VMFacet>  vf; // the vector containing all the VMFacets
    VMPoint  gr;              // gravity center of the mesh
    int  e;                   // the current error code: the error state of the mesh

}; // Mesh class

/* ----- operator overloading for a stream to a VMPoint, a VMFacet or a Mesh, or the other way around */

std::istream&  operator>>(std::istream&, VMPoint&); /*from whitespace
                                                  separated values*/
std::ostream&  operator<<(std::ostream&, VMPoint&); /*to (csv) format*/

std::istream&  operator>>(std::istream&, VMFacet&); /*from whitespace
                                                  separated values*/
std::ostream&  operator<<(std::ostream&, VMFacet&); /*to {csv} format*/

std::istream&  operator>>(std::istream&, Mesh&); /*valid for a single
                                                 line of input only*/
std::ostream&  operator<<(std::ostream&, Mesh&); /*sends all of a 
                        mesh to the ostream with vertexes first in 
                        (csv) format then the VMFacets in {csv} format*/


#endif

