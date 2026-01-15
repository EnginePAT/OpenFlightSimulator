#include <VectorPhysics/Atmosphere.hpp>


namespace VectorPhysics
{

double Atmosphere::getAirDensity(double altitude)
{
    return 1.225 * std::exp(-altitude / 8500);
}

double Atmosphere::getTemperature(double altitude)
{
    // TODO: Add logic for calculating temperature at altitude
    return 0;       // Dummy function - return 0 for now.
}

};
