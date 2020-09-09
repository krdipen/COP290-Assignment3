#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();

char* Sub(char arg1[],char arg2[]){

    char sign1=arg1[0];
    char sign2=arg2[0];
    if((sign1!='-')&&(sign2=='-')){
        arg2[0]='+';
        return Add(arg1,arg2);
    }
    if((sign1=='-')&&(sign2!='-')){
        if(sign2=='+'){
            arg2[0]='-';
            return Add(arg1,arg2);
        }
        else{
            char temp[300000];
            temp[0]='-';
            int i=0;
            while(i<strlen(arg2)){
                temp[i+1]=arg2[i];
                i++;
            }
            temp[i+1]='\0';
            return Add(arg1,temp);
        }
    }

    int greater=0;
    int i1,i2,i;
    if((sign1=='+')||(sign1=='-')){
        i1=1;
    }
    else{
        i1=0;
    }
    for(i=i1;arg1[i]!='\0';i++){
        if(arg1[i]!='0'){
            break;
        }
    }
    i1=i;
    if((sign2=='+')||(sign2=='-')){
        i2=1;
    }
    else{
        i2=0;
    }
    for(i=i2;arg2[i]!='\0';i++){
        if(arg2[i]!='0'){
            break;
        }
    }
    i2=i;
    int digits1=0;
    for(i=i1;arg1[i]!='\0';i++){
        if(arg1[i]=='.'){
            break;
        }
        digits1++;
    }
    int digits2=0;
    for(i=i2;arg2[i]!='\0';i++){
        if(arg2[i]=='.'){
            break;
        }
        digits2++;
    }
    if(digits1>digits2){
        greater=1;
    }
    else if(digits1<digits2){
        greater=2;
    }
    else{
        while(true){
            if((arg1[i1]!='\0')||(arg2[i2]!='\0')){
                if(arg1[i1]<arg2[i2]){
                    greater=2;
                    break;
                }
                else if(arg1[i1]>arg2[i2]){
                    greater=1;
                    break;
                }
            }
            else if((arg1[i1]!='\0')||(arg2[i2]=='\0')){
                greater=1;
                break;
            }
            else if((arg1[i1]=='\0')||(arg2[i2]!='\0')){
                greater=2;
                break;
            }
            else{
                greater=1;
                break;
            }
            i1++;
            i2++;
        }
    }

    char sign;
    char* integer1;
    char* fraction1;
    char* integer2;
    char* fraction2;
    if(greater==1){
        if(sign1=='-'){
            sign='-';
        }
        else{
            sign='+';
        }
        if((arg1[0]=='.')||((arg1[0]=='-')&&(arg1[1]=='.'))||((arg1[0]=='+')&&(arg1[1]=='.'))){
            integer1=NULL;
            fraction1=strtok(arg1,"+.-");
        }
        else{
            integer1=strtok(arg1,"+.-");
            fraction1=strtok(NULL,"+.-");
        }
        if((arg2[0]=='.')||((arg2[0]=='-')&&(arg2[1]=='.'))||((arg2[0]=='+')&&(arg2[1]=='.'))){
            integer2=NULL;
            fraction2=strtok(arg2,"+.-");
        }
        else{
            integer2=strtok(arg2,"+.-");
            fraction2=strtok(NULL,"+.-");
        }
    }
    else{
        if(sign2=='-'){
            sign='+';
        }
        else{
            sign='-';
        }
        if((arg1[0]=='.')||((arg1[0]=='-')&&(arg1[1]=='.'))||((arg1[0]=='+')&&(arg1[1]=='.'))){
            integer2=NULL;
            fraction2=strtok(arg1,"+.-");
        }
        else{
            integer2=strtok(arg1,"+.-");
            fraction2=strtok(NULL,"+.-");
        }
        if((arg2[0]=='.')||((arg2[0]=='-')&&(arg2[1]=='.'))||((arg2[0]=='+')&&(arg2[1]=='.'))){
            integer1=NULL;
            fraction1=strtok(arg2,"+.-");
        }
        else{
            integer1=strtok(arg2,"+.-");
            fraction1=strtok(NULL,"+.-");
        }
    }

    char result[300000];
    int index=0;
    bool borrow=false;
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
        for(int i=1;i<=length1-length2;i++){
            result[index]=fraction1[length1-i];
            index++;
        }
        for(int i=1;i<=length2;i++){
            if(borrow){
                if((fraction1[length2-i]-fraction2[length2-i]-1)<0){
                    result[index]=fraction1[length2-i]-fraction2[length2-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=fraction1[length2-i]-fraction2[length2-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((fraction1[length2-i]-fraction2[length2-i])<0){
                    result[index]=fraction1[length2-i]-fraction2[length2-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=fraction1[length2-i]-fraction2[length2-i]+48;
                    borrow=false;
                }
            }
            index++;
        }
    }
    else{
        for(int i=1;i<=length2-length1;i++){
            if(borrow){
                if((0+48-fraction2[length2-i]-1)<0){
                    result[index]=0+48-fraction2[length2-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=0+48-fraction2[length2-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((0+48-fraction2[length2-i])<0){
                    result[index]=0+48-fraction2[length2-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=0+48-fraction2[length2-i]+48;
                    borrow=false;
                }
            }
            index++;
        }
        for(int i=1;i<=length1;i++){
            if(borrow){
                if((fraction1[length1-i]-fraction2[length1-i]-1)<0){
                    result[index]=fraction1[length1-i]-fraction2[length1-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=fraction1[length1-i]-fraction2[length1-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((fraction1[length1-i]-fraction2[length1-i])<0){
                    result[index]=fraction1[length1-i]-fraction2[length1-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=fraction1[length1-i]-fraction2[length1-i]+48;
                    borrow=false;
                }
            }
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
            if(borrow){
                if((integer1[length1-i]-integer2[length2-i]-1)<0){
                    result[index]=integer1[length1-i]-integer2[length2-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-i]-integer2[length2-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((integer1[length1-i]-integer2[length2-i])<0){
                    result[index]=integer1[length1-i]-integer2[length2-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-i]-integer2[length2-i]+48;
                    borrow=false;
                }
            }
            index++;
        }
        for(int i=1;i<=length1-length2;i++){
            if(borrow){
                if((integer1[length1-length2-i]-0-48-1)<0){
                    result[index]=integer1[length1-length2-i]-0-48-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-length2-i]-0-48-1+48;
                    borrow=false;
                }
            }
            else{
                if((integer1[length1-length2-i]-0-48)<0){
                    result[index]=integer1[length1-length2-i]-0-48+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-length2-i]-0-48+48;
                    borrow=false;
                }
            }
            index++;
        }
    }
    else{
        for(int i=1;i<=length1;i++){
            if(borrow){
                if((integer1[length1-i]-integer2[length2-i]-1)<0){
                    result[index]=integer1[length1-i]-integer2[length2-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-i]-integer2[length2-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((integer1[length1-i]-integer2[length2-i])<0){
                    result[index]=integer1[length1-i]-integer2[length2-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=integer1[length1-i]-integer2[length2-i]+48;
                    borrow=false;
                }
            }
            index++;
        }
        for(int i=1;i<=length2-length1;i++){
            if(borrow){
                if((0+48-integer2[length2-length1-i]-1)<0){
                    result[index]=0+48-integer2[length2-length1-i]-1+48+10;
                    borrow=true;
                }
                else{
                    result[index]=0+48-integer2[length2-length1-i]-1+48;
                    borrow=false;
                }
            }
            else{
                if((0+48-integer2[length2-length1-i])<0){
                    result[index]=0+48-integer2[length2-length1-i]+48+10;
                    borrow=true;
                }
                else{
                    result[index]=0+48-integer2[length2-length1-i]+48;
                    borrow=false;
                }
            }
            index++;
        }
    }
    index--;

    static char answer[300000];
    int start=0;
    bool flag=false;
    bool flag2=false;
    for(int i=0;i<=index-int_index;i++){
        if((result[index-i]!='0')||flag){
            if((!flag)&&(sign=='-')){
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
                if(sign=='-'){
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
