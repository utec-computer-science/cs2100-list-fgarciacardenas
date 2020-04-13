// singlyListTail.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace mySListTail {

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
    class SList {
        private:
            typedef Node<T> Node;

            Node * front;
            Node * back;
        
        public:
            typedef iterator<T> iterator;
            
            SList(){ front = nullptr; back = nullptr; }
            ~SList(){
                while(!isEmpty()){ pop_front(); }
            }

            // Single Linked List w/ tail related functions
            
            bool isEmpty(){ return front == nullptr; }
            
            void push_front(const T & new_content){
                Node * new_node = new Node{new_content, front};
                if (front == nullptr)
                    back = new_node;
                front = new_node;
            }

            void push_back(const T & new_content){
                Node * new_node = new Node{new_content, nullptr};
                if (front == nullptr) {
                    front = new_node;
                    back = new_node;
                }
                back->nextNode = new_node;
                back = new_node;
            }
            
            void pop_front() {
                if (front != nullptr) {
                    Node * holder = front;
                    front = holder->nextNode;
                    holder->nextNode = nullptr;
                    delete holder;
                }
            }

            void pop_back() {
                if (front != nullptr) {
                    Node * holder = front;
                    while( holder->nextNode->nextNode != nullptr ) {
                        holder = holder->nextNode;
                    }
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
            
            friend ostream& operator << (ostream &os, const SList & SList) {
                Node * pointer = SList.front;
                while( pointer != nullptr ) {
                    os << pointer->content << " ";
                    pointer = pointer->nextNode;
                }
                return os;
            }
    };

}