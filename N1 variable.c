#include <stdio.h>

int check(FILE *f);

int main(void)
{
    char name[50];
    FILE *f;
    int ans;

    printf("Enter filename: ");
    scanf("%s", name);

    f = fopen(name, "r");
    
    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }

    ans = check(f);

    if (ans > 0)
    {
        printf("Elements greater than the first are more\n");
    }
    else if (ans < 0)
    {
        printf("Elements smaller than the first are more\n");
    }
    else
    {
        printf("Equal number of greater and smaller elements\n");
    }

    fclose(f);
    return 0;
}

int check(FILE *f)
{
    double first;
    double x;
    int k = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        return 0;
    }

    while (fscanf(f, "%lf", &x) == 1)
    {
        if (x > first)
        {
            k = k + 1;
        }
        else if (x < first)
        {
            k = k - 1;
        }
    }

    return k;
}