#include <stdio.h>
#include<math.h>
int bitcount(unsigned x);
int main()

{
    char digit[6];
    int ndigit[6];

    int i, t, a, g, h, j, k, l;
    int input;
    i = 0, a = 0;
    while ((digit[i] = getchar()) != EOF && digit[i] != '\n')
    {

        ndigit[i] = digit[i] - '0';
        ++i;
        a = a + 1;
        }
        g = ndigit[0];
        h = ndigit[1];
        j  = ndigit[2];
        k = ndigit[3];
        l = ndigit[4];

        t = g * pow(10, a) + h * pow(10, a - 1) + j * pow(10, a - 2) + k * pow(10, a - 3) + l * pow(10, a - 4);
        printf("%d\n", bitcount(t));
}
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
