#include <iostream>
#include <new>
#include <math.h>
#include <cmath>
using namespace std;

class body{
	public:
	double norm_mass=0;
	double init_distance=0; //from the origin
	double init_speed=0; //relative to the assumed inertial frame of the computer's memory.
	double init_position_vector[3]; //will be normalized
	double init_speed_vector[3]; //will be normalized
	double position[3];
	double moment[3];
	double force[3];
	double force2[3];
	//Constructor:
	body(double, double, double, double, double, double, double, double, double);	
	//Functions:
	void vector_normalization(double *p);
	double f_distance(double *position_1, double *position_2);
	double f_result_force(int l, int m, double *vec_distance, double G_2, body *pointeur);
	//void resulting_force();
	//void potential energy();
	//void kinetic energy();
	//double *p_position = &position[0];
	//double *p_moment = &moment[0];
	//double *p_force = &force[0];
	//double k_energy=0;
	//double pot_energy=0;
	//double total_energy=0;
	//double mass_reader(void);
	//void set_number(void);
};
/*
The body class' constructor will take the following arguments:
1) The mass of the body
2) The average distance of the body from the sun. It will be taken as the initial distance from the origin of the assumed inertial frame of the computer's memory.
3) The componants of a vector hwo points the right direction of the body's position. This vector will be normalize and then multiplied by the average distance from the sun to constitute the initial position vector.
4) The average speed of the body that we'll use as the initial speed condition.
5) The components of a second vector that we'll use as an initial unit velocity vector. This vector will be normalize and then multiplied by the average speed.
*/
body::body(double input_mass, double input_av_dist, double x, double y, double z, double input_av_speed, double velocity_x, double velocity_y, double velocity_z){
		norm_mass=input_mass;
		init_distance = input_av_dist;
		init_position_vector[0]=x;
		init_position_vector[1]=y;
		init_position_vector[2]=z;
		init_speed=input_av_speed;
		init_speed_vector[0]=velocity_x;
		init_speed_vector[1]=velocity_y;
		init_speed_vector[2]=velocity_z;
}
//Do a class function that normalizes vectors

void body::vector_normalization(double *vec){
	double norm=0;
	for(int i=0; i<3; i++){
		norm = norm + vec[i]*vec[i];
	}
	if(norm==0)
	{
		cout << "La norme du vecteur est nulle." << endl;
	}
	else
	{
		for(int i=0; i<3; i++){
		vec[i]=vec[i]/norm;
		}
	}
}

double body::f_distance(double *position_1, double *position_2){
	double distance=0;
	for(int i=0; i<3; i++){
		distance = distance + pow((position_1[i]-position_2[i]),2);
	}
	if(distance==0)
	{
		cout << "Erreur, la distance entre deux corps = 0. Division par zero." << endl;
	}
	return sqrt(distance);

}

double body::f_result_force(int l, int m, double *vec_distance, double G_2, body *body_list){
	int a;
	int b;
	int c;
	if(l==0){ //rend la force que le soleil subit
		a=0;
		b=1;
		c=2;
	}
	else if(l==1){ //rend la force que jupiter subit
		a=1;
		b=2;
		c=0;
	}
	else if(l==2){ // rend la force que saturne subit
		a=2;
		b=0;
		c=1;
	}
	return G_2*(((body_list[a].norm_mass * body_list[b].norm_mass)*(body_list[b].position[m] - body_list[a].position[m])/pow((vec_distance[a]),3)) + ((body_list[a].norm_mass * body_list[c].norm_mass)*(body_list[c].position[m] - body_list[a].position[m])/pow((vec_distance[b]),3)));
}
// Parce qu'on a toujours besoin d'un delta de dirac...
double delta_Dirac (int i, int j){
	if (i==j)
		return 1;
	else
		return 0;
}

