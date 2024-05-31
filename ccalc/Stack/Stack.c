#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

int hasNext(stack *s);

/* Add a new item to the top of the stack
 * Return 0 for successful operation, INT_MIN for unsuccessful.
 */
int push(stack* s, int val){
    if (!(s->currIndex < s->maxData)){
        printf("Cannot push another item: %d\n", val);
        return -1;
    }

    s->data[s->currIndex] = val;
    s->currIndex++;

    return 0;
}

/*
 * Remove and return the "top" element of the stack
 */
int pop(stack* s){
    if (hasNext(s) == -1) return INT_MIN;

    s->currIndex--;
    return s->data[s->currIndex];
}

/*
 * Return what the value of the current "top" element of the stack is
 */
int peek(stack* s){
    if (hasNext(s) == -1) return INT_MIN;

    return s->data[s->currIndex - 1];
}

int hasNext(stack *s){
    if (s->currIndex == 0){
        printf("Stack is empty!\n");
        return -1;
    }

    return 0;
}

/*
 * Print out all non-zero data contained in the array underneath the stack.
 */
void printStack(stack* s){
    printf("\n    *Stack*\n");
    int i = 0;
    while (i < s->currIndex){
        printf("|\t%d\t|\n", s->data[i]);
        i++;
    }

    printf("\n");
}

/*
 * Create a new Stack and return its reference.  All data inside is zeroed.
 */ 
stack* initStack(){
    stack* s = malloc(sizeof(stack));
    s->currIndex = 0;
    s->maxData = 10;

    for (int i = 0; i < s->maxData; i++){
        s->data[i] = 0;
    }

    return s;
}

/* Print all non-null characters in a String
 * Primarily used for printing a String of unknown logical length but maximum size in memory
 */
int printNonNull(char* str, int length){
    for (int i = 0; i < length; i++){
        if (str[i] == '\0'){
            break;
        }
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}
