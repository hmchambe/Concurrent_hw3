// ----------------------------------------------------------- 
// NAME : Hunter Chambers                   User ID: 81276171 
// DUE DATE : 11/01/2019                                       
// PROGRAM ASSIGNMENT 3                                        
// FILE NAME : thread-main.cpp            
// PROGRAM PURPOSE :                                           
//    This program computes the prefix sum concurrently        
// ----------------------------------------------------------- 
#include  <iostream>
#include "thread.h"

// Global Array
int B[512][512];

----------------------------------------------------------- 
// FUNCTION  main                         
//     The purpose of this function is to start the threads
//     and print the proper information for the prefix sum                            
// PARAMETER USAGE :                                           
// 	[none]
// FUNCTION CALLED :                                           
// 	[none]
// ----------------------------------------------------------- 
int main(int argc, char *argv[])
{
	int size, i;
	char buf[500];

	scanf("%d", &size);
	sprintf(buf, "Concurrent Prefix Sum Computation\n\nNumber of input data = %d\n", size);
	write(1, buf, strlen(buf));

	// Making an array of threads
	PrefixSumThread *prefixsumthread[size];

	// Reading array from stdin
	for (i = 0; i < size; i++)
	{
		scanf("%d", &B[0][i]); 
	}

	sprintf(buf, "Input array:\n");
	write(1, buf, strlen(buf));

	for (i = 0; i < size; i++)
	{
		sprintf(buf, "   %d", B[0][i]);
		write(1, buf, strlen(buf));
	}	  
	sprintf(buf, "\n");
	write(1, buf, strlen(buf));

	int k = (int) log2(size), stage; 
	for(stage=1; stage<=k; stage++)
	{
		for(i=0; i<size; i++)
		{
			// start the sum thread
			prefixsumthread[i] = new PrefixSumThread(stage, i); //call with specific row and column
			prefixsumthread[i]->Begin();
		     
		}
		
		for(i=0; i<size; i++)
		{	//wait on threads to finish
			prefixsumthread[i]->Join();

		}
	} 
    
	cout << "After prefixsum, the array is:" << endl;
	for (i = 0; i < size; i++)
	cout << B[k][i] << "   "; 
	cout << endl;
	Exit();
							     
	return 0;
} 
