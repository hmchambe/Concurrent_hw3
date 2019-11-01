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
