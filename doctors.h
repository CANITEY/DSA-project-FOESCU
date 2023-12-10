#ifndef DOCTORS_H
#define DOCTORS_H

#include <iostream>
using namespace std;


struct Node {
    string name;
    Node *next;
    Node *prev;
};

class Doctors {
    private:
        // creating new nodes for the head of the list, the end; and making count variable to ease some implementations
        Node *head, *tail;
        int count;

        // creating a function to insert if the list is empty so we don't need to call the function body every time in the 3 insert function below
        void insertEmpty(string name);

    public:
        // initializing the head and tail pointers so they point at NULL, and count so it equals zero
        Doctors();


        // insertion implementations
        // insert at first function that inserts before the head so the next pointer "points" to the head and prev pointer "points" to NULL
        void insertFirst(string name);

        // this is a function that will insert a node at the tail pointer, and the result node will point at the tail using the prev "pointer" and point at NULL using the next pointer
        void insertLast(string name);

        // this function inserts after the specified index
        void insertAt(int index, string name);
        // end of insertion
        
        void insertOrdered(string name);

        // delete functions implementations
        void deleteFirst();

        void deleteEnd(); 

        void deleteAt(int index);

        // end of delete functions implementations


        // info functions
        // get length of list
        int length(); 

        // display list
        void display();
        
        void displayRev();
        // print list in linked shape
        void visualize();

        // get the doctors name at some index;
        string at(int index);

        // check if a doctor is in list
        int search(string name);

        // check if the list is empty
        bool empty();
        // end of info functions
};

#endif
