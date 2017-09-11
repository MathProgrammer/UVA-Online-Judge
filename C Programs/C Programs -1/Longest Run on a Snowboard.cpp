#include <cstdio>
#include <vector>

#define MAX_SIZE 110
using namespace std;

typedef vector <int> v_int;

int find_maximum_from(int row, int column, vector <v_int> &matrix, vector <v_int> &maximum_from)
{
    if(maximum_from[row][column] == -1)
    {
        maximum_from[row][column] = 1;

        if(matrix[row][column] > matrix[row - 1][column])
            maximum_from[row][column] = max(maximum_from[row][column], 1 + find_maximum_from(row - 1, column, matrix, maximum_from) );

        if(matrix[row][column] > matrix[row][column - 1])
            maximum_from[row][column] = max(maximum_from[row][column], 1 + find_maximum_from(row, column - 1, matrix, maximum_from) );

        if(matrix[row][column] > matrix[row][column + 1])
            maximum_from[row][column] = max(maximum_from[row][column], 1 + find_maximum_from(row, column + 1, matrix, maximum_from) );

        if(matrix[row][column] > matrix[row + 1][column])
            maximum_from[row][column] = max(maximum_from[row][column], 1 + find_maximum_from(row + 1, column, matrix, maximum_from) );
    }
    return maximum_from[row][column];
}

void solve()
{
    char name[MAX_SIZE];
    int no_of_rows, no_of_columns;
    scanf("%s %d %d", name, &no_of_rows, &no_of_columns);

    vector <v_int> matrix(no_of_rows + 2, v_int(no_of_columns + 2, 0));
    vector <v_int> maximum_from(no_of_rows + 2, v_int(no_of_columns + 2, 0));

    for(int i = 1; i <= no_of_rows; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            scanf("%d", &matrix[i][j]);
            maximum_from[i][j] = -1;
        }
    }

    int longest_run = 0;
    for(int i = 1; i <= no_of_rows; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            longest_run = max(longest_run, find_maximum_from(i, j, matrix, maximum_from));
        }
    }

    printf("%s: %d\n",name, longest_run);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
