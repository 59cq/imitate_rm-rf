#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


void rm_rf(DIR* dp,char *path){
    char path_temp[strlen(path)];
    DIR* _dp;
    strcpy(path_temp,path);
    struct dirent* dir;
	
    while(dir = readdir(dp)){
    	//printf("%s\n",dir->d_name);
    	if(NULL == dir){
    		break;
    	}
    	if(0 == strcmp(dir->d_name,".") || 0 == strcmp(dir->d_name,"..")){
    		continue;
    	}
    	//printf("%s\n",dir->d_name);
        if(dir->d_type != DT_DIR){//delete anti-dir
            remove(strcat(path,dir->d_name));
            strcpy(path,path_temp);
        }else{
            strcat(path,dir->d_name);
            //printf("open dp:%s\n",path);
            _dp = opendir(path);
            rm_rf(_dp,strcat(path,"/"));
            rmdir(path);
            strcpy(path,path_temp);
        }
    }
}


int main(int argv,char* argc[]){

    if(argv != 3){
        return -1;
    }
    DIR* dp = opendir(argc[2]);
    if(dp == NULL){
    	return -1;
    }

    rm_rf(dp,strcat(argc[2],"/"));
	rmdir(argc[2]);
}



