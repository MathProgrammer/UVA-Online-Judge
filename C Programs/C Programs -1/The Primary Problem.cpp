#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &prime, vector <int> &is_prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple < LIMIT; multiple += i)
            {
                is_prime[multiple] = false;
            }

            prime.push_back(i);
        }
    }
}

int main()
{
    const int LIMIT = 1e6 + 1;
    vector <int> prime;
    vector <int> is_prime(LIMIT, true);
    precompute(prime, is_prime, LIMIT);

    while(true)
    {
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        printf("%d:\n", n);

        int summand_1 = 0, summand_2 = 0;

        for(unsigned int i = 0; i < prime.size() && prime[i] <= n; i++)
        {
            if(is_prime[n - prime[i]])
            {
                summand_1 = prime[i];
                summand_2 = n - prime[i];
                break;
            }
        }

        if(summand_1 + summand_2 == n)
            printf("%d+%d\n", summand_1, summand_2);
        else
            printf("NO WAY!\n");
    }

    return 0;
}
