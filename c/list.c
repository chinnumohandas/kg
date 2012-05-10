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

/*void append( int *source, int *last, int *size, int elem ) {
    ++(*last);
    // handle possible overflow
    if( (*last) == (*size) )
        (*size) = expand(int, source, *size );
    source[ *last ] = elem;
}*/

// Returns the last element and removes it
int pop( int *source, int *last, int *size ) {

    int retval = source[ (*last) ];
    --(*last);

    if( (*last) == (*size) / 4 )
        printf( "removed\n" );
        //(*size) = reduce(int, source, *size );

    return retval;
}

int* expand( int *source, int *alloc ) {
    *alloc *= 2;
    int *ret = realloc( source, (*alloc) * sizeof( int ) );

    if( !ret ) {
        fprintf( stderr, "out of memory or other memory error\n" );
        exit( 1 );
    }
    else return ret;
}

// Concatenates the two lists
// Does not destroy the two passed arrays, must be freed manually
void* concatenate( const void *first, int fsize, const void *second, int ssize, size_t s ) {

    char *cat = malloc( s * ( fsize + ssize ) );
    memcpy( cat, first, fsize * s );
    memcpy( cat + fsize * s, second, ssize * s );

    return cat;
};

list* init_list() {
    list *list = malloc( sizeof( list ) );
    list->alloc = DEFAULTSIZE;
    /* Size points to last index */
    list->size = -1;
    list->array = calloc( sizeof( int ) * list->alloc, sizeof( int ) );
    return list;
}

void append( list *list, int elem ) {
    ++( list->size );
    if( list->size == list->alloc )
        list->array = expand( list->array, &(list->size) );
        //list->array = expand( &(list->array), &(list->size) );
    list->array[ list->size ] = elem;
}

int at( list *list, int pos ){
    if( pos <= list->size && pos > -1 )
        return list->array[ pos ];
    else
        exit( 1 );
}
