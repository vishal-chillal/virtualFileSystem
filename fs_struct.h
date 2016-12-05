#define MAX_WRITABLE_SIZE 10
#define FIX_BLOCK_SIZE 4
#define FS_SIZE (4 * 1024 * 1024 * 1024)
#define NO_OF_BLOCK (FS_SIZE / FIX_BLOCK_SIZE)
#define MAX_NO_OF_INODE (NO_OF_BLOCK / 2)
#include<stdlib.h>
//flag for checking if the inode is for directory or file
typedef enum {
  directory,
  file
} iNodeFlag;

typedef enum {
  notAllocated,
  allocated
} alloacationFlag;


//actual data writting block;
typedef struct dataBlock{
  char data[FIX_BLOCK_SIZE];
}dataBlock;

//storing addresses of datablock and last address of next indexblock
//this will be the structure for an array
typedef struct indexBlock{
  struct dataBlock blockAddress[FIX_BLOCK_SIZE/(sizeof(int*))];
  } indexBlockArray;

//structure for linklist of addresses
//it is part of iNode;
typedef struct containtDetailList{
  void *ContaintAddress;
  struct  containtDetailList* next;
}containtDetailList;

typedef struct iNode{
  iNodeFlag flag ;//enum checking weather it is for directory or file
  int fSizeDetails; //file size by actual characters in file
  char fileName[32]; 
  struct containtDetailList *Head; // address of iNodes if it is a directory else addresses of indexBlocks for file
}iNode;

typedef struct iNodeMapArray{
  iNode iNodeArray[MAX_NO_OF_INODE];
}iNodeMapArray;

typedef struct bitMap{
  alloacationFlag inodeBitMap[MAX_NO_OF_INODE];
  alloacationFlag blockBitMap[NO_OF_BLOCK];
}bitMap;

typedef struct metadata
{
  struct bitMap bitMapPointer;
  struct iNodeMapArray iNodeMapArrayPointer;
  
}metadata;


