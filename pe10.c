#include<stdio.h>
#include<stdlib.h>
#include"answer10.h"


int main(argc, char**argv) {
  if(argc != 5)
    return EXIT_FAILURE;
  print_weight(argv[1]); 
  
  return EXIT_SUCCESS;
}
