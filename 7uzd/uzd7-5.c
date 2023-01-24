#include <stdio.h>

long getFileSize(char *fileName){
    long length;
    FILE *workingFile;

    workingFile = fopen(fileName, "rb");

    if(workingFile == NULL){
        printf("file not found\n");
        return -1;
    }

    fseek(workingFile, 0, SEEK_END);
    length = ftell(workingFile);

}

int main(){
    char fileName[] = "hey.txt";
    printf("%d", getFileSize(fileName));
}