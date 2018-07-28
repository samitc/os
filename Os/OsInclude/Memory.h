#ifndef _MEMORY_H_
#define _MEMORY_H_
void* memcpy(void *_Dst, const void *_Src, size_t _size);
void* memmove(void *_Dst, const void *_Src, size_t _size);
int memcmp(const void *_Src, const void *_Dst, size_t _size);
#endif