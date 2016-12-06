#include "fs_struct.h"
#include "myReadWrite.c"
#include <stdio.h>

void initFileSystem(FILE *fp)
{
  superblock *sb = (superblock *)malloc(sizeof(superblock));
  bitMap *bMap = (bitMap*) malloc(sizeof(bitMap));
  iNodeArray = (iNode*) malloc(sizeof(iNode)*MAX_NO_OF_INODE);

  sb->bitMapOffset = sizeof(superblock);  
  sb->iNodeArrayOffset = sb->bitMapOffset + sizeof(bitMap);
  sb->nextFreeInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  sb->rootDirInodeOffset = sb->bitMapOffset + sizeof(bitMap);
  sb->nextFreeDataBlockOffset = sb->iNodeArrayOffset + sizeof(iNode)*MAX_NO_OF_INODE ;
  sb->noOfFreeInode = MAX_NO_OF_INODE;
  sb->noOfFreeDataBlocks = NO_OF_BLOCK;

  

  
  myWrite(sb,sizeof(sb),1,fp,0);
  myWrite(bMap,sizeof(bitMap),1,fp,sb->bitMapOffset);
  myWrite(iNodeArray,sizeof(iNode)*MAX_NO_OF_INODE,1,fp,sb->iNodeArrayOffset);


  /*unsigned int iNodeArrayOffset;*/
  /*unsigned int bitMapOffset;*/
  /*unsigned int nextFreeDataBlockOffset;*/
  /*unsigned int noOfFreeDataBlocks;*/
  /*unsigned int nextFreeInodeOffset;*/
  /*unsigned int rootDirInodeOffset;*/
  /*unsigned int noOfFreeInode;*/
	
  return;
}
