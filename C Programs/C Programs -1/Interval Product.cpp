#include <cstdio>
#include <cstring>

const int MAX_ELEMENTS = 1e5 + 1, POSITIVE = 1, NEGATIVE = -1;
int array[MAX_ELEMENTS];
int no_of_zeroes[3*MAX_ELEMENTS];
int no_of_negative_numbers[3*MAX_ELEMENTS];

void initialise()
{
    memset(array, 0, sizeof(array));
    memset(no_of_zeroes, 0, sizeof(no_of_zeroes));
    memset(no_of_negative_numbers, 0, sizeof(no_of_negative_numbers));
}

void build(int n, int left, int right)
{
    if(left == right)
    {
        no_of_zeroes[n] = (array[left] == 0);
        no_of_negative_numbers[n] = (array[left] < 0);
        return;
    }

    int mid = (left + right) >> 1;
    build(2*n, left, mid);
    build(2*n + 1, mid + 1, right);

    no_of_zeroes[n] = no_of_zeroes[2*n] + no_of_zeroes[2*n + 1];
    no_of_negative_numbers[n] = no_of_negative_numbers[2*n] + no_of_negative_numbers[2*n + 1];
}

void change(int n, int left, int right, int index, int new_element)
{
    if(index < left || right < index)
        return;

    if(left == right)
    {
        if(array[index] < 0 && new_element >= 0)
            no_of_negative_numbers[n]--;

        if(array[index] >= 0 && new_element < 0)
            no_of_negative_numbers[n]++;

        if(array[index] == 0 && new_element != 0)
            no_of_zeroes[n]--;

        if(array[index] != 0 && new_element == 0)
            no_of_zeroes[n]++;

        array[index] = new_element;
        return;
    }

    int mid = (left + right) >> 1;
    change(2*n, left, mid, index, new_element);
    change(2*n + 1, mid + 1, right, index, new_element);

    no_of_zeroes[n] = no_of_zeroes[2*n] + no_of_zeroes[2*n + 1];
    no_of_negative_numbers[n] = no_of_negative_numbers[2*n] + no_of_negative_numbers[2*n + 1];
}

int get_zero_count(int n, int left, int right, int query_left, int query_right)
{
    if(query_left > right || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return no_of_zeroes[n];

    int mid = (left + right) >> 1;
    int left_answer = get_zero_count(2*n, left, mid, query_left, query_right);
    int right_answer = get_zero_count(2*n + 1, mid + 1, right, query_left, query_right);

    return (left_answer + right_answer);
}

int get_negative_count(int n, int left, int right, int query_left, int query_right)
{
    if(query_left > right || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return no_of_negative_numbers[n];

    int mid = (left + right) >> 1;
    int left_answer = get_negative_count(2*n, left, mid, query_left, query_right);
    int right_answer = get_negative_count(2*n + 1, mid + 1, right, query_left, query_right);

    return (left_answer + right_answer);
}

void display(int sign)
{
    switch(sign)
    {
        case  0        : printf("0"); return;
        case  POSITIVE : printf("+"); return;
        case  NEGATIVE : printf("-"); return;
    }
}

int get_sign(int zero_count, int negative_count)
{
    if(zero_count > 0)
        return 0;

    if(negative_count%2 == 1)
        return NEGATIVE;

    return POSITIVE;
}

int main()
{
    int no_of_elements, no_of_queries;
    while(scanf("%d %d", &no_of_elements, &no_of_queries) != EOF)
    {
        initialise();

        for(int i = 1; i <= no_of_elements; i++)
            scanf("%d", &array[i]);

        build(1, 1, no_of_elements);

        while(no_of_queries--)
        {
            char type;
            scanf(" %c", &type);

            if(type == 'C')
            {
                int index, new_element;
                scanf("%d %d", &index, &new_element);
                change(1, 1, no_of_elements, index, new_element);
            }
            else if(type == 'P')
            {
                int left, right;
                scanf("%d %d", &left, &right);

                int zero_count = get_zero_count(1, 1, no_of_elements, left, right);
                int negative_count = get_negative_count(1, 1, no_of_elements, left, right);

                int sign = get_sign(zero_count, negative_count);

                display(sign);
            }
        }
        printf("\n");
    }
    return 0;
}
