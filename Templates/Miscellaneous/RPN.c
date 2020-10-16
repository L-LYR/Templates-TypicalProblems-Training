/* RPN */
/* 
    Reverse Polish Notation
    Procedure:
        1. Input the infix expression.
        2. Get words from left to right:
            1. If the word is an operand, push it in ans stack.
            2. If the word is an operator, we have three cases as below:
                1. If '(' is at the t of ans, push it in.
                2. If the operator at the t of ans has lower priority, push it in.
                3. If the operator at the t of ans has higher or the same priority, 
                pop repeatedly and check as above.
            3. If the word is '(', push it in ans stack.
            4. If the word is ')', pop until '(' and discard both of them.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    get_RPN:
        1. Input an infix expression, return a suffix expression.
        2. The operand in expression must be single digits.
*/
char* get_RPN(const char* i) {
    int len, t;
    char *suffix,  // suffix is the return value.
        *temp;     // t & temp will be used like a stack.
    char* s;       // s -> suffix

    len = strlen(i) + 1;
    t = -1;
    suffix = malloc(2 * len * sizeof(*suffix));
    temp = malloc(len * sizeof(*temp));

    if (suffix == NULL || temp == NULL) {
        fprintf(stderr, "%s:%d: malloc() failed",
                __FILE__, __LINE__);
        exit(-1);
    }

    s = suffix;
    while (*i != '\0') {
        if (isdigit(*i)) {
            *s++ = *i;  // operand
        } else if (*i == '(') {
            temp[++t] = *i;  // left bracket, push in temp stack directly
        } else if (*i == ')') {
            *s++ = ' ';
            while (t >= 0) {  // right bracket, pop until meeting the left bracket
                if (temp[t] == '(') break;
                *s++ = temp[t--];  // push in temp stack suffix
            }
        } else if (*i == '+' || *i == '-') {  // lowest priority
            *s++ = ' ';
            if (t == -1 || temp[t] == '(') {  // when stack is empty or the stack-top is a left bracket,
                temp[++t] = *i;               // push in temp stack directly.
            } else {                          // otherwise the left operators have higher priority,
                *s++ = temp[t--];             // temp stack pop and push in ans.
                continue;
            }
        } else if (*i == '*' || *i == '/') {  // highest priority
            *s++ = ' ';
            if (temp[t] == '*' || temp[t] == '/') {  // when stack-top is the same level operator,
                *s++ = temp[t--];                    // temp stack pop and push in ans.
                continue;
            } else {
                temp[++t] = *i;  // otherwise push in temp stack directly.
            }
        }
        i++;  // some cases doesn't need to move forward.
    }

    while (t >= 0) {  // pop the rest data in temp stack
        *s++ = ' ';
        *s++ = temp[t--];
    }

    *s = '\0';  // terminate
    return suffix;
}

int main(void) {
    printf("%s\n", get_RPN("15+21*(41-12)-1128/12"));
    return 0;
}