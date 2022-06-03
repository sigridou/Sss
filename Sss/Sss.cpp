// Sss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <vector>
#define PI 3.14159265
#include <math.h>



class Point {
public:
	double x, y, z,vl,va;

	Point(double x, double y, double z,double vl,double va) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->vl = vl;
		this->va = va;

	};
};


class Pss {
public:
	int np, nh, d;
	double tmin, tmax, zmin, zmax;

	Pss(int np, int nh, int d, double tmin, double tmax, double zmin, double zmax) {

		this->np = np;
		this->nh = nh;
		this->d = d;
		this->tmin = tmin;
		this->tmax = tmax;
		this->zmin = zmin;
		this->zmax = zmax;


	};
};








int main(int argc, char* argv[]) {

	int np, nh, j, d;
		double tmin, tmax, t, zmin, zmax;
		double xf, yf;
	double zf;
	double cx; 
	double cz;
	double cy;
	np = 4;
	nh = 3;
	d = 2;
	tmin = -45*(PI/180);
	tmax = 45* (PI / 180);
	zmin = -45* (PI / 180);
	zmax = 45* (PI / 180);
	Point p(0, 0, 0,0,0);
	Point v[4][4]=  { {p,p,p,p},{p,p,p,p},{p,p,p,p},{p,p,p,p} };
	std::vector < std::vector <Point> > vt;
	std::vector<double> X;
	std::vector<double> Y;

	int i = 0;
	j = 0;

	
 	for (i = 0; i <= np - 1; i++)
	{
		xf = 0;
		yf = 0;
		zf = 45 * (PI / 180);;
		cx = 0;
		cy = 0;
		cz = 45*(PI/180);
		printf("%f, %f, %f  test\n", cx, cy, cz);
		for (j = 0; j <= nh - 1; j++)
		{



			t = tmin + (((tmax - tmin) * i) / (np - 1));
			cx = xf;
			cy = yf;
			cz = zf;

			xf = cx + d * (cos((t + cz)));
			yf = cy + d * (sin((t + cz)));
			if (j == 0)
			{
				zf = cz + zmin;

				v[i][j].x = 0;
				v[i][j].y = 0;
				v[i][j].z = 45 * (PI / 180);
				v[i][j].vl = 0;
				v[i][j].va = 0;
				//X[j] = 0;
				//Y[j] = 0;

			}
			else
			{
				zf = cz + zmin + (((zmax - zmin) * j) / (nh - 1)) + t;
			}



			v[i][j].x = xf;
			v[i][j].y = yf;
			v[i][j].z = zf;
			v[i][j].vl = 0;
			v[i][j].va = 0;
			//X[j] = xf;
			//Y[j] = yf;
			printf("%f , %f, %f", v[i][j].x, v[i][j].y, v[i][j].z);
			printf("\n");

		}
		printf("\n");
	}









	return 0;
}













