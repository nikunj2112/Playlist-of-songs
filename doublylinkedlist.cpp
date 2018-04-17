/*
  Declarations of doubly link lis:
  Implementation of operations in doubly link list to store and perform
  various playlist commands.  
 */

#include "doublylinkedlist.h"
#include<string>

using namespace std;

// Set head to NULL initially
DoublyLinkedList::DoublyLinkedList()
{
	head=new Node();
	head=NULL;
        tail=NULL;
}

// Destroys all the nodes in the list
DoublyLinkedList::~DoublyLinkedList()
{
    Node *temp=head;
    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
}

// Sets all parameters of node to NULL
DoublyLinkedList::Node::Node()
{
	next=NULL;
	prev=NULL;
	data=NULL;
}

// Dynamically allocates memory to string passed from playlist.cpp
DoublyLinkedList::Node::Node(const string &s)
{
    this->data=new string(s);
}

// Destroys all paramenters of node and frees the memory allocated
DoublyLinkedList::Node::~Node()
{
        next=NULL;
	prev=NULL;
	data=NULL;
	delete next;
	delete prev;
	delete data;
}

// Check whether list is present or not
bool DoublyLinkedList::empty()
{
	if(head==NULL)
        return true;
	else
		return false;
}

// Add nodes to the playlist at the end and makes that node as current node
void DoublyLinkedList::append(string &val)
{
    Node *x=new Node(val);
    current = x;
    if (empty()) 				// for the first node
    {
        current->prev = NULL;
        head = current;
        tail=current;
    }
    else 						// all other nodes
    {
        Node *s;
        s = head;
        while (s->next != NULL)
           s = s->next;
        s->next = current;
        current->prev = s;
        tail = current;
    }
    tail->next=NULL;
    current->next=NULL;
}

//Song is inserted in playlist preceding the current song and make it current
void DoublyLinkedList::insertBefore(string &s)
{
   Node *temp=head;
   Node *temp1=NULL,*temp2=NULL;
   Node *ins= new Node(s);
   if(empty()) 					// if list is not present
   {
        current=ins;
        current->prev = NULL;
        head = current;
        tail=current;
        tail->next=NULL;
        current->next=NULL;
   }
   else if(current->prev==NULL) // if it is first node
   {
        ins->next=temp;
        temp->prev=ins;
        head=ins;
        current=ins;
        ins->prev=NULL;
    }
   else
   {
        temp1=current->prev;
        temp2=current;
        current=ins;
        ins->prev=temp1;
        ins->next=temp2;
        temp1->next=ins;
        temp2->prev=ins;
    }
}

//Song is inserted in playlist following the current song and make it current
void DoublyLinkedList::insertAfter(string &s)
{
   Node *temp=head;
   Node *temp1,*temp2;
   Node *ins= new Node(s);
   if(empty()) 					// list node present
   {
        current=ins;
        current->prev = NULL;
        head = current;
        tail=current;
        tail->next=NULL;
        current->next=NULL;
   }
   else if(current->next==NULL) // last node
   {
        temp=current;
        current=ins;
        tail=current;
        current->next=NULL;
        tail->prev=temp;
        temp->next=tail;
   }
   else
   {
        temp1=current->next;
        temp2=current;
        current=ins;
        ins->prev=temp2;
        ins->next=temp1;
        temp2->next=ins;
        temp1->prev=ins;
    }
}

// Removes the song from the playlist
void DoublyLinkedList::remove(string &s)
{
    Node *temp=head;
    Node *temp2,*temp1;
    if(find(s)) 				// find the song if present
    {
        if(head == tail)		// for only one song delete the node and set it to NULL
        {
            delete head;
            head = NULL;
            tail = NULL;
            current = NULL;
        }
        else if(current == head) // for first song. Make the next song current
        {
            head = temp->next;
            head->prev = NULL;
            current = head;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else if (current == tail) // for last song. Make previous song current
        {
            temp = tail;
            current = tail->prev;
            tail = current;
            tail->next = NULL;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
        else 					// for any other song. Make next song as current
        {
            temp = current;
            temp1 = current->prev;
            temp2 = current->next;
            temp1->next = temp2;
            temp2->prev = temp1;
            current = temp2;
            temp->next=NULL;
            temp->prev=NULL;
            delete temp;
        }
    }
}

// To go to the first song in the playlist
void DoublyLinkedList::begin()
{
   if(!empty())
    current=head;
}

// To go to the last song in the playlist
void DoublyLinkedList::end()
{
    if(!empty())
        current=tail;
}

// To go to the next song in the playlist
bool DoublyLinkedList::next()
{
    if(!empty())
    {
        if(current->next!=NULL)
        {
            current=current->next;
            return true;
        }
    }
    return false;
}

// To go to the previous song in the playlist
bool DoublyLinkedList::prev()
{
    if(!empty())
    {
        if(current->prev!=NULL)
        {
            current=current->prev;
            return true;
        }
    }
    return false;
}


//Search the song from the playlist if present
bool DoublyLinkedList::find(string &s)
{
    Node *temp=head;
    if(!empty())
    {
        while(temp!=NULL)			// traverse list till end
        {
            if(*temp->data==s)
            {
                current=temp;
                return true;
            }
            else
                temp=temp->next;
        }
    }
    return false;
}

// Display the song at the current node
const string &DoublyLinkedList::getData()
{
    const string *s=current->data;
    return *s;
}
