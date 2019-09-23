#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int count1=1;
bool isSafe(int n,int row,int column)
{
   for(int i=row-1;i>=0;i--)
   {
       if(a[i][column]==1)
       return false;
   }
   for(int i=row-1,j=column-1;i>=0,j>=0;i--,j--)
   {
       if(a[i][j]==1)
       return false;
   }
   
   for(int i=row-1,j=column+1;i>=0,j<n;i--,j++)
   {
       if(a[i][j]==1)
       return false;
   }
   return true;
}
void NQueensHelper(int n,int row)
{
    if(row==n)
    {   cout<<"Combination "<<count1<<":"<<endl;
    count1++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                cout<<"1\t";
                else
                cout<<"0\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(n,row,j))
        {
           a[row][j]=1;
           NQueensHelper(n,row+1);
           a[row][j]=0;
        }
    }
    return;
}
void placeNQueens(int n)
{
    memset(a,0,11*11*sizeof(int));
    NQueensHelper(n,0);
}
int main()
{
    int n;
    cout<<"Enter N"<<endl;
    cin>>n;
    if(n==2 || n==3)
    {
        cout<<"Not Possible"<<"\n";
        return 0;
    }
    placeNQueens(n);
    return 0;
}

