#include "ADD_ZZ_Z.h"
Integer ADD_ZZ_Z(Integer first, Integer second)
{
	Integer result;
	result.setSign(first.getSign());
    NaturalNumbers firstNatural = NaturalNumbers();
    NaturalNumbers secondNatural = NaturalNumbers();
    NaturalNumbers resultNatural = NaturalNumbers();
    firstNatural.setDigits(first.getDigits());
    secondNatural.setDigits(second.getDigits());
	if (first.getSign() == second.getSign())
		result.setDigits(ADD_NN_N(firstNatural, secondNatural).getDigits());
	else
	{
		if (COM_NN_D(firstNatural, secondNatural) == 2)
			result.setDigits(SUB_NN_N(firstNatural, secondNatural).getDigits());
		else
		{
			result.setDigits(SUB_NN_N(secondNatural, firstNatural).getDigits());
            resultNatural.setDigits(result.getDigits());
			if (!NZER_N_B(resultNatural)){
                result.setSign(NullStatus);
            }
			else{
                result.setSign(second.getSign());
            }
		}
	}
	return result;
}