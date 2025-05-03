#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024 //Read 1024 characters per line
/*
argsc= how many words were written
argv = where they were stored
*/
int main(int argc, char *argv[]){ 
    if (argc < 2){
        fprintf(stderr, "Usage: %s pattern [file]\n", argv[0]); //"you are using me wrong, here's how to do it"
        return 1;
    }
    char *pattern = argv[1]; //what we are looking for
    FILE *fp = (argc >2) = fopen(argv[2], "r") : stdin; // is there a file provided? wait for input
    if (!fp){
        perror("fopen");
        return 1;
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)){
        if (strstr(line, pattern)){
            fputs(line, stdout); //show line 
        }
    }
    if (fp != stdin) fclose(fp); //close file
    return 0;
}
