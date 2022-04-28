#include <iostream>
#include "singly_linked_list.h"

int main() {
    std::cout << "Hello world\n";
    // {
    //     auto myLinkedList = new MyLinkedList{}; // 
    //     myLinkedList->print();
    //     myLinkedList->addAtHead(1);             // 1
    //     myLinkedList->print();
    //     myLinkedList->addAtTail(3);             // 1->3
    //     myLinkedList->print();
    //     myLinkedList->addAtIndex(1, 2);         // 1->2->3
    //     myLinkedList->print();
    //     std::cout << "myLinkedList->get(1): " << myLinkedList->get(1) << "\n";              // return 2
    //     myLinkedList->deleteAtIndex(1);         // 1->3
    //     myLinkedList->print();
    //     std::cout << "myLinkedList->get(1): " << myLinkedList->get(1) << "\n";              // return 3
    //     delete myLinkedList;
    // }
    // {
    //     // ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
    //     // [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    //     auto myLinkedList = new MyLinkedList{}; // 
    //     myLinkedList->print();
    //     myLinkedList->addAtHead(7);
    //     myLinkedList->print();

    //     myLinkedList->addAtHead(2);
    //     myLinkedList->print();

    //     myLinkedList->addAtHead(1);
    //     myLinkedList->print();

    //     myLinkedList->addAtIndex(3, 0);
    //     myLinkedList->print();

    //     myLinkedList->deleteAtIndex(2);
    //     myLinkedList->print();

    //     myLinkedList->addAtHead(6);
    //     myLinkedList->print();

    //     myLinkedList->addAtTail(4);
    //     myLinkedList->print();
    // }
    // {
    //     // ["MyLinkedList","addAtIndex","addAtIndex","addAtIndex","get"]
    //     // [[],[0,10],[0,20],[1,30],[0]]
    //     auto myLinkedList = new MyLinkedList{};
    //     myLinkedList->print();

    //     myLinkedList->addAtIndex(0, 10);
    //     myLinkedList->print();


    //     myLinkedList->addAtIndex(0, 20);
    //     myLinkedList->print();


    //     myLinkedList->addAtIndex(1, 30);
    //     myLinkedList->print();

    //     std::cout << "myLinkedList->get(0) = " << myLinkedList->get(0) << "\n";

    // }
    // {
    //     // ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
    //     // [[],[1],[3],[1,2],[1],[1],[1]]
    //     auto myLinkedList = new MyLinkedList{};
    //     myLinkedList->print();

    //     myLinkedList->addAtHead(1);
    //     myLinkedList->print();

    //     myLinkedList->addAtTail(3);
    //     myLinkedList->print();

    //     myLinkedList->addAtIndex(1,2);
    //     myLinkedList->print();

    //     std::cout << "myLinkedList->get(1): " << myLinkedList->get(1) << "\n";

    //     myLinkedList->deleteAtIndex(1);
    //     myLinkedList->print();

    //     std::cout << "myLinkedList->get(1): " << myLinkedList->get(1) << "\n";

    // }
    // {
    //     // ["MyLinkedList","addAtTail","get"]
    //     // [[],[1],[0]]
    //     auto myLinkedList = new MyLinkedList{};
    //     myLinkedList->print();
    //     myLinkedList->addAtTail(1);
    //     myLinkedList->print();
    //     std::cout << "myLinkedList->get(1): " << myLinkedList->get(0) << "\n";
    // }
    {
        // ["MyLinkedList","addAtHead","addAtIndex","get"]
        // [[],[2],[0,1],[1]]
        auto myLinkedList = new MyLinkedList{};
        myLinkedList->print();
        myLinkedList->addAtHead(2);
        myLinkedList->print();
        myLinkedList->addAtIndex(0,1);
        std::cout << "myLinkedList->get(1): " << myLinkedList->get(1) << "\n";
    }
    return 0;
}