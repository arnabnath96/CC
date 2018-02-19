#include <iostream>
#include <cstdlib>
#include <numeric>
 
using namespace std;
 
bool subsetSum(long *S, long n, long *sumLeft, long A[])
{
	// return true if subset is found
	if (sumLeft[0] == 0 && sumLeft[1]==0)
		return true;
	// base case: no items left
	if (n < 0)
		return false;
	bool res = false;
 
	// consider current item S[n] and explore all possibilities
	// using backtracking
	for (int i = 0; i <2; i++)
	{
		if (!res && (sumLeft[i] - S[n]) >= 0)
		{
			// mark current element subset
			A[n] = i + 1;
 
			// add current item to i'th subset
			sumLeft[i] = sumLeft[i] - S[n];
 
			// recurse for remaining items
			res = subsetSum(S, n - 1, sumLeft, A);
 
			// backtrack - remove current item from i'th subset
			sumLeft[i] = sumLeft[i] + S[n];
		}
	}
 
	// return true if we get solution
	return res;
}
 
// Function for solving k-partition problem. It prints the subsets if
// set S[0..n-1] can be divided into k subsets with equal sum
void partition(long *S, long n,long x)
{
    long  j;
	if (n < 2)
	{
		std::cout << "impossible\n";
		return;
	}
	long sum = ((n+1)*(n+2))/2 -x;
	//	std::cout << sum;
	
 	long A[n], sumLeft[2];
	for (int i = 0; i < 2; i++)
		sumLeft[i] = sum/2;
 
	bool res = !(sum % 2) && subsetSum(S, n - 1, sumLeft, A);
	if (!res)
	{
		std::cout << "impossible\n";
		return;
	}
	for (int i = 0; i<2; i++)
	   	for (j = 0; j < n; j++)
	 		if (A[j] == 1)
                S[j]=1;
            else
                 S[j]=0;
 
	int flag=0;
	   	for (j = 0; j < n; j++)
	 	{   if(j== x-1)
   	 	    {
   	 	        std::cout <<"2";
   	 	        flag=1;
                std::cout << S[j];
   	 	    }
            else
	 	    std::cout << S[j];
	 	}
	 	if(flag==0)
     	    std::cout <<"2\n";
        else
            std::cout <<"\n";
}
 
 
int main()
{
	int test;
	long N,x,k,i;
    std::cin>>test;
	for(int j=0;j<test;j++)
    {
    std::cin >>x;
	std::cin >>N;
	    long ptr[N-1];
        k=0;
        for(i=0;i<N;i++)
            if(i==x-1)
            {
                *(ptr+i)=k+2;
                k+=2;
            }
            else
            {
                 *(ptr+i)=k+1;
                 k++;
            }
    partition(ptr,N-1,x);
    //free(ptr);
    }
	return 0;
}