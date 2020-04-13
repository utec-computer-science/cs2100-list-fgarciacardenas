// circularList.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace myCList {

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
    class CList {
        private:
            typedef Node<T> Node;

            Node * front;
        
        public:
            typedef iterator<T> iterator;
            
            CList(){ front = nullptr; }
            ~CList(){
                while(!isEmpty()){ pop_front(); }
            }

            // Single Linked List related functions
            
            bool isEmpty(){ return front == nullptr; }
            
            void push_front(const T & new_content){
                Node * new_node = new Node{new_content, front};
                if (front == nullptr) {
                    front = new_node;
                    front->nextNode = front;
                } else {
                    Node * pointer = front;
                    while( pointer->nextNode != front ) {
                        pointer = pointer->nextNode;
                    }
                    pointer->nextNode = new_node;
                    front = new_node;
                }
            }

            void push_back(const T & new_content){
                Node * new_node = new Node{new_content, front};
                if (front == nullptr) {
                    front = new_node;
                    front->nextNode = front;
                } else {
                    Node * pointer = front;
                    while( pointer->nextNode != front ) {
                        pointer = pointer->nextNode;
                    }
                    pointer->nextNode = new_node;
                }
            }
            
            void pop_front() {
                if (front != nullptr) {
                    Node * holder = front;
                    Node * pointer = front;
                    while( pointer->nextNode != front ) {
                        pointer = pointer->nextNode;
                    }
                    front = holder->nextNode;
                    pointer->nextNode = front;
                    holder->nextNode = nullptr;
                    delete holder;
                }
            }

            void pop_back() {
                if (front != nullptr) {
                    Node * holder = front;
                    while( holder->nextNode->nextNode != front ) {
                        holder = holder->nextNode;
                    }
                    delete holder->nextNode;
                    holder->nextNode = front;
                }
            }
            
            // Iterator functions
            
            iterator begin(){
                return iterator(front);
            }
            
            iterator end() {
                return iterator(front);
            }
            
            // std::ostream overloading (cout, ofstream, ...)
            
            friend ostream& operator << (ostream &os, const CList & CList) {
                Node * pointer = CList.front;
                do {
                    os << pointer->content << " ";
                    pointer = pointer->nextNode;
                } while( pointer != CList.front );
                return os;
            }
    };

}