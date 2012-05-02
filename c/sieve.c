#include <string.h>
// Creates a list of bools where indeces indicates primes up to given num
int sieve( int num ) {
    // Create initial list
    int bools [ num ];

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
    return bools;
}

// Returns a list of primes (only)
int primes( int num, int *result_size ) {
    *result_size = 0;
    int (*sieve)[] = sieve( num );

    unsigned int pos = 0;
    unsigned int primes_size = 10;
    int primes[ primes_size ];

    unsigned int i;
    for( i = 0; i < num; ++i ) {
        // prime
        if( sieve[ i ] ) {
            primes[ pos ] = i;
            ++pos;

            // Increases array size 
            if( pos == primes_size ) {
                primes_size = expand( primes, primes_size );
            }
        }
    }
}

// Doubles the allocated array in size, preserves content
// Returns new size
int expand( int source[], int size ) {
    int destination[ (*size) * 2 ];
    memcpy( destination, source, (*size) );
    free( source );
    source = destination;
    return size * 2;
}
