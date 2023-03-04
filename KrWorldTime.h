#ifndef INCLUDE_KRWORLDTIME_H
#define INCLUDE_KRWORLDTIME_H
#include <chrono>

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

    double Get();
    void Tick(const double dt);
    void Output();
    double Get(unsigned int year, unsigned int day, unsigned int hour, unsigned int seconds);
    void OutputInfo();
};

#endif