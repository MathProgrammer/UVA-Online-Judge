#include <cstdio>
#include <vector>

using namespace std;

int reverse(int n)
{
    int reverse_n = 0;

    while(n > 0)
    {
        reverse_n = 10*reverse_n + n%10;
        n = n/10;
    }

    return reverse_n;
}

void precompute(vector <int> &is_prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple <= LIMIT; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }
}

int main()
{
    const int LIMIT = 1e6 + 1;
    vector <int> is_prime(LIMIT, true);
    precompute(is_prime, LIMIT);

    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(!is_prime[n])
            printf("%d is not prime.\n", n);
        else if(is_prime[n] && (!is_prime[reverse(n)] || n == reverse(n)) )
            printf("%d is prime.\n", n);
        else
            printf("%d is emirp.\n", n);
    }

    return 0;
}
