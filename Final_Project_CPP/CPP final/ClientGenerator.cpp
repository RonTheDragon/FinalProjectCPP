#include "ClientGenerator.hpp"

#include <iomanip>
#include <sstream>

/* Intake time bounds */
#define MAX_MINUTE 59
#define MIN_MINUTE 0
#define MAX_HOUR 23
#define MIN_HOUR 0

/* Protein absorbed bounds */
#define MAX_ABSORB 150.0f
#define MIN_ABSORB 50.0f
 
/* Protein intake bounds */
#define MAX_INTAKE 1.2f
#define MIN_INTAKE 0.8f

/* Weight bounds */
#define MAX_WEIGHT 100.0f
#define MIN_WEIGHT 50.0f

/* Activity level bounds */
#define MAX_ACTIVITY 3
#define MIN_ACTIVITY 1

/* Utility function---------------------------------------------------------- */
/* NOTE: This function makes the generate function more readable */

std::string generate_random_time(std::mt19937& gen)
{
    std::uniform_int_distribution<int> minute_dist{ MIN_MINUTE, MAX_MINUTE };
    std::uniform_int_distribution<int> hour_dist{ MIN_HOUR, MAX_HOUR };
    
    /* Read random time into a string stream in HH:MM format */
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour_dist(gen);
    oss << ":" << std::setw(2) << minute_dist(gen);

    /* Convert the string stream to a string and return */
    return oss.str();
}

/* Member function implementation-------------------------------------------- */

ClientData ClientGenerator::generate(const std::string& name)
{
    std::uniform_real_distribution<float> absorb_dist{ MIN_ABSORB, MAX_ABSORB };
    std::uniform_real_distribution<float> intake_dist{ MIN_INTAKE, MAX_INTAKE };
    std::uniform_real_distribution<float> weight_dist{ MIN_WEIGHT, MAX_WEIGHT };
    std::uniform_int_distribution<int> activity_dist{ MIN_ACTIVITY , MAX_ACTIVITY };

    ClientData client{
        name,
        absorb_dist(m_engine),
        intake_dist(m_engine),
        generate_random_time(m_engine),
        weight_dist(m_engine),
        activity_dist(m_engine)
    };

    return client;
}