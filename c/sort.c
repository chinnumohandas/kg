#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"
#include "sort.h"

int randpivot( int max ) {
    //srand( time( NULL ) );
    return rand() % max;
}

int* quicksort( int *source, int size ) {
    if( size <= 1 )
        return source;
    printf( "quicksort! size => %i\n", size );

    int p;
    for( p = 0; p < size; ++p )
        printf( "%i ", source[ p ] );
    printf( "\n" );

    // pick pivot index
    int pivindex = randpivot( size );
    printf( "pivindex => %i\n", pivindex );
    int pivot = source[ pivindex ];

    // Initialize variables and lists
    int lesslen = size / 2;
    int greatlen = size / 2;

    int lesslast = -1;
    int greatlast = -1;

    int *less = malloc( lesslen * sizeof( int ) );
    int *greater = malloc( greatlen * sizeof( int ) );

    unsigned int i;
    // Quickly sort in lesser & smaller
    for( i = 0; i < size; ++i ) {
        // Skip the chosen pivot
        if( i == pivindex ) { /* do not do anything */ }
        else if( source[ i ] <= pivot )
            append( less, &lesslast, &lesslen, source[ i ] );
        else
            append( greater, &greatlast, &greatlen, source[ i ] );
    }

    append( less, &lesslast, &lesslen, pivot );
    ++lesslast;
    ++greatlast;

    for( i = 0; i < lesslast; ++i ) 
        printf( "%i ", less[ i ] );
    printf( "\n\n" );

    less = quicksort( less, lesslast );
    greater = quicksort( greater, greatlast );
    int *result = concat( int, less, lesslast, greater, greatlast );

    // Free no longer needed memory
    //free( less );
    //free( greater );

    return result;
}
