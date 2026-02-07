/*
Program to check whether an expression has balanced brackets
using stack.
*/

#include <stdio.h>
#include <string.h>

#define LIMIT 100   // stack size

// Stack structure
typedef struct {
    int index;
    char items[LIMIT];
} Stack;

// Add element to stack
void add(Stack *st, char value) {
    if (st->index == LIMIT - 1)
        return;   // stack full

    st->items[++(st->index)] = value;
}

// Remove element from stack
char removeItem(Stack *st) {
    if (st->index == -1)
        return '\0';  // stack empty

    return st->items[(st->index)--];
}

// Check matching pair
int match(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '[' && right == ']') return 1;
    if (left == '{' && right == '}') return 1;
    return 0;
}

// Verify balanced brackets
int isBalanced(char *expression) {
    Stack st;
    st.index = -1;   // initialize empty stack

    int size = strlen(expression);

    for (int i = 0; i < size; i++) {
        char symbol = expression[i];

        // If opening bracket, push
        if (symbol == '(' || symbol == '[' || symbol == '{') {
            add(&st, symbol);
        }

        // If closing bracket
        else if (symbol == ')' || symbol == ']' || symbol == '}') {

            if (st.index == -1)
                return 0;   // no matching opening bracket

            if (!match(removeItem(&st), symbol))
                return 0;   // mismatch
        }
    }

    // Balanced only if stack empty
    return (st.index == -1);
}

int main() {

    char *inputs[] = {
        "a+(b-c)*(d",
        "m+[a-b*(c+d*{m)]",
        "a+(b-c)"
    };

    printf("Bracket Checking Program\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", inputs[i]);

        if (isBalanced(inputs[i]))
            printf("Result: Balanced\n\n");
        else
            printf("Result: Unbalanced\n\n");
    }

    return 0;
}
