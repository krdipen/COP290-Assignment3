#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

extern char* Add();
extern char* Sub();
extern char* Mul();
extern char* Div();

char* Sqrt(char arg1[]){

        static char temp1_copy[300000];
        static char temp2_copy[300000];
        static char precision_copy[300000];
        static char zero_copy[300000];
        static char two_copy[300000];
        static char next_copy[300000];
        static char arg1_copy[300000];

        static char temp1[300000];
        static char temp2[300000];
        static char precision[300000];
        static char zero[300000];
        static char two[300000];
        char *pointer1;
        char *pointer2;
        char *pointer3;
        char *pointer4;
        char *pointer5;
        static char next[300000];
        static char answer[300000];
        int i=0;
        while(i<strlen(arg1)){
            temp1[i]=arg1[i];
            i++;
        }
        temp1[i]='\0';
        temp2[0]='1';
        temp2[1]='\0';
        precision[0]='0';
        precision[1]='.';
        i=2;
        while(i<100){
            precision[i]='0';
            i++;
        }
        precision[i]='1';
        precision[i+1]='\0';
        zero[0]='0';
        zero[1]='\0';
        two[0]='2';
        two[1]='\0';
        i=0;
        while(i<strlen(temp1)){
            temp1_copy[i]=temp1[i];
            i++;
        }
        temp1_copy[i]='\0';
        i=0;
        while(i<strlen(temp2)){
            temp2_copy[i]=temp2[i];
            i++;
        }
        temp2_copy[i]='\0';
        pointer1=Sub(temp1,temp2);
        i=0;
        while(i<strlen(temp1_copy)){
            temp1[i]=temp1_copy[i];
            i++;
        }
        temp1[i]='\0';
        i=0;
        while(i<strlen(temp2_copy)){
            temp2[i]=temp2_copy[i];
            i++;
        }
        temp2[i]='\0';
        i=0;
        while(i<strlen(pointer1)){
            next[i]=pointer1[i];
            i++;
        }
        next[i]='\0';
        i=0;
        while(i<strlen(next)){
            next_copy[i]=next[i];
            i++;
        }
        next_copy[i]='\0';
        i=0;
        while(i<strlen(precision)){
            precision_copy[i]=precision[i];
            i++;
        }
        precision_copy[i]='\0';
        pointer2=Sub(next,precision);
        i=0;
        while(i<strlen(next_copy)){
            next[i]=next_copy[i];
            i++;
        }
        next[i]='\0';
        i=0;
        while(i<strlen(precision_copy)){
            precision[i]=precision_copy[i];
            i++;
        }
        precision[i]='\0';
        i=0;
        while(i<strlen(pointer2)){
            next[i]=pointer2[i];
            i++;
        }
        next[i]='\0';
        while((next[0]!='-')&&(strcmp(next,zero)!=0)){
            i=0;
            while(i<strlen(temp1)){
                temp1_copy[i]=temp1[i];
                i++;
            }
            temp1_copy[i]='\0';
            i=0;
            while(i<strlen(temp2)){
                temp2_copy[i]=temp2[i];
                i++;
            }
            temp2_copy[i]='\0';
            pointer3=Add(temp1,temp2);
            i=0;
            while(i<strlen(temp1_copy)){
                temp1[i]=temp1_copy[i];
                i++;
            }
            temp1[i]='\0';
            i=0;
            while(i<strlen(temp2_copy)){
                temp2[i]=temp2_copy[i];
                i++;
            }
            temp2[i]='\0';
            i=0;
            while(i<strlen(pointer3)){
                next[i]=pointer3[i];
                i++;
            }
            next[i]='\0';
            i=0;
            while(i<strlen(next)){
                next_copy[i]=next[i];
                i++;
            }
            next_copy[i]='\0';
            i=0;
            while(i<strlen(two)){
                two_copy[i]=two[i];
                i++;
            }
            two_copy[i]='\0';
            pointer4=Div(next,two);
            i=0;
            while(i<strlen(next_copy)){
                next[i]=next_copy[i];
                i++;
            }
            next[i]='\0';
            i=0;
            while(i<strlen(two_copy)){
                two[i]=two_copy[i];
                i++;
            }
            two[i]='\0';
            i=0;
            while(i<strlen(pointer4)){
                temp1[i]=pointer4[i];
                i++;
            }
            temp1[i]='\0';
            i=0;
            while(i<strlen(arg1)){
                arg1_copy[i]=arg1[i];
                i++;
            }
            arg1_copy[i]='\0';
            i=0;
            while(i<strlen(temp1)){
                temp1_copy[i]=temp1[i];
                i++;
            }
            temp1_copy[i]='\0';
            pointer5=Div(arg1_copy,temp1);
            i=0;
            while(i<strlen(arg1)){
                arg1_copy[i]=arg1[i];
                i++;
            }
            arg1_copy[i]='\0';
            i=0;
            while(i<strlen(temp1_copy)){
                temp1[i]=temp1_copy[i];
                i++;
            }
            temp1[i]='\0';
            i=0;
            while(i<strlen(pointer5)){
                temp2[i]=pointer5[i];
                i++;
            }
            temp2[i]='\0';
            i=0;
            while(i<strlen(temp1)){
                temp1_copy[i]=temp1[i];
                i++;
            }
            temp1_copy[i]='\0';
            i=0;
            while(i<strlen(temp2)){
                temp2_copy[i]=temp2[i];
                i++;
            }
            temp2_copy[i]='\0';
            pointer1=Sub(temp1,temp2);
            i=0;
            while(i<strlen(temp1_copy)){
                temp1[i]=temp1_copy[i];
                i++;
            }
            temp1[i]='\0';
            i=0;
            while(i<strlen(temp2_copy)){
                temp2[i]=temp2_copy[i];
                i++;
            }
            temp2[i]='\0';
            i=0;
            while(i<strlen(pointer1)){
                next[i]=pointer1[i];
                i++;
            }
            next[i]='\0';
            i=0;
            while(i<strlen(next)){
                next_copy[i]=next[i];
                i++;
            }
            next_copy[i]='\0';
            i=0;
            while(i<strlen(precision)){
                precision_copy[i]=precision[i];
                i++;
            }
            precision_copy[i]='\0';
            pointer2=Sub(next,precision);
            i=0;
            while(i<strlen(next_copy)){
                next[i]=next_copy[i];
                i++;
            }
            next[i]='\0';
            i=0;
            while(i<strlen(precision_copy)){
                precision[i]=precision_copy[i];
                i++;
            }
            precision[i]='\0';
            i=0;
            while(i<strlen(pointer2)){
                next[i]=pointer2[i];
                i++;
            }
            next[i]='\0';
        }
        i=0;
        while(i<strlen(temp1)){
            answer[i]=temp1[i];
            i++;
        }
        answer[i]='\0';
        return answer;

}
