#include <cstdio>
#define min(a, b) (a < b ? a : b)

long long combination(int n, int r)
{
    r = min(r, n - r);

    long long result = 1;

    for(int i = 0; i < r; i++)
        result = (result*(n - i))/(i + 1);

    return result;
}

int main()
{
    while(true)
    {
        int n, r;
        scanf("%d %d", &n, &r);

        if(n == 0 && r == 0) break;

        printf("%d things taken %d at a time is %lld exactly.\n",n,r, combination(n, r));
    }

    return 0;
}
