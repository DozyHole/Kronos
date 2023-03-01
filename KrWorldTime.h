#ifndef INCLUDE_KRWORLDTIME_H

namespace Kronos::KrWorldTime
{
    const double Get();
    void Tick(const double dt);
    const void Output();
    const void Check();
    const double Get(unsigned int year, unsigned int day, unsigned int hour, unsigned int seconds);
    const void OutputInfo();
};

#endif