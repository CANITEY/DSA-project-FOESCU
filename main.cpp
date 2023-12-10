#include <iostream>
#include "doctors.h"

using namespace std ;


int main() {
    Doctors doc;
    doc.insertOrdered("mohammed");
    doc.insertOrdered("ahmed");
    doc.insertOrdered("abmed");
    doc.insertOrdered("saeed");
    doc.insertOrdered("sad");

    doc.display();
    cout << doc.length() << endl;
    return 0;
}
