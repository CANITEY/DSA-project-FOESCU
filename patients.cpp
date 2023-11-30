#include "patients.h"
void PatientQueue::initializeQueue() {
    front = -1;
    rear = -1;
    count = 0;
    cout << "Patient queue initialized.\n";
}

PatientQueue::PatientQueue() {
    initializeQueue();
    patientNames = new string[10];
}

PatientQueue::PatientQueue(int size) {
    initializeQueue();
    maxSize = size;
    patientNames = new string[size];
}

bool PatientQueue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool PatientQueue::isFull() {
    return count == maxSize;
}

void PatientQueue::enqueue(string name) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % maxSize;
    patientNames[rear] = name;
    count++;
    cout << "Added patient " << name << " to the queue.\n";
}

void PatientQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }
    string removedName = patientNames[front];

    if (front == rear) {
        // Last element is being removed
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % maxSize;
    }

    count--;
    cout << "Patient: " << removedName << " removed from the queue.\n";
}

void PatientQueue::getFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front Patient Name: " << patientNames[front] << "\n";
}

void PatientQueue::getRear() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Rear patient's name : " << patientNames[rear] << endl;
}

void PatientQueue::destroyQueue() {
    initializeQueue(); // Reset front and rear to -1
    delete [] patientNames;
    cout << "Queue destroyed.\n";
}

