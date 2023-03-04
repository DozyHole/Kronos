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
        KrPopulator(chrono::time_point<KrWorldTime::Clock> tSpawn) : _tSpawned(tSpawn){
            std::cout << _tSpawned.time_since_epoch().count() << std::endl;
        };

        // spawn time relative to parent?
        std::shared_ptr<KrPopulator> AddChild(const chrono::time_point<KrWorldTime::Clock>& tSpawn){
            // time_point - time_point = duration
            // time_point + duration = time_point
            // duration + duration = duration
            // time_point + time_point = NOT ALLOWED
            auto child = std::make_shared<KrPopulator>(_tSpawned + tSpawn.time_since_epoch());
            //std::cout << child->_tSpawned.time_since_epoch().count() << std::endl;
            _children.push_back(child);
            return child;
        }

        std::vector<std::shared_ptr<KrPopulator>> _children;
        std::chrono::time_point<KrWorldTime::Clock> _tSpawned;
    };

};