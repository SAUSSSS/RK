#include<iostream>
#include<cmath>
#include<fstream>


double g(double x, double y,double z){
    return  x*exp(-x) - y;
}

double f(double x, double y,double z){
    return z;
}

double RK(double y[],double a,double b,double n){
    std::ofstream y1,y2;
    y1.open("y1.dat");

    int N = 2001;
    double x[N] = {0};
    double yy[N] = {0};
    double z[N] = {0};
    double h = (b - a) / n;

    double k1,k2,k3,k4;
    double l1,l2,l3,l4;

    x[0] = a;
    yy[0] = y[0];
    z[0] = y[1];

    for(int i = 0; i < n; i++){
        x[i+1] = x[i] + h;
        k1 = f(x[i],yy[i],z[i]);
        l1 = g(x[i],yy[i],z[i]);

        k2 = f(x[i] + h/2., yy[i]+(h*k1)/2.,z[i]+(h*l1)/2.);
        l2 = g(x[i] + h/2., yy[i]+(h*k1)/2.,z[i]+(h*l1)/2.);

        k3 = f(x[i] + h/2., yy[i]+(h*k2)/2.,z[i]+(h*l2)/2.);
        l3 = g(x[i] + h/2., yy[i]+(h*k2)/2.,z[i]+(h*l2)/2.);

        k4 = f(x[i]+h, yy[i] + h*k3,z[i]+h*l3);
        l4 = g(x[i]+h, yy[i] + h*k3,z[i]+h*l3);

        yy[i+1] = yy[i] + h*((k1+2*k2+2*k3+k4))/6;
        z[i+1] = z[i] + h*((l1+2*l2+2*l3+l4))/6;

        std::cout << yy[i+1] << " " << z[i+1] << std::endl;

        y1 << z[i+1] << " " << yy[i+1] << std::endl;
    }
    
    y1.close();
    return 0;
}


int main(){
    double f[2];
    f[0] = 1;
    f[1] = 0;
    RK(f,0,2,1000);
    return 0;
} 
