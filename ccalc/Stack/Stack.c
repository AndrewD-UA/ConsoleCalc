#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

#define DEFAULT_SIZE 10

int hasNext(stack *s);

/* Add a new item to the top of the stack
 * Return 0 for successful operation, INT_MIN for unsuccessful.
 */
int push(stack* s, int val){
    if (s->currIndex >= s->maxData){
        int *temp = realloc(s->data, (s->maxData * 2) * sizeof(int));
        s->data = temp;
        s->maxData << 1;
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

    if (s->currIndex < s->maxData * 4){
        s->data = realloc(s->data, (s->maxData / 2) * sizeof(int) );
        // Cannot allocate more memory
        if (s->data == NULL){
            printf("Cannot reallocate Stack size");
        }

        s->maxData *= 2;
    }

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
 * Create a new Stack and return its reference.  All data inside is zeroed similar to a calloc.
 */ 
stack* initStack(){
    stack* s = malloc(sizeof(stack));
    s->currIndex = 0;
    s->maxData = DEFAULT_SIZE;
    s->data = malloc(DEFAULT_SIZE * sizeof(int));

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
