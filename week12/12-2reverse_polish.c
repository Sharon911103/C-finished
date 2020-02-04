#include <stdio.h>
#include <string.h>

#define MAXSTR 400

void Move(char *q,int b,char *spare);

int main(void)
{
    int brk = 0;
    char str[]="(((A+B)*C)+D/((E+F)+G))";
    char *p=str;
    char *s;
    char *k;

    s = (char *)strdup(str);
    k = s;
    while (*p){ 
        if (*p=='(') brk++;
        if (*p==')') brk--;
        if (*p=='*' || *p=='/' || *p=='-' || *p=='+'){
            Move(p,brk,s);
            *s=' ';
        }
        p++;
        s++;
    }
    s=k;
    /*printf("%s\n",s); 已经转化结束只需去掉()括号就OK*/

    while (*s){
        if (*s!='(' && *s!=' '){
            putchar(*s);
        }
        s++;
    }
    printf("\n");
    return 0;
}


void Move(char *q,int b,char *spare)
{
    char o;
    int brk=b-1;
    o=*q;
    do{
        q++;
        spare++;
        if (*q=='(') b++;
        if (*q==')') b--;
    } while (*q!=')'|| b!=brk);
    *spare =o;
}
