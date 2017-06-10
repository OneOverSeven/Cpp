#include <iostream>
#include <new>
#include <math.h>
#include <cmath>
using namespace std;

// Parce qu'on a toujours besoin d'un delta de dirac...
double delta_Dirac (int i, int j){
	if (i==j)
		return 1;
	else
		return 0;
}

void f_distance(double &distance, double &x1, double &y1, double &z1, double &x2, double &y2, double &z2){
	distance=sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
}
void f_force(double &force, double &distance1, double &distance2, double &q1, double &q2, double &q3, double &mass1, double &mass2, double &mass3, double &G){
	//la force que 1 subit par 2 et 3.
	force=G*mass1*mass2*(q2-q1)/pow(distance1,3) + G*mass1*mass3*(q3-q1)/pow(distance2,3);
}

int main (){
	
	double const G_original = 6.67408e-11;
	double const AU= 149597870700; // Astronomical unit in m.
	double const sec_per_day= 24*60*60; // Number of second in a day.
	double const convertor = n_sec_jrs/(AU*(1e-3)); // le nombre par lequel on multiplie les km/s pour passer en UA/j.

	// The average distance is taken to be the body's semi-major axis around the sun in AU.
	double const av_distance_jupiter = 5.2;
	double const av_distance_saturn = 9.58;

    // The average speeds are values in km/s multiplied/converted in AU/day. 1km/s = 24*60*60/149597870.700 ~ 5.775e-4 AU/jrs
	
	
	double const av_speed_sun=0;//by definition
	double const av_speed_jupiter=13.07e3*convertor;
	double const av_speed_saturn=9.69e3*convertor;

	
	
	
	double const mass_soleil=1;
	double const mass_jupiter=1.898e27/1.989e30;
	double const mass_saturne=5.683e26/1.989e30;
	double const mass_dione=1.095452e21/1.989e30;
	
	double const real_mass_soleil=1.989e30;
	double const real_mass_jupiter=1.898e27;
	double const real_mass_saturne=5.683e26;
	double const real_mass_dione=1.095452e21;
	
	double const G = G_original	* pow((AU/1.989e30),2);
    
	double const period = 5000; // Temps en année.
	double const dt = 1; // Le pas de temps, c'est à dire la fraction que représente un jour par rapport à 5000 ans.
	
	double position_soleil_x=0;
	double position_soleil_y=0;
	double position_soleil_z=0;
	
	double position_jupiter_x=0;
	double position_jupiter_y=0;
	double position_jupiter_z=0;
	
	double position_saturne_x=0;
	double position_saturne_y=0;
	double position_saturne_z=0;
	
	double moment_soleil_x=0;
	double moment_soleil_y=0;
	double moment_soleil_z=0;
	
	double moment_jupiter_x=0;
	double moment_jupiter_y=0;
	double moment_jupiter_z=0;
	
	double moment_saturne_x=0;
	double moment_saturne_y=0;
	double moment_saturne_z=0;
	
	double force1_soleil_x=0;
	double force1_soleil_y=0;
	double force1_soleil_z=0;
	
	double force1_jupiter_x=0;
	double force1_jupiter_y=0;
	double force1_jupiter_z=0;
	
	double force1_saturne_x=0;
	double force1_saturne_y=0;
	double force1_saturne_z=0;
	
	double force2_soleil_x=0;
	double force2_soleil_y=0;
	double force2_soleil_z=0;
	
	double force2_jupiter_x=0;
	double force2_jupiter_y=0;
	double force2_jupiter_z=0;
	
	double force2_saturne_x=0;
	double force2_saturne_y=0;
	double force2_saturne_z=0;
	
	double distance_soleil_jupiter=0;
	double distance_soleil_saturne=0;
	double distance_jupiter_saturne=0;
	
	
	
	

	
	
	

	for(int i= 1; i<=1825000; i++){


		f_distance(distance_soleil_jupiter, position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		f_distance(distance_soleil_saturne, position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		f_distance(distance_jupiter_saturne,position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);
		
		f_force(force1_soleil_x, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force1_soleil_y, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force1_soleil_z, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);

		f_force(force1_jupiter_x, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force1_jupiter_y, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force1_jupiter_z, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);
				
		f_force(force1_saturne_x, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		f_force(force1_saturne_y, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		f_force(force1_saturne_z, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);
			
		position_soleil_x=position_soleil_x+(moment_soleil_x/mass_soleil)*dt + (1/2)*(force1_soleil_x/mass_soleil)*pow(dt,2);
		position_soleil_y=position_soleil_y+(moment_soleil_y/mass_soleil)*dt + (1/2)*(force1_soleil_y/mass_soleil)*pow(dt,2);
		position_soleil_z=position_soleil_z+(moment_soleil_z/mass_soleil)*dt + (1/2)*(force1_soleil_z/mass_soleil)*pow(dt,2);
				
		position_jupiter_x=position_jupiter_x+(moment_jupiter_x/mass_jupiter)*dt + (1/2)*(force1_jupiter_x/mass_jupiter)*pow(dt,2);
		position_jupiter_y=position_jupiter_y+(moment_jupiter_y/mass_jupiter)*dt + (1/2)*(force1_jupiter_y/mass_jupiter)*pow(dt,2);
		position_jupiter_z=position_jupiter_z+(moment_jupiter_z/mass_jupiter)*dt + (1/2)*(force1_jupiter_z/mass_jupiter)*pow(dt,2);
				
		position_saturne_x=position_saturne_x+(moment_saturne_x/mass_saturne)*dt + (1/2)*(force1_saturne_x/mass_saturne)*pow(dt,2);
		position_saturne_y=position_saturne_y+(moment_saturne_y/mass_saturne)*dt + (1/2)*(force1_saturne_y/mass_saturne)*pow(dt,2);
		position_saturne_z=position_saturne_z+(moment_saturne_z/mass_saturne)*dt + (1/2)*(force1_saturne_z/mass_saturne)*pow(dt,2);
		
		f_distance(distance_soleil_jupiter, position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		f_distance(distance_soleil_saturne, position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		f_distance(distance_jupiter_saturne,position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);

		f_force(force2_soleil_x, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force2_soleil_y, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force2_soleil_z, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);

		f_force(force2_jupiter_x, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force2_jupiter_y, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force2_jupiter_z, distance_soleil_jupiter, distance_jupiter_saturne_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);
		
		f_force(force2_saturne_x, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		f_force(force2_saturne_y, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		f_force(force2_saturne_z, distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);
		
		moment_soleil_x=moment_soleil_x + (1/2)*(force1_soleil_x+force2_soleil_x)*dt;
		moment_soleil_y=moment_soleil_y + (1/2)*(force1_soleil_y+force2_soleil_y)*dt;
		moment_soleil_z=moment_soleil_z + (1/2)*(force1_soleil_z+force2_soleil_z)*dt;
		
		moment_jupiter_x=moment_jupiter_x + (1/2)*(force1_jupiter_x+force2_jupiter_x)*dt;
		moment_jupiter_y=moment_jupiter_y + (1/2)*(force1_jupiter_y+force2_jupiter_y)*dt;
		moment_jupiter_z=moment_jupiter_z + (1/2)*(force1_jupiter_z+force2_jupiter_z)*dt;
		
		moment_saturne_x=moment_saturne_x + (1/2)*(force1_saturne_x+force2_saturne_x)*dt;
		moment_saturne_y=moment_saturne_y + (1/2)*(force1_saturne_y+force2_saturne_y)*dt;
		moment_saturne_z=moment_saturne_z + (1/2)*(force1_saturne_z+force2_saturne_z)*dt;
				/*
				1) calculer la force au temps t
				2) calculer la position au temps t+1 via x(t+1)=x(t)+v(t)dt+a(t)dt^2/2
				3) calculer la force à la position x(t+1)
				4) calculer le moment p(t+1) = p(t)+ (1/2)(F(t)+F(t+1))dt
				5) return to step 2)
				*/
    }
	

	return 0;
}
