#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
 
void dirstroy(char * path){
    
    printf("Statistics for directory: %s\n\n", path);
    DIR *cur;
    cur = opendir(path);
    if (!cur) {
        printf("%s\n",strerror(errno));
        return;
    }
    
    struct dirent * entry;
    entry = readdir(cur);
    int size = 0;
    while(entry) {
        struct stat data;
        stat(entry->d_name, &data);
        if (entry->d_type == DT_DIR) printf("%s: DIR\n", entry->d_name);
        else printf("%s: FILE\n", entry->d_name);
        size += data.st_size;
        entry = readdir(cur);
    }
    
    printf("\nTotal Size: %d bytes\n", size);
    
    closedir(cur);
}

int main(int argc, char * argv[]){
    char * path;
    if (argc != 2){
        printf("please input a directory name as the only input in this format:\n");
        printf("make run args=\"<pathname>\"\n");
        return 0;
    }
  dirstroy(argv[1]);
  
  return 0;
}

//Failed attempt at recursion :(
/*
int dir_stats(int size, int tab, char *path) {
    
    DIR *cur;
    cur = opendir(path);
    if (!cur) {
        printf("%s\n",strerror(errno));
        return 0;
    }
    
    char location[200];

    struct dirent *entry = readdir(cur);
    while(entry) {
        struct stat *data;
        stat(entry->d_name, data);
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            printf("%s\n", entry->d_name);
            strcat(location[tab],entry->d_name);
            tab = sizeof(entry->d_name);
            size = dir_stats(size, tab, location);
        }
        else {
            printf("%s\n", entry->d_name);
            size += data->st_size;
        }
        entry = readdir(cur);
    }
    
    closedir(cur);
    return size;
    
}
*/