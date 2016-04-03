#ifndef PE10_H
#define PE10_H

 typedef struct _node {
   int weight;
   char ch;
   struct node* l_node;
   struct node* r_node; 
 }node; 

 void print_weight(FILE*file,FILE*output,long int*weight);
 void priority_queue_by_weight(FILE*file, long int*weight);






#endif
