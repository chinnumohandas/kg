#include <stdlib.h>
#define DEFAULTSIZE 10
// Library subset to handle typical list (extended array) tasks such as
// 'dynamic' reallocation

#define concat(TYPE, first, firstn, second, secondn) \
      (TYPE *)concatenate( (const void *)(first), (firstn), (const void *)(second), (secondn), sizeof(TYPE) );

/* #define expand(TYPE, source, size) \
    expand_array( (void *)(source), (size), sizeof(TYPE) );

#define reduce(TYPE, source, size) \
    expand_array( (void *)(source), (size), sizeof(TYPE) );

    */

int expand_array( void *source, int size, size_t s );
int reduce_array( void *source, int size, size_t s );

//void append( int *source, int *last, int *size, int elem );
int pop( int *source, int *last, int *size );

// example call: concat( int, first, firstsize, second, secondsize )
void* concatenate( const void *first, int fsize, const void *second, int ssize, size_t s );

typedef struct {
    unsigned int alloc;
    int size;
    int *array;
} list;

list* init_list();

void append( list *list, int elem );
int* expand( int *source, int *size );
//int* expand( int **source, int *size );
int at( list *list, int pos );
