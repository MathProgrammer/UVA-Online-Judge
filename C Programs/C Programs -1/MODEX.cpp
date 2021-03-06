#include <cstdio>

long long power_mod(long long x, long long power, long long mod)
{
	long long y = x, result = 1;

	while(power)
	{
		if(power%2 == 1)
			result = (result*y)%mod;

		y = (y*y)%mod;
		power = power >> 1;
	}

	return result;
}

int main()
{
    int no_of_tests;
    scanf("%d", &no_of_tests);

    while(no_of_tests--)
    {
        int x, power, mod;
        scanf("%d %d %d", &x, &power, &mod);
        printf("%lld\n", power_mod(x, power, mod));
    }

    return 0;
}
