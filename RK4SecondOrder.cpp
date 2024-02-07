#include<iostream>
#include<cmath>
using namespace std;
float functiony(float x, float y, float z){
return z;
}
float functionz(float x, float y, float z){
//return (sin(x)-6*y+5*z);
return x+ 2*y +z ;
}
int main(){
float x0,y0,z0,k1,k2,k3,k4,k,l1,l2,l3,l4,h,xn,l;
cout<<"Enter x0, y0, z0: ";
cin>>x0>>y0>>z0;
cout<<"Approximate to: ";cin>>xn;
cout<<"Enter step size";
cin>>h;
while(x0<xn){

k1 = h* functiony(x0, y0, z0);
l1 = h*functionz(x0,y0,z0);

k2 = h* functiony(x0+ 0.5*h, y0+ 0.5*k1, z0+ 0.5*l1);
l2 = h* functionz(x0+ 0.5*h, y0+ 0.5*k1, z0+ 0.5*l1);

k3 = h* functiony(x0+ 0.5*h, y0+ 0.5*k2, z0+ 0.5*l2);
l3 = h* functionz(x0+ 0.5*h, y0+ 0.5*k2, z0+ 0.5*l2);

k4 = h*functiony(x0+h, y0+k3, z0+l3);
l4 = h*functionz(x0+h, y0+k3, z0+l3);

l = (l1+2*l2+2*l3+l4)/6;
k = (k1+2*k2+2*k3+k4)/6;
y0 += k;
z0 += l;
x0+=h;
}
if(x0!=xn){
    cout<<"Invalid step size"<<endl;
}
else{
    cout<<"x = "<<x0<<"\t y = "<<y0<<"\t z = "<<z0<<endl;
}
return 0;

}
