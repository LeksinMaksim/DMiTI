#include "LED_P_Q.h"

int main()
{
    Polynomials a = {"1/1x+2/3x^2+5/6x^5 +7/8x^0+9/120x^12"};
    Rationals x = LED_P_Q(a);
    std::cout<<a.getStrReference()<<std::endl;
    std::cout<<x.getStrReference()<<std::endl;
}