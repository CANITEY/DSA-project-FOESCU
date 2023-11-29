#include <exception>
#include <iostream>
#include "doctors.h"

using namespace std;



int main() {
    Doctors doc;
    doc.insertFirst("Abd elnabi");
    doc.insertFirst("Ahmed");
    doc.insertFirst("Mohammed");
    doc.insertLast("Ahmed");
    doc.insertLast("Mousa");
    doc.insertAt(4, "Imposter");
    doc.display();
    cout << "===========" << endl;
    doc.deleteAt(0);
    doc.display();
    return 0;

}

