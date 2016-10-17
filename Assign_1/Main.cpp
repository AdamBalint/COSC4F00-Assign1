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
#include <vector>
#include <sstream>


//splits the given string by spaces
std::vector<std::string> split(std::string s){
    std::vector<std::string> res;
    std::stringstream ss(s);
    std::string tmp;
    
    while(std::getline(ss, tmp, ' ')) {
        res.push_back(tmp);
    }
    return res;
}


int main(int argc, const char * argv[]) {
    // Creates data structure
    CircularDoublyLinkedList<std::string> cdll;
    
    bool running = true;
    
    std::cout << "Waiting for input: \n";
    
    // Loops until user decides to quit
    while(running){
        try{
            // Gets the input
            std::string input;
            getline(std::cin, input);
            
            // Splits the string
            std::vector<std::string> parts = split(input);
            std::string cmd = parts[0];
            std::string args = "";
            
            // combines arguments
            if (parts.size() > 1){
                std::stringstream ss;
                for (int i = 1; i < parts.size(); i++){
                    args += parts[i];
                    if (i < parts.size()-1)
                        args += " ";
                }
            }
            
            // Does action requested and prints out the result
            if (cmd.compare("s") == 0){
                std::cout << "Command: getSize\t Args: NONE\t Result: " << cdll.getSize() << "\n" <<std::endl;
            }
            else if (cmd.compare("print") == 0){
                std::cout << "Command: print\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("i") == 0){
                if (args.size() > 0){
                    cdll.insert(args);
                    std::cout << "Command: insert\t Args: "<< args << "\t Result: " << cdll.print() << "\n" << std::endl;
                }
                else {
                    std::cout << "Please enter a valid argument" << std::endl;
                }
            }
            else if (cmd.compare("ib") == 0){
                if (args.size() > 0){
                    cdll.insertBefore(args);
                    std::cout << "Command: insertBefore\t Args: "<< args << "\t Result: " << cdll.print() << "\n" << std::endl;
                }
                else {
                    std::cout << "Please enter a valid argument" << std::endl;
                }

            }
            else if (cmd.compare("ia") == 0){
                if (args.size() > 0){
                    cdll.insertAfter(args);
                    std::cout << "Command: insertAfter\t Args: "<< args << "\t Result: " << cdll.print() << "\n" << std::endl;
                }
                else {
                    std::cout << "Please enter a valid argument" << std::endl;
                }

            }
            else if (cmd.compare("r") == 0){
                cdll.remove();
                std::cout << "Command: remove\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("rb") == 0){
                cdll.removeBefore();
                std::cout << "Command: removeBefore\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("ra") == 0){
                cdll.removeAfter();
                std::cout << "Command: removeAfter\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("get") == 0){
                std::cout << "Command: getContent\t Args: NONE\t Result: " << cdll.getContent() << "\n" << std::endl;
            }
            else if (cmd.compare("set") == 0){
                std::string contBef = cdll.getContent();
                cdll.setContent(args);
                std::cout << "Command: setContent\t Args: " << args << "\t Result: " << contBef << "->" << cdll.getContent() <<"\tNew List: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("next") == 0){
                cdll.next();
                std::cout << "Command: next\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
            }
            else if (cmd.compare("prev") == 0){
                cdll.previous();
                std::cout << "Command: previous\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;

            }
            else if (cmd.compare("rma") == 0){
                cdll.removeAll();
                std::cout << "Command: removeAll\t Args: NONE\t Result: " << cdll.print() << "\n" << std::endl;
                
            }
            else if (cmd.compare("quit") == 0){
                running = false;
            }
            else {
                std::cout << "You have entered an invalid command" << std::endl;
            }
        }catch (const char* err){
            std::cout << "An Error has been caught: " << err << std::endl;
        
        }
    }
    
    
    return 0;
}
