#include <cstdlib>
#include <iostream>
#include <vector>
// QUICKSORT
// Sorts in-place
template <class T> void quicksort( std::vector< T > *list );
template <class T> int partition( std::vector< T > *list, int left, int right, int pivotIndex );
template <class T> void swap ( T& a, T& b );

template <class T> void quicksort( std::vector< T > *list, int left, int right ) {
    if( left < right ){
        // Choose pivot
        int pivot = ( rand() % ( right + 1 ) ) + left;
        int newPivot = partition( list, left, right, pivot );

        // recursivly call sort
        quicksort( list, left, newPivot - 1 );
        quicksort( list, newPivot + 1, right );
    }
}


template <class T> int partition( std::vector< T > *list, int left, int right, int pivotIndex ) {
    T pivot = list->at( pivotIndex );
    int storeIndex = left;

    int i;
    for( i = left; i < right; ++i ) {
        if( list->at( i ) < pivot ){ 
            swap( list->at( i ), list->at( storeIndex ) );
            ++storeIndex;
        }
    }
    swap( list->at( storeIndex ), list->at( right ) );

    return storeIndex;
}

template <class T> void swap ( T& a, T& b )
{
      T c( a ); a = b; b = c;
}