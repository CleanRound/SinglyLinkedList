#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    T pop_front() {
        if (empty())
            throw out_of_range("List is empty");

        Node<T>* temp = head;
        T val = temp->data;
        head = head->next;
        delete temp;
        size--;
        return val;
    }

    bool empty() {
        return size == 0;
    }

    SinglyLinkedList<T>* clone() {
        SinglyLinkedList<T>* newList = new SinglyLinkedList<T>();
        Node<T>* current = head;
        while (current != nullptr) {
            newList->push_back(current->data);
            current = current->next;
        }
        return newList;
    }

    SinglyLinkedList<T>* operator+(SinglyLinkedList<T>& other) {
        SinglyLinkedList<T>* newList = clone();
        Node<T>* current = other.head;
        while (current != nullptr) {
            newList->push_back(current->data);
            current = current->next;
        }
        return newList;
    }

    SinglyLinkedList<T>* operator*(SinglyLinkedList<T>& other) {
        SinglyLinkedList<T>* commonList = new SinglyLinkedList<T>();
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* otherCurrent = other.head;
            while (otherCurrent != nullptr) {
                if (current->data == otherCurrent->data) {
                    commonList->push_front(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }
        return commonList;
    }

    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList<int> list1;
    list1.push_front(4);
    list1.push_front(3);
    list1.push_front(2);
    list1.push_front(1);
    cout << "List 1: ";
    list1.display();

    SinglyLinkedList<int> list2;
    list2.push_front(6);
    list2.push_front(5);
    list2.push_front(4);
    list2.push_front(3);
    cout << "List 2: ";
    list2.display();

    SinglyLinkedList<int>* clonedList = list1.clone();
    cout << "Cloned List 1: ";
    clonedList->display();

    SinglyLinkedList<int>* concatenatedList = list1 + list2;
    cout << "Concatenated List: ";
    concatenatedList->display();

    SinglyLinkedList<int>* commonElementsList = list1 * list2;
    cout << "Common Elements List: ";
    commonElementsList->display();

    delete clonedList;
    delete concatenatedList;
    delete commonElementsList;

    return 0;
}
