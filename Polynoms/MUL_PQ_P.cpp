#include "MUL_PQ_P.h"
Polynomials MUL_PQ_P(Polynomials poly, Rationals r){
    size_t counter = poly.getSize();
    for(int i = 0;i<counter;i++){
        Rationals multer = poly.getElems()[i]->getNodeMultiplier();
        poly.getElems()[i]->setNodeMultiplie(MUL_QQ_Q(multer, r));
    }
    return poly;
}
