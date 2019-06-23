#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <algorithm>
#include <string>
#include "Node.h"

template<typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(std::string);

    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    LinkedList<T>& operator=(LinkedList<T>&&);
    ~LinkedList();

    void set_name(std::string);
    std::string get_name() const;
    Node<T>* get_head() const;
    Node<T>* get_tail() const;

    bool is_empty() const;
    void insert_front(T);
    void insert_back(T);
    bool insert_after (T, T);
    void clear();

private:
    Node<T>* head;
    Node<T>* tail;
    std::string name;
    void null_head(bool);
    void null_tail(bool);
    void swap(LinkedList<T>& l1, LinkedList<T> l2);
    void log(const std::string& what) const;
};
template<typename T>
inline std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{
    os << ll.get_name() << " {";
    Node<T>* current = ll.get_head();
    if (current == nullptr) {
        os << " <Empty List>";
    }
    while (current != nullptr) {
        if (current != ll.get_head())
            os << ",";
        os << " " << current->value;
        current = current->next;
    }
    os << " }";
    //os << std::endl << ll.get_head() << '\t' << ll.get_tail() << std::endl;
    return os;
}
#endif