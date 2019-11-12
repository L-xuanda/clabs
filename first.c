#include <stdio.h>
 int bitcount(unsigned x);
int main()

{
    int n = 0;
    int i = 0;
    char digit[6];

    while (i < 7)
    {
     digit[i]=getchar();
        if (digit[i] == '\n')
        {
        break;
        }
            n = n * 10 +( digit[i] - '0');
            i++;
    }
    printf("%d",bitcount(n));
}
    int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}