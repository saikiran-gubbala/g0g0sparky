#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int count=0;
int count2=0;
int depth=0;
bool all_pixels_same_color(int m,int img[m][m], int x, int y, int width, int height){
int check;
check=img[x][y];
for(int i=x;i<width;i++){
  for(int j=y;j<height;j++)
    if(img[i][j]!=check){
      return false;
    }
}
    return true;
}
void split(int m,int img[m][m], int x, int y, int width, int height,int final[m][m]){
  if (all_pixels_same_color(m,img,x,y,width,height))
  {
        count++;
        for(int i=x;i<width;i++){
          for(int j=y;j<height;j++){
            final[i][j]=count;
          }
        }

  }
    else {
     split( m,img, x, y, (width+x)/2,(y+height)/2 ,final); // Top left Quadrant.
     split( m,img, x, (height+y)/2,(width+x)/2,height,final); // Top right Q.
     split( m,img, (width+x)/2, y, width,(height+y)/2,final); // Bottom left Q.
     split( m,img, (x+width)/2, (y+height)/2,width,height,final); // Bottom right Q.
}
}
void quad(int m,int img[m][m], int x, int y, int width, int height,int final[m][m],int level){
  if (all_pixels_same_color(m,img,x,y,width,height))
  {
        count2++;
        printf("(%d,%d,%d)\n",count2,level,img[x][y]);
          }
    else {
    	level++;
     quad( m,img, x, y, (width+x)/2,(y+height)/2 ,final,level); // Top left Quadrant.
     quad( m,img, x, (height+y)/2,(width+x)/2,height,final,level); // Top right Q.
     quad( m,img, (width+x)/2, y, width,(height+y)/2,final,level); // Bottom left Q.
     quad( m,img, (x+width)/2, (y+height)/2,width,height,final,level); // Bottom right Q.
}
}

int main() {
  int p=0,q=0;
  FILE *file  = NULL;
    int symbol  = 0,
        columns = 0,
        rows    = -1;
    file = fopen("L2_P2_inputsample.txt", "r");
    if (file != NULL)
    {
        do
        {
        
            symbol = fgetc(file);
            
            if (rows == 0 && (isspace(symbol) || feof(file)))
            {
                columns++;
            }
            if (symbol == '\n' || feof(file))
            {
                rows++;
            }
        }
        while (symbol != EOF);
        if (ferror(file))
        {
            printf("Error on reading from file.\n");
        }
        else
        {
            printf("The file contains %d row(s) and %d column(s).\n", rows, columns);
    }
        fclose(file);
    }
    
    else
    {
        perror("Error on opening the input file");
   }
FILE *star=NULL;
   star=fopen("L2_P2_inputsample.txt","r");
   int read;
   int arr[rows][rows];
   while(EOF!=fscanf(star,"%d",&read))
   {
    arr[p][q]=read;
    printf("%d",read);
    q++;
    if(q==rows)
    {
      q=0;
      printf("\n");
      p++;
     }
    }  
      int n=rows;
        int size=1;
        while(size<n)
           size=size*2;
        printf("\n"); 
        printf("size=%d",size);
        printf("\n");
int arr2[size][size];
for(int i=0;i<size-n;i++){
for(int j=0;j<size;j++){
arr2[i][j]=0;
arr2[j][i]=0;
}}
for(int i=size-n;i<size;i++){
for(int j=size-n;j<size;j++){
arr2[i][j]=arr[i+n-size][j+n-size];
}}
for(int i=0;i<size;i++){
  for(int j=0;j<size;j++){
    printf("%d",arr2[i][j]);
    if(j==size-1){
      printf("\n");
    }
  }
}
int final2[size][size];
split(size,arr2,0,0,size,size,final2);
for(int i=0;i<size;i++){
  for(int j=0;j<size;j++){
    printf("%d",final2[i][j]);
    printf("\t");
    if(j==size-1){
      printf("\n");
    }
  }
}
quad(size,arr2,0,0,size,size,final2,depth);
  return 0;
}
