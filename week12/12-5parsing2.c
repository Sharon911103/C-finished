#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXEXPR 40

struct prog{
    char str[MAXEXPR];
    int count;
};
typedef struct prog Prog;

void Op(Prog *p);
int isop(char c);
void Expr(Prog *p);

int main(void)
{
    Prog p;
    p.count=0;
    /* 读入[]中的字符，当有字符串读入时scanf==1 */
    if (scanf("%[A-Z,+,-,*,/,(,)]s",p.str)!=1){
        printf("Couldn't read your expression ?\n");
        exit(EXIT_FAILURE);
    }
    Expr(&p);
    printf("Parsing OK!\n");
    return 0;
}

int isop(char c)
{
    if (c=='+'||c=='-'||c=='*'||c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

void Op(Prog *p)
{
    if (!isop(p->str[p->count])){
        printf("I was expecting a letter ?\n");
        exit(EXIT_FAILURE);
    }
}

void Expr(Prog *p)
{
    if (p->str[p->count]=='('){
        p->count = p->count+1;
        Expr(p);
        p->count = p->count+1;
        if (p->str[p->count]!=')'){
            printf("I was expecting a ) ?\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (p->str[p->count]=='-'){
        p->count = p->count+1;
        Expr(p);
    }
    /* Not Look-Ahead */
    else if (isop(p->str[p->count+1])){
        if (isupper(p->str[p->count])){
            p->count = p->count+1;
            Op(p);
            p->count = p->count+1;
            Expr(p);
        }
    }
    else{
        if (!isupper(p->str[p->count]) || isupper(p->str[p->count+1])) {
            printf("Expected a single letter ?\n");
            exit(EXIT_FAILURE);
        }
    }
}

