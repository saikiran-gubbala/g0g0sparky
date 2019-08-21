#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{ char ch;
  char s[150];
  int count=0;
  char str[50];
  int n,a,b;
   FILE *fp;
printf("enter n,a,b\n");
scanf("%d %d %d",&n,&a,&b);
int a1,b1,h;
for(h=0;h<n;h++){
  if((h*n)%a==1)
  {
    a1=(h*n+1)%a;
    b1=n-((a1*b)%n);
  }
}
 
   fp = fopen("outputfile.txt", "r"); // read mode
 
   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
 
while(EOF!=fscanf(fp,"%c",&ch))
{
s[count]=ch;
count++;
printf("%c",ch);
}
printf("\n");
  char lol[150];
  char req[150];
  int l,rl,test;
  l=count-1;
  test=l/n;
  if(l%n==0)
{
     rl=l;
     strcpy(req,s);
}
  else
{
     rl=(test+1)*5;
     for(int i=0;i<l;i++)
     req[i]=s[i];
    
     for(int i=l;i<rl;i++)
     req[i]='\0';
}
  int rows,columns;
  rows=rl/n;
  columns=n;
  char new_string[rows][columns];
  int count2=0;
  for(int i=0;i<rows;i++){
      for(int j=0;j<columns;j++){
          new_string[i][j]=req[count2];
          count2++;
      }
  }
  char final[rows][columns];
char please[rl];
for (int i=0;i<n;i++){
    int j;
    j=((a1*i)+b1)%n;
    for(int x=0;x<rows;x++){
        final[x][i]=new_string[x][j];
    }
}
  for(int i=0;i<rows;i++){
for(int j=0;j<columns;j++){
printf("%c",final[i][j]);
}}
printf("\n");
fp=fopen("decryptedOutputfile.txt","w");
for(int i=0;i<rows;i++){
for(int j=0;j<columns;j++)
{
fputc(final[i][j],fp);
}
}
  return 0;
}