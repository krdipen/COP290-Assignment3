#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();
extern char* Sub();
extern char* Mul();
extern char* Div();

char* Pow(char arg1[],char arg2[]){

    static char answer[300000];
    answer[0]='1';
    answer[1]='\0';
    static char one[300000];
    one[0]='1';
    one[1]='\0';
    static char zero[300000];
    zero[0]='0';
    zero[1]='\0';
    static char power[300000];
    static char count[300000];
    char current[300000];
    static char next[300000];
    static char temp1[300000];
    static char temp2[300000];
    char *pointer;
    pointer=Sub(arg2,zero);
    int i=0;
    while(i<strlen(pointer)){
        power[i]=pointer[i];
        i++;
    }
    power[i]='\0';

    if(strcmp(power,zero)==0){
        return answer;
    }
    else if(power[0]=='-'){
        arg2[0]='+';
        pointer=Pow(arg1,arg2);
        i=0;
        while(i<strlen(pointer)){
            temp1[i]=pointer[i];
            i++;
        }
        temp1[i]='\0';
        pointer=Div(one,temp1);
        i=0;
        while(i<strlen(pointer)){
            answer[i]=pointer[i];
            i++;
        }
        answer[i]='\0';
        return answer;
    }
    else{
        count[0]='1';
        count[1]='\0';
        i=0;
        while(arg1[i]!='\0'){
            current[i]=arg1[i];
            i++;
        }
        current[i]='\0';
        next[0]='2';
        next[1]='\0';
        pointer=Sub(arg2,next);
        i=0;
        while(i<strlen(pointer)){
            next[i]=pointer[i];
            i++;
        }
        next[i]='\0';
        while(next[0]!='-'){
            pointer=Add(count,count);
            i=0;
            while(i<strlen(pointer)){
                count[i]=pointer[i];
                i++;
            }
            count[i]='\0';
            pointer=Mul(current,current);
            i=0;
            while(i<strlen(pointer)){
                current[i]=pointer[i];
                i++;
            }
            current[i]='\0';
            pointer=Add(count,count);
            i=0;
            while(i<strlen(pointer)){
                next[i]=pointer[i];
                i++;
            }
            next[i]='\0';
            pointer=Sub(arg2,next);
            i=0;
            while(i<strlen(pointer)){
                next[i]=pointer[i];
                i++;
            }
            next[i]='\0';
        }
        pointer=Sub(arg2,count);
        i=0;
        while(i<strlen(pointer)){
            temp1[i]=pointer[i];
            i++;
        }
        temp1[i]='\0';
        pointer=Pow(arg1,temp1);
        i=0;
        while(i<strlen(pointer)){
            temp2[i]=pointer[i];
            i++;
        }
        temp2[i]='\0';
        pointer=Mul(current,temp2);
        i=0;
        while(i<strlen(pointer)){
            answer[i]=pointer[i];
            i++;
        }
        answer[i]='\0';
        return answer;
    }

}
