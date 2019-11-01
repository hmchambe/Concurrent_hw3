// ----------------------------------------------------------- 
// NAME : Hunter Chambers                   User ID: 81276171 
// DUE DATE : 11/01/2019                                       
// PROGRAM ASSIGNMENT 3                                        
// FILE NAME : thread.cpp            
// PROGRAM PURPOSE :                                           
//    This program computes the prefix sum concurrently        
// ----------------------------------------------------------- 
#include  <iostream>
#include "thread.h"

PrefixSumThread::PrefixSumThread(int Column, int Row) 
          :column(Column), row(Row)
{
	ThreadName.seekp(0, ios::beg);
	ThreadName << "Thread" 
		<< '(' << column << ':' << row << ')'
		<< '\0';
}

----------------------------------------------------------- 
// FUNCTION  ThreadFunc                          
//     this function is what each individual thread does
//     it computes the prefix sum for an individual element                            
// PARAMETER USAGE :                                           
// 	this function takes the column(stage) and row(element)
// 	that needs to be modified
// FUNCTION CALLED :                                           
// 	[none]
// ----------------------------------------------------------- 
void PrefixSumThread::ThreadFunc()
{
	Thread::ThreadFunc();
	int position = row - (int) pow(2, column-1);
     	char buf[300];

	if(position < 0)
	{
		//if it is one of the initial elements, no calculations just copy
		B[column][row] = B[column-1][row];
		sprintf(buf, "        Thread %d copies x[%d]\n        ..........\n", row, row);
	}else
	{	//otherwise perform prefixsum calculation
		B[column][row] = B[column-1][row] + B[column-1][position];
		sprintf(buf, "        Thread %d computes x[%d] + x[%d-2^(%d-1)]\n        ..........\n", row, row, row, column);
	}

	write(1, buf, strlen(buf));
  	Exit();                            // done and exit
}
