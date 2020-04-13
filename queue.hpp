// queue.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace myQueue {

    template <typename T>
    struct Node {
        T content;
        Node<T> * nextNode;
    };

    template <typename T>
    class iterator {
        private:
            typedef Node<T> Node;
            Node * pointer;
            
        public:
            iterator(){ pointer = nullptr; }
            iterator(Node * ptr) { this->pointer = ptr; }
            
            void operator ++(){
                this->pointer = this->pointer->nextNode;
            }
            
            T operator * (){
                return this->pointer->content;
            }
            
            bool operator == (const iterator & it){
                return this->pointer == it.pointer;
            }
            
            bool operator != (const iterator & it){
                return this->pointer != it.pointer;
            }
    };


    template <typename T>
    class queue {
        private:
            typedef Node<T> Node;
        
            Node * front;
            Node * back;
        
        public:
            typedef iterator<T> iterator;
            
            queue(){ front = nullptr; back = nullptr; }
            ~queue(){
                while(!isEmpty()){ dequeue(); }
            }

            // Queue related functions
            
            bool isEmpty(){ return front == nullptr; }
            
            void enqueue(const T & new_content){
                Node * new_node = new Node{new_content, nullptr};
                if (front == nullptr) {
                    front = new_node;
                    back = new_node;
                }
                back->nextNode = new_node;
                back = new_node;
            }
            
            void dequeue() {
                if (front != nullptr) {
                    Node * holder = front;
                    front = holder->nextNode;
                    holder->nextNode = nullptr;
                    delete holder;
                }
            }
            
            // Iterator functions
            
            iterator begin(){
                return iterator(front);
            }
            
            iterator end() {
                return iterator(nullptr);
            }
            
            // std::ostream overloading (cout, ofstream, ...)
            
            friend ostream& operator << (ostream &os, const queue & queue) {
                Node * pointer = queue.front;
                while( pointer != nullptr ) {
                    os << pointer->content << " ";
                    pointer = pointer->nextNode;
                }
                return os;
            }
    };

}