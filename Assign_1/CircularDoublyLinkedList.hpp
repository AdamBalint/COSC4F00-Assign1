//
//  CircularDoublyLinkedList.hpp
//  Assign_1
//
//  Created by Adam Balint on 2016-10-06.
//  Copyright © 2016 Adam Balint. All rights reserved.
//

#ifndef ADT_hpp
#define ADT_hpp

#include <stdio.h>
#include "Node.hpp"
#include <string>

#endif /* CircularDoublyLinkedList_hpp */

template <typename E> class CircularDoublyLinkedList {

private:
    Node<E>* current;
    int size = 0;
    bool start_flag = false;
    
public:
    
    CircularDoublyLinkedList<E>(){
        
    }
    
    Node<E>* previous(){
        current = (*current).prevNode();
    }
    
    Node<E>* next(){
        current = (*current).nextNode();
    }
    
    E getContent(){
        return (*current).getContent();
    }
    
    void setContent(E content){
        (*current).setContent(content);
    }
    
    void remove(){
        if (size > 1){
            (*(*current).prevNode()).setNext((*current).nextNode());
            (*(*current).nextNode()).setPrev((*current).prevNode());
            current = (*current).nextNode();
            size--;
        }
        else {
            size--;
            current = nullptr;
        }
        
    }
    
    void removeBefore(){
        (*(*current).prevNode()).prevNode().setNext(current);
        (*current).setPrev((*(*current).prevNode()).prevNode());
    }
    
    void removeAfter(){
    
    }
    
    void insertBefore(E content){
        
    }
    
    void insertAfter(E content){
    
    }
    
    void insert(E content){
        if (size == 0)
            current = Node<E>(content);
        else
            insertAfter(content);
    }
    
    int getSize(){
        return size;
    }
    
    std::string print(){
        
    }
    
    void removeAll(){
    
    }
    
    bool isNull(){
    
    }
};
