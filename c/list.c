#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// Doubles the allocated array in size, preserves content
// Returns new size
int expand( int **source, int size ) {
    size *= 2;
    int *ret = realloc( *source, size * sizeof( int ) );
    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error.\n", size );
        exit( 1 );
    }
    else *source = ret;

    return size;
}

int reduce( int **source, int size ) {
    size /= 2;
    int *ret = realloc( *source, size * sizeof( int ) );

    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error.\n", size );
        exit( 1 );
    }
    else *source = ret;

    return size;
}
