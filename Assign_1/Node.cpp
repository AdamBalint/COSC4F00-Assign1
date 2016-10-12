//
//  Node.cpp
//  Assign_1
//
//  Created by Adam Balint on 2016-10-06.
//  Copyright © 2016 Adam Balint. All rights reserved.
//



#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Node.hpp"
#include <iostream>

#endif /* Node_hpp */


template <typename E> class Node{

private:
    Node* next;
    Node* prev;
    E content;
    
    
public:
    

    Node(){
        
    }
    Node(E content){
        std::cout << "Setting content\n";
        this->content = content;
        std::cout << "Setting next\n";
        next = *this;
        std::cout << "Setting prev\n";
        prev = *this;
        std::cout << "Set all\n";
    }
    
    
    Node(Node<E>* prevNode, E content, Node<E>* nextNode){
        this->content = content;
        next = nextNode;
        prev = prevNode;
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
