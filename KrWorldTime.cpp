#include "KrWorldTime.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std::chrono_literals;

namespace Kronos::KrWorldTime
{
    using Clock = std::chrono::steady_clock;

    // morning / afternoon / evening
    // 8mins   / 8mins     / 8mins          -> 24 mins per day (1 hour == 1 minute)
    // 12 days a year

    const short SECOND = 1;     // 1 second is 1 second
    const short HOUR = 60;      // 1 hour is 60 seconds
    const short DAY = 24;       // 1 day is 24 hours
    const short YEAR = 12;      // 1 year is 12 days 

    using second = std::chrono::duration<long long, std::ratio<SECOND>>;
    using hour = std::chrono::duration<long long, std::ratio<second::period::num * HOUR>>;
    using day = std::chrono::duration<long long, std::ratio<hour::period::num * DAY>>;
    using year = std::chrono::duration<long long, std::ratio<day::period::num * YEAR>>;

    std::chrono::time_point<Clock> tp = {};
  
    const double Get(){
        return tp.time_since_epoch().count();
    }

    long long Get(unsigned int y, unsigned int d, unsigned int h, unsigned int sec, unsigned int ms){
        std::chrono::time_point<Clock> t;
        t += year(y) + day(d) + hour(h) + second(sec) + std::chrono::milliseconds(ms);
        return t.time_since_epoch().count();
    }

    void Tick(const double dt){
        long long ms = dt*1000;
        tp += std::chrono::microseconds{ms};
    }

    const void Output(){
        auto tpcMilliSeconds = std::chrono::time_point_cast<std::chrono::milliseconds>(tp);
        auto tpcSeconds = std::chrono::time_point_cast<second>(tp);
        auto tpcHours = std::chrono::time_point_cast<hour>(tp);
        auto tpcDays = std::chrono::time_point_cast<day>(tp);
        auto tpcYears = std::chrono::time_point_cast<year>(tp);

        auto y = tpcYears.time_since_epoch().count();
        auto d = tpcDays.time_since_epoch().count()%YEAR;
        auto h = tpcHours.time_since_epoch().count()%DAY;
        auto s = tpcSeconds.time_since_epoch().count()%HOUR;
        auto cs = (tpcMilliSeconds.time_since_epoch().count()%1000) / 10;  // 100th of a second
        
        std::cout << y << ":";
        std::cout << d << ":";
        std::cout << h << ":";
        std::cout << s << "::";
        std::cout << cs << std::endl;
    }

    const void OutputInfo(){
        auto gameHourToRealMinutes = std::chrono::duration_cast<std::chrono::minutes>(hour(1));
        std::cout << "1 game Hour: " << gameHourToRealMinutes.count() << " minutes" << std::endl;

        auto gameDaysToRealMinutes = std::chrono::duration_cast<std::chrono::minutes>(day(1));
        std::cout << "1 game Day: " << gameDaysToRealMinutes.count() << " minutes" << std::endl;

        auto gameYearsToRealMinutes = std::chrono::duration_cast<std::chrono::minutes>(year(1));
        std::cout << "1 game Year: " << gameYearsToRealMinutes.count() << " minutes" << std::endl;
    }
}