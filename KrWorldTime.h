#ifndef INCLUDE_KRWORLDTIME_H
#define INCLUDE_KRWORLDTIME_H
#include <chrono>

namespace Kronos::KrWorldTime
{
    using Clock = std::chrono::steady_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    // morning / afternoon / evening
    // 8mins   / 8mins     / 8mins          -> 24 mins per day (1 hour == 1 minute)
    // 12 days a year

    const short SECOND  = 1;        // 1 second is 1 second
    const short HOUR    = 60;       // 1 hour is 60 seconds
    const short DAY     = 24;       // 1 day is 24 hours
    const short YEAR    = 12;       // 1 year is 12 days 

    using dur_second    = std::chrono::duration<long long, std::ratio<SECOND>>;
    using dur_hour      = std::chrono::duration<long long, std::ratio<dur_second::period::num * HOUR>>;
    using dur_day       = std::chrono::duration<long long, std::ratio<dur_hour::period::num * DAY>>;
    using dur_year      = std::chrono::duration<long long, std::ratio<dur_day::period::num * YEAR>>;

    std::chrono::time_point<Clock> GetTimePoint(unsigned int years, unsigned int days, unsigned int hours, unsigned int seconds);
    double  Get();
    void    Tick(const double dt);
    double  Get(unsigned int year, unsigned int day, unsigned int hour, unsigned int seconds);
    void    Output();
    void    OutputInfo();
};

#endif