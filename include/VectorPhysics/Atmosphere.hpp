#ifndef ATMOSPHERE_HPP
#define ATMOSPHERE_HPP


#include <cmath>


namespace VectorPhysics
{

class Atmosphere
{
public:
    static double getAirDensity(double altitude);
    static double getTemperature(double altitude);
};

};


#endif      // ATMOSPHERE_HPP
