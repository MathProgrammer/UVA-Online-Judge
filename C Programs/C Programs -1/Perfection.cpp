#include <iostream>
#include <cstdio>
using namespace std;

void solve(int n)
{
    int divisor_sum = (n == 1 ? 0 : 1);

    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            if(i*i == n)
                divisor_sum += i;
            else
                divisor_sum += i + n/i;
        }
    }

    cout.width(5);
    cout << n;

    if(divisor_sum == n)
        printf("  PERFECT\n");
    else
        printf("  %s\n", divisor_sum < n ? "DEFICIENT" : "ABUNDANT");
}

int main()
{
    printf("PERFECTION OUTPUT\n");
    while(true)
    {
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        solve(n);
    }

    printf("END OF OUTPUT\n");
    return 0;
}
