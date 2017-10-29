#include "stdafx.h"
#include "mesh.h"

#define _TEMP_COMMENT_EXTRACT 200
#define IS_INT(i) (i<0?1:0) /* MACRO for vertexes indexes (positive only) :
                          returns 0: positive value, 1: negative value */

using namespace std;

/**--------------------------------------------------- */
// the VMPoint class

/** contains VMPoints with double values x(), y(), z() */
VMPoint::VMPoint() : x(0), y(0), z(0) {
}

/* destructor: empties the vectors for a new object */
VMPoint::~VMPoint() {
    // NO MEMORY TO MANAGE
}

// easy-to-use constructor for easy initializations
VMPoint::VMPoint(double m, double n, double l) : x(m), y(n), z(l) {
}

// accessors for the coordinates (return copies)
double  VMPoint::getx() {return x;}
double  VMPoint::gety() {return y;}
double  VMPoint::getz() {return z;}

// set fucntions for the coordinates
void  VMPoint::setx(double n) {x=n;}
void  VMPoint::sety(double n) {y=n;}
void  VMPoint::setz(double n) {z=n;}


/**--------------------------------------------------- */
// the VMFacet class

// empty constructor, sets VMPoints to zero values
VMFacet::VMFacet() : x(0), y(0), z(0) {
}

/* destructor: empties the vectors for a new object */
VMFacet::~VMFacet() {
    // NO MEMORY TO MANAGE
}

// easy-to-use constructor for easy initializations
VMFacet::VMFacet(int m, int n, int l) {
    x = m;
    y = n;
    z = l;
}

// accessors for the indexes (return copies, ints)
int  VMFacet::getx() {return x;}
int  VMFacet::gety() {return y;}
int  VMFacet::getz() {return z;}

// set fucntions for the indexes
int  VMFacet::setx(int n) {
    if (IS_INT(n)==1) 
        return 4; /* ERROR code to display : 
                  "trying to set negative index" */
    x=n;
    return 0;
}
int  VMFacet::sety(int n) {
    if (IS_INT(n)==1)
        return 4; // ERROR code to display
    y=n;
    return 0;
}
int  VMFacet::setz(int n) {
    if (IS_INT(n)==1)
        return 4; // ERROR code to display
    z=n;
    return 0;
}


/**--------------------------------------------------- */
// the Mesh class

//default constructor: initializes an object
Mesh::Mesh() : e(0) {
    gr = VMPoint();
}

/* destructor: empties the vectors for a new object */
Mesh::~Mesh() {
    reset();       // delete all points and facets data
}

/* adding a new VMPoint to the vector of vertexes vp */
int  Mesh::add_point(double x, double y, double z) {
    this->vp.push_back(VMPoint(x,y,z));
    return 0;
}

// adding a new VMFacet to the vector of VMFacets vf
int  Mesh::add_facet(int m, int n, int l) {
    /* using the macro to check if any of the values is negative
    it is simple here to use of the bit-wise operator OR (|)
    ! nota: checks are just to ensure that no incorrect data
    (vertex) index is stored, which would ruin the mesh: the
    error code informs on the origin of the error (see forms.h) */
	if (IS_INT(m) | IS_INT(n) | IS_INT(l)) {
        this->e=4;
        return 4; // ERROR code to display
    }
    this->vf.push_back(VMFacet(m,n,l));
    return 0;
}

/* read function: puts the coordinates from the stream (file) in the mesh
returns an error code  0: OK, 1: bad read, 2: failed read, 3: empty file
4: VMFacet with negative values, 5: incorrect line formatting */
int  Mesh::read_file(char* filename) {
    int err=0; // error code
    ifstream ifst(filename); // the file stream to read from
    /* initial checks (basic tests)
    4 possible states: good(), bad(), fail(), eof()*/
    if (!ifst) {
        if (ifst.bad()) {err=1;}// unexpected and serious error
        else if (ifst.fail() & (!ifst.eof())) {err=2;}// unexpected error
        else if (ifst.eof()) {err=3;}// end of file reached, i.e. file empty
    } // stream is good()
     
    /* getting and storing input from the stream:
	the filestream formatting is supposed to be correct i.e. 1 char ('v' or 'f')
	followed by 3 (signed double)s or 3 (int)s for each line

	! note that the implementation of this file reading function does not make
	use of the operators overloading functions declared in the header but consists
	in an optimised version of adding a VMPoint (vertex) or a VMFacet into a Mesh */
    char c; // line identifier ('c' or 'v' or '#')
    char s[ _TEMP_COMMENT_EXTRACT + 1 ]; // temporary c-string to extract and discard comments
    while ((ifst >> c) && (err == 0)) {
        if (c =='v') { // testing if a vertex ?
            double x, y, z; // for the three values of a VMPoint
            // retrieving the values
            ifst >> x >> y >> z;
            err = add_point(x,y,z); /* adding a VMPoint or a VMFacet this way 
            is considered more efficient than using the overloaded operator >> 
			to store VMPoints */
        }
        else if (c=='f') { /*testing if a VMFacet ? (test for readability but
						   should not be needed*/
            int x, y, z; 
            ifst >> x >> y >> z;
            err = add_facet(x,y,z);
        }
		else if ((c=='#') | (c=='g')) { /* the '#' and 'g' chars mark respectively
						   the beginning of a comment and a specification. as such
                           the entire line may be ignored */
			ifst.getline(s, _TEMP_COMMENT_EXTRACT); /* the next 200 char
                                   in the line are extracted &discarded; */
		}
        else err=5;
		/* no actual possible 'else' statement, as the file is considered 
		of a correct format so possible values for char 'c' are only 'v' or 'f' */
    }

	/* checks after the loop so as to output the correct message after the read */
    if (!ifst || !(err==0)) {
        if (ifst.bad()) {err=1;}
        else if (ifst.fail() & (!ifst.eof())) {err=2;}
        else { /* ifst.eof() is true, the file has been 'put' in the mesh:
			   the file will be closed at the end of the function (when the
			   ifstream goes out-of-scope) */
			err=0;
		}
    }
    this->e=err;
    gravity();
    return err;
} //read_file

