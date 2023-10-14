#include "common.h"
#include "chunk.c"
#include "debug.c"
#include "value.c"
#include "vm.c"

int main(int argc,const char* argv[]){
    initVM();
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 122);
    writeChunk(&chunk, OP_CONSTANT, 91);
    writeChunk(&chunk, constant, 91);
    writeChunk(&chunk, OP_RETURN, 91);
    disassembleChunk(&chunk,"test chunk");
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);

    return 0;
}

