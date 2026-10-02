#include <stdio.h>
#include "min_func.h"

int main(void)
{
    char filename[256];
    FILE *f;
    int result;

    /* Просим имя файла */
    printf("Enter filename: ");
    if (scanf("%255s", filename) != 1)
    {
        return 1;
    }

    /* Открываем файл */
    f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("File error\n");
        return 1;
    }

    /* Вызываем функцию и получаем ответ */
    result = find_last_min(f);

    /* Закрываем файл */
    fclose(f);

    /* Выводим результат */
    printf("Answer: %d\n", result);

    return 0;
}