// doublyListTail.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace myDListTail {

    template <typename T>
    struct Node {
        T content;
        Node<T> * nextNode;
        Node<T> * prevNode;
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

            void operator --(){
                this->pointer = this->pointer->prevNode;
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
    class DList {
        private:
            typedef Node<T> Node;

            Node * front;
            Node * back;
        
        public:
            typedef iterator<T> iterator;
            
            DList(){ front = nullptr; }
            ~DList(){
                while(!isEmpty()){ pop_front(); }
            }

            // Doubly Linked List related functions
            
            bool isEmpty(){ return front == nullptr; }
            
            void push_front(const T & new_content){
                Node * new_node = new Node{new_content, front, nullptr};
                if (front == nullptr) {
                    front = new_node;
                    back = new_node;
                } else {
                    front->prevNode = new_node;
                    front = new_node;
                }
            }

            void push_back(const T & new_content){
                Node * new_node = new Node{new_content, nullptr, nullptr};
                if (front == nullptr) {
                    front = new_node;
                    back = new_node;
                }
                back->nextNode = new_node;
                back->nextNode->prevNode = back;
                back = new_node;
            }
            
            void pop_front() {
                if (front != nullptr) {
                    Node * holder = front;
                    front = holder->nextNode;
                    holder->nextNode->prevNode = nullptr;
                    holder->nextNode = nullptr;
                    delete holder;
                }
            }

            void pop_back() {
                if (front != nullptr) {
                    Node * holder = back->prevNode;
                    holder->nextNode->prevNode = nullptr;
                    holder->nextNode = nullptr;
                    delete holder->nextNode;
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
            
            friend ostream& operator << (ostream &os, const DList & DList) {
                Node * pointer = DList.front;
                while( pointer != nullptr ) {
                    os << pointer->content << " ";
                    pointer = pointer->nextNode;
                }
                return os;
            }
    };
}