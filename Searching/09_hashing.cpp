

#include <stdio.h>

#define ul		unsigned long
#define ull		unsigned long long

#define TABLE_SZ		107 //any prime no. as per needs

//different sets of hash functions
#define h1(x)			(x % TABLE_SZ)
#define rh1(y)			((y+1) % TABLE_SZ)

#define h2(x)			h1(x) // = y
#define rh2(y)			(1 + (y % TABLE_SZ))

#define h3(x)			h1(x) // = y
#define rh3(y)			(1 + y/TABLE_SZ) % (TABLE_SZ - 1)


//djb2 hash for string
ul hash(unsigned char *str)
{
    ul hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
//murmur hash for string - 32 bit
unsigned int MurmurOAAT32 ( const char * key)
{
  unsigned int h(3323198485ul);
  for (;*key;++key)
  {
    h ^= *key;
    h *= 0x5bd1e995;
    h ^= h >> 15;
  }
  return h;
}
//murmur hash for string - 64 bit
ull MurmurOAAT64 ( const char * key)
{
  ull h(525201411107845655ull);
  for (;*key;++key)
  {
    h ^= *key;
    h *= 0x5bd1e9955bd1e995;
    h ^= h >> 47;
  }
  return h;
}
