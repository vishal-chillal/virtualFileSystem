#include "fs_struct.h"
#include <unistd.h>
int createDir(char *DirName);
int createFile(char *FileName);
void getCmd(char* ip);

int main()
{
  FILE *fp;
  fp = fopen("myFileSystem.fs","r");
  if(!fp)
    {
      fp = fopen("myFileSystem.fs","w");
      initFileSystem(fp);
    }
  else
    readFileSystem(fp);
  return 0;
}

void getCmd(char* ip)
{
  int i;
  size_t no;

  char *tmp[10],*saveptr,*str;

  printf("MyShell-$ ");
  getline(&ip,&no,stdin);//taking the input for execition
  if(strcmp(ip,"exit")==0)
    exit(0);

  ip[strlen(ip)-1]='\0';
	
  for(i=0,str=ip;;i++,str=NULL){
    tmp[i]=strtok_r(str," ",&saveptr);
    if(tmp[i]==NULL)
      break;
  }
  i = 0;
	
  if(strcmp(tmp[0],"exit")==0)
    {
      return ;
    }
  else if(strcmp(tmp[0],"mkdir")==0)
    {
      if(createDir(tmp[1])==0)
	{
	  printf("%s\n","creationFailed." );
	}
    }
  else if(strcmp(tmp[0],"touch")==0)
    {
      if(createFile(tmp[1])==0)
	{
	  printf("%s\n","creationFailed." );
	}
    }
  
  getCmd(ip);
	  
}

int createDir(char *DirName){
  printf("%s\n",DirName );
  return 0;
}

int createFile(char *FileName){
  printf("%s\n",FileName );
  return 0;
}
