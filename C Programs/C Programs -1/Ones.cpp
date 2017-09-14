#include <cstdio>

void solve(int n)
{
    int no_of_digits = 1;
    int number = 1;

    while(number%n != 0)
    {
        number = (number*10 + 1)%n;
        no_of_digits++;
    }

    printf("%d\n", no_of_digits);
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
        solve(n);

    return 0;
}
