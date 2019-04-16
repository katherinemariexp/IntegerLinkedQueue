#ifndef INTLINKEDQUEUE_H
#define INTLINKEDQUEUE_H

#include <iostream>
#include <string>

using namespace std;

class SubsError{
    int number;
    public: SubsError(int var):number(var){}
    int getValue(){ return number; }
};


class IntLinkedQueue {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *front; // front
    Node *rear; // end
    Node *p; // traverse
    Node *pp; // previous
    int size; //
    
public:
    // Default Constructor 
    IntLinkedQueue() : front(nullptr), rear(nullptr), size(0) {}
    
    // Destructor; // return all dynamically allocated nodes
    ~IntLinkedQueue() { }
    
    
    /*The Integer Linked Queue, IntLinkedQueue class should have the following member functions: 

Constructor; 
Destructor; // return all dynamically allocated nodes
bool isEmpty(); 
int getSize(); // size of the Queue
void clear(int);
string toString(); // return a string of a comma(,) delimited items e.g. "1, 2, 3, 4"
Front and Rear port access: the following 4 methods return operation success or failure as True/False, and pass the item value In/Out as a reference.

bool add(int &);  // Front add 
bool append(int &) // Rear append
bool fremove(int &);  // Front Remove
bool rremove(int &); // rear remove
*/
    void isEmpty() const{
        if (!front)
            cout << "LinkedQueue is empty";
        else
            cout << "LinkedQueue is not empty.";
    }
    void add(int n){
        Node *newNode;
        Node *p;
        Node *pp = nullptr;
        
        newNode = new Node;
        newNode->data = n;
        
        newNode->next = front;
        front = newNode;

    }
    void append(int n){
        p = new Node;
        p->next = nullptr;
        p->data = n;
        (front) ? rear = rear->next = p : front = rear = p;
        size++;

    }
    
    void fremove() {

        Node *p;
        
        if(!front)
            return;
        else
        {
            p = front->next;
            delete front;
            front = p;
        }
        
    }
    
    void rremove(){
        
        Node *p;
        Node *pp;
        
        if (!front)
            return;
        else if (!front->next)
        {
            p = front;
            delete front;
            front = p;
        }
        else
        {
            p = front;
            while (p->next != nullptr)
            {
                pp = p;
                p = p->next;
            }
            
            pp->next = nullptr;
            delete p;
        }
        
    }
    
    // fill the other methods below
    
    void displayList() const
    {
        Node *p;
        
        p = front;
        
        while (p)
        {
            cout << p->data << " ";
            
            p = p->next;
        }
    }
    
    int getSize()  
    {
        
        int count = 0;
        
        p = front;
        while(p != nullptr)
        {
            count++;
            p = p->next;
        }
    return count;


    }
    
};
#endif