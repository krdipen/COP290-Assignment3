#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Sub();

char* Div(char arg1[],char arg2[]){

    char sign;
    if((arg1[0]=='-')&&(arg2[0]=='-')) {sign='+';}
    else if((arg1[0]!='-')&&(arg2[0]=='-')) {sign='-';}
    else if((arg1[0]=='-')&&(arg2[0]!='-')) {sign='-';}
    else {sign='+';}

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

    int length1;
    int length2;
    if(fraction1!=NULL) {length1=strlen(fraction1);}
    else {length1=0;}
    if(fraction2!=NULL) {length2=strlen(fraction2);}
    else {length2=0;}
    int decimal=length1-length2;
    int index;
    bool flag;

    char nums1[300000];
    index=0;
    flag=false;
    if(integer1!=NULL){
        for(int i=0;i<strlen(integer1);i++){
            if((integer1[i]!='0')||(flag)){
                flag=true;
                nums1[index]=integer1[i];
                index++;
            }
        }
    }
    if(fraction1!=NULL){
        for(int i=0;i<strlen(fraction1);i++){
            if((fraction1[i]!='0')||(flag)){
                flag=true;
                nums1[index]=fraction1[i];
                index++;
            }
        }
    }
    for(int i=0;i<20-length1+length2;i++){
        nums1[index]='0';
        index++;
        decimal++;
    }
    nums1[index]='\0';
    char nums2[300000];
    index=0;
    flag=false;
    if(integer2!=NULL){
        for(int i=0;integer2[i]!='\0';i++){
            if((integer2[i]!='0')||(flag)){
                flag=true;
                nums2[index]=integer2[i];
                index++;
            }
        }
    }
    if(fraction2!=NULL){
        for(int i=0;fraction2[i]!='\0';i++){
            if((fraction2[i]!='0')||(flag)){
                flag=true;
                nums2[index]=fraction2[i];
                index++;
            }
        }
    }
    nums2[index]='\0';
    length1=strlen(nums1);
    length2=strlen(nums2);

    static char answer[300000];
    if(length2==0){
        answer[0]='e';
        answer[1]='r';
        answer[2]='r';
        answer[3]='o';
        answer[4]='r';
        answer[5]='\0';
        return answer;
    }
    char result[300000];
    if(length1<length2){
        result[0]='0';
    }
    char mystring[300000];
    for(int j=0;j<length1;j++){
        mystring[j]=nums1[j];
    }
    mystring[length1]='\0';
    char remain_prev[300000];
    char *remainder;
    index=0;
    while(true){
        if(length1-index<length2){
            if(index==0){
                result[1]='\0';
            }
            else{
                result[index]='\0';
            }
            break;
        }
        for(int i=0;i<=9;i++){
            char vector[300000];
            for(int j=length1-index-length2;j>=1;j--){
                vector[length2+j]='0';
            }
            char carry='0';
            for(int j=length2-1;j>=0;j--){
                vector[j+1]=(((nums2[j]-48)*i+(carry-48))%10)+48;
                carry=(((nums2[j]-48)*i+(carry-48))/10)+48;
            }
            vector[0]=carry;
            vector[length1-index+1]='\0';
            remainder=Sub(mystring,vector);
            if(remainder[0]=='-'){
                break;
            }
            for(int j=0;j<strlen(remainder);j++){
                remain_prev[j]=remainder[j];
            }
            remain_prev[strlen(remainder)]='\0';
            result[index]=i+48;
        }
        for(int j=0;remain_prev[j]!='\0';j++){
            mystring[j]=remain_prev[j];
        }
        mystring[strlen(remain_prev)]='\0';
        index++;
    }
    index=0;
    flag=false;
    for(int i=0;result[i]!='\0';i++){
        if((result[i]!='0')||(flag)){
            flag=true;
            result[index]=result[i];
            index++;
        }
    }
    result[index]='\0';

    index=0;
    int last=-1;
    for(int i=strlen(result)-1;i>=0;i--){
        if(result[i]!='0'){
            last=i;
            break;
        }
    }
    if(last==-1){
        answer[index]='0';
        index++;
        answer[index]='\0';
        return answer;
    }
    if(sign=='-'){
        answer[index]='-';
        index++;
    }
    if(strlen(result)>decimal){
        for(int i=0;i<strlen(result)-decimal;i++){
            answer[index]=result[i];
            index++;
        }
        if(strlen(result)-decimal-1<last){
            answer[index]='.';
            index++;
            for(int i=strlen(result)-decimal;i<=last;i++){
                answer[index]=result[i];
                index++;
            }
        }
    }
    else{
        answer[index]='0';
        index++;
        answer[index]='.';
        index++;
        for(int i=0;i<decimal-strlen(result);i++){
            answer[index]='0';
            index++;
        }
        for(int i=0;i<=last;i++){
            answer[index]=result[i];
            index++;
        }
    }
    answer[index]='\0';
    return answer;

}
