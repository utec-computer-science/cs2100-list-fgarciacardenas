#include <iostream>
#include "lists.hpp"

using namespace std;
using namespace myList;

int main(int argc, const char * argv[]) {
    
    // ---------------------- SINGLY LINKED LIST ---------------------- //
    
    // Single Linked List initilizer
    cout << endl << "// ------------ SINGLY LINKED LIST TEST ------------ //" << endl;
    list_t list;

    // Insert values into Singly Linked List
    list >> 55 >> 38 >> 27;
    list << 72 << 9 << 43;
    
    // Reference to first element
    cout << "First element: " << list.front() << endl;

    // Reference to last element
    cout << "Last element:  " << list.back() << endl << endl;

    // Pop values from Singly Linked List
    cout << "Popped value:  " << list.pop_front() << endl;
    cout << "Popped value:  " << list.pop_back() << endl << endl;

    // Print Singly Linked List values by overloading <<
    cout << "Singly List values: " << list << endl;

    // Random access
    auto snode = list[2];
    cout << "Random access dir [2]: " << snode->value << ", p: " << &snode << endl;

    // Check if list is empty
    cout << "Is the list empty?: " << boolalpha << list.empty() << endl;

    // Print size of the list
    cout << "Size of the list: " << list.size() << endl;

    // Insert repeating values
    list.insert(snode,3); list.insert(list[0],3);
    cout << "List with repeating values: " << list << endl;

    // Remove repeting values
    list.remove(3);
    cout << "List w/o repeating values: " << list << endl;

    // // Erase an element
    list.erase(snode);
    cout << "List after erasing element: " << list << endl;

    // Clear the list
    list.clear();
    cout << "Size of cleared list: " << list.size() << endl;

    // Create a random list
    list_t random_list(5);
    cout << "Random list: " << random_list << endl;
    
    // Sort the list
    random_list.sort();
    cout << "Sorted list: " << random_list << endl;

    // Reverse the list
    random_list.reverse();
    cout << "Reversed list: " << random_list << endl;

    // Copy the list
    list_t copy_list(random_list);
    cout << "Copied list: " << copy_list << endl;

    // Create a list based on an array
    float arr[] = {1.0,2.0,3.0,4.0,5.0};
    list_t arr_list(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "Array list: " << arr_list << endl;

    // ---------------------- DOUBLY LINKED LIST ---------------------- //

    // Doubly Linked List initilizer
    cout << endl << "// ------------ DOUBLY LINKED LIST TEST ------------ //" << endl;
    dlist_t dlist;

    // Insert values into Doubly Linked List
    dlist.push_front(11); dlist.push_front(34); dlist.push_front(6);
    dlist.push_back(23); dlist.push_back(97); dlist.push_back(88);
    
    // Reference to first element
    cout << "First element: " << dlist.front() << endl;

    // Reference to last element
    cout << "Last element:  " << dlist.back() << endl << endl;

    // Pop values from Doubly Linked List
    cout << "Popped value:  " << dlist.pop_front() << endl;
    cout << "Popped value:  " << dlist.pop_back() << endl << endl;

    // Print Doubly Linked List values by overloading <<
    cout << "Doubly List values: " << dlist << endl;

    // Random access
    auto dnode = dlist[2];
    cout << "Random access dir [2]: " << dnode->value << ", p: " << &dnode << endl;

    // Check if list is empty
    cout << "Is the list empty?: " << boolalpha << dlist.empty() << endl;

    // Print size of the list
    cout << "Size of the list: " << dlist.size() << endl;

    // Insert repeating values
    dlist.insert(dnode,3); dlist.insert(dlist[0],3);
    cout << "List with repeating values: " << dlist << endl;

    // Remove repeting values
    dlist.remove(3);
    cout << "List w/o repeating values: " << dlist << endl;

    // Erase an element
    dlist.erase(dnode);
    cout << "List after erasing element: " << dlist << endl;

    // Clear the list
    dlist.clear();
    cout << "Size of cleared list: " << dlist.size() << endl;

    // Create a random list
    dlist_t random_dlist(5);
    cout << "Random list: " << random_dlist << endl;

    // Sort the list
    random_dlist.sort();
    cout << "Sorted list: " << random_dlist << endl;

    // Reverse the list
    random_dlist.reverse();
    cout << "Reversed list: " << random_dlist << endl;

    // Copy the list
    dlist_t copy_dlist(random_dlist);
    cout << "Copied list: " << copy_dlist << endl;

    // Create a list based on an array
    float arr2[] = {6.0,7.0,8.0,9.0,10.0};
    dlist_t arr_dlist(arr2, sizeof(arr2)/sizeof(arr2[0]));
    cout << "Array list: " << arr_dlist << endl;

    // ---------------------- CIRCULAR LINKED LIST ---------------------- //

    // Circular Linked List initilizer
    cout << endl << "// ------------ CIRCULAR LINKED LIST TEST ------------ //" << endl;
    clist_t clist;

    // Insert values into Circular Linked List
    clist >> 84 >> 92 >> 70;
    clist << 61 << 46 << 25;
    
    // Reference to first element
    cout << "First element: " << clist.front() << endl;

    // Reference to last element
    cout << "Last element:  " << clist.back() << endl << endl;

    // Pop values from Circular Linked List
    cout << "Popped value:  " << clist.pop_front() << endl;
    cout << "Popped value:  " << clist.pop_back() << endl << endl;

    // Print Circular Linked List values by overloading <<
    cout << "Circular List values: " << clist << endl;

    // Random access
    auto cnode = clist[2];
    cout << "Random access dir: " << cnode << ", value: " << cnode->value << endl;

    // Check if list is empty
    cout << "Is the list empty?: " << boolalpha << clist.empty() << endl;

    // Print size of the list
    cout << "Size of the list: " << clist.size() << endl;

    // Insert repeating values
    clist.insert(cnode,3); clist.insert(clist[0],3);
    cout << "List with repeating values: " << clist << endl;

    // Remove repeting values
    clist.remove(3);
    cout << "List w/o repeating values: " << clist << endl;

    // Erase an element
    clist.erase(cnode);
    cout << "List after erasing element: " << clist << endl;

    // Clear the list
    clist.clear();
    cout << "Size of cleared list: " << clist.size() << endl;

    // Create a random list
    clist_t random_clist(5);
    cout << "Random list: " << random_clist << endl;

    // Sort the list
    random_clist.sort();
    cout << "Sorted list: " << random_clist << endl;

    // Reverse the list
    random_clist.reverse();
    cout << "Reversed list: " << random_clist << endl;

    // Copy the list
    clist_t copy_clist(random_clist);
    cout << "Copied list: " << copy_clist << endl;

    // Create a list based on an array
    float arr3[] = {2.0,4.0,6.0,8.0,10.0};
    clist_t arr_clist(arr3, sizeof(arr3)/sizeof(arr3[0]));
    cout << "Array list: " << arr_clist << endl;

    // ---------------------- CIRCULAR DOUBLY LINKED LIST ---------------------- //

    // Circular Doubly Linked List initilizer
    cout << endl << "// ------------ CIRCULAR DOUBLY LINKED LIST TEST ------------ //" << endl;
    dclist_t cdlist;

    // Insert values into Circular Doubly Linked List
    cdlist.push_front(51); cdlist.push_front(12); cdlist.push_front(26);
    cdlist.push_back(82); cdlist.push_back(60); cdlist.push_back(1);
    
    // Reference to first element
    cout << "First element: " << cdlist.front() << endl;

    // Reference to last element
    cout << "Last element:  " << cdlist.back() << endl << endl;

    // Pop values from Doubly Linked List
    cout << "Popped value:  " << cdlist.pop_front() << endl;
    cout << "Popped value:  " << cdlist.pop_back() << endl << endl;

    // Print Circular Doubly Linked List values by overloading <<
    cout << "Circular Doubly List values: " << cdlist << endl;

    // Random access
    auto cdnode = cdlist[2];
    cout << "Random access dir: " << cdnode << ", value: " << cdnode->value << endl;

    // Check if list is empty
    cout << "Is the list empty?: " << boolalpha << cdlist.empty() << endl;

    // Print size of the list
    cout << "Size of the list: " << cdlist.size() << endl;

    // Insert repeating values
    cdlist.insert(cdnode,3); cdlist.insert(cdlist[0],3);
    cout << "List with repeating values: " << cdlist << endl;

    // Remove repeting values
    cdlist.remove(3);
    cout << "List w/o repeating values: " << cdlist << endl;

    // Erase an element
    cdlist.erase(cdnode);
    cout << "List after erasing element: " << cdlist << endl;

    // Clear the list
    cdlist.clear();
    cout << "Size of cleared list: " << cdlist.size() << endl;

    // Create a random list
    dclist_t random_cdlist(5);
    cout << "Random list: " << random_cdlist << endl;

    // Sort the list
    random_cdlist.sort();
    cout << "Sorted list: " << random_cdlist << endl;

    // Reverse the list
    random_cdlist.reverse();
    cout << "Reversed list: " << random_cdlist << endl;

    // Copy the list
    dclist_t copy_cdlist(random_cdlist);
    cout << "Copied list: " << copy_cdlist << endl;

    // Create a list based on an array
    float arr4[] = {1.0,2.0,3.0,4.0,5.0};
    dclist_t arr_cdlist(arr4, sizeof(arr4)/sizeof(arr4[0]));
    cout << "Array list: " << arr_cdlist << endl;
}