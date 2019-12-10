#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
int getch(void);
void ungetch(int);
char buf[BUFSIZE];
int bufp = 0;
int getfloat(float *pn);
int main()
{
    int i;
    float s[10];
    float sum = 0.0;
    for (i = 0; i < 10; i = i + 1)
    {
        if (getfloat(&s[i]) == '\n')
        {
            sum = sum + s[i];
            break;
        }
        sum = sum + s[i];
    }
    printf("%f\n", sum);
}
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
int getfloat(float *p)
{
    double power;
    int c, sign;
    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != '+' && c != '-' && c != '.' && c != EOF && c != '\n')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*p = 0; isdigit(c); c = getch())
        *p = 10 * *p + (c - '0');

    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        power = 10 * power;
        *p = 10 * *p + (c - '0');
    }
    *p = *p * (1 / power);
    if (c != EOF)
        ungetch(c);
    return c;
}
