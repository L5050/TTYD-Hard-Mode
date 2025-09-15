#pragma once

#include <cstdint>

namespace gc::os {

#define ATTRIBUTE_FORMAT(...) __attribute__((format(__VA_ARGS__)))

struct ChunkInfo
{
	ChunkInfo *prev;
	ChunkInfo *next;
	uint32_t size;
} ;

struct HeapInfo
{
	uint32_t capacity;
	ChunkInfo *firstFree;
	ChunkInfo *firstUsed;
} ;

extern "C" {

extern HeapInfo *OSAlloc_HeapArray;
extern int OSAlloc_NumHeaps;

ATTRIBUTE_FORMAT(printf, 1, 2) void OSReport(const char * message, ...);


}

}