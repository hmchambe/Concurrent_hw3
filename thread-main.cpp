#include  <iostream>
#include "thread.h"

int B[512][512];

int main(int argc, char *argv[])
{
     PrefixSumThread *prefixsumthread;
     int size, i;

     cout << "Reading array size" << endl;
     cin >> size;

     array = new int[size]; // create the array

     cout << "Reading in array " << endl;
     for (i = 0; i < size; i++)
          cin >> B[0][i]; 

     cout << "Before sum, the array is:" << endl;
     for (i = 0; i < size; i++)
          cout << B[0][i] << "   ";
     cout << endl;

    // start the sum thread
    prefixsumthread = new PrefixSumThread(); //call with specific row and column
    prefixsumthread->Begin();
     
    // wait for the sum thread to finish
    prefixsumthread->Join();
     
    cout << "After quicksort, the array is:" << endl;
    for (i = 0; i < arraySize; i++)
    cout << array[i] << "   "; 
    cout << endl;
    Exit();
                                                             
    return 0;
} 
