#include <iostream>
#include <new>
using namespace std;


class body{
	private:
	int number;
	double mass=0;
	
	double init_distance=0; //from the origin
	double initial_speed=0; //relative to the assumed inertial frame of the computer's memory.
	
	double init_position_vector[3]; //will be normalized
	double init_speed_vector[3]; //will be normalized
	
	double norm_mass=0;
	
	double position[3];
	double moment[3];
	double force[3];
	
	double *p_position = &position[0];
	double *p_moment = &moment[0];
	double *p_force = &force[0];
	
	public:
	double mass_reader(void);
	void set_number(void);
	void vector_normalization(void);
	void resulting_force();
	
};

/*

The body class' constructor will take the following arguments:
1) The mass of the body
2) The average distance of the body from the sun. It will be taken as the initial distance from the origin of the assumed inertial frame of the computer's memory.
3) The componants of a vector hwo points the right direction of the body's position. This vector will be normalize and then multiplied by the average distance from the sun to constitute the initial position vector.
4) The average speed of the body that we'll use as the initial speed condition. 
5) The components of a second vector that we'll use as an initial unit velocity vector. This vector will be normalize and then multiplied by the average speed.

*/
void body::body(double input_mass, double input_av_dist, double x, double y, double z, double input_av_speed, double velocity_x, double velocity_y, double velocity_z){
		mass=input_mass;
		init_distance = input_av_dist;
		init_position_vector[0]=x;
		init_position_vector[1]=y;
		init_position_vector[2]=z;
		initial_speed=input_av_speed;
		init_speed_vector[0]=velocity_x;
		init_speed_vector[1]=velocity_y;
		init_speed_vector[2]=velocity_z;
}

//Do a class finction that normalizes vectors

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

void set_number(body *list_body){
	for(int i=1; i<=N_body; i++)
	{
		list_body[i].number=i;
	}
}

double body::mass_reader(void){
	return mass;
}







//normalization to the heaviest body in the problem.

int main ()
{
  int N_body=3;
  double masses[3]={1.989e30, 1.898e27, 5.683e26};
  double AU= 149597870700;
  double n_sec_jrs= 24*60*60;
  
  // the average distance is taken to be the body's semi-major axis around the sun in AU.
  double av_distance_sun = 0; //by definition
  double av_distance_jupiter = 5.2;
  double av_distance_saturn = 9.58; 
  
  // The average speeds are values in km/s multiplied/converted in AU/day. 1km/s = 24*60*60/149597870700 ~ 5.775e-7 AU/jrs
  double av_speed_sun=0;//by definition
  double av_speed_jupiter=13.07*5.775e-7;
  double av_speed_saturn=9.69*5.775e-7;
  
  double position_sun[3]={0,0,0};
  double position_jupiter[3]={1,0,0};
  double position_saturn[3]={0,1,0};
  
  double velocity_sun[3]={0,0,0};
  double velocity_jupiter[3]={0,1,0};
  double velocity_saturn[3]={-1,0,0};
  
  // The body's construcors with arguments: (double input_mass, double input_av_dist, double x, double y, double z, double input_av_speed, double velocity_x, double velocity_y, double velocity_z)
  body sun(masses[0],av_distance_sun,position_sun[0],position_sun[1],position_sun[2], av_speed_sun, velocity_sun[0], velocity_sun[1], velocity_sun[2]);
  body jupiter(masses[1], av_distance_jupiter, position_jupiter[0], position_jupiter[1], position_jupiter[2], av_speed_jupiter, velocity_jupiter[0], velocity_jupiter[1], velocity_jupiter[2]);
  body saturn(masses[2],av_distance_saturn, position_saturn[0], position_saturn[1], position_saturn[2], av_speed_saturn,velocity_saturn[0], velocity_saturn[1],velocity_saturn[2] );
  
  body * p_list; // pointer to class body.
  
  return 0;
}