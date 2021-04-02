#include <iostream>
#include "Doctor.h"
#include "Patient.h"

int main(int argc, char** argv)
{
    Patient john{ "John Doe", 12 };
    Patient jane{ "Jane Doe", 8 };

    Doctor smith{ "TR Smith", 48 };

    john.add_doctor(smith);
    jane.add_doctor(smith);

    smith.add_patient(john);
    smith.add_patient(jane);

    smith.list_patients();

    john.list_doctors();
    jane.list_doctors();

    return 0;
}