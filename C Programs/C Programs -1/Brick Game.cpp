#include <cstdio>

void solve()
{
    int no_of_players, captain_age;
    scanf("%d", &no_of_players);

    for(int i = 1; i <= no_of_players; i++)
    {
        int age;
        scanf("%d", &age);

        if(2*i == no_of_players + 1)
            captain_age = age;
    }

    printf("%d\n", captain_age);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    for(int i = 1; i <= no_of_test_cases; i++)
    {
        printf("Case %d: ",i);
        solve();
    }

    return 0;
}
