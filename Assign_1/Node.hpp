//
//  Node.hpp
//  Assign_1
//
//  Created by Adam Balint on 2016-10-06.
//  Copyright © 2016 Adam Balint. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <iostream>

template <typename E> class Node{
    
private:
    Node* next;
    Node* prev;
    E content;
    
public:
    Node(E content){
//        std::cout << "Setting content\n";
        this->content = content;
//        std::cout << "Setting next\n";
        next = this;
//        std::cout << "Setting prev\n";
        prev = this;
//        std::cout << "Set all\n";
        
//        std::cout << "Node Creation Next Content: " << (*next).getContent() << std::endl;
//        std::cout << "Node Creation Prev Content: " << (*prev).getContent() << std::endl;
        
    }
    
    Node(Node<E>* prevNode, E content, Node<E>* nextNode){
        this->content = content;
        next = nextNode;
        prev = prevNode;
    }
    
    ~Node(){
    
    }
    
    E getContent(){
        return content;
    }
    
    
    Node<E>* nextNode(){
        return next;
    }
    
    
    Node<E>* prevNode(){
        return prev;
    }
    
    
    void setNext(Node<E>* nextNode){
        next = nextNode;
    }
    
    
    void setPrev(Node<E>* prevNode){
        prev = prevNode;
    }
};

#endif /* Node_hpp */
