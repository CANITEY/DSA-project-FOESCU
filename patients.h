#ifndef PATIENTQUEUE_H
#define PATIENTQUEUE_H

#include <iostream>

using namespace std;


class PatientQueue {
    private:
        int front;
        int rear;
        int count;
        string *patientNames;
        int maxSize;

        void initializeQueue();
    public:
        // initialize a queue with max size of 10
        PatientQueue();

        // initialize a queue with dynamic max size that is specified at run time
        PatientQueue(int size);

        // checks if the queue is empty or full
        bool isEmpty();
        bool isFull();

        // adds a patient to queue
        void enqueue(string name);

        // remove a patient from queue
        void dequeue();

        // get the queue first patient
        void getFront();

        // get the queue last patient
        void getRear();

        // destroy the queue
        void destroyQueue();
};

#endif
