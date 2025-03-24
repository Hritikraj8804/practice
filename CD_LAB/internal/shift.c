#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ip[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len;

void check() {
    if (st_ptr > 0 && (stack[st_ptr - 1] == 'a' || stack[st_ptr - 1] == 'b')) {
        stack[st_ptr - 1] = 'E';
        st_ptr--;
        stack[st_ptr] = '\0';
        printf("\n$%s\t%s$\tE->%c", stack, ip + ip_ptr, stack[st_ptr]);
    } else if (st_ptr >= 3 && (!strncmp(stack + st_ptr - 3, "E+E", 3) || !strncmp(stack + st_ptr - 3, "E*E", 3) || !strncmp(stack + st_ptr - 3, "E/E", 3))) {
        strcpy(stack + st_ptr - 3, "E");
        st_ptr -= 2;
        stack[st_ptr] = '\0';
        printf("\n$%s\t%s$\tE->EEE", stack, ip + ip_ptr);
    }
    if (strcmp(stack, "E") == 0 && ip_ptr == len) {
        printf("\n$%s\t%s$\tAccept", stack, ip + ip_ptr);
        exit(0);
    }
}

int main() {
    printf("Input: ");
    scanf("%s", ip);
    len = strlen(ip);
    printf("\nStack\tInput\tAction\n$\t%s$\t--", ip);

    while (ip_ptr <= len) {
        if (ip_ptr < len) {
            stack[st_ptr++] = ip[ip_ptr++];
            stack[st_ptr] = '\0';
            printf("\n$%s\t%s$\tshift %c", stack, ip + ip_ptr, stack[st_ptr - 1]);
            check();
        } else {
            check();
            break;
        }
    }
    return 0;
}
