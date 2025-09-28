#include <iostream>
using namespace std;

bool check(int row,int col,int cols[100]) 
{
    for(int r=0;r<row;r++) 
    {
        int c=cols[r];
        if(c==col) return false;
        if((c-col)==(r-row) || (col-c)==(r-row)) return false;
    }
    return true;
}

void N_Queens(int row,int n,int cols[100]) {
    if(row==n) {
        for(int r=0;r<n;r++) {
            for(int c=0;c<n;c++) {
                if(cols[r]==c) cout<<"Q ";
                else cout<<". ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    for(int c=0;c<n;c++) {
        if(check(row,c,cols)) {
            cols[row]=c;
            N_Queens(row+1,n,cols);
            cols[row]=-1;
        }
    }
}

int main() {
    int n;
    int cols[100];
    cin>>n;
    for(int i=0;i<n;i++) 
    {
        cols[i]=-1;
    }
    N_Queens(0,n,cols);
}
