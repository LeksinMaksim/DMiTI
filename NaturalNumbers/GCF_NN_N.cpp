#include "GCF_NN_N.h"

NaturalNumbers GCF_NN_N(NaturalNumbers& a, NaturalNumbers& b) {
    // Создаем копии начальных значений, чтобы не изменять оригинальные объекты
    NaturalNumbers num1 = a;
    NaturalNumbers num2 = b;

    // Основной цикл алгоритма Евклида
    while (true) {
        // Если num2 равно нулю, то num1 содержит НОД
        if (!NZER_N_B(num2)) {
            return num1;
        }

        // Если num1 равно нулю, то num2 содержит НОД
        if (!NZER_N_B(num1)) {
            return num2;
        }

        // Сравниваем num1 и num2
        int comparison = COM_NN_D(num1, num2);

        // Если num1 > num2, вычисляем остаток от деления num1 на num2 и обновляем num1
        if (comparison == 2) {
            num1 = MOD_NN_N(num1, num2);
        }
        // Если num2 > num1, вычисляем остаток от деления num2 на num1 и обновляем num2
        else if (comparison == 1) {
            num2 = MOD_NN_N(num2, num1);
        }
        // Если num1 == num2, возвращаем любое из них, так как это и есть НОД
        else {
            return num1;
        }
    }
}

