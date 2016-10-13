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
    
    void previous(){
        current = (*current).prevNode();
    }
    
    void next(){
        current = (*current).nextNode();
    }
    
    E getContent(){
        if (size == 0)
            throw "\nEmpty List Exception\n";
        
        return (*current).getContent();
    }
    
    void setContent(E content){
        (*current).setContent(content);
    }
    
    void remove(){
        if (size > 1){
            (*(*current).prevNode()).setNext(((*current).nextNode()));
            (*(*current).nextNode()).setPrev((*current).prevNode());
            Node<E>* old = current;
            current = (*current).nextNode();
            delete(old);
            size--;
        }
        else {
            size--;
            delete(current);
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
        //Create new node with correct previous and next pointers
        Node<E>* n = new Node<E>((*current).prevNode(), content, current);
        
        //std::cout << "Insert Content: " << n->getContent() << std::endl;
        
        //set current's next's previous node to the new node
        current->prevNode()->setNext(n);
        
        //set current's next to the new node
        current->setPrev(n);
        
        //increase the size
        size++;

    }
    
    void insertAfter(E content){
        //Create new node with correct previous and next pointers
        Node<E>* n = new Node<E>(current, content, (*current).nextNode());
        
        //std::cout << "Insert Content: " << n->getContent() << std::endl;
        
        //set current's next's previous node to the new node
        current->nextNode()->setPrev(n);
        
        //set current's next to the new node
        current->setNext(n);
        
        //increase the size
        size++;
    }
    
    void insert(E content){
        if (size == 0){
            current = (new Node<E>(content));
            size ++;
        }
        else
            insertAfter(content);
    }
    
    int getSize(){
        return size;
    }
    
    std::string print(){
        
    }
    
    void removeAll(){
        while (size != 0){
            remove();
        }
    }
    
    bool isNull(){
    
    }
};
