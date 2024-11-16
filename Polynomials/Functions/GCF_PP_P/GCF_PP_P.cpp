#include "GCF_PP_P.h"

// Функция для нахождения НОД двух многочленов
Polynomials GCF_PP_P(Polynomials poly1, Polynomials poly2) {
    // Проверяем, что оба многочлена не пустые
    if (poly1.getSize() == 0 && poly2.getSize() == 0) {
        throw std::invalid_argument("GCF of two zero polynomials is undefined.");
    }

    // Если один из многочленов нулевой, возвращаем другой
    if (poly1.getSize() == 0) return poly2;
    if (poly2.getSize() == 0) return poly1;

    // Упорядочиваем многочлены так, чтобы poly1 имел наибольшую степень
    if (poly2.getMaxDegree() > poly1.getMaxDegree()) {
        Polynomials tmp = poly1;
        poly1 = poly2;
        poly2 = tmp;
    }
    
    // Основной цикл Евклида
    while (poly2.getSize() > 0) {
        
        Polynomials remainder = MOD_PP_P(poly1, poly2); // Остаток от деления
        
        // Обновляем многочлены
        poly1 = poly2;
        poly2 = remainder;

        // Проверяем упорядоченность многочленов
        if (poly2.getMaxDegree() > poly1.getMaxDegree()) {
        Polynomials tmp = poly1;
        poly1 = poly2;
        poly2 = tmp;
    }
    }

    // Возвращаем последний ненулевой остаток как НОД
    return poly1;
}
