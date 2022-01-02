#include <stdio.h>
#include <math.h>

void main()
{
    int ns, nsy, a[10][10], b[8][2], bi, byte[3], taken[8], k = 1, l = 0, flag = 1, byte1[3], g = 0, p;
    printf("Enter the no. of states: ");
    scanf("%d", &ns);
    printf("enter the no. of symbols: ");
    scanf("%d", &nsy);
    p = pow(2, ns);
    for (int i = 0; i < p; i++)
    {
        taken[i] = 0;
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < nsy; j++)
        {
            b[i][j] = 0;
        }
    }
    for (int i = 0; i < ns; i++)
    {
        for (int j = 0; j < nsy; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    
    int bin(int n)
    {
        if (n == 0)
            return 0;
        else
            bi = n % 2 + 10 * bin(n / 2);
        return bi;
    }

    int sum(int n, int nsp)
    {
        for (int i = 0; i < 3; i++)
        {
            byte[i] = 0;
        }
        int i = 2;
        while (n != 0)
        {
            byte[i] = n % 10;
            n = n / 10;
            i--;
        }
        int str = 0;
        for (int i = 0; i < 3; i++)
        {
            if (byte[i] == 1)
            {
                str = str | a[i][nsp];
            }
        }
        return str;
    }
    int ataken(int n)
    {
        for (int i = 0; i < p; i++)
        {
            if (taken[i] == n)
                return 1;
        }
        return 0;
    }
    for (int j = 0; j < nsy; j++)
    {
        b[0][j] = a[0][j];
    }
    taken[l] = 4;
    l = l + 1;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < nsy; j++)
        {
            if (!ataken(b[i][j]))
            {
                taken[l] = b[i][j];
                for (int m = 0; m < nsy; m++)
                {
                    b[l][m] = sum(bin(b[i][j]), m);
                }
                l++;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < p; i++)
    {
        if (taken[i] != 0)
        {
            g = bin(taken[i]);
            int f = ns - 1;
            while (g != 0)
            {
                byte1[f] = g % 10;
                g = g / 10;
                f--;
            }
            for (int d = 0; d < 3; d++)
            {
                if (byte1[d] != 0)
                {
                    printf("q%d", d);
                }
            }
            for (int i = 0; i < 3; i++)
            {
                byte1[i] = 0;
            }
            printf("--> ");
        }

        for (int j = 0; j < nsy; j++)
        {
            if (b[i][j] != 0)
            {
                g = bin(b[i][j]);
                int f = ns - 1;
                while (g != 0)
                {
                    byte1[f] = g % 10;
                    g = g / 10;
                    f--;
                }
                for (int d = 0; d < 3; d++)
                {
                    if (byte1[d] != 0)
                    {
                        printf("q%d", d);
                    }
                }
                printf(" ");
                if (bin(b[i][j]) == 0)
                {
                    printf("@");
                }
            }
            for (int i = 0; i < 3; i++)
            {
                byte1[i] = 0;
            }
        }
        printf("\n");
    }
}