#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sieve.h"
#include "list.h"

// Creates a list of bools where indeces indicates primes up to given num
int* sieve( int num ) {
    // Create initial list
    int* bools = malloc( num * sizeof( int ) );

    unsigned int i;
    unsigned int j;

    // Sets all elements to 'true'
    for( i = 0; i < num; ++i )
        bools[ i ] = 1;

    // Generates all primes
    for( i = 2; i < num; ++i ) {
        if( bools[ i ] ) {
            for( j = 2*i; j < num; j += i )
                bools[ j ] = 0;
        }
    }
    return ( &bools[ 0 ] );
}

// Returns a list of primes (only)
int* primes( int num, int *pos ) {
    int *sievelist = sieve( num );

    *pos = 0;
    unsigned int primes_size = 10;
    int* primes = malloc( primes_size * sizeof( int ) );

    unsigned int i;
    for( i = 1; i < num; ++i ) {
        // prime
        if( sievelist[ i ] ) {
            primes[ *pos ] = i;
            ++(*pos);

            // Increases array size 
            if( (*pos) == primes_size )
                primes_size = expand( &primes, primes_size );
        }
    }
    free( sievelist );
    return ( &primes[ 0 ] );
}
