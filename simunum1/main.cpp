#include <iostream>
#include <new>
#include <math.h>
//#include <cmath>
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
    distance = sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
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
	double const AU= 149.5978707e9; // Astronomical unit in m.
	double const sec_per_day= 24*60*60; // Number of second in a day.

	// The average distance is taken to be the body's semi-major axis around the sun in AU.
	double const av_distance_jupiter = 5.2;
	double const av_distance_saturn = 9.58;

	double mass_vegeta=1e13;
	double mass_soleil=1.989e30/mass_vegeta;
	double mass_jupiter=1.898e27/mass_vegeta;
	double mass_saturne=5.683e26/mass_vegeta;

	double real_mass_soleil=1.989e30;
	double real_mass_jupiter=1.898e27;
	double real_mass_saturne=5.683e26;
	double real_mass_dione=1.095452e21;

	double  G = ((G_original*(pow((mass_vegeta),2)))/pow(AU,3));

	double const period = 5000; // Temps en année.
	double dt = 1.0; // Le pas de temps, c'est à dire la fraction que représente un jour par rapport à 5000 ans.

	double position_soleil_x=0;
	double position_soleil_y=0;
	double position_soleil_z=0;

	double position_jupiter_x=5.2;
	double position_jupiter_y=0;
	double position_jupiter_z=0;

	double position_saturne_x=0;
	double position_saturne_y=9.58;
	double position_saturne_z=0;

	double vitesse_soleil_x=0;
	double vitesse_soleil_y=0;
	double vitesse_soleil_z=0;

	double vitesse_jupiter_x=0;
	double vitesse_jupiter_y=((13070.0)/((AU)*sec_per_day));
	double vitesse_jupiter_z=0;

	double vitesse_saturne_x=((-9690.0)/(AU*sec_per_day));
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

	double K_0;
	double U_0;

	double zero = 0;

	K_0 = pow(f_distance(vitesse_jupiter_x, vitesse_jupiter_z, vitesse_jupiter_z,zero,zero,zero), 2) + pow(f_distance(vitesse_saturne_x, vitesse_saturne_z, vitesse_saturne_z,zero,zero,zero), 2);
	U_0 = (1/f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z) + (1/f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z)) + (1/f_distance(position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z)));

	ofstream myfile ("data.txt");

	cout << "vitesse_jupiter_y : " << pow(dt,2) << endl;
	cout << "L'energie initiale = " << K_0-U_0 << endl;

	for(int i= 1; i<=1825000; i++){//1825000

		distance_soleil_jupiter = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		distance_soleil_saturne = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		distance_jupiter_saturne = f_distance(position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);

		force1_jupiter_x = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		force1_jupiter_y = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		force1_jupiter_z = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

		force1_saturne_x = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		force1_saturne_y = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		force1_saturne_z = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);

		position_jupiter_x = position_jupiter_x + ((vitesse_jupiter_x*dt) + ((1/2)*(force1_jupiter_x/mass_jupiter)*(pow(dt,2))));
		position_jupiter_y = position_jupiter_y + ((vitesse_jupiter_y*dt) + ((1/2)*(force1_jupiter_y/mass_jupiter)*(pow(dt,2))));
		position_jupiter_z = position_jupiter_z + ((vitesse_jupiter_z*dt) + ((1/2)*(force1_jupiter_z/mass_jupiter)*(pow(dt,2))));

		position_saturne_x = position_saturne_x + ((vitesse_saturne_x*dt) + ((1/2)*(force1_saturne_x/mass_saturne)*(pow(dt,2))));
		position_saturne_y = position_saturne_y + ((vitesse_saturne_y*dt) + ((1/2)*(force1_saturne_y/mass_saturne)*(pow(dt,2))));
		position_saturne_z = position_saturne_z + ((vitesse_saturne_z*dt) + ((1/2)*(force1_saturne_z/mass_saturne)*(pow(dt,2))));

		distance_soleil_jupiter = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_jupiter_x, position_jupiter_y, position_jupiter_z);
		distance_soleil_saturne = f_distance(position_soleil_x, position_soleil_y, position_soleil_z, position_saturne_x, position_saturne_y, position_saturne_z);
		distance_jupiter_saturne = f_distance(position_jupiter_x, position_jupiter_y, position_jupiter_z, position_saturne_x, position_saturne_y, position_saturne_z);

		force2_jupiter_x = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_x, position_soleil_x, position_saturne_x, mass_jupiter, mass_soleil, mass_saturne, G);
		force2_jupiter_y = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_y, position_soleil_y, position_saturne_y, mass_jupiter, mass_soleil, mass_saturne, G);
		force2_jupiter_z = f_force(distance_soleil_jupiter, distance_jupiter_saturne, position_jupiter_z, position_soleil_z, position_saturne_z, mass_jupiter, mass_soleil, mass_saturne, G);

		force2_saturne_x = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_x, position_soleil_x, position_jupiter_x, mass_saturne, mass_soleil, mass_jupiter, G);
		force2_saturne_y = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_y, position_soleil_y, position_jupiter_y, mass_saturne, mass_soleil, mass_jupiter, G);
		force2_saturne_z = f_force(distance_soleil_saturne, distance_jupiter_saturne, position_saturne_z, position_soleil_z, position_jupiter_z, mass_saturne, mass_soleil, mass_jupiter, G);

		vitesse_jupiter_x=vitesse_jupiter_x + (1/(2*mass_jupiter))*(force1_jupiter_x+force2_jupiter_x)*dt;
		vitesse_jupiter_y=vitesse_jupiter_y + (1/(2*mass_jupiter))*(force1_jupiter_y+force2_jupiter_y)*dt;
		vitesse_jupiter_z=vitesse_jupiter_z + (1/(2*mass_jupiter))*(force1_jupiter_z+force2_jupiter_z)*dt;

		vitesse_saturne_x=vitesse_saturne_x + (1/(2*mass_saturne))*(force1_saturne_x+force2_saturne_x)*dt;
		vitesse_saturne_y=vitesse_saturne_y + (1/(2*mass_saturne))*(force1_saturne_y+force2_saturne_y)*dt;
		vitesse_saturne_z=vitesse_saturne_z + (1/(2*mass_saturne))*(force1_saturne_z+force2_saturne_z)*dt;

		K_0 = f_distance(vitesse_jupiter_x, vitesse_jupiter_z, vitesse_jupiter_z,zero,zero,zero) + f_distance(vitesse_saturne_x, vitesse_saturne_z, vitesse_saturne_z,zero,zero,zero);



		if (myfile.is_open())
		{
			myfile << position_soleil_x << " " << position_soleil_y << " " << position_soleil_z << "\n" << position_jupiter_x << " " << position_jupiter_y << " " << position_jupiter_z << "\n" << position_saturne_x << " " << position_saturne_y << " " <<position_saturne_z << "\n"

			<< "F 1 Sol " << force1_soleil_x << " " << force1_soleil_y << " " << force1_soleil_z << "\n" << "F1 J " <<force1_jupiter_x << " " << force1_jupiter_y << " " << force1_jupiter_z << "\n" << "F1 Sat " << force1_saturne_x << " " << force1_saturne_y << " " << force1_saturne_z << "\n"

			<< "F2 Sol " << force2_soleil_x << " " << force2_soleil_y << " " << force2_soleil_z << "\n" << "F2 J " <<force2_jupiter_x << " " << force2_jupiter_y << " " << force2_jupiter_z << "\n" << "F2 Sat " <<force2_saturne_x << " " << force2_saturne_y << " " << force2_saturne_z << "\n"

			<< "D Sol-J " << distance_soleil_jupiter<<"\n" << "D Sol-Sat " << distance_soleil_saturne << "\n" << "D J-Sat " << distance_jupiter_saturne << "\n"

			<< "P Sol: " << position_soleil_x << " " << position_soleil_y << " " << position_soleil_z << "\n" << "P J " <<position_jupiter_x << " " << position_jupiter_y << " " << position_jupiter_z << "\n" << "P Sat " << position_saturne_x << " " << position_saturne_y << " " <<position_saturne_z << "\n"

			<< "V Sol: " << vitesse_soleil_x << " " << vitesse_soleil_y << " " << vitesse_soleil_z << "\n" << "V J " << vitesse_jupiter_x << " " <<
			vitesse_jupiter_y << " " << vitesse_jupiter_z << "\n" << "V Sat " << vitesse_saturne_x << " " << vitesse_saturne_y << " " << vitesse_saturne_z << "\n"

			<< "E=" << K_0-U_0 << "\n";
		}
		else cout << "Unable to open file";

				/*
				1) calculer la force au temps t
				2) calculer la position au temps t+1 via x(t+1)=x(t)+v(t)dt+a(t)dt^2/2
				3) calculer la force à la position x(t+1)
				4) calculer le moment p(t+1) = p(t)+ (1/2)(F(t)+F(t+1))dt
				5) return to step 2)
				*/
