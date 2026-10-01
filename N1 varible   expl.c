#include <stdio.h>

// Прототип функции
int check(FILE *f);

int main(void)
{
    char name[50]; // Имя файла
    FILE *f;       // Указатель на файл
    int ans;       // Ответ

    printf("Enter filename: ");
    scanf("%s", name);

    f = fopen(name, "r");
    
    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }

    ans = check(f); // Вызов функции

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

    fclose(f); // Закрываем файл
    return 0;
}

// Функция с одним счетчиком
int check(FILE *f)
{
    double first; // Первое число
    double x;     // Текущее число
    int k = 0;    // Счетчик (баланс)

    // Читаем первое число
    if (fscanf(f, "%lf", &first) != 1)
    {
        return 0; // Если файл пустой
    }

    // Читаем остальные числа
    while (fscanf(f, "%lf", &x) == 1)
    {
        if (x > first)
        {
            k = k + 1; // Если больше, прибавляем 1
        }
        else if (x < first)
        {
            k = k - 1; // Если меньше, вычитаем 1
        }
    }

    return k; // Возвращаем результат
}