#ifndef INCLUDE_KRWORLDTIME_H

namespace Kronos::KrWorldTime
{
    const double Get();
    void Tick(const double dt);
    const void Output();
    const void OutputInfo();
};

#endif