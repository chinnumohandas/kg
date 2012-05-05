#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

int main( int args, char **argv ) {

    int unsorted[11] = { 1, 63, 24, 35, 12, 6, 209, 248, 51, 24, 62 };

    int *sorted = quicksort( unsorted, 11 );
    srand( time( NULL ) );

    int i;
    for( i = 0; i < 11; ++i )
        printf( "%i ", sorted[ i ] );
    printf( "\n" );

    free( sorted );

    return 0;
}
