#include "cave.h"
//#include "cave.h"
#include <bits/stdc++.h>
const int MAX = 5005;
int a[MAX], s[MAX], d[MAX], n, y;
void settin(int i)
{
        for(int j = 0; j < i; j++)
        {
            a[d[j]] = s[d[j]];
        }
}
void solve(int c, int i)
{

        int S = 0, e = n - 1, mid = -1, u = -1;
                for(int j = S; j <= e; j++)
                {
                    a[j] = 1 - c;
                }
            //    printf("%d %d\n", i, c);
            while(S <= e)
            {
                //if(i == 0)
                mid = (S + e) / 2;
              // printf("%d %d %d %d\n", S, e, mid, y);
                for(int j = S; j <= mid; j++)
                {
                    a[j] = c;
                }
                settin(i);
                y = tryCombination(a);
                for(int j = S; j <= mid; j++)
                {
                    a[j] = 1 - c;
                }
                //settin(i);
                if(y <= i && y != -1)
                {
                    //puts("HERE");
                    S = mid + 1;
                  //  printf("%d %d\n", S, mid);
                }
                else
                {
                    u = mid;
                    e = mid - 1;
                }
            }

    d[i] = u;
    s[u] = c;
}
void exploreCave(int N)
{
    n = N;
    for(int i = 0; i < N; i++)
    {
        memset(a, 0, sizeof(a));
        settin(i);
        y = tryCombination(a);
        if(y <= i && y != -1)
        {
            solve(1, i);
        }
        else
        {
            solve(0, i);
        }
    }
    for(int j = 0; j < N; j++) a[d[j]] = j;
    answer(s, a);
}
