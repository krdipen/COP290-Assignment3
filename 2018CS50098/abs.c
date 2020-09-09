#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();

char* Abs(char arg1[]){

    if(arg1[0]=='-'){
        arg1[0]='+';
    }

    char arg2[300000];
    arg2[0]='0';
    arg2[1]='\0';

    char *result=Add(arg1,arg2);

    static char answer[300000];
    int index=0;
    while(result[index]!='\0'){
        answer[index]=result[index];
        index++;
    }
    answer[index]='\0';
    return answer;

}
