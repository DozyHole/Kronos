#include "KrWorldTime.h"
#include <cmath>

namespace Kronos
{
    class KrVec3
    {
    public:
        float _x, _y, _t;

        KrVec3() : _x(0.f), _y(0.f), _t(0.f) {}
        KrVec3(float x, float y, float t) : _x(x), _y(y), _t(t){}
        KrVec3(float x, float y, KrWorldTime::TimePoint t) : _x(x), _y(y), _t(std::chrono::time_point_cast<KrWorldTime::dur_second>(t).time_since_epoch().count()){}
        
        float Dist(const KrVec3& other){
            return sqrt(_x*_x + _y*_y + _t*_t);
        }

        float DistSq(const KrVec3& other){
            return _x*_x + _y*_y + _t*_t;
        }
    };
}