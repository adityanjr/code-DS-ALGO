// # BALANCED PARANTHESES

// ## PROBLEM STATEMENT
// Given an expression string exp , write a program to examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp

// ## Algorithm:
// 1) Declare a character stack S.
// 2) Now traverse the expression string exp.
//     a) If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
//     b) If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and 
//        if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
// 3) After complete traversal, if there is some starting bracket left in stack then “not balanced”


#include<bits/stdc++.h> 
using namespace std; 
  
// function to check if paranthesis are balanced 
bool areParanthesisBalanced(string expr) 
{ 
    stack<char> s; 
    char x; 
  
    // Traversing the Expression 
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            // Push the element in the stack 
            s.push(expr[i]); 
            continue; 
        } 
  
        // IF current current character is not opening 
        // bracket, then it must be closing. So stack 
        // cannot be empty at this point. 
        if (s.empty()) 
           return false; 
  
        switch (expr[i]) 
        { 
        case ')': 
  
            // Store the top element in a 
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return false; 
            break; 
  
        case '}': 
  
            // Store the top element in b 
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return false; 
            break; 
  
        case ']': 
  
            // Store the top element in c 
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return false; 
            break; 
        } 
    } 
  
    // Check Empty Stack 
    return (s.empty()); 
} 

int main() 
{ 
    string expr = "{()}[]"; 
  
    if (areParanthesisBalanced(expr)) 
        cout << "true"; 
    else
        cout << "false"; 
    return 0; 
} 