/* gravity processing function */
VMPoint  Mesh::gravity() {
    double gx=0, gy=0, gz=0;
    for (unsigned int i=0; i<vp.size(); i++) {
        gx += vp[i].getx();
        gy += vp[i].gety();
        gz += vp[i].getz();
    }
    gr.setx(gx/vp.size());
    gr.sety(gy/vp.size());
    gr.setz(gz/vp.size());
    return gr;
} //gravity

/* access function to get n-th VMPoint (vertex) from the mesh
returns a copy of the VMPoint or 0 if index out of bounds (as such,
the retrieval at wrong negative indexes will return "null VMPoints (0,0,0)") */
VMPoint  Mesh::get_point(int n) {
    if (n>=this->p_count()) return VMPoint();
    return this->vp[n];
}

/* access function to get n-th VMPoint (verte'x) from the mesh
returns a copy of the VMFacet or 0 if index out of bounds (as such,
the retrieval at wrong negative indexes will return "null VMFacets (0,0,0)") */
VMFacet  Mesh::get_facet(int n) {
    if (n>=this->f_count()) return VMFacet();
	return this->vf[n];
}

/* access function to the gravity point of the mesh */
VMPoint  Mesh::get_gravity() { return gr; }

/* accessor for the number of vertexes (VMPoint) constituting the Mesh
returns the index int value */
int  Mesh::p_count() {
	return vp.size();
}

/* accessor for the number of VMFacets constituting the Mesh
returns the index int value */
int  Mesh::f_count() {
	return vf.size();
}

/* function reset the data contained in the mash to 0 */
int Mesh::reset() {
    vp.clear();    // points vector cleared
    vf.clear();    // facets vector cleared
    return ( vp.empty() | vf.empty() );  // error code
}


/**--------------------------------------------------- */
// the operator overloading functions

/* operator overloading for an istream into a VMPoint
returned variable may need a cast */
istream& operator>>(istream& ist, VMPoint& o) {
    /* the file format is supposed to be correct
       next values are 3 signed doubles */

    /* getting and storing input from the stream */
    double x, y, z; // for the three values of a VMPoint
    // retrieving then setting the values
    ist >> x >> y >> z;
    o.setx(x);
    o.sety(y);
    o.setz(z);
    return ist;
}

/* output of a VMPoint in a comma separated values format in brackets */
ostream& operator<<(ostream& ost, VMPoint& o) {
	return ost << "(" << o.getx() << "," << o.gety() << "," << o.getz() << ")";
}

/* operator overloading for an istream to a VMFacet
(a VMFacet here is a triangle only: (x,y,z) vertexes) */
istream& operator>>(istream& ist, VMFacet& o) {
    /* the file format is supposed to be correct
    the three next values are 3 (unsigned int)s */
    
    /* getting and storing input from the stream */
    int x, y, z;
    ist >> x >> y >> z;
    o.setx(x);
    o.sety(y);
    o.setz(z);
    return ist;
}

/* output of a VMFacet in a comma separated values format in curly brackets */
ostream& operator<<(ostream& ost, VMFacet& o) {
	return ost << "{" << o.getx() << "," << o.gety() << "," << o.getz() << "}";
}

/* operator overloading for an istream to a Mesh */
istream& operator>>(istream& ist, Mesh& m) {
    int err=0; // error code
    /* the stream formatting is supposed to be correct: 1 char ('v' or 'f') 
	followed by 3 (signed double)s or 3 (unsigned int)s */
     
    /* getting and storing ONE LINE of input from the stream:
	! note that the implementation of this overloading function of the 
	operator >> does not use the '>>' operator to put stream data in VMPoints or 
	VMFacets but consists in an optimised version of adding a VMPoint (vertex) or 
	a VMFacet into a Mesh (the same version is used in the read_file() function) */
	char c;
	ist >> c;
	if (c =='v') { // testing if a vertex ?
		double x, y, z; 
		ist >> x >> y >> z;
		err=m.add_point(x,y,z); 
	}
	else if (c=='f') { //testing if a VMFacet ?
		int x, y, z; 
		ist >> x >> y >> z;
		err=m.add_facet(x,y,z);
	}
	/* else 0; /* no actual possible 'else' statement, the line is considered of 
	a correct format */

	return ist;
}

/* operator overloading to output a Mesh to a stream
first are output the vertexes then the vertex indexes constituting
the VMFacets of the Mesh */
ostream& operator<<(ostream& ost, Mesh& m) {
    int num_p = m.p_count();
    int num_f = m.f_count();
    ost << "-- Vertexes (" << m.p_count() << ") :\n";
    for (int i=0; i<num_p; i++) 
        ost << m.get_point(i) << '\n';
    ost << "-- Facets (" << m.f_count() << ") :\n";
    for (int i=0; i<num_f; i++)
        ost << m.get_facet(i) << '\n';
    return ost;
}

