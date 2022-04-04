#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_ {
    int top;
    int capacity;
    char *array;
} dstack;

dstack* CreateStack() {
    dstack* s = (dstack*)malloc(sizeof(dstack));
    if (!s)
        return NULL;
    s->capacity = 1;
    s->top = -1;
    s->array = (char*)malloc(s->capacity * sizeof(char));
    if(!s->array)
        return NULL;
    return s;
}

int isEmptyStack(dstack* s) { //ture1false0
    return s->top == -1;
}

int isFullStack(dstack* s) {
    return (s->top == s->capacity - 1);
}

void doublestack(dstack* s) {
    s->capacity *= 2;
    s->array = (char*)realloc(s->array, s->capacity*sizeof(char));
}

int top(dstack* s) {
    if (isEmptyStack(s))
        return -1;
    return s->array[s->top];
}

void push(dstack* s, char x) {
    if (isFullStack(s))
        doublestack(s);
    s->array[++s->top] = x;
}

int pop(dstack* s) {
    if (isEmptyStack(s))
        return -1;
    return s->array[s->top--];
}

void deleteStack(dstack* s) {
    if (s) {
        if(s->array)
            free(s->array);
        free(s);
    }
}