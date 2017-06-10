#include <iostream>
#include <new>
#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

// Parce qu'on a toujours besoin d'un delta de dirac...
double delta_Dirac (int i, int j){
	if (i==j)
		return 1;
	else
		return 0;
}

double f_distance(double &x1, double &y1, double &z1, double &x2, double &y2, double &z2){
    double distance=0;
    distance = distance=sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
	return distance;
}

double f_distance_vec(double *q1, double *q2){
    double square_distance=0;
    for(int i=0; i<3; i++){
		square_distance = square_distance + pow((q1[i]-q2[i]),2);
	}
	return sqrt(square_distance);
}

double f_force(double &distance, double &q1, double &q2,double &mass1, double &mass2, double &G){
	//la force que 1 subit par 2 et 3.
	double force;
	force=(G*mass1*mass2*(q2-q1)/pow(distance,3));
	return force;
}

int main (){

double mass_1 = 1;
double mass_2 = 1;
double G=2;

double position_body_1[3]={0,0,0};
double position_body_2[3]={1,0,0};

double force_body_1[3]={0,0,0};
double force_body_2[3]={0,0,0};

double distance_1;
double distance_2;

double force_1x;
double force_1y;
double force_1z;

distance_1 = f_distance(x1,y1,z1,x2,y2,z2);
distance_2 = f_distance_vec(&position_body_1[0], &position_body_2[0]);
cout << distance_1 << endl;
cout << distance_2 << endl;



	return 0;
}
