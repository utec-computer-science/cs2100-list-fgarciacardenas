#include <iostream>
#include "node.hpp"
#include "list.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Single Linked List initilizer
    myList::List<int> list;

    // Insert values into Singly Linked List
    list.push_front(55); list.push_front(38); list.push_front(27);
    list.push_back(72); list.push_back(9); list.push_back(43);
    
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
    Node<int> *ac_node = list[2];
    cout << "Random access dir: " << ac_node << ", value: " << ac_node->value << endl;

    // Check if list is empty
    cout << "Is the list empty?: " << boolalpha << list.isEmpty() << endl;

    // Print size of the list
    cout << "Size of the list: " << list.size() << endl;

    // Insert repeating values
    list.insert(ac_node,3); list.insert(ac_node,3);
    cout << "List with repeating values: " << list << endl;

    // Remove repeting values
    list.remove(3);
    cout << "List w/o repeating values: " << list << endl;

    // Erase an element
    list.erase(ac_node);
    cout << "List after erasing element: " << list << endl;

    // Clear the list
    list.clear();
    cout << "Size of cleared list: " << list.size() << endl;

    // Create a random list
    myList::List<int> random_list(5);
    cout << "Random list: " << random_list << endl;

    // Sort the list
    random_list.sort();
    cout << "Sorted list: " << random_list << endl;

    // Reverse the list
    random_list.reverse();
    cout << "Reversed list: " << random_list << endl;

    // Copy the list
    myList::List<int> copy_list(random_list);
    cout << "Copied list: " << copy_list << endl;

    // Create a list based on an array
    int arr[] = {1,2,3,4,5};
    myList::List<int> arr_list(arr, size(arr));
    cout << "Array list: " << arr_list << endl;
}