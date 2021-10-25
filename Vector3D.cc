#include "Vector3D.h"
#include <cmath>
#include <iostream>

using namespace std;

//constructors

Vector3D::Vector3D(){}

Vector3D::Vector3D(double x1, double x2, double x3){
  x_ = x1;
  y_ = x2;
  z_ = x3;
}

/*Vector3D::Vector3D(const Vector3D& v){
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
  }*/


//setters:
void Vector3D::set_x(const double x){ x_ = x; }
void Vector3D::set_y(const double y){ y_ = y; }
void Vector3D::set_z(const double z){ z_ = z; }

//getters:
double Vector3D::x(){ return x_; }
double Vector3D::y(){ return y_; }
double Vector3D::z(){ return z_; }

// function that return the magnitude of the vector
double Vector3D::magnitude(){
  return sqrt((x_*x_)+(y_*y_)+(z_*z_));
}

// function that return the scalar product of two vectors
double Vector3D::scalarProduct(const Vector3D& v){
  return (x_*v.x_)+(y_*v.y_)+(z_*v.z_);
}

// function that return the angle theta between the vector
//and the z axis by making the scalar product of the two
double Vector3D::theta(){
  return acos(z_/(*this).magnitude()); //rad
}

// function that return the angle phi between the projecton of the vector
//on the xy plane and the x axis by making the scalar product
double Vector3D::phi(){
  double ris;
  double mod= sqrt((x_*x_)+(y_*y_));
  if (y_>=0) ris=acos(x_/mod);
  else ris = -acos(x_/mod)+2*M_PI;
  return ris;
}

// function that return the vector product of two vectors
Vector3D Vector3D::vectorProduct(const Vector3D& v){
  Vector3D ris = Vector3D::Cartesian(0,0,0);
  ris.set_x((y_*v.z_)-(z_*v.y_));
  ris.set_y(-(x_*v.z_)+(z_*v.x_));
  ris.set_z((x_*v.y_)-(y_*v.x_));
  return ris;
}

// fuction that return the angle between two vectors
double Vector3D::angle(Vector3D v){
  return acos((*this).scalarProduct(v)/((*this).magnitude()*v.magnitude()));
}
    

//print vector in cartesian coordinates
void Vector3D::print(){
  cout << "v = (" << x_ << " , " << y_ << " , " << z_ << ")" << endl;

}


//destructor
Vector3D::~Vector3D() {
  //cout << "Destructor called for vector" << endl;
}




//overloading operators
//sum between vectors
Vector3D Vector3D::operator+(const Vector3D& v) const{
  double x = x_ + v.x_;
  double y = y_ + v.y_;
  double z = z_ + v.z_;

  return Vector3D(x,y,z);
}

//difference between vectors
Vector3D Vector3D::operator-(const Vector3D& v) const{
  double x = x_ - v.x_;
  double y = y_ - v.y_;
  double z = z_ - v.z_;

  return Vector3D(x,y,z);
}

//reassignment
const Vector3D& Vector3D::operator=(const Vector3D& v){
  x_ = v.x_;
  y_ = v.y_;
  z_ = v.z_;
  return *this;
}



//implementing operations between Vector3D objects and doubles
//product by a double
Vector3D operator*(const double&a, Vector3D& v){
  return Vector3D::Cartesian(v.x()*a, v.y()*a, v.z()*a);
}

//division by a double
Vector3D operator/(Vector3D& v, const double&a){
  return Vector3D::Cartesian(v.x()/a, v.y()/a, v.z()/a);
}
