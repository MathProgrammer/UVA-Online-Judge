#include <cstdio>

int is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int main()
{
    const int MAX_N = 1e4 + 1;
    int no_of_primes[MAX_N] = {0};

    no_of_primes[0] = 1;

    for(int n = 1; n < MAX_N; n++)
        no_of_primes[n] = no_of_primes[n - 1] + is_prime(n*n + n + 41);

    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
    {
        int primes_in_interval = no_of_primes[b] - (a > 0 ? no_of_primes[a - 1] : 0);

        double prime_percentage = double(primes_in_interval)/double(b - a + 1);
        prime_percentage = prime_percentage*100.0 + 1e-6;

        //1e-6 has to be added for getting correct answer. Don't know why

        printf("%.2lf\n", prime_percentage);
    }

    return 0;
}
