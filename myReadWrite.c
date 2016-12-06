#include<stdlib.h>
/* myRead:  Function returns a pointer to memory location having data from a file
            on success return ptr else NULL*/

void *myRead(void *ptr,int size, int nmemb, FILE *fp, int offset){

 
  fseek(fp, SEEK_SET, offset);
  if(fread(ptr, size, nmemb, fp)){
    return ptr;
  }
  return NULL;
}

/* myWrite:  Function writes  a data from memory location to a file 
            on success return 1 else 0 */
int myWrite(void *ptr, int size, int nmemb, FILE *fp, int offset){
  

  fseek(fp, SEEK_SET, offset);
  if(fwrite(ptr, size, nmemb, fp)){
    return 1;
  }
  return 0;
}

