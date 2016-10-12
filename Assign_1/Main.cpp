//
//  Main.cpp
//  Assign_1
//
//  Created by Adam Balint on 2016-10-06.
//  Copyright © 2016 Adam Balint. All rights reserved.
//

#include <iostream>
#include "CircularDoublyLinkedList.hpp"
#include "Node.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    CircularDoublyLinkedList<int> cdll;
    
    Node<int> n(1);
   // Node<int> n;
    
    std::cout << n.getContent() << ", " << (*n.nextNode()).getContent() << ", " << (*n.prevNode()).getContent() << std::endl;
    
    
    return 0;
}
