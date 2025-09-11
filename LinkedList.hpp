#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
protected:
    struct Node {
        T value;
        Node* next;

        Node(T v = T(), Node* n = nullptr)
        : value(v), next(n) { }
    };

    Node* head;

public:
    LinkedList();
    virtual ~LinkedList();

    virtual void append(const T&) override;
    virtual void clear() override;
    virtual T getElement(int) const override;
    virtual int getLength() const override;
    virtual void insert(int, const T&) override;
    virtual bool isEmpty() const override;
    virtual void remove(int) override;
    virtual void replace(int, const T&) override;

    // Inline friend operator to avoid template linking errors
    friend ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
        if (myObj.isEmpty()) {
            outStream << "List is empty.\n";
        } else {
            Node* curr = myObj.head;
            while (curr != nullptr) {
                outStream << curr->value;
                if (curr->next != nullptr)
                    outStream << " --> ";
                curr = curr->next;
            }
            outStream << endl;
        }
        return outStream;
    }
};

#include "LinkedList.tpp"
#endif
