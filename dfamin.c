#include <stdio.h>
#include <stdbool.h>
int global_flag = 1;
int temp_store = 0;
bool checkInArray(int key, int *a, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (key == a[i])
            return true;
    }
    return false;
}
void replace(int i, int j, int a[10][10], int ns, int nsy)
{
    int nu;
    if (global_flag == 0)
    {
        nu = temp_store * 10 + j;
        printf("%d", nu);
    }
    else
    {
        i < j ? (i == 0 ? (nu = j * 10 + i) : (nu = i * 10 + j)) : (j == 0 ? (nu = i * 10 + j) : (nu = j * 10 + i));
        temp_store = nu;
    }

    for (int k = 0; k < ns; k++)
        for (int t = 0; t < nsy; t++)
        {
            if (a[k][t] == i || a[k][t] == j || a[k][t] == temp_store)
            {
                a[k][t] = nu;
            }
        }

    temp_store = nu;
}
void main()
{
    int ns, i, j, nsy, a[10][10], bi, byte[3], k = 1, l = 0, flag = 1, byte1[3], g = 0, p;
    printf("Enter the no. of states: ");
    scanf("%d", &ns);
    printf("Enter the no. of symbols: ");
    scanf("%d", &nsy);
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < nsy; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter final states : (Enter -1 when done)");
    int fs, finalstates[ns];
    i = 0;
    while (fs != -1)
    {
        scanf("%d", &fs);
        if (fs != -1)
            finalstates[i] = fs;
        i = i + 1;
    }
    int fc_count = i - 1;
    int mntable[ns][ns];
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < i; j++)
        {
            mntable[i][j] = 0;
        }
    }
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (checkInArray(i, finalstates, fc_count) && !checkInArray(j, finalstates, fc_count) || checkInArray(j, finalstates, fc_count) && !checkInArray(i, finalstates, fc_count))
            {
                mntable[i][j] = 1;
            }
        }
    }
    while (flag != -1)
    {
        for (i = 0; i < ns; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (mntable[i][j] == 0)
                {
                    for (int u = 0; u < nsy; u++)
                    {
                        if (mntable[a[i][u]][a[j][u]] == 1)
                        {
                            mntable[i][j] = 1;
                            flag = 1;
                            break;
                        }
                        else
                            flag = -1;
                    }
                }
            }
        }
    }
    int c[10];
    bi = 0;
    int count_of_new_states = 1;
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < i; j++)
        {
            //printf("%d", mntable[i][j]);
            if (mntable[i][j] == 0)
            {

                replace(i, j, a, ns, nsy);
                c[bi] = i;
                bi = bi + 1;
                global_flag = 0;
                count_of_new_states = count_of_new_states + 1;
            }
        }
        printf("\n");
        global_flag = 1;
    }

    if (checkInArray(ns - 1, finalstates, fc_count))
    {
        count_of_new_states = count_of_new_states + 1;
    }

    int b[count_of_new_states][nsy];
    int check_first = 1;
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (mntable[i][0] == 0)
            {

                check_first = 0;
            }
        }
    }

    if (check_first != 0)
        p = 1;
    else
    {
        p = 0;
        count_of_new_states = count_of_new_states - 1;
    }
    for (i = 0; i < nsy; i++)
    {
        if (check_first != 0)
            b[0][i] = a[0][i];
        b[count_of_new_states - 1][i] = a[ns - 1][i];
    }

    for (i = 1; i < ns - 1; i++)
    {
        for (j = 0; j < nsy; j++)
        {
            if (checkInArray(i, c, bi))
            {

                b[p][j] = a[i][j];
            }
        }
        if (checkInArray(i, c, bi))
            p = p + 1;
    }
    printf("\n");
    printf("Minimized DFA table is:\n");
    for (i = 0; i < count_of_new_states; i++)
    {
        for (j = 0; j < nsy; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
