#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &primes, vector <int> &is_prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple <= LIMIT; multiple += i)
                is_prime[multiple] = false;

            primes.push_back(i);
        }
    }
}

int main()
{
    const int LIMIT = 1e6;
    vector <int> primes;
    vector <int> is_prime(LIMIT + 1, true);

    precompute(primes, is_prime, LIMIT);

    while(true)
    {
        int n;
        scanf("%d", &n);

        if(n == 0) break;
        int summand_1 = 0, summand_2 = 0;

        for(unsigned int i = 0; i < primes.size() && primes[i] < n; i++)
        {
            if(is_prime[n - primes[i]])
            {
                summand_1 = primes[i];
                summand_2 = n - primes[i];

                break;
            }
        }

        printf("%d = %d + %d\n", n, summand_1, summand_2);
    }

    return 0;
}
