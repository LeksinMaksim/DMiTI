#include "ADD_1N_N.h"

NaturalNumbers ADD_1N_N(NaturalNumbers& number){
    std::vector<size_t> digits = number.getDigits();
    int n = digits.size();
    // Проходим по цифрам с конца к началу
    for(int i = n - 1; i >= 0; --i) {
        if(digits[i] < 9) {
            // Если текущая цифра меньше 9, увеличиваем её на 1 и завершаем функцию
            digits[i]++;
            number.setDigits(digits);
            return number;
        }
        // Если цифра равна 9, устанавливаем её в 0 и переходим к следующей
        digits[i] = 0;
    }
    // Если все цифры были 9, добавляем 1 в начало вектора
    digits.insert(digits.begin(), 1);
    number.setDigits(digits);
    return number;
}
