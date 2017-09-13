#include <cstdio>

int main()
{
    int n;

    for(int i = 1; scanf("%d", &n) != EOF; i++)
    {
        if(i > 1) printf("\n");

        long long answer = 1LL;

        for(int i = 0; i <= n - 1; i++)
            answer = (answer*(2*n - i))/(i + 1);

        answer = answer/(n + 1);

        printf("%lld\n", answer);
    }
    return 0;
}
