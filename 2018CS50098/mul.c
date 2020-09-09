#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();

char* Mul(char arg1[],char arg2[]){

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
    int decimal=length1+length2;
    int index;

    char nums1[300000];
    index=0;
    if(integer1!=NULL){
        for(int i=0;integer1[i]!='\0';i++){
            nums1[index]=integer1[i];
            index++;
        }
    }
    if(fraction1!=NULL){
        for(int i=0;fraction1[i]!='\0';i++){
            nums1[index]=fraction1[i];
            index++;
        }
    }
    nums1[index]='\0';
    char nums2[300000];
    index=0;
    if(integer2!=NULL){
        for(int i=0;integer2[i]!='\0';i++){
            nums2[index]=integer2[i];
            index++;
        }
    }
    if(fraction2!=NULL){
        for(int i=0;fraction2[i]!='\0';i++){
            nums2[index]=fraction2[i];
            index++;
        }
    }
    nums2[index]='\0';
    length1=strlen(nums1);
    length2=strlen(nums2);

    char temp[300000]="0";
    char *result=temp;
    for(int i=length2-1;i>=0;i--){
        char vector[300000];
        char carry='0';
        for(int j=length1-1;j>=0;j--){
            vector[j+1]=(((nums1[j]-48)*(nums2[i]-48)+(carry-48))%10)+48;
            carry=(((nums1[j]-48)*(nums2[i]-48)+(carry-48))/10)+48;
        }
        vector[0]=carry;
        for(int j=1;j<=length2-1-i;j++){
            vector[length1+j]='0';
        }
        vector[length1+length2-i]='\0';
        char mystring[300000];
        for(int j=0;j<strlen(result);j++){
            mystring[j]=result[j];
        }
        mystring[strlen(result)]='\0';
        result=Add(vector,mystring);
    }

    static char answer[300000];
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
