## Q1: Balanced Parentheses Checker (Using Stack)

## 1. Introduction

This program verifies whether a given mathematical expression contains properly balanced brackets.
It uses a stack data structure to store opening brackets and compares them with closing brackets while scanning the expression.

## 2. Data Structure Used
 - Stack Implementation
 ```c
typedef struct {
    int index;
    char items[LIMIT];
} Stack;
```

- index = Represents the current top position of the stack.

- items[LIMIT] = Character array used to store brackets ((, [, {).

The stack operates on the LIFO (Last In, First Out) principle, making it suitable for solving parentheses matching problems.

## 3. Objective

- To check whether every opening bracket has a corresponding closing bracket.
- To ensure brackets are closed in the correct order.
- To support all three bracket types:(),{},[]
- To demonstrate stack operations in a modular and structured way.

## 4. Functions Used
### a. add(Stack *st, char value)
- Pushes an opening bracket onto the stack.
- Checks for overflow condition.
- Increments index and stores the character.

### b. removeItem(Stack *st)
- Pops the top element from the stack.
- Checks for underflow condition.
- Returns '\0' if the stack is empty.

### c. match(char left, char right)
- Checks whether the opening and closing brackets form a valid pair.
- Returns 1 if matched, otherwise 0.

### d. isBalanced(char *expression)
- Main function that validates bracket balance.
- Traverses the expression character by character:
- Pushes opening brackets onto the stack.
- Pops and compares when a closing bracket is found.
- Immediately returns 0 if a mismatch occurs.
- A closing bracket appears with an empty stack.
- Returns 1 only if the stack is empty after complete traversal.

## 5.Program Flow (Main Function)
- An array of sample expressions is defined.
- Each expression is passed to isBalanced().
- The program prints whether the expression is Balanced or Unbalanced.
- This demonstrates the correctness of the stack-based algorithm.

## 6. Sample Output
```
Bracket Checking Program

Expression: a+(b-c)*(d
Result: Unbalanced

Expression: m+[a-b*(c+d*{m)]
Result: Unbalanced

Expression: a+(b-c)
Result: Balanced
```
