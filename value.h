#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// to store data in chunks immediate instructions will be used
// these values are stored in the code stream after the opcode
typedef double Value;

// constant pool for the clox interpreter
// load a constant = look up value by array index
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);

#endif