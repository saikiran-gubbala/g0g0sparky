#include <iostream>
#include <bits/stdc++.h> 
#include <assert.h>
using namespace std;
int count1=0;
struct Node1 { 
   int data1,data2,data3; 
   struct Node1 *next; 
}; 
struct Node1* head1 = NULL;   
void insert1(int new_data1,int new_data2,int new_data3) { 
   struct Node1* new_node = (struct Node1*) malloc(sizeof(struct Node1)); 
   new_node->data1 = new_data1;
   new_node->data2 = new_data2;
   new_node->data3 = new_data3;
   new_node->next = head1; 
   head1 = new_node;
   count1++;
}
void display1() { 
   struct Node1* ptr;
   ptr = head1;
   while (ptr != NULL) { 
      cout<< "(";
      cout<< ptr->data1 <<",";
      cout<< ptr->data2 <<",";
      cout<< ptr->data3 <<")"<<endl;
      ptr = ptr->next; 
   }
}
struct Node { 
   int data; 
   struct Node *next; 
}; 
struct Node* head = NULL;   
void insert(struct Node *node,int numb) {
  int d; 
  if(numb!=1){
   node->next=(struct Node*)malloc(sizeof(struct Node));
   cout<<"Enter node value\n";
   cin>>d;
   node->next->data=d;
   insert(node->next,numb-1);
 }
 else return;
} 
void display() { 
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   }
}
int get(Node* head, int index)  
{  
      
    Node* current = head;  
    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
    assert(0);        
}
bool xorfor(int a,int b){
    int initial=get(head,a-1);
    for(int i=a;i<b;i++){
      initial=initial^(get(head,i));  
    }
    if(initial==0)
    return true;
    else
    return false;
}
int main() {
   int n,numb,plug=0;
   cout<<"enter number of numbers"<<endl;
   cin>>n;
   cout<<"enter the numbers"<<endl;
   numb=n;
   cout<<"Enter node value\n";
   head=(struct Node*)malloc(sizeof(struct Node));
   cin>>head->data;
   insert(head,n);
   cout<<"The linked list is: "<<endl;
   display();
   cout<<endl;
   bool use;
   for(int i=1;i<=numb;i++){
       for(int j=1;j<i;j++){
           use=xorfor(j,i);
           if(use){
               for(int lol=(j+1);lol<=i;lol++){
                   insert1(j,lol,i);
               }
           }
       }
   }
   cout<<"number of solutions are "<<count1<<endl;
   display1();  
   return 0; 
} 
