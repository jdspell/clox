#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}

void freeChunk(Chunk* chunk) {
    // deallocate all chunk memory and use initchunk to zero out fields
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte) {
    // if capacity is less than count then:
    //  Allocate a new array with more capacity.
    //  Copy the existing elements from the old array to the new one.
    //  Store the new capacity.
    //  Delete the old array.
    //  Update code to point to the new array.
    //  Store the element in the new array now that there is room.
    //  Update the count.
    // else add byte and update count.


    if (chunk->capacity < chunk->count + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
            oldCapacity, chunk->capacity);
    }
        chunk->code[chunk->count] = byte;
        chunk->count ++;

}

int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}