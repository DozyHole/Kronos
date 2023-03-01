//#include "KrWorldTime.h"
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
    
    // using second = std::chrono::duration<double, std::ratio<SECOND, 1>>; 
    // using hour = std::chrono::duration<double, std::ratio<second::period::num * HOUR, 1>>;  
    // using day = std::chrono::duration<double, std::ratio<hour::period::num * DAY, 1>>;
    // using year = std::chrono::duration<double, std::ratio<day::period::num * YEAR, 1>>;

    using second = std::chrono::duration<long long, std::ratio<SECOND>>;
    using hour = std::chrono::duration<long long, std::ratio<second::period::num * HOUR>>;
    using day = std::chrono::duration<long long, std::ratio<hour::period::num * DAY>>;
    using year = std::chrono::duration<long long, std::ratio<day::period::num * YEAR>>;

    //double t = 0.0;
    //std::chrono::time_point<std::chrono::system_clock/*, std::chrono::system_clock::duration*/> tp = {};
    std::chrono::time_point<Clock> tp = {};
  

    const double Get(){
        //return t;
        return 0.0;
    }

    long long Get(unsigned int y, unsigned int d, unsigned int h, unsigned int sec, unsigned int ms){
        // double seconds = (second(1ms).count()*sec);// % HOUR;
        // double hours = (hour(1ms).count()*h);// % DAY;
        // double days = (day(1ms).count()*d);// % YEAR;
        // double years = (year(1ms).count()*y);
        // return (years + days + hours + seconds);

        // auto tpcHours = std::chrono::time_point_cast<hour>(tp);
        // auto tpcSeconds = std::chrono::time_point_cast<second>(tp);
        // auto tpcDays = std::chrono::time_point_cast<day>(tp);
        // auto tpcYears = std::chrono::time_point_cast<year>(tp);
        std::chrono::time_point<Clock> t;
        t += year(y);
        t += day(d);
        t += hour(h);
        t += second(sec);
        t += std::chrono::milliseconds(ms);
        return t.time_since_epoch().count();
    }

    void Tick(const double dt){
        long long ms = dt*1000;
        //std::chrono::microseconds(dt);
        tp += std::chrono::microseconds{ms};
        //tp += std::chrono::milliseconds{dt};
        //t+=dt;
    }

    const void Check(){
        //std::cout << t << std::endl;

        // unsigned int tRounded = std::round(t);
        // unsigned int seconds = (unsigned int)(second(1ms).count()*tRounded) % HOUR;
        // unsigned int hours = (unsigned int)(hour(1ms).count()*tRounded) % DAY;
        // unsigned int days = (unsigned int)(day(1ms).count()*tRounded) % YEAR;
        // unsigned int years = (unsigned int)(year(1ms).count()*tRounded);
        // std::cout << years << ":" << days << ":" << hours << ":" << seconds << " " << std::flush; 

        // std::cout << std::endl;
        // double time = Get(years, days, hours, seconds);
        // std::cout << time << std::endl << std::endl;
    }

    const void Output(){
        
        // unsigned int tRounded = std::round(t);
        // unsigned int seconds = (unsigned int)(second(1ms).count()*tRounded) % HOUR;
        // unsigned int hours = (unsigned int)(hour(1ms).count()*tRounded) % DAY;
        // unsigned int days = (unsigned int)(day(1ms).count()*tRounded) % YEAR;
        // unsigned int years = (unsigned int)(year(1ms).count()*tRounded);
        // std::cout << years << ":" << days << ":" << hours << ":" << seconds << " " << std::flush; 

        // to do - test with integrals?
        //auto tpcSeconds = std::chrono::time_point_cast<second>(tp);
        //auto tpcHours = std::chrono::time_point_cast<hour>(tp);
        //std::cout << "s:" << tpcSeconds.time_since_epoch().count() << " ";
        //std::cout << "h:" << tpcHours.time_since_epoch().count() << std::endl;

        auto tpcMilliSeconds = std::chrono::time_point_cast<std::chrono::milliseconds>(tp);
        auto tpcSeconds = std::chrono::time_point_cast<second>(tp);
        auto tpcHours = std::chrono::time_point_cast<hour>(tp);
        auto tpcDays = std::chrono::time_point_cast<day>(tp);
        auto tpcYears = std::chrono::time_point_cast<year>(tp);

        auto y = tpcYears.time_since_epoch().count();
        auto d = tpcDays.time_since_epoch().count()%YEAR;
        auto h = tpcHours.time_since_epoch().count()%DAY;
        auto s = tpcSeconds.time_since_epoch().count()%HOUR;
        auto ms = tpcMilliSeconds.time_since_epoch().count()%100;
        

        std::cout << "y:" << y << " ";
        std::cout << "d:" << d << " ";
        std::cout << "h:" << h << " ";
        std::cout << "s:" << s << " ";
        std::cout << "ms:" << ms << std::endl;

        std::cout << tp.time_since_epoch().count() << std::endl;
        std::cout << Get(y, d, h, s, ms) << std::endl;

        // sample
        // auto t1 = std::chrono::system_clock::now();
        // auto t2 = t1 + std::chrono::milliseconds(400);  //std::chrono::high_resolution_clock::now();
        // // floating-point duration: no duration_cast needed
        // std::chrono::duration<double, std::milli> fp_ms = t2 - t1; 
        // // integral duration: requires duration_cast
        // auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - tp);
        // //std::cout << std::endl;
        // std::cout << int_ms.count() << std::endl;

        //std::cout << "tp: " << tp.time_since_epoch().count() << std::endl;
    }

    const void OutputInfo(){
        // std::cout << 1.0 / year(1ms).count() << " real milliseconds per game year" << std::endl;
        // std::cout << 1.0 / year(1s).count() << " real seconds per game year" << std::endl;
        // std::cout << 1.0 / year(1min).count() << " real minutes per game year" << std::endl;
        // std::cout << 1.0 / year(1h).count() << " real hours per game year" << std::endl;
    }
}