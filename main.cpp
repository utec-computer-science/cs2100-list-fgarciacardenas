#include "stack.hpp"
#include "queue.hpp"
#include "singlyList.hpp"
#include "singlyListTail.hpp"
#include "doublyList.hpp"
#include "doublyListTail.hpp"
#include "circularList.hpp"
#include "circularListTail.hpp"

int main(int argc, const char * argv[]) {
    
    // ---------------------- STACK ----------------------

    // Stack initilizer
    myStack::stack<int> stack;
    myStack::stack<int>::iterator it_s;

    // Insert values into stack
    stack.push(5); stack.push(6); stack.push(7); stack.push(1);
    stack.pop();
    
    // Print stack values by overloading <<
    cout << endl << "Stack values by overloading: " << stack << endl;

    // Print stack values using iterator
    cout << "Stack values by iterator: ";
    for(it_s = stack.begin() ; it_s != stack.end() ; ++it_s){
        cout << *it_s << " ";
    }
    cout << "\n";
    
    // ---------------------- QUEUE ----------------------

    // Queue initilizer
    myQueue::queue<int> queue;
    myQueue::queue<int>::iterator it_q;

    // Insert values into queue
    queue.enqueue(11); queue.enqueue(4); queue.enqueue(23); queue.enqueue(9);
    queue.dequeue();
    
    // Print queue values by overloading <<
    cout << endl << "Queue values by overloading: " << queue << endl;

    // Print queue values using iterator
    cout << "Queue values by iterator: ";
    for(it_q = queue.begin() ; it_q != queue.end() ; ++it_q){
        cout << *it_q << " ";
    }
    cout << "\n";

    // ---------------------- SINGLY LINKED LIST w/o tail ----------------------

    // Single Linked List initilizer
    mySList::SList<int> slist;
    mySList::SList<int>::iterator it_sl;

    // Insert values into Single Linked List
    slist.push_front(30); slist.push_front(14); slist.push_front(74);
    slist.push_back(92); slist.push_back(3);
    slist.pop_front(); slist.pop_back();
    
    // Print Single Linked List values by overloading <<
    cout << endl << "Singly List values by overloading: " << slist << endl;

    // Insert an element
    slist.insert(94, 1);

    // Erase an element
    slist.erase(3);

    // Print Single Linked List values using iterator
    cout << "Singly List values by iterator: ";
    for(it_sl = slist.begin() ; it_sl != slist.end() ; ++it_sl){
        cout << *it_sl << " ";
    }
    cout << "\n";

    // Override operator []
    cout << "Override operator []: " << slist[2] << endl;
    
    // Print size of the stack
    cout << "Size of the stack: " << slist.size() << endl;

    // Search for an element
    mySList::Node<int> * element = slist.search(14);
    cout << "Reference to element: " << element << endl;

    // Print maximum value
    mySList::Node<int> * max = slist.maximum();
    cout << "Max element: " << max->content << endl;

    // Print minimum value
    mySList::Node<int> * min = slist.minimum();
    cout << "Min element: " << min->content << endl;

    // Remove similar values
    slist.insert(4,1); slist.insert(4,3);
    cout << "List with repeating elements: " << slist << endl;
    slist.remove(4);
    cout << "Clear list: " << slist << endl; 

    // Reverse the elements of the list
    slist.reverse();
    cout << "Reversed list: " << slist << endl; 

    // ---------------------- SINGLY LINKED LIST w/ tail ----------------------

    // Single Linked List w/ tail initilizer
    mySListTail::SList<int> slistwt;
    mySListTail::SList<int>::iterator it_slwt;

    // Insert values into Single Linked List w/ tail
    slistwt.push_front(55); slistwt.push_front(38); slistwt.push_front(27);
    slistwt.push_back(72); slistwt.push_back(9);
    slistwt.pop_front(); slistwt.pop_back();
    
    // Print Single Linked List w/ tail values by overloading <<
    cout << endl << "Singly List w/ tail values by overloading: " << slistwt << endl;

    // Print Single Linked List w/ tail values using iterator
    cout << "Singly List w/ tail values by iterator: ";
    for(it_slwt = slistwt.begin() ; it_slwt != slistwt.end() ; ++it_slwt){
        cout << *it_slwt << " ";
    }
    cout << "\n";

    // ---------------------- DOUBLY LINKED LIST w/o tail ----------------------

    // Doubly Linked List initilizer
    myDList::DList<int> dlist;
    myDList::DList<int>::iterator it_dl;

    // Insert values into Doubly Linked List
    dlist.push_front(32); dlist.push_front(44); dlist.push_front(17);
    dlist.push_back(94); dlist.push_back(81);
    dlist.pop_front(); dlist.pop_back();
    
    // Print Doubly Linked List values by overloading <<
    cout << endl << "Doubly List values by overloading: " << dlist << endl;

    // Print Doubly Linked List values using iterator
    cout << "Doubly List values by iterator: ";
    for(it_dl = dlist.begin() ; it_dl != dlist.end() ; ++it_dl){
        cout << *it_dl << " ";
    }
    cout << "\n";

    // ---------------------- DOUBLY LINKED LIST w/ tail ----------------------

    // Doubly Linked List w/ tail initilizer
    myDListTail::DList<int> dlistwt;
    myDListTail::DList<int>::iterator it_dlwt;

    // Insert values into Doubly Linked List w/ tail
    dlistwt.push_front(11); dlistwt.push_front(19); dlistwt.push_front(64);
    dlistwt.push_back(45); dlistwt.push_back(77);
    dlistwt.pop_front(); dlistwt.pop_back();
    
    // Print Doubly Linked List w/ tail values by overloading <<
    cout << endl << "Doubly List w/ tail values by overloading: " << dlistwt << endl;

    // Print Doubly Linked List w/ tail values using iterator
    cout << "Doubly List w/ tail values by iterator: ";
    for(it_dlwt = dlistwt.begin() ; it_dlwt != dlistwt.end() ; ++it_dlwt){
        cout << *it_dlwt << " ";
    }
    cout << "\n";

    // ---------------------- CIRCULAR LINKED LIST w/o tail ----------------------

    // Circular Linked List initilizer
    myCList::CList<int> clist;
    myCList::CList<int>::iterator it_cl;

    // Insert values into Circular Linked List
    clist.push_front(93); clist.push_front(44); clist.push_front(51);
    clist.push_back(17); clist.push_back(28);
    clist.pop_front(); clist.pop_back();
    
    // Print Circular Linked List w/ tail values by overloading <<
    cout << endl << "Circular List values by overloading: " << clist << endl;

    // Print Circular Linked List values using iterator
    cout << "Circular List values by iterator: ";
    it_cl = clist.begin() ;
    do {
        cout << *it_cl << " ";
        ++it_cl;
    } while (it_cl != clist.end());
    cout << "\n";

    // ---------------------- CIRCULAR LINKED LIST w/ tail ----------------------

    // Circular Linked List w/ tail initilizer
    myCListTail::CList<int> clistwt;
    myCListTail::CList<int>::iterator it_clwt;

    // Insert values into Circular Linked List w/ tail
    clistwt.push_front(54); clistwt.push_front(67); clistwt.push_front(13);
    clistwt.push_back(22); clistwt.push_back(4);
    clistwt.pop_front(); clistwt.pop_back();
    
    // Print Circular Linked List w/ tail values by overloading <<
    cout << endl << "Circular List w/ tail values by overloading: " << clistwt << endl;

    // Print Circular Linked List values using iterator
    cout << "Circular List w/ tail values by iterator: ";
    it_clwt = clistwt.begin() ;
    do {
        cout << *it_clwt << " ";
        ++it_clwt;
    } while (it_clwt != clistwt.end());
    cout << "\n";
    
    return 0;
}
