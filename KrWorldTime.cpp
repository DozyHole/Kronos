//#include "KrWorldTime.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std::chrono_literals;

namespace Kronos::KrWorldTime
{
    // morning / afternoon / evening
    // 8mins   / 8mins     / 8mins          -> 24 mins per day (1 hour == 1 minute)
    // 12 days a year

    const short SECOND = 1;     // 1 second is 1 second
    const short HOUR = 60;      // 1 hour is 60 seconds
    const short DAY = 24;       // 1 day is 24 hours
    const short YEAR = 12;      // 1 year is 12 days 

    using second = std::chrono::duration<double, std::ratio<SECOND, 1>>; 
    using hour = std::chrono::duration<double, std::ratio<second::period::num * HOUR, 1>>;  
    using day = std::chrono::duration<double, std::ratio<hour::period::num * DAY, 1>>;
    using year = std::chrono::duration<double, std::ratio<day::period::num * YEAR, 1>>;

    double t = 0.0;

    const double Get(){
        return t;
    }

    void Tick(const double dt){
        t+=dt;
    }

    const void Output(){
        unsigned int tRounded = std::round(t);
        unsigned int seconds = (unsigned int)(second(1ms).count()*tRounded) % HOUR;
        unsigned int hours = (unsigned int)(hour(1ms).count()*t) % DAY;
        unsigned int days = (unsigned int)(day(1ms).count()*t) % YEAR;
        unsigned int years = (unsigned int)(year(1ms).count()*t);
        std::cout << years << ":" << days << ":" << hours << ":" << seconds << " " << std::flush; 
    }

    const void OutputInfo(){
        std::cout << 1.0 / year(1ms).count() << " real milliseconds per game year" << std::endl;
        std::cout << 1.0 / year(1s).count() << " real seconds per game year" << std::endl;
        std::cout << 1.0 / year(1min).count() << " real minutes per game year" << std::endl;
        std::cout << 1.0 / year(1h).count() << " real hours per game year" << std::endl;
    }
}