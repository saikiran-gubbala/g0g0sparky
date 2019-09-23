#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main(){
	
int n,i,sum=0,h=0,ans,low=0,high=0,f_low=0,f_high=0;
map<int,int> max;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements: "<<endl;
    for(i=0;i<n;i++){
    cin>>a[i];
    max.insert(pair<int, int>(i, a[i]));
    }
    cout<<"Enter sum: "<<endl;
    cin>>ans;
    map<int, int>::iterator itr;
    for (itr = max.begin(); itr != max.end(); ++itr) { sum=0;
    for(i=itr->first;i<n;i++){
         sum=sum+a[i]; if(high-low>h) h=high-low;
          if(sum==ans){
              high=i;
              low=itr->first;
              if(high-low>h){  h=high-low; f_low=low; f_high=high; }
         }
    }
    }
    cout<<"Length of longest sub array is "<<h+1<<endl;
    cout<<"Index from "<<f_low<<" to "<<f_high<<endl;
}


