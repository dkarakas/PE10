#include<stdio.h>
#include<stdlib.h>
#include"answer10.h"

void print_weight(FILE*fptr,FILE* out_fptr,long int*weight){
  //VARIABLES
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
}

void priority_queue_by_weight(FILE*fptr, long int*weight){
  //


printf("chec");

}
