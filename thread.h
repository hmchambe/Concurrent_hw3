----------------------------------------------------------- 
// NAME : Hunter Chambers                 User ID: 81276171 
// DUE DATE : 11/01/2019                                       
// PROGRAM ASSIGNMENT 3                                        
// FILE NAME : thread.h            
// PROGRAM PURPOSE :                                           
// 	this contains the prefixsum thread class for what the
// 	thread will contain
// ----------------------------------------------------------- 
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "ThreadClass.h"

extern int B[512][512];

class PrefixSumThread : public Thread
{
	public:
	// constructor
	PrefixSumThread(int column, int row); 

	private:
	void ThreadFunc();  // thread body
	int row;
	int column;
};
