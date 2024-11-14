#include "MUL_Pxk_P.h"

Polynomials MUL_Pxk_P(Polynomials polynom, Elem pOne){
	size_t kDegree = pOne.getDegree();
	if (kDegree = 0) return polynom;
	std::vector<Elem*> newPolynomElements = polynom.getElems();
	size_t countElements = polynom.getSize();
	for (size_t i = 0; i < countElements; i++){
		Integer oldDegree = newPolynomElements[i]->getNodeDegree();
		newPolynomElements[i]->setNodeDegree(ADD_ZZ_Z(oldDegree, kDegree));
	}
	polynom.setElems(newPolynomElems);
	return polynom;
}
