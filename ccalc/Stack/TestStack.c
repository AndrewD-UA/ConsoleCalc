#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

const char* INTRO_MESSAGE = "Choose an operation:\n\t0)Quit\n\t1)Push\n\t2)Pop\n\t3)Peek";

int main(){
    stack *s = initStack();
    int op = 0, val = 0;

    for(;;){
        // Print the operation choice menu
        printf("%s\n", INTRO_MESSAGE);

        // Retrieve the operation choice
        scanf("%d", &op);

        // Restart for invalid input
        if (op < 0 || op > 3){
            printf("Invalid selection made.\n");
            continue;
        }

        // Quit operation
        if (op == 0){
            break;
        }

        // Push Operation
        if (op == 1){
            printf("Enter a number: ");
            scanf("%d", &val);

            if (push(s, val) == 0) printStack(s);
            continue;
        }

        // Pop Operation
        if (op == 2){
            int result = pop(s);
            if (result != INT_MIN){
                printf("Retrieved val: %d\n", result);
                printStack(s);
            }

            continue;
        }       

        // Peek Operation
        if (op == 3){
            int result = peek(s);
            if (result != INT_MIN){
                printf("Next value: %d\n", result);
            }

            continue;
        }
    }

    free(s);

    return 0;
}