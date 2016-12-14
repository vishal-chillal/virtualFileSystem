#include "fs_struct.h"

int inodeAddr;

void creatingRootDir(FILE*);
int checkNextFreeiNode(bitMap *bMap);
void initFileSystem(FILE *fp)
{
  int i;
  superblock *sb = (superblock *) malloc(sizeof(superblock));
  if(!sb)
    {
      printf("Allocation to superBlock failed\n");
      return ;
    }
  bitMap *bMap = (bitMap *) malloc(sizeof(bitMap));
  if(!bMap)
    {
      printf("Allocation to bitMap failed\n");
      return ;
    }
  if(bMap){
    for (i = 0; i < MAX_NO_OF_INODE; i++) 
      bMap -> iNodeBitMap[i] = allocated;
    for (i = 0; i < NO_OF_BLOCK ; i++) 
      bMap -> blockBitMap[i] = allocated;    
  }
  iNodeArray = (iNode *) malloc(sizeof(iNode)*MAX_NO_OF_INODE);
  if(!iNodeArray)
  {
    printf("allocation to iNodeArray Failed\n");
  }
  if(iNodeArray) {
    //    creatingRootDir(fp);
    bMap ->iNodeBitMap[0] = allocated;
    bMap ->blockBitMap[0] = allocated;
  }
  myWrite(bMap,sizeof(bitMap),1,fp,sb->bitMapOffset);
  sb->bitMapOffset = ftell(fp);//sizeof(superblock);
  
  myWrite(iNodeArray,sizeof(iNode)*MAX_NO_OF_INODE,1,fp,sb->iNodeArrayOffset);  
  sb->iNodeArrayOffset = ftell(fp);//sb->bitMapOffset + sizeof(bitMap);
  //sb->nextFreeInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  //sb->rootDirInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  
  //sb->nextFreeDataBlockOffset = sb->iNodeArrayOffset + sizeof(iNode)*MAX_NO_OF_INODE;
  sb->noOfFreeInode = MAX_NO_OF_INODE-1;
  sb->noOfFreeDataBlocks = 22;//NO_OF_BLOCK-1;

  

  //  printf("%d\n", checkNextFreeiNode(bMap));

  //  myWrite(sb,sizeof(sb),1,fp,0);
  printf("%d\n",sb->noOfFreeDataBlocks );

  free (sb);
  free (bMap);
  free (iNodeArray);
  
  return;
}

int checkNextFreeiNode(bitMap *bMap){
  int i;
  for (i = 0; i < MAX_NO_OF_INODE; i++) {
    if (bMap -> iNodeBitMap[i] == notAllocated)
      return i;
  }
  return -1;
}
  void creatingRootDir(FILE *fp){
	  iNode *root;
	  root = (iNode*)malloc(sizeof(iNode));
	  root->flag = directory;
	  strcpy(root->fileName, "/");
	  inodeAddr = ftell(fp);
	  fwrite(root, sizeof(root), 1, fp);
}
