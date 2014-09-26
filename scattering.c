#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "func.h"

#define PI 3.141592653589793
#define Na 6.022141e23

int main(int argc, char **argv) {

//initial parameters_______________________________________________________________
	srand(time(NULL));
	//beam parameters
	double E0 = atof(argv[1]);
	double dE = atof(argv[2]);
	//target parameters
	int Z = atoi(argv[3]);
	int A = atoi(argv[4]);
	double density = atof(argv[5]); 
	//target geometry
	double L = atof(argv[6]);
	double R = atof (argv[7]);	
	
	printf("scat_position  E_incident  E_at_vertex  E_exit  scat_angle  psi_angle \n");

//scattering simmulation for 1 event_______________________________________________	
	double E = p_energy(E0,dE);
	double cs = cross_section(E,Z);
	double pass_before = travel_distance(A, density, cs);
	double phi = scattering_angle(E, Z);
	double psi = psi_angle();	

	//checking if there is a scattering inside the target	
	if (pass_before > L) printf("particle wasn't scattered in the target");	
	
	//the pass after the collision
	double d = R*cos(phi)/sin(phi);
	double pass_after;
	if (d < (L-pass_before)) {
		pass_after = R/sin(phi); 
	}
	else {
		pass_after = (L-pass_before)/cos(phi);
	}
	
	//the energies at vertex and at exit 
	double E_vertex = E - energy_loss(density, E, Z, A)*pass_before;
	double E_exit = E_vertex - energy_loss(density, E_vertex, Z, A)*pass_after;  

	printf("%10e %10e %10e %10e %10e %10e \n", pass_before, E , E_vertex, E_exit, phi, psi);

return 0;

}

