#include "Memory.h"
void* memcpy(void *_Dst, const void *_Src, size_t _size);
void* memmove(void *_Dst, const void *_Src, size_t _size);
int memcmp(const void *_Src, const void *_Dst, size_t _size)
{
    const void *f=_Src+_size;
    while(_Src!=f)
    {
       if(*_Src!=*_Dst)
       {
          return 0;
       }
       ++_Src;
       ++_Dst;
    }
    return 1;
}