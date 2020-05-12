// list.hpp
#pragma once

#include<iostream>
#include <random>

using namespace std;

namespace myList {
    // --------------------- NODE DEFINITION --------------------- //
    template <typename T>
    class Node {
        public: 
            // Define the value type
            typedef T value_t;

            // Initialize the node value
            value_t value = NULL;
            
            // Default constructor
            Node(const value_t& _value = NULL) : value(_value) {}

            // Default destructor
            ~Node(){}

            // Override operator *
            value_t& operator*(){
                return value;
            }

            // Print node value
            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
                _out << "Node: " <<  _node.value;
                return _out;
            }
    };

    // --------------------- SINGLY NODE --------------------- //
    template <typename T>
    class SinglyListNode : public Node<T> {
        public:
            // Define the value type
            typedef typename Node<T>::value_t value_t;

            // Initialize the next node
            SinglyListNode<T> * next = nullptr;

            // Default constructor
            SinglyListNode(const T& _value = NULL) : Node<T>(_value), next(nullptr) {}

            // Default destructor
            ~SinglyListNode(){}

            // Print singly node information
            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const SinglyListNode<_T>& _node){
                _out << "Node: [v: " <<  _node.value << ", p: " << _node.next << "]";
                return _out;
            }
    };

    // --------------------- DOUBLY NODE --------------------- //
    template <typename T>
    class DoublyListNode : public Node<T> {
        public:
            // Define the value type
            typedef typename Node<T>::value_t value_t;
            
            // Initialize the next and prev nodes
            DoublyListNode<T> * next = nullptr;
            DoublyListNode<T> * prev = nullptr;

            // Default constructor
            DoublyListNode(const T& _value = NULL) : Node<T>(_value), next(nullptr), prev(nullptr) {}

            // Default destructor
            ~DoublyListNode(){}

            // Print doubly node information
            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const DoublyListNode<_T>& _node){
                _out << "Node: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.prev << "]";
                return _out;
            }
    };

    // --------------------- CIRCULAR NODE --------------------- //
    template <typename T>
    class CircularListNode : public Node<T> {
        public:
            // Define the value type
            typedef typename Node<T>::value_t value_t;
            
            // Initialize the next and prev nodes
            CircularListNode<T> * next = nullptr;

            // Default constructor
            CircularListNode(const T& _value = NULL) : Node<T>(_value), next(nullptr) {}

            // Default destructor
            ~CircularListNode(){}

            // Print circular node information
            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
                _out << "Node: [v: " <<  _node.value << ", p_next: " << _node.next << "]";
                return _out;
            }
    };

    // --------------------- DOUBLY CIRCULAR NODE --------------------- //
    template <typename T>
    class DoublyCircularListNode : public Node<T> {
        public:
            // Define the value type
            typedef typename Node<T>::value_t value_t;
            
            // Initialize the next and prev nodes
            DoublyCircularListNode<T> * next = nullptr;
            DoublyCircularListNode<T> * prev = nullptr;

            // Default constructor
            DoublyCircularListNode(const T& _value = NULL) : Node<T>(_value), next(nullptr), prev(nullptr) {}

            // Default destructor
            ~DoublyCircularListNode(){}

            // Print doubly node information
            template <typename _T>
            inline friend ostream& operator<< (ostream& _out, const DoublyCircularListNode<_T>& _node){
                _out << "Node: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.prev << "]";
                return _out;
            }
    };

    // --------------------- NODE TRAITS --------------------- //
    #define DEFAULT_NODE 0
    #define SINGLY_NODE 1
    #define DOUBLY_NODE 2
    #define CIRCULAR_NODE 3
    #define DOUBLY_CIRCULAR_NODE 4

    template <typename T, typename NT>
    struct NodeTraits{ 
        static const int nodeType = DEFAULT_NODE; 
    };

    template <typename NT>
    struct NodeTraits< SinglyListNode<NT>, NT >{
        static const int nodeType = SINGLY_NODE;
    };

    template <typename NT>
    struct NodeTraits< DoublyListNode<NT>, NT >{
        static const int nodeType = DOUBLY_NODE;
    };

    template <typename NT>
    struct NodeTraits< CircularListNode<NT>, NT >{
        static const int nodeType = CIRCULAR_NODE;
    };

    template <typename NT>
    struct NodeTraits< DoublyCircularListNode<NT>, NT >{
        static const int nodeType = DOUBLY_CIRCULAR_NODE;
    };

    // --------------------- LIST DEFINITION --------------------- //
    template <typename Node>
    class List{
    public:
        // Define the node, value and size types
        typedef Node node_t;
        typedef typename node_t::value_t value_t;
        typedef unsigned int size_t;
        
        class Iterator{
            private:
                // Initialize the node pointer
                node_t * pointer = nullptr;

            public: 
                // Default constructor
                Iterator(node_t* _pointer = nullptr) : pointer(_pointer) {}

                // Default destructor
                ~Iterator() {}

                // Override != operator
                virtual bool operator!= (Iterator it){ return pointer != it.pointer; }

                // Override * operator
                virtual value_t& operator* () { return **pointer; }

                void operator++ (void){
                    this->pointer = this->pointer->next; 
                }

                void operator ++(int n){
                    for (int i = 0; i < n; ++i)
                        this->pointer = this->pointer->next;
                }
        };

        protected:
            node_t *head = nullptr;
            node_t *tail = nullptr;

            template<int nodeType>
            void __push_front__(Node**&,Node**&,value_t);
            template<int nodeType2>
            void __push_back__(Node**&,Node**&,value_t);
            template<int nodeType3>
            node_t* __pop_front__(Node**&,Node**&);
            template<int nodeType4>
            node_t* __pop_back__(Node**&,Node**&);
            template<int nodeType5>
            void __insert__(Node**&,Node**&,Node*,value_t);
            template<int nodeType6>
            void __remove__(Node**&,Node**&,value_t);
            template<int nodeType7>
            void __erase__(Node**&,Node**&,Node*&);
            template<int nodeType8>
            void __clear__(Node**&,Node**&);
            template<int nodeType9>
            void __sort__(Node**&,Node**&);
            template<int nodeType10>
            void __reverse__(Node**&,Node**&);
            template<int nodeType11>
            size_t __size__(Node**&,Node**&);

        public:
            // Copy constructor: Builds a list based on another list
            List(List &_list){ 
                node_t * ptr = _list.head;
                int i = 0;
                while (ptr != nullptr) {
                    push_front(_list[i]->value);
                    ptr = ptr->next;
                    ++i;
                    if (ptr == _list.head)
                        return;
                }
            }
            
            // Array constructor: Fills a list based on an array
            List(value_t *arr, int n){ 
                for(int i = 0; i < n; ++i) {
                    push_back(arr[i]);
                }
            }

            // Node constructor: Returns a list with a single node
            List(node_t * singleNode){ 
                push_front(singleNode->value);
            }

            // Randomized constructor of size n
            List(int n){ 
                // Generate random seed
	            std::random_device dev;
	            std::mt19937 rng(dev());
                
                // Generate distribution in range [0, 100]
                if (std::is_same<value_t, char>::value) {
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
            List(void) : head(nullptr), tail(nullptr){}

            // Default destructor
            ~List (void){}
            
            void push_front(const value_t& element){
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __push_front__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer,element);
            }

            void push_back(const value_t& element){
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __push_back__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer,element);
            }

            node_t* pop_front(){
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                return __pop_front__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            node_t* pop_back(){
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                return __pop_back__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            void insert(node_t* ref, const value_t &element) {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __insert__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer,ref,element);
            }

            void remove(const value_t &element) {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __remove__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer,element);
            }

            void erase(node_t* &reference) {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __erase__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer,reference);
            }

            void clear() {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __clear__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            void sort() {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __sort__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            void reverse() {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                __reverse__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            size_t size() {
                node_t ** head_pointer = &head;
                node_t ** tail_pointer = &tail;
                return __size__<NodeTraits<node_t,value_t>::nodeType>(head_pointer,tail_pointer);
            }

            Iterator begin(){ return Iterator(head); }

            Iterator end(){ return Iterator(tail); }

            value_t& front(void){ return head->value; }; 

            value_t& back(void){ return tail->value; };  

            // Random access
            node_t* operator[] (const int& _position){
                node_t * tmp = head;
                for (int i = 0; i < _position; i++, tmp = tmp->next);
                return tmp;
            }

            bool empty(void){ return head == nullptr; }

            inline friend ostream& operator<< (ostream& out, List<node_t>& _list){
                typename List<node_t>::Iterator it = _list.begin();
                for(; it != _list.end(); ++it){
                    out << *it << " -> ";
                }
                out << *it << " -> ";
                return out;
            }

            List& operator<< (const value_t& _value){
                this->push_back(_value);
                return *this;
            }

            List& operator>> (const value_t& _value){
                this->push_front(_value);
                return *this;
            }
    };

    // --------------------- DEFAULT LIST HELPER --------------------- //
    template <typename Node, typename ValueNode, int nodeType>
    class ListHelper{
        public:
            static void push_front(Node** &head, Node** &tail, ValueNode element){
                cout << "Trait type was not defined" << endl;
            }
            static void push_back(Node** &head, Node** &tail, ValueNode element){
                cout << "Trait type was not defined" << endl;
            }
            static Node* pop_front(Node** &head, Node** &tail){
                cout << "Trait type was not defined" << endl;
                return nullptr;
            }
            static Node* pop_back(Node** &head, Node** &tail){
                cout << "Trait type was not defined" << endl;
                return nullptr;
            }
            static void insert(Node** &head, Node** &tail, Node* ref, const ValueNode &element) {
                cout << "Trait type was not defined" << endl;
            }
            static void remove(Node** &head, Node** &tail, const ValueNode &element) {
                cout << "Trait type was not defined" << endl;
            }
            static void erase(Node** &head, Node** &tail, Node* &ref) {
                cout << "Trait type was not defined" << endl;
            }
            static void clear(Node** &head, Node** &tail) {
                cout << "Trait type was not defined" << endl;
            }
            static void sort(Node** &head, Node** &tail) {
                cout << "Trait type was not defined" << endl;
            }
            static void reverse(Node** &head, Node** &tail) {
                cout << "Trait type was not defined" << endl;
            }
            static unsigned int size(Node** &head, Node** &tail) {
                cout << "Trait type was not defined" << endl;
            }
    };

    template <typename Node, typename ValueNode>
    class ListHelper<Node,ValueNode,SINGLY_NODE>{
        public:
            // // Insert an element at the front
            static void push_front(Node** &head, Node** &tail, ValueNode element) {
                Node *new_node = new Node(element);
                if (!(*head)) {
                    *tail = new_node;
                    *head = new_node;
                } else {
                    new_node->next = *head;
                    *head = new_node;
                }
            }
            
            // Insert an element at the back
            static void push_back(Node** &head, Node** &tail, ValueNode element){
                Node *new_node = new Node(element);
                if (!(*head))
                    *tail = *head = new_node;
                else {
                    (*tail)->next = new_node;
                    *tail = (*tail)->next;
                }
            }

            // Delete the element at the front
            static Node* pop_front(Node** &head, Node** &tail) {
                Node *ret = new Node((*head)->value);
                Node *ptr = *head;
                *head = ptr->next;
                delete ptr;
                return ret;
            }

            // Delete the element at the back
            static Node* pop_back(Node** &head, Node** &tail) {
                Node *ret = new Node((*tail)->value);
                Node *ptr = *head;
                while(ptr->next != (*tail)){
                    ptr = ptr->next;
                }
                *tail = ptr;
                delete (*tail)->next;
                (*tail)->next = nullptr;
                return ret;
            }
            
            // Inserta un elemento en base a un puntero
            static void insert(Node** &head, Node** &tail, Node* ref, const ValueNode &element) {
                for (Node *ptr = *head; ptr != nullptr; ptr = ptr->next){
                    if (ptr == ref) {
                        Node *new_node = new Node(element);
                        new_node->next = ptr->next;
                        ptr->next = new_node;
                        if (ref == *tail)
                            *tail = new_node;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            }

            // Elimina todos los elementos por similitud
            static void remove(Node** &head, Node** &tail, const ValueNode &element) {
                Node * tmp;
                for (Node * ptr = *head; ptr != nullptr; ptr = ptr->next) { 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(head, tail, ptr);
                        ptr = tmp;
                    }
                }
            }
            
            // Elimina un elemento en base a un puntero
            static void erase(Node** &head, Node** &tail, Node* &ref) {
                if (ref == *head) {
                    *head = (*head)->next;
                    delete ref;
                    return;
                }
                for (Node *ptr = *head; ptr != nullptr; ptr = ptr->next){
                    if (ptr->next == ref) {
                        ptr->next = ptr->next->next;
                        if (ref == *tail)
                            *tail = ptr;
                        delete ref;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            } 

            // Elimina toda la lista
            static void clear(Node** &head, Node** &tail) { 
                while(*head != nullptr){ pop_front(head, tail); } 
            } 

            // Ordena la lista usando BubbleSort
            static void sort(Node** &head, Node** &tail) {
                bool fin; 
                Node * ptr; 
                Node * hold = nullptr; 
            
                do { 
                    ptr = *head; 
                    fin = false; 
            
                    while (ptr->next != hold) { 
                        if (ptr->value > ptr->next->value) {  
                            ValueNode tmp = ptr->value; 
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
            static void reverse(Node** &head, Node** &tail) {
                push_front(head, tail, (*tail)->value);
                pop_back(head, tail);
                for (Node * ptr = *head; ptr->next != nullptr; ptr = ptr->next) {
                    insert(head, tail, ptr, (*tail)->value);
                    pop_back(head, tail);
                }
            }

            static unsigned int size(Node** &head, Node** &tail){
                unsigned int i = 0;
                for (Node * tmp = *head; tmp != nullptr; i++, tmp = tmp->next);
                return i;
            }
    };

    template <typename Node, typename ValueNode>
        class ListHelper<Node,ValueNode,DOUBLY_NODE>{
        public:
            public:
            // // Insert an element at the front
            static void push_front(Node** &head, Node** &tail, ValueNode element) {
                Node *new_node = new Node(element);
                new_node->next = *head;
                if (*head == nullptr)
                    *tail = new_node;
                else
                    (*head)->prev = new_node;
                *head = new_node;
            }
            
            // Insert an element at the back
            static void push_back(Node** &head, Node** &tail, ValueNode element){
                Node *new_node = new Node(element);
                new_node->prev = *tail;
                if (*head == nullptr)
                    *head = new_node;
                else
                    (*tail)->next = new_node;
                *tail = new_node;
            }

            // Delete the element at the front
            static Node* pop_front(Node** &head, Node** &tail) {
                Node *ret = new Node((*head)->value);
                Node *ptr = *head;
                *head = ptr->next;
                if (*head != nullptr)
                    (*head)->prev = nullptr;
                delete ptr;
                return ret;
            }

            // Delete the element at the back
            static Node* pop_back(Node** &head, Node** &tail) {
                Node *ret = new Node((*tail)->value);
                Node *ptr = (*tail)->prev;
                delete (*tail);
                (*tail) = ptr;
                (*tail)->next = nullptr;
                return ret;
            }
            
            // Inserta un elemento en base a un puntero
            static void insert(Node** &head, Node** &tail, Node* ref, const ValueNode &element) {
                for (Node *ptr = *head; ptr != nullptr; ptr = ptr->next){
                    if (ptr == ref) {
                        Node *new_node = new Node(element);
                        new_node->next = ptr->next;
                        new_node->prev = ptr;
                        ptr->next = new_node;
                        if (ref == *tail)
                            *tail = new_node;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            }

            // Elimina todos los elementos por similitud
            static void remove(Node** &head, Node** &tail, const ValueNode &element) {
                Node * tmp;
                for (Node * ptr = *head; ptr != nullptr; ptr = ptr->next) { 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(head, tail, ptr);
                        ptr = tmp;
                    }
                }
            }
            
            // Elimina un elemento en base a un puntero
            static void erase(Node** &head, Node** &tail, Node* &ref) {
                Node * tmp = nullptr;
                if (ref == *head) {
                    *head = (*head)->next;
                    (*head)->prev = nullptr;
                    delete ref;
                    return;
                }
                for (Node *ptr = *head; ptr != nullptr; ptr = ptr->next){
                    if (ptr->next == ref) {
                        tmp = ptr->next->next;
                        ptr->next = ptr->next->next;
                        tmp->prev = ptr;
                        if (ref == *tail)
                            *tail = ptr;
                        delete ref;
                        return;
                    }
                }
                cout << "The reference element was not found" << endl;
            } 

            // Elimina toda la lista
            static void clear(Node** &head, Node** &tail) { 
                while(*head != nullptr){ pop_front(head, tail); } 
            } 

            // Ordena la lista usando BubbleSort
            static void sort(Node** &head, Node** &tail) {
                bool fin; 
                Node * ptr; 
                Node * hold = nullptr; 
            
                do { 
                    ptr = *head; 
                    fin = false; 
            
                    while (ptr->next != hold) { 
                        if (ptr->value > ptr->next->value) {  
                            ValueNode tmp = ptr->value; 
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
            static void reverse(Node** &head, Node** &tail) {
                Node * tmp = nullptr;
                for (Node * ptr = *tail; (*head)->next != nullptr; ptr = ptr->next) {
                    tmp = ptr->prev;
                    ptr->prev = ptr->next;
                    ptr->next = tmp;
                }
                tmp = *head;
                *head = *tail;
                *tail = tmp;
            }

            static unsigned int size(Node** &head, Node** &tail){
                unsigned int i = 0;
                for (Node * tmp = *head; tmp != nullptr; i++, tmp = tmp->next);
                return i;
            }
    };

    template <typename Node, typename ValueNode>
        class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
        public:
            public:
            // // Insert an element at the front
            static void push_front(Node** &head, Node** &tail, ValueNode element) {
                Node *new_node = new Node(element);
                new_node->next = *head;
                if (*head == nullptr)
                    *tail = new_node;
                *head = new_node;
                (*tail)->next = *head;
            }
            
            // Insert an element at the back
            static void push_back(Node** &head, Node** &tail, ValueNode element){
                Node *new_node = new Node(element);
                new_node->next = *head;
                if (*head == nullptr) {
                    *head = new_node;
                    new_node->next = *head;
                } else
                    (*tail)->next = new_node;
                *tail = new_node;
            }

            // Delete the element at the front
            static Node* pop_front(Node** &head, Node** &tail) {
                Node *ret = new Node((*head)->value);
                Node *ptr = *head;
                *head = ptr->next;
                ptr->next = nullptr;
                (*tail)->next = *head;
                delete ptr;
                if (ptr == *head) {
                    *head = nullptr;
                    *tail = nullptr;
                }
                return ret;
            }

            // Delete the element at the back
            static Node* pop_back(Node** &head, Node** &tail) {
                Node *ret = new Node((*tail)->value);
                Node *ptr = *head;
                while (ptr->next->next != *head)
                    ptr = ptr->next;
                
                Node * tmp = ptr->next;
                delete ptr->next;
                *tail = ptr;
                (*tail)->next = *head;
                return ret;
            }
            
            // Inserta un elemento en base a un puntero
            static void insert(Node** &head, Node** &tail, Node* ref, const ValueNode &element) {
                Node * ptr = *head;
                do {
                    if (ptr == ref) {
                        Node * new_node = new Node(element);
                        new_node->next = ptr->next;
                        ptr->next = new_node;
                        if (ref == *tail)
                            *tail = new_node;
                        return;
                    }
                    ptr = ptr->next;
                } while (ptr != *head);
                cout << "The reference element was not found" << endl;
            }

            // Elimina todos los elementos por similitud
            static void remove(Node** &head, Node** &tail, const ValueNode &element) {
                Node * ptr = *head;
                Node * tmp;
                do { 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(head, tail, ptr);
                        ptr = tmp;
                    } else
                        ptr = ptr->next;
                } while (ptr != *head);
            }
            
            // Elimina un elemento en base a un puntero
            static void erase(Node** &head, Node** &tail, Node* &ref) {
                Node * ptr = *head;
                if (ref == *head) {
                    *head = (*head)->next;
                    (*tail)->next = *head;
                    delete ref;
                    return;
                }
                do {
                    if (ptr->next == ref) {
                        ptr->next = ptr->next->next;
                        if (ref == *tail)
                            *tail = ptr;
                        delete ref;
                        return;
                    }
                    ptr = ptr->next;
                } while (ptr != *head);
                
                cout << "The reference element was not found" << endl;
            } 

            // Elimina toda la lista
            static void clear(Node** &head, Node** &tail) { 
                while(*head != nullptr){ pop_front(head, tail); }
            } 

            // Ordena la lista usando BubbleSort
            static void sort(Node** &head, Node** &tail) {
                bool fin; 
                Node * ptr; 
                Node * hold = *head; 
            
                do { 
                    ptr = *head; 
                    fin = false; 
            
                    while (ptr->next != hold) { 
                        if (ptr->value > ptr->next->value) {  
                            ValueNode tmp = ptr->value; 
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
            static void reverse(Node** &head, Node** &tail) {
                push_front(head, tail, (*tail)->value);
                pop_back(head, tail);
                Node * ptr = *head;
                do {
                    insert(head, tail, ptr, (*tail)->value);
                    pop_back(head, tail);
                    ptr = ptr->next;
                } while (ptr != *head);
            }

            static unsigned int size(Node** &head, Node** &tail){
                unsigned int i = 0;
                if (*head != nullptr) {
                    Node * tmp = *head;
                    do {
                        i++;
                        tmp = tmp->next;
                    } while (tmp != *head);
                }
                return i;
            }
    };

    template <typename Node, typename ValueNode>
        class ListHelper<Node,ValueNode,DOUBLY_CIRCULAR_NODE>{
        public:
            public:
            // // Insert an element at the front
            static void push_front(Node** &head, Node** &tail, ValueNode element) {
                Node *new_node = new Node(element);
                new_node->next = *head;
                new_node->prev = *tail;
                if (*head == nullptr) {
                    *tail = new_node;
                    (*tail)->next = new_node;
                    (*tail)->prev = new_node;
                } else
                    (*head)->prev = new_node;
                *head = new_node;
                (*tail)->next = *head;
            }
            
            // Insert an element at the back
            static void push_back(Node** &head, Node** &tail, ValueNode element){
                Node *new_node = new Node(element);
                new_node->next = *head;
                new_node->prev = *tail;
                if (*head == nullptr) {
                    *head = new_node;
                    new_node->next = *head;
                    new_node->prev = *head;
                } else
                    (*tail)->next = new_node;
                *tail = new_node;
            }

            // Delete the element at the front
            static Node* pop_front(Node** &head, Node** &tail) {
                Node *ret = new Node((*head)->value);
                Node *ptr = *head;
                *head = ptr->next;
                if (*head != nullptr)
                    (*head)->prev = *tail;
                (*tail)->next = *head;
                delete ptr;
                if (ptr == *head) {
                    *head = nullptr;
                    *tail = nullptr;
                }
                return ret;
            }

            // Delete the element at the back
            static Node* pop_back(Node** &head, Node** &tail) {
                Node *ret = new Node((*tail)->value);
                Node * ptr = (*tail)->prev;
                delete (*tail);
                *tail = ptr;
                (*tail)->next = *head;
                return ret;
            }
            
            // Inserta un elemento en base a un puntero
            static void insert(Node** &head, Node** &tail, Node* ref, const ValueNode &element) {
                Node * ptr = *head;
                do {
                    if (ptr == ref) {
                        Node * new_node = new Node(element);
                        new_node->next = ptr->next;
                        new_node->prev = ptr;
                        ptr->next = new_node;
                        if (ref == *tail)
                            *tail = new_node;
                        return;
                    }
                    ptr = ptr->next;
                } while (ptr != *head);
                cout << "The reference element was not found" << endl;
            }

            // Elimina todos los elementos por similitud
            static void remove(Node** &head, Node** &tail, const ValueNode &element) {
                Node * ptr = *head;
                Node * tmp;
                do { 
                    if (ptr->value == element) {
                        tmp = ptr->next;
                        erase(head, tail, ptr);
                        ptr = tmp;
                    } else
                        ptr = ptr->next;
                } while (ptr != *head);
            }
            
            // Elimina un elemento en base a un puntero
            static void erase(Node** &head, Node** &tail, Node* &ref) {
                Node * ptr = *head;
                Node * tmp = nullptr;
                if (ref == *head) {
                    *head = (*head)->next;
                    (*head)->prev = *tail;
                    delete ref;
                    return;
                }
                do {
                    if (ptr->next == ref) {
                        tmp = ptr->next->next;
                        ptr->next = tmp;
                        tmp->prev = ptr;
                        if (ref == *tail) {
                            (*tail) = ptr;
                            (*tail)->next = *head;
                        }
                        delete ref;
                        return;
                    }
                    ptr = ptr->next;
                } while (ptr != *head);
                
                cout << "The reference element was not found" << endl;
            } 

            // Elimina toda la lista
            static void clear(Node** &head, Node** &tail) { 
                while(*head != nullptr){ pop_front(head, tail); }
            } 

            // Ordena la lista usando BubbleSort
            static void sort(Node** &head, Node** &tail) {
                bool fin; 
                Node * ptr; 
                Node * hold = *head; 
            
                do { 
                    ptr = *head; 
                    fin = false; 
            
                    while (ptr->next != hold) { 
                        if (ptr->value > ptr->next->value) {  
                            ValueNode tmp = ptr->value; 
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
            static void reverse(Node** &head, Node** &tail) {
                Node * ptr = *tail;
                Node * tmp = nullptr;
                do {
                    tmp = ptr->prev;
                    ptr->prev = ptr->next;
                    ptr->next = tmp;
                    ptr = ptr->next;
                } while ((*head)->next != *tail);

                tmp = *head;
                *head = *tail;
                *tail = tmp;
            }

            static unsigned int size(Node** &head, Node** &tail){
                unsigned int i = 0;
                if (*head != nullptr) {
                    Node * tmp = *head;
                    do {
                        i++;
                        tmp = tmp->next;
                    } while (tmp != *head);
                }
                return i;
            }
    };

    // Override SinglyList functions
    template<typename Node> template<int nodeType>
    void List<Node>::__push_front__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail, 
        typename List<Node>::value_t element){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front(head,tail,element);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__push_back__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail, 
        typename List<Node>::value_t element){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back(head,tail,element);
    }

    template<typename Node> template<int nodeType>
    Node* List<Node>::__pop_front__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        return ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_front(head,tail);
    }

    template<typename Node> template<int nodeType>
    Node* List<Node>::__pop_back__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        return ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back(head,tail);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__insert__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail,
        typename List<Node>::node_t * ref,
        typename List<Node>::value_t element){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::insert(head,tail,ref,element);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__remove__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail,
        typename List<Node>::value_t element){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::remove(head,tail,element);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__erase__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail,
        typename List<Node>::node_t * &reference){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::erase(head,tail,reference);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__clear__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::clear(head,tail);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__sort__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::sort(head,tail);
    }

    template<typename Node> template<int nodeType>
    void List<Node>::__reverse__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::reverse(head,tail);
    }

    template<typename Node> template<int nodeType>
    unsigned int List<Node>::__size__(
        typename List<Node>::node_t ** &head, 
        typename List<Node>::node_t ** &tail){
    
        return ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::size(head,tail);
    }

    typedef SinglyListNode<float> singly_node_t;
    typedef List<singly_node_t> list_t;

    typedef DoublyListNode<float> double_node_t;
    typedef List<double_node_t> dlist_t;

    typedef CircularListNode<float> circular_node_t;
    typedef List<circular_node_t> clist_t;

    typedef DoublyCircularListNode<float> doubly_circular_node_t;
    typedef List<doubly_circular_node_t> dclist_t;
}