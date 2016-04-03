#ifndef PE10_H
#define PE10_H

 typedef struct _node {
   int weight;
   char ch;
   struct node* l_node;
   struct node* r_node; 
 }node; 

 void print_weight(char*file, char*output);






#endif
