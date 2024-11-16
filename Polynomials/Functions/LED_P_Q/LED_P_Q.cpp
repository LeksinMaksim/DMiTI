#include "LED_P_Q.h"

// Выполнил Пьянков Михаил 3384

Rationals LED_P_Q(Polynomials polinom)
{
    if (polinom.getSize() != 0)  // Проверка полинома на пустоту
        return polinom.getElems()
            .back()
            ->getNodeMultiplier();  // Максимальная степень одночлена в
                                    // многочлене уже встроена в базовый класс
    else
        return Rationals(0);
}

Rationals LED_P_Q_Interactive()
{
    Polynomials polinom = NumberInput::readPolynomial("Введите полином: ");
    return LED_P_Q(polinom);
}
