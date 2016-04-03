#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer10.h"

lnode * n_construct(int ch, long int weight);
lnode * Enqueue(lnode * * head,int ch, long int weight);
void destroy_list(lnode* head);
void print_list(lnode *head, FILE* print);

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
  lnode *head = NULL;
  lnode *new_node =NULL;
  int i;
  //print_list(head);
  for(i = 0; i < 256; i++){
    if(weight[i] != 0){
      new_node = Enqueue(&head,i,weight[i]); 
//print_list(head,fptr);
    }
  }

  print_list(head,fptr);
  destroy_list(head);
}

lnode* n_construct(int ch,long int weight){
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

lnode* Enqueue(lnode **head,int ch,long int weight){
  lnode* new_node = n_construct(ch,weight);
  if(new_node == NULL){
    fprintf(stderr,"failed to malloc new node");
    return NULL;
  }
  lnode dummy;
  lnode* prev = &dummy;
  lnode* cur = *head;
  dummy.r_node = *head;
  while(cur != NULL){
    if(cur->weight > new_node->weight){
      break;}
    else if(cur->weight == new_node->weight){
        if(new_node->weight == 0){
          fprintf(stderr,"check2");
          break;
        }
        if((int) cur->ch > (int) new_node->ch ){
          fprintf(stdout,"\ncur(big) %c %ld prec(smal) %c %ld \n",cur->ch,cur->weight,new_node->ch,new_node->weight);
          break;
        }
        prev = cur;
        cur = cur->r_node;
    }else{
          prev = cur;
          cur = cur->r_node;
    }
  }
  prev->r_node = new_node;
  new_node->r_node = cur;
  *head = dummy.r_node;
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


void print_list(lnode *head,FILE* fptr){
  while(head != NULL){
    fprintf(fptr,"%c:%ld",head->ch,head->weight);
    fprintf(fptr, "->");
    head = head->r_node;
  } 
  fprintf(fptr, "NULL\n");
}

