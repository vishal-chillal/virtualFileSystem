#include "fs_struct.h"

int inodeAddr;

void creatingRootDir();
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
      bMap -> iNodeBitMap[i] = notAllocated;
    for (i = 0; i < NO_OF_BLOCK ; i++) 
      bMap -> blockBitMap[i] = notAllocated;
  }
  iNodeArray = (iNode *) malloc(sizeof(iNode)*MAX_NO_OF_INODE);
  if(!iNodeArray)
    {
      printf("allocation to iNodeArray Failed\n");
    }
  if(iNodeArray) {
    creatingRootDir();
    bMap ->iNodeBitMap[0] = 1;
    bMap ->blockBitMap[0] = 1;
  }
  
  sb->bitMapOffset = sizeof(superblock);
  sb->iNodeArrayOffset = sb->bitMapOffset + sizeof(bitMap);
  sb->nextFreeInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  sb->rootDirInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  
  sb->nextFreeDataBlockOffset = sb->iNodeArrayOffset + sizeof(iNode)*MAX_NO_OF_INODE;
  sb->noOfFreeInode = MAX_NO_OF_INODE-1;
  sb->noOfFreeDataBlocks = NO_OF_BLOCK-1;

  myWrite(sb,sizeof(*sb),1,fp,0);
  myWrite(bMap,sizeof(bitMap),1,fp,sb->bitMapOffset);
  myWrite(iNodeArray,sizeof(iNode)*MAX_NO_OF_INODE,1,fp,sb->iNodeArrayOffset);
  
  printf("here is the op of array\n");
  printf("%d\n",iNodeArray[0].fSizeDetails );
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
void creatingRootDir(){
  strcpy(iNodeArray[0].fileName, "/");
  iNodeArray[0].fSizeDetails=5;
  iNodeArray[0].flag = 1;
}
