#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"


typedef enum {
    OP_CONSTANT,
    OP_RETURN,
    OP_NEGATE,
    OP_ADDITION,
    OP_SUBTRACTION,
    OP_MULTIPLY,
    OP_DIVIDE,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk,uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
void freeChunk(Chunk* chunk);

#endif
