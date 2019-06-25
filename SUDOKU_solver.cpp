// geeksforgeeks

#include <bits/stdc++.h> 
using namespace std; 
int grid[9][9];
	    
bool FindUnassignedLocation(int &row, int &col);  
bool isSafe(int row,int col, int num);  
void printGrid(void); 
bool SolveSudoku(void);  

bool SolveSudoku(void)  
{  
    int row, col;  
  
    if (!FindUnassignedLocation(row, col))  
    return true; // success!  
  
    for (int num = 1; num <= 9; num++)  
    {  
        if (isSafe(row, col, num))  
        {  
            grid[row][col] = num;  
  
            if (SolveSudoku())  
                return true;    
            grid[row][col] = 0;  
        }  
    }  
    return false;  
}  

bool FindUnassignedLocation(int &row, int &col)  
{  
    for (row = 0; row < 9; row++)  
        for (col = 0; col < 9; col++)  
            if (grid[row][col] == 0)  
                return true;  
    return false;  
}  

bool UsedInRow(int row, int num)  
{  
    for (int col = 0; col < 9; col++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
  
bool UsedInCol(int col, int num)  
{  
    for (int row = 0; row < 9; row++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  

bool UsedInBox(int boxStartRow, int boxStartCol, int num)  
{  
    for (int row = 0; row < 3; row++)  
        for (int col = 0; col < 3; col++)  
            if (grid[row + boxStartRow][col + boxStartCol] == num)  
                return true;  
    return false;  
}  
  
bool isSafe(int row, int col, int num)  
{  
    bool Urow=false, Ucol=false, Usubgrid=false;
    
    for (int r = 0; r<9; r++)  
        if (grid[r][col] == num)
        {
            Urow=true;return false;
        }
    
    for (int c = 0; c<9; c++)  
        if (grid[row][c] == num)
        {
            Ucol=true;return false;
        }    
    
    for (int r=0; r<3; r++)  
        for (int c=0; c<3; c++)  
            if (grid[r+(row-row%3)][c+(col- col%3)] == num) 
            {
                Usubgrid=true;return false;
            }    
    return !Urow && !Ucol && !Usubgrid && grid[row][col]==0;  
}  
  
void printGrid()  
{  
    int row,col;
    
    for (row=0; row<9; row++)  
    {  
    for (col=0; col<9; col++)  
            cout<<grid[row][col]<<" ";  
        //cout<<endl; 
    }
    cout<<"\n";
}  


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if(SolveSudoku())
        printGrid(); 
	}
	return 0;
}
