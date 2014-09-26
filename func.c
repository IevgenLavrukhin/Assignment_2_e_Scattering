#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "func.h"

#define PI 3.141592653589793
#define Na 6.022141e23

double gaus_rand() {
	double x1 = rand()/(double) RAND_MAX;
	double x2 = rand()/(double) RAND_MAX;
	return sqrt(-2*log(x1))*cos(2*PI*x2);
}

double p_energy(double E, double dE) {
	return E*(1+dE*gaus_rand());
}

double cross_section (double E, int Z) {
	double a = 3.4e-3 * pow(Z, 0.67)/E;
	double p1 = 5.21e-21*Z*Z/(E*E);
	double p2 = 4*PI/(a*(a+1));
	double p3 = pow((E+511)/(E+1024),2);

	return p1*p2*p3;
}

double travel_distance (int A, double d, double cs) {
	double l = A/(Na*d*cs);
	return -l*log(rand()/(double) RAND_MAX);
}

double scattering_angle(double E, int Z) {
	double a = 3.4e-3 * pow(Z, 0.67)/E;
	double rnd = rand()/(double) RAND_MAX;
	return acos(1 - 2*a*rnd/(1 + a - rnd));
}

double psi_angle () {
	return 2*PI*rand()/(double) RAND_MAX;
}


double energy_loss (double ro, double E, int Z, int A) {
	double J = (9.76*Z + 58.5/pow(Z,0.19))*0.001; //keV
	return 78500*ro*Z*log10(1.166*E/J +1)/(A*E); //keV/cm
}
















