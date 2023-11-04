#include "demo.h"
#include "stack.h"

bool isMatchingBracket(char char1, char char2) { // Function given two characters determines if they are matching brackets
    if (char1 == '(' && char2 == ')') { // Check for circular brackets
        return true;     
    } else if (char1 == '{' && char2 == '}') { // Checks for curly brackets
        return true; 
    } else if (char1 == '[' && char2 == ']') { // Checks for straight brackets
        return true;  
    } else {
        return false; // If none of them are the same then they are not matching
    }
}

bool check_brackets(const char *str) { // Function using a stack to check for matching brackets
    stack_ptr s = stack_new(); // Instantiate a stack 
    char holder; // Declare a character to be used as an output for the pop function
    while(*str) { // While valid characters within the string
        if(*str == '{' || *str == '(' || *str == '[') { // Check said characters to see if they are opening brackets
            stack_push(s, *str); // If they are opening brackets push to the stack 
        }
        if (*str == '}' || *str == ')' || *str == ']') { // If they are closing brackets then 
             if (!stack_pop(s, &holder)) { // Pop from the stack, pop returns true if successful, so continue if pop failed (!)
                return false; // If a pop failed, the stack is empty and is experiencing underflow meaning it cannot have matching brackets
             } else if (!isMatchingBracket(holder, *str)) { // If failed to match brackets, return false
                return false; 
             }
        }
    str++; // Increment the address the pointer str is pointing to by 1
    }
    if(stack_pop(s, &holder)){ // Utilize the pop function to determine if the stack is empty
        stack_free(s); // Free stack
        return false; // Return false, since the stack was able to pop a value it has open brackets remaining
    } else { // No remaining brackets in the stack
        stack_free(s); // Free the stack
        return true; // Return true, all brackets had matching pairs
    }
}