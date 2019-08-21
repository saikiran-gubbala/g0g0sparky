
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{ char ch;
  char s[150];
  int count=0;
   FILE *fp;
   fp = fopen("decryptedOutputfile.txt", "r"); // read mode
 
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
char ch2;
  char s2[150];
  int count2=0;
   FILE *fp2;
   fp2 = fopen("inputfile.txt", "r"); // read mode
 
   if (fp2 == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
 
while(EOF!=fscanf(fp2,"%c",&ch2))
{
s2[count2]=ch2;
count2++;
printf("%c",ch2);
}
for (int i = 0; i < count2-1; i++)
{
     if (s[i]!=s2[i])
     {
        printf("\nboth are not same\n");
        return 0;
     }
}
printf("\nboth are same\n");

return 0;
}