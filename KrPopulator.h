#include <vector>
#include <memory>
#include "KrWorldTime.h"
#include <iostream>

using namespace std;

namespace Kronos
{
    class KrPopulator
    {
    public:
        KrPopulator(KrWorldTime::TimePoint tSpawn);

        // spawn time relative to parent?
        std::shared_ptr<KrPopulator> AddChild(const KrWorldTime::TimePoint& tBirth);

    private:
        std::vector<std::shared_ptr<KrPopulator>> _children;
        KrWorldTime::TimePoint _tSpawned;
        // did this entity ever exist in time? Maybe not if parent has been removed before spawn time
        bool _didExist;
    };

};