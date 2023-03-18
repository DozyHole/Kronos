#include "KrVec3.h"

namespace Kronos
{
    class KrBounds3
    {
    public:
        KrVec3 _min, _max;
        
        KrBounds3(const KrVec3& min, const KrVec3& max) : _min(min), _max(max){}
        KrBounds3(){
            _min._x = rand()%500;
            _min._y = rand()%500;
            _min._t = rand()%500;
            _max._x = _min._x + rand()%500;
            _max._y = _min._y + rand()%500;
            _max._t = _min._t + rand()%500;
        }

        bool Overlap(const KrBounds3& other) const {
            return 
                _max._x >= other._min._x && other._max._x >= _min._x && 
                _max._y >= other._min._y && other._max._y >= _min._y && 
                _max._t >= other._min._t && other._max._t >= _min._t;
        }
    };
}