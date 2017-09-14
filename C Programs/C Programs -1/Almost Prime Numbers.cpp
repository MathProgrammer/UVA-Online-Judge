#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void precompute(vector <long long> &prime_powers)
{
    const int LIMIT = 1e6;

    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*1LL*i; multiple < LIMIT; multiple += i)
                is_prime[multiple] = false;


            long long prime_power = i*1LL*i;
            while(prime_power <= LIMIT*1LL*LIMIT)
            {
                prime_powers.push_back(prime_power);
                prime_power *= i;
            }
        }
    }
}

int main()
{
    vector <long long> prime_powers;
    precompute(prime_powers);
    sort(all(prime_powers));

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        long long left, right;
        scanf("%lld %lld", &left, &right);

        int elements_before_range = lower_bound(all(prime_powers), left) - prime_powers.begin();

        int elements_including_range = lower_bound(all(prime_powers), right) - prime_powers.begin();
        elements_including_range += binary_search(all(prime_powers), right);

        printf("%d\n", elements_including_range - elements_before_range);
    }

    return 0;
}