void update_distance(double *vecteur_distance, body *body_list){
	
	int a;
	int b;
	
	for(int p=0; p<3; p++){
		if(p==0){
			a=0;
			b=1;
		}
		else if(p==1){
			a=0;
			b=2;
		}
		else{
			a=1;
			b=2;
		}
		vecteur_distance[a]=body_list[a].f_distance(&body_list[a].position[0], &body_list[b].position[0]);
	}
}

int main (){

	double const G = 6.67408e-11;
	double const AU= 149597870700; // Astronomical unit in m.
	double const n_sec_jrs= 24*60*60; // Number of second in a day.
	
	double const masses[3]={1.989e30, 1.898e27, 5.683e26}; // The mass of each body. In the following order: Sun, Jupiter, Saturn
	double const mass_dione=1.095452e21;
	//double const norm_masses[3]={1.989e30/1.095452e21, 1.898e27/1.095452e21, 5.683e26/1.095452e21};
	double const norm_masses[3]={1.989e30, 1.898e27, 5.683e26};
	// La constante gravitationnelle doit être modifié de manière à ce que les masse soit comptée en (masse solaire * 10^9) (pour avoir des moments de l'ordre de l'unité)
	double const converted_G = G * pow((AU/1.989e30),2);
    double const period = 5000; // Temps en année.
	double const dt = 1; // Le pas de temps, c'est à dire la fraction que représente un jour par rapport à 5000 ans.
	int const N_body=3; // The number of body in the problem

	// The average distance is taken to be the body's semi-major axis around the sun in AU.
	double const av_distance_sun = 0; //by definition
	double const av_distance_jupiter = 5.2*AU;
	double const av_distance_saturn = 9.58*AU;

    // The average speeds are values in km/s multiplied/converted in AU/day. 1km/s = 24*60*60/149597870.700 ~ 5.775e-4 AU/jrs
	double const convertor = n_sec_jrs/(AU*(1e-3)); // le nombre par lequel on multiplie les km/s pour passer en UA/j.
	double const av_speed_sun=0;//by definition
	double const av_speed_jupiter=13.07e3;
	double const av_speed_saturn=9.69e3;

	// Choose random radius vector. It will be normalized and then multiply by the average distance of the body from the origin to locate it at t=0. It is suppose to be a realistic initial condition for the position.
	double position_sun[3]={0,0,0};
	double position_jupiter[3]={1,0,0};
	double position_saturn[3]={0,1,0};

	// Choose random velocity vector. It will be normalized and then multiply by the average velocity of the body at t=0. It is suppose to make a realistic initial condition...
	double velocity_sun[3]={0,0,0};
	double velocity_jupiter[3]={0,1,0};
	double velocity_saturn[3]={-1,0,0};

	double vecteur_distance[3];//vecteur_distance[0]=dist(sun,jupiter), vecteur_distance[1]=dist(sun,saturn), vecteur_distance[2]=dist(jupiter,saturn)
	double matrice_force[3][3];

	// The body's construcors arguments: (double input_mass, double input_av_dist, double x, double y, double z, double input_av_speed, double velocity_x, double velocity_y, double velocity_z)

	// The sun's constructor:
	body sun(norm_masses[0],av_distance_sun, position_sun[0], position_sun[1], position_sun[2], av_speed_sun, velocity_sun[0], velocity_sun[1], velocity_sun[2]);

	// Jupiter's constructor:
	body jupiter(norm_masses[1], av_distance_jupiter, position_jupiter[0], position_jupiter[1], position_jupiter[2], av_speed_jupiter, velocity_jupiter[0], velocity_jupiter[1], velocity_jupiter[2]);

	// Saturn's constructor:
	body saturn(norm_masses[2],av_distance_saturn, position_saturn[0], position_saturn[1], position_saturn[2], av_speed_saturn, velocity_saturn[0], velocity_saturn[1],velocity_saturn[2] );

	//We make a list of all the bodies
	body body_list[3]={sun, jupiter, saturn};

	//Now the initial conditions. We normalize the initial position and initial velocity vectors of each body. Then we multiply the normalized position vectors by the average distance of the body from the sun, and multiply the unit speed vector by the average velocity of the body around the sun.

	for(int i=0; i<3; i++){
		// la boucle parcours la liste des body. La fonction vector_normalization agit d'elle même sur les composantes des vecteurs à normaliser.
		body_list[i].vector_normalization(&body_list[i].init_position_vector[0]);
		body_list[i].vector_normalization(&body_list[i].init_speed_vector[0]);
		
	}
	
	//We must multiply each components of the initial unit position vectors by the average distance of the body. NB: les composantes du vecteur unité sont les cosinus directeur. We must multiply each components of the initial unit velocity vector by the average speed of the body. NB: les composantes du vecteur unité sont les cosinus directeur. ET les moments sont normalisés à la masse du soleil.

	for(int i; i<3; i++){
		for(int j=0; j<3; j++){
			body_list[i].position[j]=(body_list[i].init_position_vector[j])*(body_list[i].init_distance);
			body_list[i].moment[j]=(body_list[i].init_speed_vector[j])*(body_list[i].init_speed)*(body_list[i].norm_mass);
        }
	}
	
	/*
		Les deux boucles suivantes affichent à l'écran les valeurs initiales des vecteurs position et vitesse.
        
		for(int k = 0; k<3; k++){
            cout << "position du corp " << i << ", x_" << k << " = " << body_list[i].position[k] << endl;
        }
        for(int k = 0; k<3; k++){
            cout << "Moment du corp " << i << ", m_" << k << " = " << body_list[i].moment[k] << endl;
        }
		

	
	*/
	//int a;
	//cout << "The size of int a is " << sizeof(a) << " bytes. Or " << sizeof(a)*8 << " bits."<< endl;
	

	for(int i= 1; i<=1825000; i++){

		// à chaque itération, calcul des distances entre chaque corps.
		// Peut-être optimisé car la matrice est symétrique à diagonale 0.

		update_distance(&vecteur_distance[0], &body_list[0]);
		
		for(int l=0; l<3; l++){
			for(int m=0; m<3;m++){
				//les "m" composantes de la ligne "l" sont les résultantes des forces appliquées au corp "l" (sun=0, jupiter=1, saturn=2)
				//Si m=0 calcul la composante de la force selon x, si m=1:y, si m=2:z.
				body_list[l].force[m]=body_list[l].f_result_force(l, m, &vecteur_distance[0], G, &body_list[0]);
				body_list[l].position[m]=(body_list[l].moment[m]/body_list[l].norm_mass)*dt + (body_list[l].force[m]/body_list[l].norm_mass)*(pow(dt,2)/2);
				cout << body_list[l].position[m] << endl;
				/*
				1) calculer la force au temps t
				2) calculer la position au temps t+1 via x(t+1)=x(t)+v(t)dt+a(t)dt^2/2
				3) calculer la force à la position x(t+1)
				4) calculer le moment p(t+1) = p(t)+ (1/2)(F(t)+F(t+1))dt
				5) return to step 2)

				*/
			}
		}
		update_distance(&vecteur_distance[0], &body_list[0]);
		for(int l=0; l<3; l++){
			for(int m=0; m<3;m++){
				//les "m" composantes de la ligne "l" sont les résultantes des forces appliquées au corp "l" (sun=0, jupiter=1, saturn=2)
				//Si m=0 calcul la composante de la force selon x, si m=1:y, si m=2:z.
				body_list[l].force2[m]=body_list[l].f_result_force(l, m, &vecteur_distance[0], G, &body_list[0]);
				body_list[l].moment[m]=(body_list[l].moment[m]) + (body_list[l].force[m]+body_list[l].force2[m])*(dt/2);
				/*
				1) calculer la force au temps t
				2) calculer la position au temps t+1 via x(t+1)=x(t)+v(t)dt+a(t)dt^2/2
				3) calculer la force à la position x(t+1)
				4) calculer le moment p(t+1) = p(t)+ (1/2)(F(t)+F(t+1))dt
				5) return to step 2)

				*/
			}
		}

    }
	

	return 0;
}
