#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include "ThreadClass.h"

extern int B[512][512]

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
