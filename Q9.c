#include <stdio.h>

void Q9()
{
    for(int a = 1; a < 500; a++)
    {
        for(int b = a; b+a < 1000; b++)
        {
            int c = 1000-a-b;
            if(a*a + b*b == c*c)
            {
                long Ans = a*b*c;
                printf("%ld, %d, %d, %d", Ans, a, b, c);
                return;
            }
        }
    }
}
