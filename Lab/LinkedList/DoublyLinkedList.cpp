#include "DoublyLinkedList.h"
#include <iomanip>
#include <sstream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int val)
{
    Node* n = new Node(val);
    head = n;
    tail = n;
    //head->next = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* next = nullptr;

    while(head)
    {
        next = head -> next;
        delete head;
        head = next;
    }
}

void DoublyLinkedList::insert_back(int val)
{
    Node* n = new Node(val);
    if(head == nullptr){
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void DoublyLinkedList::insert_front(int val)
{
    Node* n = new Node(val);
    if (head == nullptr){
        tail = n;
        head = n;
    }
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void DoublyLinkedList::insert_at(int data, int position)
{
    Node* n = new Node(data);
    Node* after = head;
    Node* before = head;

    for(int i = 1; i <= position; ++i)
    {
        after = after->next;
        before = after->prev;
    }

    before->next = n;
    n->prev = before;

    n->next = after;
    after->prev = n;
}

Node& DoublyLinkedList::find(int val)
{
    Node* curr = head;

    while (curr->data != val)
    {
        if (curr->next == nullptr)
        {
            throw runtime_error("error");
        }
        curr = curr->next;
    }
    
    return *curr;

}

void DoublyLinkedList::delete_at(int idx)
{
    Node* curr = head;

    for (int i = 0; i < idx; i++)
    {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr;

}

Node& DoublyLinkedList::get_head()
{
    return *head;
}

Node& DoublyLinkedList::get_tail()
{
    return *tail;
}

Node const& DoublyLinkedList::get_head() const
{
    return *head;
}

Node const& DoublyLinkedList::get_tail() const
{
    return *tail;
}

ostream& operator<<(ostream &os, DoublyLinkedList const& ll) {
    os << "Doubly Linked List" << endl;
    if (&(ll.get_head()) == nullptr)
        return (os << "Empty" << endl);
    os << "Head: " << &(ll.get_head()) << "\t Tail: " << &(ll.get_tail()) << endl;
    Node const* curr = &(ll.get_head());
    os << "Nodes (accessible from head to tail):" << endl << endl;
    os << setw(16) << setfill(' ') << ' ' << ' ' << center("prev", 15) << ' ' << center("data", 15) << ' ' << center("next", 15) << endl;
    while (curr != nullptr) {
        ostringstream oss; oss << (curr->prev); string prev = oss.str(); oss.str(""); oss << (curr->next); string next = oss.str(); oss.str(""); oss << (curr->data); string data = oss.str(); oss.str(""); oss << curr; string address = oss.str();
        os << setw(16) << setfill(' ') << ' ' << '.' << setw(16) << setfill('-') << '.' << setw(16) << '.' << setw(16) << '.' << endl;
        os << setw(16) << setfill(' ') << center(address,15) << '|' << setw(15) << setfill(' ') << center(prev, 15) << '|' << setw(15) << center(data, 15) << '|' << setw(15) << center(next, 15) << '|'<< endl;
        os << setw(16) << setfill(' ') << ' ' << '\'' << setw(16) << setfill('-') << '\'' << setw(16) << '\'' << setw(16) << '\'' << endl;
        os << endl;
        curr = curr->next;
    }
    return os;
}

string center (const string &str, const int col_width)
{
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    string strf = string(padl, ' ') + str + string(padr, ' ');
    return strf;
}
