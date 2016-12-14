#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#ifndef STRUCT
#define STRUCT 1
//#define MAX_WRITABLE_SIZE 10

/* #define FIX_BLOCK_SIZE (4*1024) //4KB */
/* #define HALF 2 */
/* #define FS_SIZE (1024 *1024 * 1024) //1GB */
/* #define NO_OF_BLOCK (FS_SIZE / FIX_BLOCK_SIZE) */
/* #define TOTAL_NO_OF_INDEX_BLOCK (NO_OF_BLOCK / HALF) */
/* #define MAX_NO_OF_INODE 7864                       // (NO_OF_BLOCK *(floor(3/100))) */
#define FIX_BLOCK_SIZE (16) //4KB
#define HALF 2
#define FS_SIZE (16 * 16) //1GB
#define NO_OF_BLOCK (FS_SIZE / FIX_BLOCK_SIZE)
#define TOTAL_NO_OF_INDEX_BLOCK (NO_OF_BLOCK / HALF)
#define MAX_NO_OF_INODE 1                       // (NO_OF_BLOCK *(floor(3/100)))


//flag for checking if the inode is for directory or file
typedef enum  inodeFlag{
  directory,
  file
} iNodeFlag;

typedef enum alloacationFlag{
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

//typedef struct iNodeMapArray{
 iNode *iNodeArray;
//}iNodeMapArray;

typedef struct bitMap{
  alloacationFlag iNodeBitMap[MAX_NO_OF_INODE];
  alloacationFlag blockBitMap[NO_OF_BLOCK];
}bitMap;

typedef struct metadata
{
  struct bitMap bitMapPointer;
  //struct iNodeMapArray iNodeMapArrayPointer;
  
}metadata;

typedef struct superblock{
  
  unsigned int iNodeArrayOffset;
  unsigned int bitMapOffset;
  unsigned int nextFreeDataBlockOffset;
  unsigned int noOfFreeDataBlocks;
  unsigned int nextFreeInodeOffset;
  unsigned int rootDirInodeOffset;
  unsigned int noOfFreeInode;
}superblock;
#endif
void creatingRootDir(FILE*);
int checkNextFreeiNode(bitMap *bMap);
void initFileSystem(FILE *fp);
void readFileSystem(FILE*fp);
int myRead(void *ptr,int size, int nmemb, FILE *fp, int offset);
int myWrite(void *ptr, int size, int nmemb, FILE *fp, int offset);
int createDir(char *DirName);
int createFile(char *FileName);
void getCmd(char* ip);
