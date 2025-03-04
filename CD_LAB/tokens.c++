#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100

// Function to check if a word is a keyword
int is_keyword(char *word) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "int", 
        "long", "register", "return", "short", "signed", "sizeof", "static", "struct", 
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while", NULL
    };
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1; // It's a keyword
    }
    return 0;
}

// Function to check if a word is an identifier
int is_identifier(char *word) {
    if (isalpha(word[0]) || word[0] == '_') {
        for (int i = 1; word[i] != '\0'; i++) {
            if (!isalnum(word[i]) && word[i] != '_') {
                return 0; // Invalid identifier
            }
        }
        return 1; // Valid identifier
    }
    return 0; // Invalid identifier
}

// Function to check if a string is a constant (numeric or string literal)
int is_constant(char *word) {
    // Check for numeric constants (integer or float)
    if (isdigit(word[0])) {
        for (int i = 1; word[i] != '\0'; i++) {
            if (!isdigit(word[i]) && word[i] != '.') {
                return 0; // Not a numeric constant
            }
        }
        return 1; // Numeric constant
    }
    // Check for string literals
    if (word[0] == '"' && word[strlen(word) - 1] == '"') {
        return 1; // String literal
    }
    return 0;
}

// Function to check if a character is an operator
int is_operator(char c) {
    char operators[] = "+-*/%=&|^!~<>,.;:?";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (c == operators[i]) {
            return 1; // It's an operator
        }
    }
    return 0;
}

// Function to check if a character is a separator
int is_separator(char c) {
    return (c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']');
}

// Function to extract and classify tokens from a given program
void identify_tokens(const char *program) {
    char token[MAX_TOKEN_SIZE];
    int token_index = 0;

    for (int i = 0; program[i] != '\0'; i++) {
        char current_char = program[i];

        if (isspace(current_char)) {
            if (token_index > 0) {
                token[token_index] = '\0';
                if (is_keyword(token)) {
                    printf("Keyword: %s\n", token);
                } else if (is_identifier(token)) {
                    printf("Identifier: %s\n", token);
                } else if (is_constant(token)) {
                    printf("Constant: %s\n", token);
                }
                token_index = 0;
            }
        } else if (isalpha(current_char) || current_char == '_') {
            token[token_index++] = current_char;
        } else if (isdigit(current_char) || current_char == '.') {
            token[token_index++] = current_char;
        } else if (is_operator(current_char)) {
            printf("Operator: %c\n", current_char);
        } else if (is_separator(current_char)) {
            printf("Separator: %c\n", current_char);
        } else {
            // Skip other characters or handle error
            continue;
        }
    }

    // Check the last token if there is one
    if (token_index > 0) {
        token[token_index] = '\0';
        if (is_keyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (is_identifier(token)) {
            printf("Identifier: %s\n", token);
        } else if (is_constant(token)) {
            printf("Constant: %s\n", token);
        }
    }
}

int main() {
    // Sample C program as input
    char program[] = "int main() { int a = 5; float b = 3.14; if (a > 0) { a = a + 1; } }";
    
    printf("Identifying tokens in the program:\n");
    identify_tokens(program);

    return 0;
}
