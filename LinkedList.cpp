#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

LinkedList::s_node::s_node(){
    data = 0;
    next = nullptr;
}
LinkedList::s_node::s_node(int d){
    data = d;
    next = nullptr;
}

LinkedList::s_node::s_node(int d, s_node *n){
    data = d;
    next = n;
}

LinkedList::s_node *LinkedList::s_node::get_next(){
    return next;
}

void LinkedList::s_node::set_next(s_node *n){
    next = n;
}

LinkedList::LinkedList(){
    start = nullptr;
}

void LinkedList::insert_front(int d){
    LinkedList::s_node *newnode = new LinkedList::s_node(d,start);
    start = newnode;
}

void LinkedList::insert_back(int d){
    s_node *current = start;
    LinkedList::s_node *newnode = new LinkedList::s_node(d);
    if(current == nullptr){
        start = newnode;
        return;
    }
    while(current->get_next()!=nullptr)
        current = current->get_next();
    current->set_next(newnode);
}

void LinkedList::insert_mid(int d, int pos){
    if(pos==0){
        insert_front(d);
        return;    
    }
    s_node *current = start;
    for(int i=1; current != nullptr && i<pos; i++){
        current = current->get_next();
    }
    if(current == nullptr){
        cout << "pos out of bounds" << endl;
        return;
    }
    LinkedList::s_node *newnode = new LinkedList::s_node(d);
    newnode->set_next(current->get_next()); 
    current->set_next(newnode);
}

void LinkedList::print(){
    if(start==nullptr){
        cout << "empty" << endl;
        return;
    }
    s_node *current = start;
    while(current!=nullptr){
        cout << current->get_data() << " ";
        current = current->get_next();
    }
    cout << endl;
}
int LinkedList::media() {
    if (start == nullptr) {
        cout << "La lista è vuota." << endl;
        return 0; 
    }
    int media = 0;
    int count = 0;
    s_node *current = start;

    while (current != nullptr) {
        media += current->get_data();
        count++;
        current = current->get_next();
    }

    return media / count;
}
int LinkedList::nearMedia() {
    int Media = media();
    
    if (start == nullptr) {
        cout << "empty" << endl;
        return -1;
    }
    
    s_node* current = start;
    int near = current->get_data();
    int minDiff = abs(near - Media);

    while (current != nullptr) {
        int dataCurrent = current->get_data();
        int currentDiff = abs(dataCurrent - Media);

        if (currentDiff < minDiff) {
            near = dataCurrent;
            minDiff = currentDiff;
        }
        
        current = current->get_next();
    }
    
    return near;
}

int LinkedList::s_node::get_data(){
    return this->data;
}

void LinkedList::s_node::set_data(int d){
    this->data = d;
}

void LinkedList::remove_front(){
    if(start==nullptr)
        return;
    s_node *front_node = start;
    start = start->get_next(); 
    delete front_node;
}

void LinkedList::remove_back(){
    if(start==nullptr)
        return;
    if(start->get_next()==nullptr){
        delete start;
        start = nullptr;
        return;
    }
    s_node *current = start;
    while(current->get_next()->get_next() != nullptr)
        current = current->get_next();

    s_node * back_node = current->get_next();
    delete back_node;
    current->set_next(nullptr);
}

void LinkedList::remove_mid(int pos){
    if(start==nullptr)
        return;
    if(pos==0){
        remove_front();
        return;
    }
    s_node *current = start;
    for(int i=1; current!=nullptr && i<pos; i++){
        current = current->get_next();
    }
    if(current == nullptr){
        cout << "pos out of bounds" << endl;
        return;
    }
    s_node *current_next = current->get_next();
    if(current_next == nullptr){
        cout << "pos out of bounds" << endl;
        return;
    }
    s_node *current_nextnext = current_next->get_next();
    current->set_next(current_nextnext);
    delete current_next;
}
void LinkedList::removeMult(int val) {
    if (start == nullptr) {
        cout << "La lista è vuota." << endl;
        return;
    }

    s_node *current = start;

    while (current != nullptr) {
        s_node *next = current->get_next();
        if (next != nullptr && next->get_data() % val == 0) {
            current->set_next(next->get_next());
            delete next;
        } else {
            current = next;
        }
    }
}

int LinkedList::get_data(int pos){
    if(start==nullptr)
        return INT_MIN;
    s_node *current = start;
    for(int i=0; current != nullptr && i<pos; i++)
        current = current->get_next();
    if(current == nullptr){
        return INT_MIN;
    }
    return current->get_data();
}

bool LinkedList::is_empty(){
    return start == nullptr;
}
