#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct  
{
    Chunk* chunk;
    uint8_t* ip;  // instruction pointer
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_RUNTIME_ERROR,
    INTERPRET_COMPILE_ERROR,
} InterpretResult;

void initVM();
void freeVM();
InterpretResult interpret(Chunk* chunk);

#endif