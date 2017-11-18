#include <cstdio>

int main()
{
    const int MAX_DIGITS = 2002;
    char number[MAX_DIGITS];

    while(true)
    {
        scanf("%s", number);

        if(number[0] == '0')
            return 0;

        int digit_sum = 0;
        for(int i = 0; number[i] != '\0'; i++)
        {
            digit_sum += number[i] - '0';
        }

        digit_sum = (digit_sum%9 == 0 && digit_sum != 0 ? 9 : digit_sum%9);
        printf("%d\n", digit_sum);
    }
}
