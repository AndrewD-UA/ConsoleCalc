#ifndef Stack
#define Stack

typedef struct{
    int maxData;    // The maximum number of items that can be stored in this Stack
    int currIndex;  // The current index of the backing array that is available for insertion
    int *data;   // The backing array of the stack
} stack;

int pop(stack*);
int push(stack*, int);
int peek(stack*);
void printStack(stack*);
stack* initStack();

#endif