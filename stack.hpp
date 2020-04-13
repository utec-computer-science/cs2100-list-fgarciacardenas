// stack.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace myStack {

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
    class stack {
    private:
        typedef Node<T> Node;
        
        Node * top;
        
    public:
        typedef iterator<T> iterator;
        
        stack(){ top = nullptr; }
        ~stack(){
            while(!isEmpty()){ pop(); }
        }

        // Stack related functions
        
        bool isEmpty(){ return top == nullptr; }
        
        void push(const T & new_content){
            Node * new_node = new Node{new_content, top};
            top = new_node;
        }
        
        void pop() {
            if (top != nullptr) {
                Node * holder = top;
                top = holder->nextNode;
                holder->nextNode = nullptr;
                delete holder;
            }
        }
        
        // Iterator functions
        
        iterator begin(){
            return iterator(top);
        }
        
        iterator end() {
            return iterator(nullptr);
        }
        
        // std::ostream overloading (cout, ofstream, ...)
        
        friend ostream& operator << (ostream &os, const stack & stack){
            Node * pointer = stack.top;
            while( pointer != nullptr ){
                os << pointer->content << " ";
                pointer = pointer->nextNode;
            }
            return os;
        }
    };

}