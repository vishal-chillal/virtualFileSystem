#include "initFs.c"
#include <stdio.h>
int main(){
  FILE *fp = fopen("myFileSystem.fs","w");
  initFileSystem(fp);
  return 0;
}
