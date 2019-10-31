#include  <iostream>
#include "thread.h"

PrefixSumThread::PrefixSumThread(int Column, int Row) 
          :column(Column), row(Row)
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "sum" 
                << '(' << Lowerbound << ':' << Upperbound << ')'
                << '\0';
}

void PrefixSumThread::ThreadFunc()
{
     Thread::ThreadFunc();
 	



  Exit();                            // done and exit
}
