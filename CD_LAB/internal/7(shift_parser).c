#include <stdio.h>
#include <string.h>

char stack[100], input[100];
int top = -1, i = 0;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

void print_action(const char *action) {
    printf("%-12s %-12s %-12s\n", stack, input + i, action);
}

void reduce() {
    int reduced = 1;
    while (reduced) {
        reduced = 0;
        if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'E') {
            pop(3); push('E'); print_action("Reduce E→E+E"); reduced = 1;
        } else if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '*' && stack[top] == 'E') {
            pop(3); push('E'); print_action("Reduce E→E*E"); reduced = 1;
        }else if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '/' && stack[top] == 'E') {
            pop(3); push('E'); print_action("Reduce E→E/E"); reduced = 1;
        } else if (top >= 0 && stack[top] == 'i') {
            pop(1); push('E'); print_action("Reduce E→i"); reduced = 1;
        }
    }
}

int main() {
    printf("Enter input (e.g., i+i*i): ");
    scanf("%s", input);

    printf("\n%-12s %-12s %-12s\n", "Stack", "Input", "Action");
    printf("============ ============ ============\n");

    while (input[i] != '\0') {
        push(input[i++]);
        print_action("Shift");
        reduce();
    }

    if (strcmp(stack, "E") == 0)
        printf("\nInput Accepted!\n");
    else
        printf("\nInput Rejected!\n");

    return 0;
}



/*

Enter input (e.g., i+i*i): i/i

Stack        Input        Action      
============ ============ ============
i            /i           Shift       
E            /i           Reduce E→i
E/           i            Shift       
E/i                       Shift       
E/E                       Reduce E→i
E                         Reduce E→E/E

Input Accepted!

*/
