#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();
extern char* Sub();
extern char* Mul();
extern char* Div();
extern char* Abs();
extern char* Pow();
extern char* Sqrt();

int main(int argc,char *argv[]){
    FILE *outfile;
    outfile=fopen(argv[2],"w");
    if(outfile==NULL){
       printf("File Not Found\n");
       exit(0);
    }
    FILE *infile;
    infile=fopen(argv[1],"r");
    if(infile==NULL){
       printf("File Not Found\n");
       exit(0);
    }
    char cmd[5];
    while(fscanf(infile,"%s",cmd)!=EOF){
        if(strcmp(cmd,"ADD")==0){
            char arg1[300000];
            char arg2[300000];
            fscanf(infile,"%s",arg1);
            fscanf(infile,"%s",arg2);
            char *answer=Add(arg1,arg2);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"SUB")==0){
            char arg1[300000];
            char arg2[300000];
            fscanf(infile,"%s",arg1);
            fscanf(infile,"%s",arg2);
            char *answer=Sub(arg1,arg2);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"MUL")==0){
            char arg1[300000];
            char arg2[300000];
            fscanf(infile,"%s",arg1);
            fscanf(infile,"%s",arg2);
            char *answer=Mul(arg1,arg2);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"DIV")==0){
            char arg1[300000];
            char arg2[300000];
            fscanf(infile,"%s",arg1);
            fscanf(infile,"%s",arg2);
            char *answer=Div(arg1,arg2);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"ABS")==0){
            char arg1[300000];
            fscanf(infile,"%s",arg1);
            char *answer=Abs(arg1);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"POW")==0){
            char arg1[300000];
            char arg2[300000];
            fscanf(infile,"%s",arg1);
            fscanf(infile,"%s",arg2);
            char *answer=Pow(arg1,arg2);
            fprintf(outfile,"%s\n",answer);
        }
        else if(strcmp(cmd,"SQRT")==0){
            char arg1[300000];
            fscanf(infile,"%s",arg1);
            char *answer=Sqrt(arg1);
            fprintf(outfile,"%s\n",answer);
        }
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}
