# Program 2: Infix to Postfix Conversion and Evaluation

## 1. Data Structure Definition
This program uses a stack data structure implemented using a structure. The stack stores characters during infix to postfix conversion and integers during postfix evaluation. The stack follows the LIFO (Last In First Out) principle.

## 2. Function Description

- `initStack()`  
  Initializes the stack by setting the top value to -1.

- `push()`  
  Inserts an element into the stack.

- `pop()`  
  Removes and returns the top element from the stack.

- `precedence()`  
  Returns operator priority to maintain correct order of operations.

- `infixToPostfix()`  
  Converts an infix expression into postfix form using stack operations.

- `evaluatePostfix()`  
  Evaluates the postfix expression by applying operators to operands.

## 3. Main Function Overview
The `main()` function takes an infix expression as input from the user. It converts the expression to postfix form and then evaluates the postfix expression. Finally, it displays the postfix expression and the evaluated result.

## 4. Sample Output
```
Enter infix expression (single digit operands): 3+52
Postfix expression: 352+
Evaluated result: 13
```

## 5. Conclusion
This program demonstrates the use of stack data structure to convert and evaluate expressions. It shows how operator precedence and stack operations help in expression processing.
