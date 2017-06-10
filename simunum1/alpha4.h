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
double f_force(double &distance1, double &distance2, double &q1, double &q2, double &q3, double &mass1, double &mass2, double &mass3, double &G){
	//la force que 1 subit par 2 et 3.
	double resultat;
	resultat=((G*mass1*mass2*(q2-q1)/pow(distance1,3)) + (G*mass1*mass3*(q3-q1)/pow(distance2,3)));
	return resultat;
}

int main (){

	double const G_original = 6.67408e-11;
	double const AU= 149597870700; // Astronomical unit in m.
	double const sec_per_day= 24*60*60; // Number of second in a day.
	double const convertor = sec_per_day/(AU*(1e-3)); // le nombre par lequel on multiplie les km/s pour passer en UA/j.

	// The average distance is taken to be the body's semi-major axis around the sun in AU.
	double const av_distance_jupiter = 5.2;
	double const av_distance_saturn = 9.58;

    // The average speeds are values in km/s multiplied/converted in AU/day. 1km/s = 24*60*60/149597870.700 ~ 5.775e-4 AU/jrs


	double const av_speed_sun=0;//by definition
	double const av_speed_jupiter=13.07e3*convertor;
	double const av_speed_saturn=9.69e3*convertor;

	//double mass_soleil=1;
	//double mass_jupiter=1.898e27/1.989e30;
	//double mass_saturne=5.683e26/1.989e30;
	//double mass_dione=1.095452e21/1.989e30;

	double mass_vegeta=1e13;
	double mass_soleil=1.989e30/mass_vegeta;
	double mass_jupiter=1.898e27/mass_vegeta;
	double mass_saturne=5.683e26/mass_vegeta;

	double real_mass_soleil=1.989e30;
	double real_mass_jupiter=1.898e27;
	double real_mass_saturne=5.683e26;
	double real_mass_dione=1.095452e21;

	double  G = G_original	* pow((mass_vegeta),2) * pow((1/AU),1.5);

	double const period = 5000; // Temps en année.
	double dt = 1/10; // Le pas de temps, c'est à dire la fraction que représente un jour par rapport à 5000 ans.

	double position_soleil_x=0;
	double position_soleil_y=0;
	double position_soleil_z=0;

	double position_jupiter_x=5.2;
	double position_jupiter_y=0;
	double position_jupiter_z=0;

	double position_saturne_x=0;
	double position_saturne_y=9.58;
	double position_saturne_z=0;
	/*
	double moment_soleil_x=0;
	double moment_soleil_y=0;
	double moment_soleil_z=0;

	double moment_jupiter_x=0;
	double moment_jupiter_y=(13070*mass_jupiter)/(149597870700*24*60*60);
	double moment_jupiter_z=0;

	double moment_saturne_x=(-9690*mass_saturne)/(149597870700*24*60*60);
	double moment_saturne_y=0;
	double moment_saturne_z=0;
	*/

	double vitesse_soleil_x=0;
	double vitesse_soleil_y=0;
	double vitesse_soleil_z=0;

	double vitesse_jupiter_x=0;
	double vitesse_jupiter_y=(13070)/(149597870700*24*60*60);
	double vitesse_jupiter_z=0;

	double vitesse_saturne_x=(-9690)/(149597870700*24*60*60);
	double vitesse_saturne_y=0;
	double vitesse_saturne_z=0;

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

	//ofstream myfile ("data.txt");

	cout << "vitesse_jupiter_y : " << vitesse_jupiter_y << endl;

	for(int i= 1; i<=3000; i++){//1825000

		distance_soleil_jupiter = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		distance_soleil_saturne = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		distance_jupiter_saturne = f_distance(position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);

		//cout << distance_soleil_jupiter << endl;
		
		/*

		force1_soleil_x = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		force1_soleil_y = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		force1_soleil_z = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);
		
		*/

		force1_jupiter_x = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		force1_jupiter_y = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		force1_jupiter_z = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

		force1_saturne_x = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		force1_saturne_y = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		force1_saturne_z = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);

		/*
		f_force(force1_soleil_x, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force1_soleil_y, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force1_soleil_z, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);

		f_force(force1_jupiter_x, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force1_jupiter_y, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force1_jupiter_z, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

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

		

		position_soleil_x=position_soleil_x+(vitesse_soleil_x)*dt + (1/2)*(force1_soleil_x/mass_soleil)*pow(dt,2);
		position_soleil_y=position_soleil_y+(vitesse_soleil_y)*dt + (1/2)*(force1_soleil_y/mass_soleil)*pow(dt,2);
		position_soleil_z=position_soleil_z+(vitesse_soleil_z)*dt + (1/2)*(force1_soleil_z/mass_soleil)*pow(dt,2);

		*/
		
		position_jupiter_x=position_jupiter_x+(vitesse_jupiter_x)*dt + (1/2)*(force1_jupiter_x/mass_jupiter)*pow(dt,2);
		position_jupiter_y=position_jupiter_y+(vitesse_jupiter_y)*dt + (1/2)*(force1_jupiter_y/mass_jupiter)*pow(dt,2);
		position_jupiter_z=position_jupiter_z+(vitesse_jupiter_z)*dt + (1/2)*(force1_jupiter_z/mass_jupiter)*pow(dt,2);

		position_saturne_x=position_saturne_x+(vitesse_saturne_x)*dt + (1/2)*(force1_saturne_x/mass_saturne)*pow(dt,2);
		position_saturne_y=position_saturne_y+(vitesse_saturne_y)*dt + (1/2)*(force1_saturne_y/mass_saturne)*pow(dt,2);
		position_saturne_z=position_saturne_z+(vitesse_saturne_z)*dt + (1/2)*(force1_saturne_z/mass_saturne)*pow(dt,2);

		distance_soleil_jupiter = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		distance_soleil_saturne = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		distance_jupiter_saturne = f_distance(position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);

		/*
		force2_soleil_x = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		force2_soleil_y = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		force2_soleil_z = f_force(distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);
		*/

		force2_jupiter_x = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		force2_jupiter_y = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		force2_jupiter_z = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

		force2_saturne_x = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		force2_saturne_y = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		force2_saturne_z = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);

		/*
		f_force(force2_soleil_x, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_x, position_jupiter_x, position_saturne_x, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force2_soleil_y, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_y, position_jupiter_y, position_saturne_y, mass_soleil, mass_jupiter, mass_saturne, G);
		f_force(force2_soleil_z, distance_soleil_jupiter, distance_soleil_saturne, position_soleil_z, position_jupiter_z, position_saturne_z, mass_soleil, mass_jupiter, mass_saturne, G);

		f_force(force2_jupiter_x, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force2_jupiter_y, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		f_force(force2_jupiter_z, distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

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
		*/
		/*
		vitesse_soleil_x=vitesse_soleil_x + (1/(2*mass_soleil))*(force1_soleil_x+force2_soleil_x)*dt;
		vitesse_soleil_y=vitesse_soleil_y + (1/(2*mass_soleil))*(force1_soleil_y+force2_soleil_y)*dt;
		vitesse_soleil_z=vitesse_soleil_z + (1/(2*mass_soleil))*(force1_soleil_z+force2_soleil_z)*dt;
		*/

		vitesse_jupiter_x=vitesse_jupiter_x + (1/(2*mass_jupiter))*(force1_jupiter_x+force2_jupiter_x)*dt;
		vitesse_jupiter_y=vitesse_jupiter_y + (1/(2*mass_jupiter))*(force1_jupiter_y+force2_jupiter_y)*dt;
		vitesse_jupiter_z=vitesse_jupiter_z + (1/(2*mass_jupiter))*(force1_jupiter_z+force2_jupiter_z)*dt;

		vitesse_saturne_x=vitesse_saturne_x + (1/(2*mass_saturne))*(force1_saturne_x+force2_saturne_x)*dt;
		vitesse_saturne_y=vitesse_saturne_y + (1/(2*mass_saturne))*(force1_saturne_y+force2_saturne_y)*dt;
		vitesse_saturne_z=vitesse_saturne_z + (1/(2*mass_saturne))*(force1_saturne_z+force2_saturne_z)*dt;

		cout << "Distance Soleil - Jupiter " << distance_soleil_jupiter<<"\n Distance Soleil - Saturne " << distance_soleil_saturne << "\n Distance Jupiter - Saturne" << distance_jupiter_saturne << endl;

		cout << "position Soleil: " << position_soleil_x << " " << position_soleil_y << " " << position_soleil_z << "\n" << "position Jupiter: " <<position_jupiter_x << " " << position_jupiter_y << " " << position_jupiter_z << "\n" << "position Saturne: " << position_saturne_x << " " << position_saturne_y << " " <<position_saturne_z << "\n";

		cout << "vitesse Soleil: " << vitesse_soleil_x << " " << vitesse_soleil_y << " " << vitesse_soleil_z << "\n" << "vitesse Jupiter: " << vitesse_jupiter_x << " " << vitesse_jupiter_y << " " << vitesse_jupiter_z << "\n" << "vitesse Saturne: " << vitesse_saturne_x << " " << vitesse_saturne_y << " " << vitesse_saturne_z << "\n";

		cout << "Force1 Soleil: " << force1_soleil_x << " " << force1_soleil_y << " " << force1_soleil_z << "\n" << "Force Jupiter: " <<force1_jupiter_x << " " << force1_jupiter_y << " " << force1_jupiter_z << "\n" << "Force Saturne: " <<force1_saturne_x << " " << force1_saturne_y << " " << force1_saturne_z << "\n";
		
		cout << "Force2 Soleil: " << force2_soleil_x << " " << force2_soleil_y << " " << force2_soleil_z << "\n" << "Force Jupiter: " <<force2_jupiter_x << " " << force2_jupiter_y << " " << force2_jupiter_z << "\n" << "Force Saturne: " <<force2_saturne_x << " " << force2_saturne_y << " " << force2_saturne_z << "\n";

/*

		if (myfile.is_open())
		{
			myfile << position_soleil_x << " " << position_soleil_y << " " << position_soleil_z << "\n" << position_jupiter_x << " " << position_jupiter_y << " " << position_jupiter_z << "\n" << position_saturne_x << " " << position_saturne_y << " " <<position_saturne_z << "\n";
		}
		else cout << "Unable to open file";
*/
				/*
				1) calculer la force au temps t
				2) calculer la position au temps t+1 via x(t+1)=x(t)+v(t)dt+a(t)dt^2/2
				3) calculer la force à la position x(t+1)
				4) calculer le moment p(t+1) = p(t)+ (1/2)(F(t)+F(t+1))dt
				5) return to step 2)
				*/
    }

	//myfile.close();


	return 0;
}
