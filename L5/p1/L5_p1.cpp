#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{   int temp1,size1,temp2,size2,ope,temp3;
    cout<<"enter No. of terms in the expression"<<endl;
    cin>>size1;
    vector<int> g1; 
    
    cout<<"enter coefficients in ascending order "<<endl;
    for (int i = 0; i <size1; i++){
        cin>>temp1;
        g1.push_back(temp1); 
    }
    cout<<"enter No. of terms in the expression"<<endl;
    cin>>size2;
    vector<int> g2;
    vector<int> g3;
    
    cout<<"enter coefficients in ascending order "<<endl;
    for (int i = 0; i <size2; i++){
        cin>>temp2;
        g2.push_back(temp2); 
    }
    cout<<"Enter 1 to add or 2 for multiply "<<endl;
    cin>>ope;
    if(ope==1){
        int s = max(size1,size2);
        for(int i=0;i<s;i++){
            temp3=g1[i]+g2[i];
            g3.push_back(temp3);
        }
        for (int i = 0; i < g3.size(); i++) 
        cout << g3[i] << " "; 
    }
    else{
        for (int i = 0; i<size1+size2-1; i++) 
        g3.push_back(0); 
        for (int i=0; i<size1; i++) 
     { 
     for (int j=0; j<size2; j++) 
         g3[i+j] += g1[i]*g2[j]; 
   } 
    for (int i = 0; i < g3.size(); i++) 
        cout << g3[i] << " "; 
    }
    return 0; 
} 

