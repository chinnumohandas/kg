def sieve( size ):
### Create initial list
    A = [ True for x in range( size ) ]

    for i in range( 2, size ):
        if( A[ i ] ):
            for j in range( 2*i, size, i ):
                A[ j ] = False

    return A
