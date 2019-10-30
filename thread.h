#include "ThreadClass.h"

class PrefixSumThread : public Thread
{
     public:
          // constructor
     QuickSortThread(int Lowerbound, int Upperbound, int Array[]); 
	  private:
	  void ThreadFunc();  // thread body
	  int  lowerbound;    // lower bound of the sub-array to be sorted
	  int  upperbound;    // upper bound of the sub-array to be sorted
	  int  *a;            // pointing to array to be sorted
};
