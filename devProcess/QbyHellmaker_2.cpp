#include <iostream>
using namespace std ;
struct Queue{
    int front,rear,size;
    string *arr;
};
void iniatialization(Queue *queue ,int size){
    queue->front=queue->rear = -1;
    queue->size=size;
    queue->arr =new string[size];
}
bool isEmpty(Queue *queue){
    if(queue->front == -1 && queue->rear == -1){
        return true;
    }
    else{
        return false;
    }

}
bool isFull(Queue *queue){
    if((queue->rear +1)% queue->size == queue->front){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(Queue* queue, string name) {
    if (isFull(queue)) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = name;
    cout << "Added patient " << name << " to the queue.\n";
}
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return;
    }

    cout << "Removed " << queue->arr[queue->front] << " from the queue.\n";

    if (queue->front == queue->rear) {
        // Last element is being removed, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
}
void getFront(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Front patient's name :" << queue->arr[queue->front] << endl;
}
void getRear(Queue* queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Rear patient's name : " << queue->arr[queue->rear] << endl;
}
void destroyQueue(Queue* queue) {
    delete[] queue->arr;
    queue->front = -1;
    queue->rear = -1;
    cout << "Queue destroyed.\n";
}
int main() {
    Queue myQueue;
    iniatialization(&myQueue, 50);

    enqueue(&myQueue, "ahmed");
    enqueue(&myQueue, "moanes");
    enqueue(&myQueue, "ziad");

    getFront(&myQueue);
    getRear(&myQueue);

    dequeue(&myQueue);
    getFront(&myQueue);

    destroyQueue(&myQueue);

    return 0;
}
