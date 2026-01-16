#ifndef AIRCRAFTFORCES_HPP
#define AIRCRAFTFORCES_HPP


#include <cmath>
#include <glm/glm.hpp>


class AircraftForces
{
public:
    double lift;
    double wingArea;
    double Clift;

    static double getDrag(double rho, glm::vec3 velocity, double refA, double Cd, double Cl, double wingspan, double e);
    static double getLift(double rho, glm::vec3 velocity, double wingA, double Cl);
};


#endif          // AIRCRAFTFORCES_HPP
