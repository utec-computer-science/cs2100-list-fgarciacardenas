// singlyList.hpp
#pragma once

#include <iostream>
#include <ostream>
using namespace std;

namespace mySList {

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

            Node * front = nullptr;
            unsigned int length = 0;
        
        public:
            typedef iterator<T> iterator;
            
            // Copy constructor: Builds a list based on another list
            SList(SList* List){ 
                front = List.front;
                length = List.length;
            }
            
            // Array constructor: Fills a list based on an array
            SList(T*){ 
                front = T[0];
                length = T.size();
            }

            // Node constructor: Returns a list with a single node
            SList(Node* singleNode){ 
                front = singleNode;
                length = 1;
            }

            // Randomized constructor of size n
            SList(int n){ 
                for(int i = 0; i < n; ++i) {
                    Node * new_node = new Node{rand(), front};
                    front = new_node;
                    ++length;
                }
            }
            
            // Default constructor
            SList(void){ 
                front = nullptr;
            }

            // Default destructor
            ~SList(void){
                while(!isEmpty()){ pop_front(); }
            }

            // Single Linked List related functions
            
            bool isEmpty(){ return front == nullptr; }
            
            void push_front(const T & new_content){
                Node * new_node = new Node{new_content, front};
                front = new_node;
                ++length;
            }

            void push_back(const T & new_content){
                Node * new_node = new Node{new_content, nullptr};
                if (front == nullptr)
                    front = new_node;
                Node * pointer = front;
                while( pointer->nextNode != nullptr ) {
                    pointer = pointer->nextNode;
                }
                pointer->nextNode = new_node;
                ++length;
            }
            
            void pop_front() {
                if (front != nullptr) {
                    Node * holder = front;
                    front = holder->nextNode;
                    holder->nextNode = nullptr;
                    delete holder;
                    --length;
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
                    --length;
                }
            }

            // Access an element
            T operator[] (const int& pos) {
                Node * ptr = front;
                int i = 0;
                
                for (ptr = front; ptr != nullptr; ptr = ptr->nextNode){
                    if (i == pos)
                        return ptr->content;
                    i++;
                }

                return NULL;
            }

            unsigned int size() {
                return length;
            }; 

            void erase(const int& pos) {
                if (pos >= length) {
                    cout << "The desired position is out of bounds";
                } else {
                    Node * ptr = front;
                    int i = 0;

                    for (ptr = front; ptr != nullptr; ptr = ptr->nextNode){
                        if(i == (pos - 1)) {
                            Node * temp = ptr->nextNode;
                            ptr->nextNode = ptr->nextNode->nextNode;
                            delete temp;
                            --length;
                            break;
                        }
                        ++i;
                    }
                }
            }

            mySList::Node<int> * search(const int& element) {
                if (front != nullptr) {
                    Node * ptr = front;
                    while( ptr->nextNode != nullptr ) {
                        if ( ptr->content == element )
                            return ptr; 
                        ptr = ptr->nextNode;
                    }
                }
                return nullptr;
            }

            // Eliminate the whole list
            void clear() {
                while(!isEmpty()){ pop_front(); }
            }

            // Insert an element in the list
            void insert(const T& element, const int& pos) {
                if (pos >= length) {
                    cout << "The desired position is out of bounds";
                    
                } else if (front != nullptr) {
                    Node * ptr = front;
                    Node * new_node = new Node{element, nullptr};
                    int i = 0;
                    
                    for (ptr = front; ptr != nullptr; ptr = ptr->nextNode){
                        if (i == (pos - 1)) {
                            new_node->nextNode = ptr->nextNode;
                            ptr->nextNode = new_node;
                            break;
                        }
                        i++;
                    }
                    ++length;
                } else {
                    push_front(element);
                }
            }

            // Find the maximum value
            mySList::Node<T> * maximum() {
                if (front != nullptr) {
                    Node * ptr = front;
                    Node * max = front;
                
                    while( ptr != nullptr ) {
                        if (max->content < ptr->content)
                            max = ptr;
                        ptr = ptr->nextNode;
                    }

                    return max;
                }
                return nullptr;
            }

            // Find the minimum value
            mySList::Node<T> * minimum() {
                if (front != nullptr) {
                    Node * ptr = front;
                    Node * min = front;

                    while( ptr != nullptr ) {
                        if (min->content > ptr->content)
                            min = ptr;
                        ptr = ptr->nextNode;
                    }

                    return min;
                }
                return nullptr;
            }

            // Remove similar elements
            void remove(const int& element) {
                if (front != nullptr) {
                    Node * ptr = front;
                    while( ptr->nextNode != nullptr ) {
                        if ( ptr->nextNode->content == element )
                            Node * temp = ptr->nextNode;
                            ptr->nextNode = ptr->nextNode->nextNode;
                            --length;
                        ptr = ptr->nextNode;
                    }
                }
            }

            // Reverse the list order
            void reverse() {
                if (front != nullptr) {
                    Node * ptr = front;
                    Node * temp = front;
                    for(int i = 1; i < length; ++i) {
                        while( ptr->nextNode->nextNode != nullptr ) {
                            ptr = ptr->nextNode;
                        }
                        front = ptr->nextNode;
                        ptr->nextNode = nullptr;
                        front->nextNode = temp;
                        ptr = front;
                        temp = front;
                    }
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