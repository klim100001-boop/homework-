#include <stdio.h>

int main(void) {
    int n;
    printf("Введите количество элементов последовательности: ");
    scanf("%d", &n);

    // Проверяем корректность ввода количества элементов
    if (n <= 1) {
        printf("Последовательность должна содержать хотя бы 2 элемента.\n");
        return 0;
    }

    double first;
    printf("Введите элементы через пробел или Enter:\n");
    // Считываем первый элемент, который станет эталоном
    scanf("%lf", &first);

    int count_greater = 0; // Счетчик элементов, которые больше первого
    int count_less = 0;    // Счетчик элементов, которые меньше первого

    // Цикл со 2-го элемента до n
    for (int i = 2; i <= n; i++) {
        double current;
        scanf("%lf", &current);

        if (current > first) {
            count_greater++;
        } else if (current < first) {
            count_less++;
        }
    }

    // Вывод итогового результата сравнения счетчиков
    if (count_greater > count_less) {
        printf("Больше элементов, которые больше первого.\n");
    } else if (count_less > count_greater) {
        printf("Больше элементов, которые меньше первого.\n");
    } else {
        printf("Элементов, которые больше и меньше первого, поровну.\n");
    }

    return 0;
}
