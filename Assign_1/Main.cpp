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
    
    std::cout << "Adding Node 1" << std::endl;
    
    cdll.insert(1);
    std::cout << "Adding Node 2" << std::endl;
    cdll.insertAfter(2);
    std::cout << "Adding Node 3" << std::endl;
    cdll.insertBefore(3);
    
    std::cout << "Size: " << cdll.getSize() << std::endl;
    
    std::cout << "Forward loop" << std::endl;
    
    for (int i = 0; i < 3; i++){
        std::cout << "Content: " << cdll.getContent() << std::endl;
        std::cout << "Getting Next Node" << std::endl;
        cdll.next();
    }
    
    std::cout << "Backward loop" << std::endl;
    
    for (int i = 0; i < 3; i++){
        std::cout << "Content: " << cdll.getContent() << std::endl;
        std::cout << "Getting Next Node" << std::endl;
        cdll.previous();
    }
    
    std::cout << "Size: " << cdll.getSize() << std::endl;
    cdll.removeAll();
    std::cout << "Size: " << cdll.getSize() << std::endl;
    try{
        std::cout << cdll.getContent() << std::endl;
    }catch (const char* e){
        std::cout << e;
    }
    //Node<int> n(1);
    
   // Node<int> n;
    
    //std::cout << n.getContent() << ", " << (*n.nextNode()).getContent() << ", " << (*n.prevNode()).getContent() << std::endl;
    
    
    return 0;
}
