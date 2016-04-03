#include<stdio.h>
#include<stdlib.h>
#include"answer10.h"

void print_weight(char*file,char*output,long int*weight){
  //VARIABLES
  FILE *fptr = fopen(file,"r");
  FILE *out_fptr = fopen(output,"w");
  int int_ch;
  int i;
  char ch;

  //FILE OPERATIONS
  fseek(fptr,0,SEEK_SET);
  while((ch=fgetc(fptr))!=EOF){
    int_ch = (int) ch; 
    weight[int_ch]++;
  }
  //PRINTING THE WIGHT TO THE GIVEN FILE OUTPUT
  for(i = 0; i <256; i++){
    fprintf(out_fptr,"%ld\n",weight[i]);
  }
  fclose(out_fptr);
  fclose(fptr);
}

