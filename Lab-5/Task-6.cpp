#include <iostream>
using namespace std;

bool safe(int x,int y,int n,int maze[20][20],int sol[20][20]) 
{
    return x>=0 && x<n && y>=0 && y<n && maze[x][y]==1 && sol[x][y]==0;
}

bool solve(int x,int y,int n,int maze[20][20],int sol[20][20]) 
{
    if(x==n-1 && y==n-1) 
    {
        sol[x][y]=1;
        return true;
    }
    if(safe(x,y,n,maze,sol)) 
    {
        sol[x][y]=1;
        if(solve(x+1,y,n,maze,sol)) return true;
        if(solve(x-1,y,n,maze,sol)) return true;
        if(solve(x,y+1,n,maze,sol)) return true;
        if(solve(x,y-1,n,maze,sol)) return true;
        sol[x][y]=0;
    }
    return false;
}

int main() 
{
    int n;
    int maze[20][20],sol[20][20];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }

    if(solve(0,0,n,maze,sol)) 
    {
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) cout<<sol[i][j]<<" ";
            cout<<"\n";
        }
    } 
    else 
    {
        cout<<"No path\n";
    }
}
