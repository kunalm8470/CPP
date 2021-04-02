#include "constants.h"

/*
    const instead of constexpr in this method 
    because constexpr variables can't be forward declared, 
    even if they have external linkage.
*/
/*
    Turning these constants into external variables, 
    since we can then have a single variable
*/
namespace constants
{
    // actual global variables
    extern const double pi{ 3.14159 };
    extern const double avogadro{ 6.0221413e23 };
    extern const double my_gravity{ 9.2 };
}