#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer10.h"

lnode * n_construct(long int ch, int weight);
lnode * Enqueue(lnode * * head,long int ch, int weight);
void destroy_list(lnode* head);
void print_list(lnode *head);

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
  lnode *head;
  lnode *new_node =NULL;
  int i;
  for(i = 0; i <256; i++){
    if(weight[i] != 0){
      new_node = Enqueue(&head,i,weight[i]); 
    }
  }

  print_list(head);
  destroy_list(head);
}

lnode* n_construct(long int ch,int weight){
  lnode* new_node = (lnode *)malloc(sizeof(lnode));
  if(new_node == NULL){
    fprintf(stderr,"failed to malloc new node");
    return NULL;
  }
  new_node->weight = weight;
  new_node->ch = (char)ch;
  new_node->l_node = NULL;
  new_node->r_node = NULL;
  return new_node;
} 

lnode* Enqueue(lnode **head,long int ch, int weight){
  lnode* new_node = n_construct(ch,weight);
  if(new_node == NULL){
    fprintf(stderr,"failed to malloc new node");
    return NULL;
  }
  lnode dummy;
  lnode* prev = &dummy;
  lnode* cur = *head;
  dummy.r_node = *head;
  //printf(stderr,"check");
  while(cur != NULL){
    if(cur->weight > new_node->weight)
      break;
    else if(cur->weight == new_node->weight){
      if(new_node->weight == 0)
        break;
      if(strcmp((char *)(&cur->ch),(char *)(&prev->ch)) > 0)
        break;
    }else{
      prev = cur;
      cur = cur->r_node;
    }
  }
  *head = dummy.r_node;
  new_node->r_node = cur;
  prev->r_node = new_node;
  return new_node;
}


void destroy_list(lnode *head){
  lnode *temp = head;
  while(head != NULL){
    temp = head->r_node;
    head->r_node = NULL;
    free(head);
    head = temp;
  }
  
}


void print_list(lnode *head){
  while(head != NULL){
    printf("%c",head->ch);
    fprintf(stdout, "->");
    head = head->r_node;
  } 
  fprintf(stdout, "NULL\n");
}

