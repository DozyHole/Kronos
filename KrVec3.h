#include "KrWorldTime.h"
#include <cmath>

namespace Kronos
{
    class KrVec3
    {
    public:
        float _x, _y, _t;

        KrVec3(float x, float y, float t) : _x(x), _y(y), _t(t){}
        KrVec3(float x, float y, KrWorldTime::TimePoint t) : _x(x), _y(y), _t(std::chrono::time_point_cast<KrWorldTime::dur_second>(t).time_since_epoch().count()){}
        
        float dist(const KrVec3& other){
            return sqrt(_x*_x + _y*_y + _t*_t);
        }

        float distSq(const KrVec3& other){
            return _x*_x + _y*_y + _t*_t;
        }
    };

    class KrBounds3
    {
    public:
        KrBounds3(const KrVec3& min, const KrVec3& max) : _min(min), _max(max){}
        KrVec3 _min, _max;
    };

}