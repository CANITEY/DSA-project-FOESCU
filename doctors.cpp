#include "doctors.h"
#include <iterator>



Doctors::Doctors() {
    head = NULL;
    tail = NULL;
    count = 0;
}

void Doctors::insertEmpty(string name) {
    Node *newDoctor = new Node;
    newDoctor->name = name;
    head = newDoctor;
    tail = newDoctor;
    newDoctor->next = newDoctor->prev = NULL;
    count++;
}

void Doctors::insertFirst(string name) {

    // checking if the list is empty so we call the insert empty function
    if (empty()) {

        insertEmpty(name);
        // we use return so we don't need to use the else keyword in the statement we can remove it and use the else statement
        return; // it returns no value because the function has the return type of void

    } // else { ...content 

    // here we initialized newDoctor of the Node type then we altered its value and link it with the head
    Node *newDoctor = new Node;

    newDoctor->name = name;
    newDoctor->next = head;
    head->prev = newDoctor;
    newDoctor->prev = NULL;
    head = newDoctor;
    count++;
    return;
}


void Doctors::insertLast(string name) {
    // checking if it is empty so we call the insert empty function
    if (empty()) {
        // same as insertFirst
        insertEmpty(name);
        return;
    }

    Node *newDoctor = new Node;
    newDoctor->name = name;
    newDoctor->next = NULL;
    newDoctor->prev = tail;
    tail->next = newDoctor;
    tail = newDoctor;
    count++;
    return;
}


void Doctors::insertAt(int index, string name) {
    // same as the two above
    if (empty()) {
        insertEmpty(name);
        return;
    }

    if (index >= count) {
        cout << "index is >= the list length\ninserting new doctor at the end of the list\n";
        insertLast(name);
        return;
    }

    if (index == 0) {
        insertFirst(name);
        return;
    }

    Node *newDoctor = new Node;
    newDoctor->name = name;

    Node *current = head;

    while (current != NULL && index != 0) {
        current = current->next;
        index--;
    }

    if (index == 0) {
        newDoctor->next = current;
        newDoctor->prev = current->prev;
        current->prev->next = newDoctor;
        current->prev = newDoctor;
        count++;
        return;
    }
}

void Doctors::insertOrdered(string name) {
    if (empty()) {
        insertEmpty(name);
    } else if (name < head->name) {
        insertFirst(name);
    } else if (name > tail->name) {
        insertLast(name);
    } else {
        Node *current = head;
        int index = 0;
        while (current != NULL && current->name < name) {
            index++;
            current = current->next;
        }
        insertAt(index, name);
    }
    return;
}



void Doctors::deleteFirst() {
    if (empty()) {
        cout << "list is empty";
        return;
    }

    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    temp = NULL;
    count--;
}

void Doctors::deleteEnd() {
    if (empty()) {
        cout << "list is empty";
        return;
    }

    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
    temp = NULL;
    count--;
}

void Doctors::deleteAt(int index) {
    if (empty()) {
        cout << "list is empty";
        return;
    }
    if (index == 0) {
        deleteFirst();
        return;
    }
    if (index == count - 1) {
        deleteEnd();
        return;
    }

    if (index > count - 1) {
        cout << "you can't delete out of the list\n";
        return;
    }

    Node *current = head;
    while (current != NULL && index != 0) {
        current = current->next;
        index--;
    }

    Node *temp;
    temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete temp;
    temp = NULL;
}



int Doctors::length() {
    return count;
}

void Doctors::display() {
    Node *current = head;
    while (current != NULL) {
        cout << current->name << endl;
        current = current->next;
    }
}

void Doctors::displayRev() {
    Node *current = tail;
    while (current != NULL) {
        cout << current->name << endl;
        current = current->prev;
    }
}

void Doctors::visualize() {
    cout << "**List length is: " << this->length() << "**" << endl;
    Node *current = head;
    cout << "|NULL|<-->";
    while (current != NULL) {
        cout << "|" << current->name << "|<-->";
        current = current->next;
    }
    cout << "|NULL|" << endl;
}

string Doctors::at(int index) {
    if (index >= count) {
        return "index is above the list length";
    }
    Node *current = head;
    while (current != NULL && index != 0) {
        index--;
        current = current->next;
    }
    return current->name;
}

int Doctors::search(string name) {
    Node *current = head;
    bool found = false;
    int index = 0;

    while (!found && current != NULL) {
        if (current->name == name) {
            found = true;
            break;
        }
        current = current->next;
        index++;
    }
    if (found) {
        return index;
    }

    return -1;
}


bool Doctors::empty() {
    if (head == NULL && tail == NULL) {
        return true;
    }
    return false;
}

