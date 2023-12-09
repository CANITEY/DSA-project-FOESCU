#include <iostream>
#include "patients.h"

using namespace std ;


int main() {
    PatientQueue q(4);
    q.enqueue("Mohammed");
    q.enqueue("Zyad");
    q.enqueue("Omar");
    q.enqueue("Steven");
    q.enqueue("ss");

    q.getFront();
    q.getRear();
    return 0;
}
