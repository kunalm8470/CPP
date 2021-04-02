#include <iostream>
#include "Teacher.h"
#include "Department.h"

int main(int argc, char** argv)
{
    /*
        Aggregation objects are managed by
        external call-site and they might not be
        destroyed if the call-site forgets to de-allocate them
        which can cause potential memory leaks
    */
    Teacher kunal{ "Kunal" };

    {
        /*
            Memory for department is
            allocated here
        */
        Department math{ "Math", kunal };
        /*
            Memory for department is
            de-allocated here

            The teacher reference is destroyed here
            But not the original object
        */
    }

    // Teacher object still accessible here
    std::cout << kunal.get_name() << std::endl;
    return 0;
}
