#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <long long> &no_of_patterns, int LIMIT)
{
    no_of_patterns[0] = no_of_patterns[1] = 1;
    no_of_patterns[2] = 2;

    for(int i = 3; i < LIMIT; i++)
        no_of_patterns[i] = no_of_patterns[i - 1] + no_of_patterns[i - 2];
}

int main()
{
    const int LIMIT = 51;
    vector <long long> no_of_patterns(LIMIT, 0);
    precompute(no_of_patterns, LIMIT);

    while(true)
    {
        int n;
        scanf("%d", &n);

        if(n == 0) break;

        printf("%lld\n", no_of_patterns[n]);
    }
    return 0;
}
