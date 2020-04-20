// doublyList.hpp
#pragma once

#include <iostream>
#include <ostream>
#include <random>
#include "node2.hpp"

using namespace std;

namespace myDoublyList {
    template <typename T>
    class List {
        protected:
            typedef Node2<T> Node;
            
            Node * head = nullptr;
            Node * tail = nullptr;
            unsigned int length = 0;

        public:
            // Copy constructor: Builds a list based on another list
            List(List* List){ 
                Node * ptr = List.head;
                int i = 0;
                while (ptr != nullptr) {
                    push_front(List[i]->value);
                    ptr = ptr->next;
                    ++i;
                }
            }
            
            // Array constructor: Fills a list based on an array
            List(T *arr, int n){ 
                for(int i = 0; i < n; ++i) {
                    push_back(arr[i]);
                }
            }

            // Node constructor: Returns a list with a single node
            List(Node* singleNode){ 
                push_front(singleNode->value);
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
                Node * new_node = new Node(element, nullptr, tail);
                if (head == nullptr) 
                    head = new_node;  
                else
                    tail->next = new_node;
                tail = new_node;
                ++length;
            }

            // Inserta un elemento al inicio
            void push_front(const T& element) {
                Node * new_node = new Node(element, head, nullptr);
                if (head == nullptr)
                    tail = new_node;
                else
                    head->prev = new_node;
                head = new_node;
                ++length;
            }

            // Quita el ultimo elemento y retorna una referencia
            Node * pop_back() {
                Node * ptr = tail->prev;
                Node * tmp = tail;
                delete tail;
                tail = ptr;
                tail->next = nullptr;
                --length;
                return tmp;
            }

            // Quita el primer elemento y retorna una referencia
            Node * pop_front() {
                Node * ptr = head;
                head = ptr->next;
                if (length > 1)
                    head->prev = nullptr;
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
            bool isEmpty() { return head == nullptr; }

            // Retorna el tamaño de la lista
            unsigned int size() { return length; }

            // Elimina toda la lista
            void clear() { while(!isEmpty()){ pop_front(); } }

            // Elimina un elemento en base a un puntero
            void erase(Node * ref) {
                Node * tmp = nullptr;
                if (ref == head) {
                    head = head->next;
                    head->prev = nullptr;
                    delete ref;
                    --length;
                    return;
                }
                for (Node * ptr = head; ptr != nullptr; ptr = ptr->next){
                    if (ptr->next == ref) {
                        tmp = ptr->next->next;
                        ptr->next = ptr->next->next;
                        tmp->prev = ptr;
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
                        Node * new_node = new Node(element, ptr->next, ptr);
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
                Node * tmp;
                for (Node * ptr = head; ptr != nullptr; ptr = ptr->next) { 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(ptr);
                        ptr = tmp;
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
                Node * tmp = nullptr;
                for (Node * ptr = tail; head->next != nullptr; ptr = ptr->next) {
                    tmp = ptr->prev;
                    ptr->prev = ptr->next;
                    ptr->next = tmp;
                }
                tmp = head;
                head = tail;
                tail = tmp;
            }

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