#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NUMBER '0'
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("too many\n");
    else
        buf[bufp++] = c;
}
char stack[100];
int topindex = 0;
int getch(void);
void ungetch(int);
int getop(char s[ ])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
    if(c=='-'){
       if ( isdigit(s[++i] ))
        -s[++i]==getch( );
        
       else {
           if (c!=EOF)
           ungetch(c);
           return '-';
       }
        
    }
}
void push(double  a)
{
    if (topindex <= 98)
    {
        stack[topindex++] = a;
    }

    else
    {
        printf("full\n");
    }
}

int  pop(void)
{
    if (topindex >= 0)
    {
        int result;
        result = stack[--topindex];
        return result;
    }
    else
    {
        printf("no ");
        printf("\n");
    }
}
int  top(void)
{
    if (topindex >= 0)
    {
        return stack[topindex];
    }
    else
    {
        printf("no number");
        printf("/n");
    }
}
void print (void){
    printf("%d\n",stack[topindex-1]);
}
int main()
{
    printf("c means copy\n");
    printf("p means print\n");
    printf("e means exchange\n");
    printf("d means delete\n");
    int type;
    int op2;
    char s[100];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atoi(s));
            break;

        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("errror");
            }
        case '\n':
            printf("%d\n", pop());
            break;
        case '%':
          op2 = pop();
          if(op2!=0)
          push(pop()%op2);
          else{
              printf("error");
          }
          case 'p':
              print();
              break;
        case 'c':
          push(stack[topindex-1]);
                 push(stack[topindex-1]);
            
              break;
        case 'e':
             op2=stack[topindex-1];
             stack[topindex-1]=stack[topindex-2];
             stack[topindex-2]=op2;
             break;
        case 'd':
           topindex=0;
           break;
        }
    }
}