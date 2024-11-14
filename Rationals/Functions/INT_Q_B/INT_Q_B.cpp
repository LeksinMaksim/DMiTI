#include "INT_Q_B.h"

bool INT_Q_B(Ratinals fraction){
	NaturalNumbers numeratorNaturalForm = NaturalNumbers(0);
	numeratorNaturalForm.setDigits(fraction.getNumerator.getDigits());	
	size_t resultOfCompare = COM_NN_D(numeratorNaturalForm, fraction.getDenominator);
	if (resultOfCompare == 0) return true;
	if (resultOfCompare == 1) return false;
	NaturalNumbers modNumeratorOfDenominator = MOD_NN_N(numeratorNaturalForm, fraction.getDenominator());
	return COM_NN_D(modNumeratorOfDenominator, NaturalNumbers(0)) == 0 ? true : false;
}
