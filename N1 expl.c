#include <stdio.h>

// Прототип функции. Принимает файл, возвращает разницу.
int check_sequence(FILE *f);

// Главная функция
int main(void)
{
    // Объявляем переменные в самом начале (требование строгих компиляторов)
    char filename[100]; // Строка для имени файла
    FILE *f;            // Указатель на файл
    int result;         // Переменная для результата функции (целое число)

    // Просим пользователя ввести имя файла
    printf("Enter filename: ");
    scanf("%s", filename);

    // Открываем файл только для чтения
    f = fopen(filename, "r");
    
    // Проверяем, открылся ли файл
    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }
    else
    {
        // Вызываем функцию и получаем результат
        result = check_sequence(f);

        // Анализируем результат и выводим ответ
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
        
        // Закрываем файл и завершаем программу
        fclose(f);
        return 0;
    }
}

// Функция для обработки последовательности
int check_sequence(FILE *f)
{
    // ВАЖНО: используем double для вещественных чисел
    double first;          // Первое число последовательности
    double current;        // Текущее число, которое читаем
    int greater_count = 0; // Счетчик чисел, которые больше первого (целое число)
    int smaller_count = 0; // Счетчик чисел, которые меньше первого (целое число)

    // Пытаемся прочитать первое число
    // %lf - спецификатор для чтения типа double
    if (fscanf(f, "%lf", &first) != 1)
    {
        return 0; // Возвращаем 0, если файл пустой
    }

    // Читаем остальные числа в цикле while
    while (fscanf(f, "%lf", &current) == 1)
    {
        // Если текущее число больше первого
        if (current > first)
        {
            greater_count++; // Увеличиваем счетчик больших
        }
        // Если текущее число меньше первого
        else if (current < first)
        {
            smaller_count++; // Увеличиваем счетчик меньших
        }
        // Если числа равны, мы их просто игнорируем
    }

    // Возвращаем разницу: 
    // Если больших больше, результат будет > 0
    // Если меньших больше, результат будет < 0
    return greater_count - smaller_count;
}