// List.hpp
#pragma once

#include <iostream>
#include <ostream>
#include <random>
#include "node.hpp"

using namespace std;

namespace myList {
    template <typename T>
    class List {
        protected:
            typedef Node<T> Node;
            
            Node * head = nullptr;
            Node * tail = nullptr;
            unsigned int length = 0;

        public:
            // Copy constructor: Builds a list based on another list
            List(List* List){ 
                head = List.front;
                tail = List.tail;
                length = List.length;
            }
            
            // Array constructor: Fills a list based on an array
            List(T *arr, int n){ 
                for(int i = 0; i < n; ++i) {
                    push_back(arr[i]);
                }
            }

            // Node constructor: Returns a list with a single node
            List(Node* singleNode){ 
                head = singleNode;
                tail = singleNode;
                length = 1;
            }

            // Randomized constructor of size n
            List(int n){ 
                // Generate random seed
	            std::random_device dev;
	            std::mt19937 rng(dev());

                // Generate distribution in range [0, 100]
                if (std::is_same<T, char>::value) {
                    static std::uniform_int_distribution<> dist26(0, 25);
                    for(int i = 0; i < n; ++i)
                        push_front('a' + dist26(rng));
                } else {
                    static std::uniform_real_distribution<> dist100(0, 100);
                    for(int i = 0; i < n; ++i)
                        push_front(dist100(rng));
                }
            }
            
            // Default constructor
            List(){ 
                head = nullptr;
                tail = nullptr;
                length = 0;
            }

            // Default destructor
            ~List(){
                while(!isEmpty()){ pop_front(); }
            }

            // Retorna una referencia al primer elemento
            Node * front() { return head; }
            
            // Retorna una referencia al ultimo elemento
            Node * back() { return tail; }; 
            
            // Inserta un elemento al final
            void push_back(const T& element) {
                Node * new_node = new Node(element, nullptr);
                if (head == nullptr) { 
                    head = new_node;
                    tail = new_node;
                } else {
                    tail->next = new_node;
                    tail = new_node;
                    ++length;
                }
            }

            // Inserta un elemento al inicio
            void push_front(const T& element) {
                Node * new_node = new Node(element, head);
                if (head == nullptr)
                    tail = new_node;
                head = new_node;
                ++length;
            }

            // Quita el ultimo elemento y retorna una referencia
            Node * pop_back() {
                Node * ptr = head;
                while (ptr->next->next != nullptr)
                    ptr = ptr->next;
                
                Node * tmp = ptr->next;
                delete ptr->next;
                ptr->next = nullptr;
                tail = ptr;
                --length;
                return tmp;
            }

            // Quita el primer elemento y retorna una referencia
            Node * pop_front() {
                Node * ptr = head;
                head = ptr->next;
                ptr->next = nullptr;
                delete ptr;
                --length;
                return ptr;
            }

            // Acceso aleatorio
            Node * operator[] (const int& pos) {
                Node * ptr = head;
                int i = 0;
                
                for (ptr = head; ptr != nullptr; ptr = ptr->next){
                    if (i == pos)
                        return ptr;
                    ++i;
                }

                return nullptr;
            }
            
            // La lista esta vacia?
            bool isEmpty() { return head == nullptr; }; 

            // Retorna el tamaño de la lista
            unsigned int size() { return length; }; 

            // Elimina toda la lista
            void clear() { while(!isEmpty()){ pop_front(); } } 

            // Elimina un elemento en base a un puntero
            void erase(Node * ref) {
                if (ref == head) {
                    head = head->next;
                    delete ref;
                    --length;
                    return;
                }
                for (Node * ptr = head; ptr != nullptr; ptr = ptr->next){
                    if (ptr->next == ref) {
                        ptr->next = ptr->next->next;
                        if (ref == tail)
                            tail = ptr;
                        delete ref;
                        --length;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            } 
            
            // Inserta un elemento en base a un puntero
            void insert(Node * ref, const T& element) {
                for (Node * ptr = head; ptr != nullptr; ptr = ptr->next){
                    if (ptr == ref) {
                        Node * new_node = new Node(element, ptr->next);
                        ptr->next = new_node;
                        ++length;
                        if (ref == tail)
                            tail = new_node;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            }

            // Elimina todos los elementos por similitud
            void remove(const T& element) {
                Node * ptr = head;
                Node * tmp;
                while (ptr != nullptr){ 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(ptr);
                        ptr = tmp;
                    } else {
                        ptr = ptr->next;
                    }
                }
            }

            // Ordena la lista usando BubbleSort
            void sort() {
                bool fin; 
                Node * ptr; 
                Node * hold = nullptr; 
            
                do { 
                    ptr = head; 
                    fin = false; 
            
                    while (ptr->next != hold) { 
                        if (ptr->value > ptr->next->value) {  
                            T tmp = ptr->value; 
                            ptr->value = ptr->next->value; 
                            ptr->next->value = tmp; 
                            fin = true; 
                        } 
                        ptr = ptr->next; 
                    } 
                    hold = ptr;
                } while (fin);
            } 

            // Invierte la lista
            void reverse() {
                push_front(tail->value);
                pop_back();
                for (Node * ptr = head; ptr->next != nullptr; ptr = ptr->next) {
                    insert(ptr, tail->value);
                    pop_back();
                }
            }; 

            // Imprime la lista con cout
            inline friend ostream& operator << (ostream &os, const List &List) {
                Node * ptr = List.head;
                while (ptr != nullptr) {
                    os << ptr->value << " ";
                    ptr = ptr->next;
                }
                return os;
            }
    };
}