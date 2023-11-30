#include <iostream>
using namespace std;

// Maximum size of the queue
const int MAX_SIZE = 5;

// Circular Queue for managing patients
class PatientQueue {
    private:
        int front;
        int rear;
        int count;
        int patientIDs[MAX_SIZE];
        string patientNames[MAX_SIZE];

    public:
        // Constructor
        PatientQueue() {
            front = -1;
            rear = -1;
            count = 0;
        }

        // Destructor is not needed for this example

        // Function to initialize the queue
        void initializeQueue() {
            front = -1;
            rear = -1;
            count = 0;
            cout << "Patient queue initialized.\n";
        }

        // Function to add a patient to the queue
        void enqueue(int id, const string& name) {
            if (isFull()) {
                cout << "Queue is full. Cannot add more patients.\n";
                return;
            }

            if (isEmpty()) {
                front = 0;
            }

            rear = (rear + 1) % MAX_SIZE;
            patientIDs[rear] = id;
            patientNames[rear] = name;

            count++;
            cout << "Patient " << name << " added to the queue.\n";
        }

        // Function to remove a patient from the queue
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot dequeue.\n";
                return;
            }

            int removedID = patientIDs[front];
            string removedName = patientNames[front];

            if (front == rear) {
                // Last element is being removed
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }

            count--;
            cout << "Patient ID: " << removedID << ", Name: " << removedName << " removed from the queue.\n";
        }

        // Function to get the front patient in the queue
        void getFront() {
            if (isEmpty()) {
                cout << "Queue is empty.\n";
                return;
            }

            cout << "Front Patient ID: " << patientIDs[front] << ", Name: " << patientNames[front] << "\n";
        }

        // Function to check if the queue is full
        bool isFull() {
            return count == MAX_SIZE;
        }

        // Function to check if the queue is empty
        bool isEmpty() {
            return count == 0;
        }

        // Function to destroy the queue
        void destroyQueue() {
            initializeQueue(); // Reset front and rear to -1
            cout << "Queue destroyed.\n";
        }
};

int main() {
    // Create a patient queue
    PatientQueue patientQueue;

    // Perform patient queue operations
    patientQueue.initializeQueue();
    patientQueue.enqueue(101, "John Doe");
    patientQueue.enqueue(102, "Jane Doe");
    patientQueue.enqueue(103, "Bob Smith");

    patientQueue.getFront();

    patientQueue.dequeue();
    patientQueue.getFront();

    patientQueue.destroyQueue();

    return 0;
}
