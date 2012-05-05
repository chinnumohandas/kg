#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// Doubles the allocated array in sizes, preserves content
// Returns new size

int expand_array( void *source, int size, size_t s ) {
    size *= 2;
    void *ret = realloc( source, size * s );
    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error\n" );
        exit( 1 );
    }
    else source = ret;

    return size;
}

int reduce_array( void *source, int size, size_t s ) {
    size /= 2;
    void *ret = realloc( source, size * s );

    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error.\n" );
        exit( 1 );
    }
    else source = ret;

    return size;
}

/* Idea: offer struct to hold last/size values (and optional function pointer?)
 * in order to deal with pre-increment first element problem
 */

void append( int *source, int *last, int *size, int elem ) {
    ++(*last);
    // handle possible overflow
    if( (*last) == (*size) )
        (*size) = expand(int, source, *size );
    source[ *last ] = elem;
}

// Returns the last element and removes it
int pop( int *source, int *last, int *size ) {

    int retval = source[ (*last) ];
    --(*last);

    if( (*last) == (*size) / 4 )
        (*size) = reduce(int, source, *size );

    return retval;
}

// Concatenates the two lists
// Does not destroy the two passed arrays, must be freed manually
void* concatenate( const void *first, int fsize, const void *second, int ssize, size_t s ) {

    char *cat = malloc( s * ( fsize + ssize ) );
    memcpy( cat, first, fsize * s );
    memcpy( cat + fsize * s, second, ssize * s );

    return cat;
}
