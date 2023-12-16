#include "patients.h"
void PatientQueue::initializeQueue() {
    front = -1;
    rear = -1;
    count = 0;
    cout << "Patient queue initialized.\n";
}

bool PatientQueue::idReused(int id) {
    for (int i = 0; i < count; i++) {
        if (patientIds[i] == id) {
            return true;
        }
    }
    return false;
}


PatientQueue::PatientQueue() {
    initializeQueue();
    maxSize = 10;
    patientNames = new string[maxSize];
    patientIds = new int[maxSize];
}

PatientQueue::PatientQueue(int size) {
    initializeQueue();
    maxSize = size;
    patientNames = new string[size];
    patientIds = new int[size];
}

bool PatientQueue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool PatientQueue::isFull() {
    return count == maxSize;
}

void PatientQueue::enqueue(int id, string name) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (idReused(id)) {
        cerr << "Already added ID" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % maxSize;
    patientNames[rear] = name;
    patientIds[rear] = id;
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
    cout << "Front Patient Id: " << patientIds[front] << "\n";
}

void PatientQueue::getRear() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Rear patient's name : " << patientNames[rear] << endl;
    cout << "Rear Patient Id: " << patientIds[rear] << "\n";
}

void PatientQueue::destroyQueue() {
    initializeQueue(); // Reset front and rear to -1
    delete [] patientNames;
    delete [] patientIds;
    cout << "Queue destroyed.\n";
}

