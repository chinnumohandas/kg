#include <stdlib.h>
// Library subset to handle typical list (extended array) tasks such as
// 'dynamic' reallocation

#define concat(TYPE, first, firstn, second, secondn) \
      (TYPE *)concatenate( (const void *)(first), (firstn), (const void *)(second), (secondn), sizeof(TYPE) );

int expand( int **source, int size );
int reduce( int **source, int size );
void append( int **source, int *last, int *size, int elem );
int pop( int *source, int *last, int *size );

// example call: concat( int, first, firstsize, second, secondsize )
void* concatenate( const void *first, int fsize, const void *second, int ssize, size_t s );
