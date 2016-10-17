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
    
// Holds the content, the next and previous nodes
private:
    Node* next;
    Node* prev;
    E content;
    
public:
    
    // Creates a new node with the the given content
    // ! element circular linked list
    Node(E content){
        this->content = content;
        next = this;
        prev = this;
    }
    
    // Creates a new node by fitting it into the list
    // Has a next and previous node other than itself
    Node(Node<E>* prevNode, E content, Node<E>* nextNode){
        this->content = content;
        next = nextNode;
        prev = prevNode;
    }
    
    // The destructor for the node
    ~Node(){
    
    }
    
    // Returns the content of the node
    E getContent(){
        return content;
    }
    
    // Sets the content of the node
    void setContent(E cont){
        content = cont;
    }
    
    // Returns the next node
    Node<E>* nextNode(){
        return next;
    }
    
    // Returns the previous node
    Node<E>* prevNode(){
        return prev;
    }
    
    // Sets the next node
    void setNext(Node<E>* nextNode){
        next = nextNode;
    }
    
    // Sets the previous node
    void setPrev(Node<E>* prevNode){
        prev = prevNode;
    }
};

#endif /* Node_hpp */
