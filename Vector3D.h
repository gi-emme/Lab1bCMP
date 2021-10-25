#include <iostream>
#include <cmath>

#ifndef Vector3D_h
#define Vector3D_h

class Vector3D{

 public:
  
  //cartesian coordinates
  static Vector3D Cartesian(double x, double y, double z){
    return Vector3D(x, y, z);
  }

  //spherical coordinates
  static Vector3D Spherical(double r, double theta, double phi){
    return Vector3D(r*sin(theta)*cos(phi), r*sin(theta)*sin(phi), r*cos(theta));
  }

  

  //setters
  void set_x(const double x);
  void set_y(const double y);
  void set_z(const double z);

  

  //getters
  double x();
  double y();
  double z();
  
  double magnitude();
  double scalarProduct(const Vector3D& v);
  double theta();
  double phi();
  Vector3D vectorProduct(const Vector3D& v);
  double angle(Vector3D v);

  //print vector in cartesian coordinates
  void print();


  //destructor
  ~Vector3D();


  //overloading operators
  //sum between vectors
  Vector3D operator+(const Vector3D& v) const;

  //difference between vectors
  Vector3D operator-(const Vector3D& v) const;

  //reassignment
  const Vector3D& operator=(const Vector3D& v);

 private:
  double x_, y_, z_;

  //regular constructors:
  Vector3D();
  Vector3D(double x1, double x2, double x3);
  //Vector3D(const Vector3D& v);


};

//implementing operations between Vector3D objects and doubles
//product by a double
Vector3D operator*(const double&a, Vector3D& v);

//division by a double
Vector3D operator/(Vector3D& v, const double&a);


#endif
