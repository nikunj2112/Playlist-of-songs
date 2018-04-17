/*
 	Declaration of a doubly link list for music.
 
 	Implementation of doubly link list to store playlist and perform
 	various operations on it.
 */

#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class DoublyLinkedList   	// operations to perform on list
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void print();
        bool empty();
        void append(string &s);
        void insertBefore(string &s);
        void insertAfter(string &s);
        void remove(string &s);
        void begin();
        void end();
        bool next();
        bool prev();
        bool find(string &s);
        const string &getData();
    private:
        class Node   		// This will contain data and pointers to other nodes
        {
            public:
                Node *next;
                Node *prev;
                string *data;
            public:
                Node();
                Node(const string &);
                ~Node();
        };
        Node *head; 		// start of list
        Node *tail; 		// end of list
        Node *current; 		// to access node after performing any operation
};

#endif
