// Description: Assignment 9 - Int Linked Queue
// Author: Katherine-Marie Gonzales
// COMSC200 - 5001
// April 15, 2019
// Status: Incomplete: Missing commas

//IntLinkedQueue.h

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
    Node *front; 
    Node *rear; 
    Node *p; 
    Node *pp; 
    int size;
    
public:

    IntLinkedQueue() : front(nullptr), rear(nullptr), size(0) {}
    

    ~IntLinkedQueue() { }
    
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
    
    void clear() 
    {
        p = front;
        while (p != nullptr)
        {
            front = p->next;
            delete p;
            p = front;
       }
       cout << "Queue is cleared" << endl;
       
    }


};
#endif