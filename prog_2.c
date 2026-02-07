/*
program to convert an infix mathematical expression to postfix and evaluate it.
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

/* stack structure */
struct Stack {
    int top;
    char items[MAX];
};

/* initialize stack */
void initStack(struct Stack *s) {
    s->top = -1;
}

/* push element */
void push(struct Stack *s, char value) {
    s->items[++s->top] = value;
}

/* pop element */
char pop(struct Stack *s) {
    return s->items[s->top--];
}

/* check operator precedence */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

/* convert infix to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        /* if operand, add to postfix */
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        /* if opening bracket */
        else if (ch == '(') {
            push(&s, ch);
        }
        /* if closing bracket */
        else if (ch == ')') {
            while (s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // remove '('
        }
        /* if operator */
        else {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    /* pop remaining operators */
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

/* evaluate postfix expression */
int evaluatePostfix(char postfix[]) {
    struct Stack s;
    initStack(&s);
    int i;
    char ch;
    int a, b, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        /* if operand */
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        /* if operator */
        else {
            b = pop(&s);
            a = pop(&s);

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

/* main function */
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single digit operands): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Evaluated result: %d\n", evaluatePostfix(postfix));

    return 0;
}
