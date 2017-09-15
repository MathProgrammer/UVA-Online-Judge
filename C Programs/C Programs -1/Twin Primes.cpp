#include <cstdio>
#include <vector>

using namespace std;

const int LIMIT = 2e7;
vector <int> is_prime(LIMIT + 1, true);

void precompute(vector <pair <int, int> > &twin_prime)
{
    is_prime[0] = is_prime[1] = false;
    vector <int> primes;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);

             if(is_prime[i - 2])
                twin_prime.push_back(make_pair(i - 2, i));
        }

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int main()
{
    vector <pair <int, int> > twin_prime;
    precompute(twin_prime);

    int n;

    while(scanf("%d", &n) != EOF)
    {
        printf("(%d, %d)\n", twin_prime[n - 1].first, twin_prime[n - 1].second);
    }

    return 0;
}
