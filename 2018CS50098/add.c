#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Sub();

char* Add(char arg1[],char arg2[]){

    char sign1=arg1[0];
    char sign2=arg2[0];
    if((sign1!='-')&&(sign2=='-')){
        arg2[0]='+';
        return Sub(arg1,arg2);
    }
    if((sign1=='-')&&(sign2!='-')){
        arg1[0]='+';
        return Sub(arg2,arg1);
    }

    char* integer1;
    char* fraction1;
    if((arg1[0]=='.')||((arg1[0]=='-')&&(arg1[1]=='.'))||((arg1[0]=='-')&&(arg1[1]=='.'))){
        integer1=NULL;
        fraction1=strtok(arg1,"+.-");
    }
    else{
        integer1=strtok(arg1,"+.-");
        fraction1=strtok(NULL,"+.-");
    }
    char* integer2;
    char* fraction2;
    if((arg2[0]=='.')||((arg2[0]=='-')&&(arg2[1]=='.'))||((arg2[0]=='-')&&(arg2[1]=='.'))){
        integer2=NULL;
        fraction2=strtok(arg2,"+.-");
    }
    else{
        integer2=strtok(arg2,"+.-");
        fraction2=strtok(NULL,"+.-");
    }

    char result[300000];
    int index=0;
    int carry=0;
    int length1;
    int length2;

    if(fraction1!=NULL){
        length1=strlen(fraction1);
    }
    else{
        length1=0;
    }
    if(fraction2!=NULL){
        length2=strlen(fraction2);
    }
    else{
        length2=0;
    }
    if(length1>=length2){
        for(int i=1;i<=(length1-length2);i++){
            result[index]=fraction1[length1-i];
            index++;
        }
        for(int i=1;i<=length2;i++){
            result[index]=(char)(((int)fraction1[length2-i]+(int)fraction2[length2-i]+carry-96)%10+48);
            carry=((int)fraction1[length2-i]+(int)fraction2[length2-i]+carry-96)/10;
            index++;
        }
    }
    else{
        for(int i=1;i<=(length2-length1);i++){
            result[index]=fraction2[length2-i];
            index++;
        }
        for(int i=1;i<=length1;i++){
            result[index]=(char)(((int)fraction1[length1-i]+(int)fraction2[length1-i]+carry-96)%10+48);
            carry=((int)fraction1[length1-i]+(int)fraction2[length1-i]+carry-96)/10;
            index++;
        }
    }
    int int_index=index;
    if(integer1!=NULL){
        length1=strlen(integer1);
    }
    else{
        length1=0;
    }
    if(integer2!=NULL){
        length2=strlen(integer2);
    }
    else{
        length2=0;
    }
    if(length1>=length2){
        for(int i=1;i<=length2;i++){
            result[index]=(char)(((int)integer1[length1-i]+(int)integer2[length2-i]+carry-96)%10+48);
            carry=((int)integer1[length1-i]+(int)integer2[length2-i]+carry-96)/10;
            index++;
        }
        for(int i=1;i<=(length1-length2);i++){
            result[index]=(char)(((int)integer1[length1-length2-i]+carry-48)%10+48);
            carry=((int)integer1[length1-length2-i]+carry-48)/10;
            index++;
        }
    }
    else{
        for(int i=1;i<=length1;i++){
            result[index]=(char)(((int)integer1[length1-i]+(int)integer2[length2-i]+carry-96)%10+48);
            carry=((int)integer1[length1-i]+(int)integer2[length2-i]+carry-96)/10;
            index++;
        }
        for(int i=1;i<=(length2-length1);i++){
            result[index]=(char)(((int)integer2[length2-length1-i]+carry-48)%10+48);
            carry=((int)integer2[length2-length1-i]+carry-48)/10;
            index++;
        }
    }
    result[index]=(char)(carry+48);

    static char answer[300000];
    int start=0;
    bool flag=false;
    bool flag2=false;
    for(int i=0;i<=index-int_index;i++){
        if((result[index-i]!='0')||flag){
            if((!flag)&&(sign1=='-')){
                answer[start]='-';
                start++;
            }
            answer[start]=result[index-i];
            start++;
            flag=true;
        }
    }
    for(int i=0;i<int_index;i++){
        if(result[i]!='0'){
            flag2=true;
            if(!flag){
                if(sign1=='-'){
                    answer[start]='-';
                    start++;
                }
                answer[start]='0';
                start++;
            }
            answer[start]='.';
            start++;
            for(int j=int_index-1;j>=i;j--){
                answer[start]=result[j];
                start++;
            }
            break;
        }
    }
    if((!flag2)&&(!flag)){
        answer[start]='0';
        start++;
    }
    answer[start]='\0';
    return answer;

}
