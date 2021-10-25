#include <iostream>
#include <cmath>
#include "Vector3D.h"

#define _USE_MATH_DEFINES

using namespace std;

int main(){

  //i vettori li devi sempre definire in uno di questi due modi perche'
  //gli altri contructors sono privati
  
  Vector3D v1 = Vector3D::Spherical(1,M_PI/2,M_PI/2); 
  v1.print();

  Vector3D v2 = Vector3D::Cartesian(2,3,12);
  v2.print();

  Vector3D v3 = Vector3D::Cartesian(1,1,1);
  Vector3D v4 = Vector3D::Cartesian(2,2,2);

  v3.print();
  v4.print();

  Vector3D v5 = v3 - v4 ;
  v5.print();

  Vector3D v6 = Vector3D::Cartesian(0,0,0);
  v6 = v5;
  v6.print();

  //proviamo a fare le op se definiamo i vec in coord sferiche
  Vector3D v7 = Vector3D::Spherical(1,0,0);
  Vector3D v8 = Vector3D::Spherical(1,M_PI/2,0);

  v7.print();
  v8.print();

  Vector3D v9 = v7 + v8 ;
  v9.print(); //

  double a = v9.z();
  cout << "v9.z() = " << a << endl;

  Vector3D v10 = Vector3D::Spherical(1,M_PI/4,0);
  v10.print();
  Vector3D v11 = 2*v10;
  v11.print();

  Vector3D v12 = Vector3D::Cartesian(1,1,1);
  Vector3D v13 = v12/2;
  v13.print();

  Vector3D v14 = Vector3D::Cartesian(1,1,1);
  Vector3D v15 = Vector3D::Cartesian(0,0,1);
  cout << "v14 : \t " ;
  v14.print();
  cout << "v15 : \t " ;
  v15.print();
  double r1 = v14.magnitude();
  double r2 = v15.magnitude();
  cout << "v14.magnitude() = " << r1 << endl;
  cout << "v15.magnitude() = " << r2 << endl;
  double dotP = v14.scalarProduct(v15);
  cout << "v14.scalarProduct(v15) = " << dotP << endl;
  double theta14 = v14.theta();
  cout << "v14.theta() = " << theta14 << " rad"  << endl;
  double phi14 = v14.phi();
  cout << "v14.phi() = " << phi14 << " rad"  << endl;
  Vector3D v16 = v14.vectorProduct(v15);
  cout << "v16 = v14 x v15 : \t " ;
  v16.print();
  double angle = v14.angle(v15);
  cout << "v14.angle(v15):  " << angle << endl;
  
  

  return 0;
}
