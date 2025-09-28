#include <iostream>
using namespace std;

bool check(int grid[9][9], int m, int n, int val) 
{
    for(int i=0;i<9;i++) 
    {
        if(grid[m][i]==val)
        { 
            return false;
        }
    }
    for(int i=0;i<9;i++) 
    {
        if(grid[i][n]==val)
        { 
            return false;
        }
    }
    int t=(m/3)*3, l=(n/3)*3;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[t+i][l+j]==val) 
            {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku(int grid[9][9]) 
{
    for(int m=0;m<9;m++) 
    {
        for(int n=0;n<9;n++) 
        {
            if(grid[m][n]==0) 
            {
                for(int val=1;val<=9;val++) 
                {
                    if(check(grid,m,n,val)) 
                    {
                        grid[m][n]=val;
                        if(Sudoku(grid)) 
                        {
                            return true;
                        }
                        grid[m][n]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,2,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,6,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,8,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,1,0,0,8,0,0,7,9}
    };
    bool t=Sudoku(grid);
    if(t)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cout<<grid[i][j]<<" ";
            cout<<"\n";
        }
    } 
    else 
    {
        cout<<"No solution\n";
    }
}
