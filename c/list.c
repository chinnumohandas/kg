#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// Doubles the allocated array in sizes, preserves content
// Returns new size
int expand( int **source, int size ) {
    size *= 2;
    int *ret = realloc( *source, size * sizeof( int ) );
    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error.\n" );
        exit( 1 );
    }
    else *source = ret;

    return size;
}

int reduce( int **source, int size ) {
    size /= 2;
    int *ret = realloc( *source, size * sizeof( int ) );

    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error.\n" );
        exit( 1 );
    }
    else *source = ret;

    return size;
}

/* Idea: offer struct to hold last/size values (and optional function pointer?)
 * in order to deal with pre-increment first element problem
 */

void append( int **source, int *last, int *size, int elem ) {
    ++(*last);
    // handle possible overflow
    if( (*last) == (*size) )
        (*size) = expand( source, *size );
    (*source)[ *last ] = elem;
}

// Returns the last element and removes it
int pop( int **source, int *last, int *size ) {
    int retval = (*source)[ (*last ) ];
    --(*last);

    if( (*last) == (*size) / 4 )
        (*size) = reduce( source, *size );

    return retval;
}

// Concatenates the two lists
// Destroyes the two passed arrays
int* concatenate( int *first, int fsize, int *second, int ssize, int *size ) {
    (*size) = fsize + ssize + 2;
    char* cated = calloc( sizeof( int ), (*size) * sizeof( int ) );

    memcpy( cated, first, ( fsize + 1 ) * sizeof( int ) ); 
    memcpy( cated + ( ( fsize + 1 ) * sizeof( int ) ), second, ssize * sizeof( int ) ); 

    free( first );
    free( second );

    return (int*)cated;
}
