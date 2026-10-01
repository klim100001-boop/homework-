#include <stdio.h>

int check_sequence(FILE *f);

int main(void)
{
    char filename[100];
    FILE *f;
    int result;

    printf("Enter filename: ");
    scanf("%s", filename);

    f = fopen(filename, "r");
    
    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }
    else
    {
        result = check_sequence(f);

        if (result > 0)
        {
            printf("Elements greater than the first are more\n");
        }
        else if (result < 0)
        {
            printf("Elements smaller than the first are more\n");
        }
        else
        {
            printf("Equal number of greater and smaller elements (or empty file)\n");
        }
        
        fclose(f);
        return 0;
    }
}

int check_sequence(FILE *f)
{
    double first;
    double current;
    int greater_count = 0;
    int smaller_count = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        return 0;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (current > first)
        {
            greater_count++;
        }
        else if (current < first)
        {
            smaller_count++;
        }
    }

    return greater_count - smaller_count;
}