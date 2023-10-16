#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"
#include "table.h"


#define STACK_MAX 256

typedef struct  
{
    Chunk* chunk;
    uint8_t* ip;  // instruction pointer
    Value stack[STACK_MAX];
    Value* stackTop;
    Table strings;
    Obj* objects;
}VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_RUNTIME_ERROR,
    INTERPRET_COMPILE_ERROR,
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();

InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif