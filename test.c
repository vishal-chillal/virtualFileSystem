#include<stdio.h>
#include "fs_struct.h"

int main(){
  iNodeMapArray *i = (iNodeMapArray *)malloc(sizeof(iNodeMapArray));
  
  
  printf("%d \n",sizeof(i->iNodeArray));

  return 0;
}