/*
	cout << "Force1 Soleil: " << force1_soleil_x << " " << force1_soleil_y << " " << force1_soleil_z << "\n" << "Force Jupiter: " <<force1_jupiter_x << " " << force1_jupiter_y << " " << force1_jupiter_z << "\n" << "Force Saturne: " <<force1_saturne_x << " " << force1_saturne_y << " " << force1_saturne_z << "\n";

	cout << "Force2 Soleil: " << force2_soleil_x << " " << force2_soleil_y << " " << force2_soleil_z << "\n" << "Force Jupiter: " <<force2_jupiter_x << " " << force2_jupiter_y << " " << force2_jupiter_z << "\n" << "Force Saturne: " <<force2_saturne_x << " " << force2_saturne_y << " " << force2_saturne_z << "\n";

	cout << "Distance Soleil - Jupiter " << distance_soleil_jupiter<<"\n Distance Soleil - Saturne " << distance_soleil_saturne << "\n Distance Jupiter - Saturne" << distance_jupiter_saturne << endl;

	cout << "Position Soleil: " << position_soleil_x << " " << position_soleil_y << " " << position_soleil_z << "\n" << "position Jupiter: " <<position_jupiter_x << " " << position_jupiter_y << " " << position_jupiter_z << "\n" << "position Saturne: " << position_saturne_x << " " << position_saturne_y << " " <<position_saturne_z << "\n";

	cout << "Vitesse Soleil: " << vitesse_soleil_x << " " << vitesse_soleil_y << " " << vitesse_soleil_z << "\n" << "vitesse Jupiter: " << vitesse_jupiter_x << " " <<
	vitesse_jupiter_y << " " << vitesse_jupiter_z << "\n" << "vitesse Saturne: " << vitesse_saturne_x << " " << vitesse_saturne_y << " " << vitesse_saturne_z << "\n";

	K_0 = f_distance(vitesse_jupiter_x, vitesse_jupiter_z, vitesse_jupiter_z,zero,zero,zero) + f_distance(vitesse_saturne_x, vitesse_saturne_z, vitesse_saturne_z,zero,zero,zero);

	cout << "Energie = " << K_0-U_0 << endl;
	*/
	}

	myfile.close();

	return 0;
}
