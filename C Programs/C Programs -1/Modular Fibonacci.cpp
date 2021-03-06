#include <cstdio>

const int N = 2;

void load_identity(long long I[N][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            I[i][j] = (i == j ? 1 : 0);
}

void copy(long long A[N][N], long long B[N][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j];
}

void multiply(long long A[N][N], long long B[N][N], int MOD)
{
    long long P[N][N];

    for(int row = 0; row < N; row++)
    {
        for(int column = 0; column < N; column++)
        {
            P[row][column] = 0;

            for(int i = 0; i < N; i++)
                P[row][column] += (A[row][i]*B[i][column])%MOD;

            P[row][column] %= MOD;
        }
    }

    copy(P, A);
}

void power(long long X[N][N], long long power, int MOD)
{
    long long result[N][N];
    load_identity(result);

    while(power)
    {
        if(power%2 == 1)
            multiply(result, X, MOD);

        multiply(X, X, MOD);
        power = power >> 1;
    }

    copy(result, X);
}

long long fibo_mod(long long n, int MOD)
{
    long long fibonacci[N][N] = { {1, 0} };
    long long matrix[N][N] = { {1, 1},
                               {1, 0} };


    if(n <= 1)
        return n%MOD;

    power(matrix, n - 1, MOD);
    multiply(fibonacci, matrix, MOD);

    return fibonacci[0][0];
}

int main()
{
    int n, m;

    while(scanf("%d %d", &n, &m) == 2)
    {
        int MOD = 1 << m;

        long long fibo_n = fibo_mod(n, MOD);

        printf("%lld\n", fibo_n);
    }

    return 0;
}
