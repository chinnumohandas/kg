// Library subset to handle typical list (extended array) tasks such as
// 'dynamic' reallocation

int expand( int **source, int size );
int reduce( int **source, int size );
void append( int **source, int *last, int *size, int elem );
int pop( int **source, int *last, int *size );
