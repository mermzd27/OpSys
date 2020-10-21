#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
 char directoryName[] = ("tmp");
 DIR* dirp = opendir(directoryName);
 if(dirp == NULL) {
  return -1;
 }
 struct dirent *entries;
 struct stat staT;
 char filE[64];
 while((entries = readdir(dirp))!=NULL) {
  strcpy(filE, directoryName);
  strcat(filE, "/");
  strcat(filE, entries->d_name);
  stat(filE,&staT);
  if(staT.st_nlink >= 2) {
   printf("File - %s   Link - %ld\n", entries->d_name, entries->d_ino);
  }
 }
 return 0;
}
