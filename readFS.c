#include "fs_struct.h"
#include <stdio.h>

//void creatingRootDir();
//int checkNextFreeiNode(bitMap *bMap);
void readFileSystem(FILE *fp)
{
  //  int i;
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
  /* if(bMap){ */
  /*   for (i = 0; i < MAX_NO_OF_INODE; i++)  */
  /*     bMap -> iNodeBitMap[i] = notAllocated; */
  /*   for (i = 0; i < NO_OF_BLOCK ; i++)  */
  /*     bMap -> blockBitMap[i] = notAllocated;     */
  /* } */
  iNodeArray = (iNode *) malloc(sizeof(iNode)*MAX_NO_OF_INODE);
  if(!iNodeArray){
    printf("allocation to iNodeArray Failed\n");
  }
  /* if(iNodeArray) { */
  /*   creatingRootDir(); */
  /*   bMap ->iNodeBitMap[0] = allocated; */
  /*   bMap ->blockBitMap[0] = allocated; */
  /* } */
  
 
  /* sb->bitMapOffset = sizeof(superblock); */
  /* sb->iNodeArrayOffset = sb->bitMapOffset + sizeof(bitMap); */
  /* sb->nextFreeInodeOffset = sb->bitMapOffset + sizeof(bitMap); */
  /* sb->rootDirInodeOffset = sb->bitMapOffset + sizeof(bitMap); */
  /* sb->nextFreeDataBlockOffset = sb->iNodeArrayOffset + sizeof(iNode)*MAX_NO_OF_INODE; */
  /* sb->noOfFreeInode = MAX_NO_OF_INODE-1; */
  /* sb->noOfFreeDataBlocks = NO_OF_BLOCK-1; */

  

  myRead(sb,sizeof(sb),1,fp,0);
  myRead(bMap,sizeof(bitMap),1,fp,sb->bitMapOffset);
  //myRead(iNodeArray,sizeof(iNode)*MAX_NO_OF_INODE,1,fp,sb->iNodeArrayOffset);

  printf("%d\n",sb->noOfFreeDataBlocks );
  printf("%d\n",bMap->iNodeBitMap[0] );
  int i;
  for (i = 0; i < NO_OF_BLOCK; i++) {
    printf("%d\t",bMap->blockBitMap[0] );    
  }

   printf("\n");
  free (sb);
  free (bMap);
  free (iNodeArray);

  return;
}

/* int checkNextFreeiNode(bitMap *bMap){ */
/*   int i; */
/*   for (i = 0; i < MAX_NO_OF_INODE; i++) { */
/*     if (bMap -> iNodeBitMap[i] == notAllocated) */
/*       return i; */
/*   } */
/*   return -1; */
/* } */

/*   void creatingRootDir(){ */
/*   iNodeArray[0].flag = directory; */
/*   iNodeArray[0].fSizeDetails = 0; */
/*   strcpy(iNodeArray[0].fileName,"/");   */
/* } */
