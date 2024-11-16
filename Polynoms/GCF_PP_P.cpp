#include "GCF_PP_P.h"

Polynomials GCF_PP_P(Polynomials a, Polynomials b){
    
    while (a.getStrReference().compare(0,1,"0") && b.getStrReference().compare(0,1,"0")){
        if (a.getMaxDegree() > b.getMaxDegree())
            a = MOD_PP_P(a,b);
        else
            b = MOD_PP_P(b,a);
    }
    //возвращаем наибольшее по степени из a, b
    return (a.getMaxDegree() > b.getMaxDegree()) ? a : b;
}


// Функция для нахождения НОД двух многочленов
/*Polynomials GCF_PP_P(Polynomialss poly1, Polynomials poly2) {
    // Проверяем, что оба многочлена не пустые
    if (poly1.getSize() == 0 && poly2.getSize() == 0) {
        throw std::invalid_argument("GCF of two zero polynomialss is undefined.");
    }

    // Если один из многочленов нулевой, возвращаем другой
    if (poly1.getSize() == 0) return poly2;
    if (poly2.getSize() == 0) return poly1;

    // Упорядочиваем многочлены так, чтобы poly1 имел наибольшую степень
    if (poly2.getMaxDegree() > poly1.getMaxDegree()) {
        Polynomialss tmp = poly1;
        poly1 = poly2;
        poly2 = tmp;
    }
    Integer res_deg = poly2.getMaxDegree();
    
    // Основной цикл Евклида
    int i = 0;
    while (poly2.getSize() > 0 && (poly2.getMaxDegree() > res_deg || poly2.getMaxDegree() == res_deg)) {
        Polynomials remainder = MOD_PP_P(poly1, poly2); // Остаток от деления
        // Обновляем многочлены
        poly1 = poly2;
        poly2 = remainder;
        i++;
    }
    poly1=poly2;

    // Возвращаем последний ненулевой остаток как НОД
    return poly1;
}*/

