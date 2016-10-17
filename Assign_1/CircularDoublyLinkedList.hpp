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
#include <sstream>


#endif /* CircularDoublyLinkedList_hpp */

template <typename E> class CircularDoublyLinkedList {

// Holds the current node, and the size of the data structure
private:
    Node<E>* current;
    int size;
    
public:
    
    // Initializes the constructor
    CircularDoublyLinkedList<E>(){
        size = 0;
    }
    
    // Changes the current node to the previous node
    void previous(){
        current = (*current).prevNode();
    }
    
    // Changes the current node to the next node
    void next(){
        current = (*current).nextNode();
    }
    
    // Gets the content of the current node
    E getContent(){
        if (size == 0)
            throw "\nEmpty List Exception\n";
        
        return (*current).getContent();
    }
    
    // Sets the content of the current node
    void setContent(E content){
        if (size == 0)
            throw "\n cmd List Exception\n";
        else
            (*current).setContent(content);
    }
    
    // Removes theinsert current node
    void remove(){
        // If there is more than 1 node, then make prev and next pointers skip
        // over the current node, set the current to the next node, and then delete
        // the node that was supposed to be deleted
        if (size > 1){
            (*(*current).prevNode()).setNext(((*current).nextNode()));
            (*(*current).nextNode()).setPrev((*current).prevNode());
            Node<E>* old = current;
            current = (*current).nextNode();
            delete(old);
            size--;
        }
        // If there is only 1 node, delete the node, and set the current pointer
        // to nothing
        else if (size == 1){
            size--;
            Node<E>* tmp = current;
            current = nullptr;
            delete(tmp);
            
        }else {
            std::cout << "No nodes in data structure!" << std::endl;
            throw "\n Empty List Exception\n";
        }
        
    }
    
    // Removes the node before the current node
    void removeBefore(){
        if (size <= 1){
            remove();
        }
        else {
            previous();
            remove();
        }
    }
    
    // Removes the node after the current node
    void removeAfter(){
        if (size <= 1){
            remove();
        }else {
            next();
            remove();
            previous();
        }
    }
    
    // Inserts new node before the current node
    void insertBefore(E content){
        if (size < 1){
            insert(content);
        }else {
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

    }
    
    // Inserts new node after the current node
    void insertAfter(E content){
        if (size < 1){
            insert(content);
        }else {
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
    }
    
    // inserts a node into the ADT. If there is already a node in the ADT,
    // then it acts as an insertAfter
    void insert(E content){
        if (size == 0){
            Node<E>* n = new Node<E>(content);
            current = n;
            size ++;
        }
        else
            insertAfter(content);
    }
    
    // Returns the size of the ADT
    int getSize(){
        return size;
    }
    
    // Prints the ADT
    std::string print(){
        if (size > 0){
            Node<E>* cur = current;
            Node<E>* start = current;
            
            std::ostringstream s;
            
            s << cur->getContent();
            cur = (cur->nextNode());
            while ((cur) != (start)){
                s << "-";
                s << cur->getContent();
                cur = (cur->nextNode());
            }
            
            //std::cout << s.str() << std::endl;
            return s.str();
        }else {
            throw "\n Empty List Exception\n";
        }
    }
    
    
    // Removes all elements from the ADT
    void removeAll(){
        while (size != 0){
            remove();
            size = 0;
        }
    }
    
    // Checks if the ADT is empty
    bool isEmpty(){
        if (size == 0)
            return true;
        return false;
    }
    
    
};
