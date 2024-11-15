#include "DIV_NN_N.h"

NaturalNumbers DIV_NN_N(NaturalNumbers firstNumber, NaturalNumbers secondNumber){
    if (secondNumber.getDigit(0).second == 1 && secondNumber.getSize() == 1) return firstNumber;
 size_t firstNumberSize = firstNumber.getSize();
 size_t secondNumberSize = secondNumber.getSize();
 if (firstNumberSize < secondNumberSize){
  return NaturalNumbers(0);
 }
 if (firstNumberSize == secondNumberSize){
  return DIV_NN_Dk(firstNumber, secondNumber, 0);
 }
 size_t k = firstNumberSize - secondNumberSize;
 NaturalNumbers resultDiv = NaturalNumbers(0);
 NaturalNumbers subtrahend = NaturalNumbers(0);
 while (COM_NN_D(firstNumber, secondNumber) == 2){
     k = firstNumber.getSize() - secondNumberSize;
  NaturalNumbers resultDivNnDk = DIV_NN_Dk(firstNumber, secondNumber, 0);
  NaturalNumbers resultMulNkN = MUL_Nk_N(resultDivNnDk, k);
  subtrahend = MUL_NN_N(secondNumber, MUL_Nk_N(resultDivNnDk, k));
  if (COM_NN_D(firstNumber, subtrahend) == 1){
      resultMulNkN = MUL_Nk_N(resultDivNnDk, --k);
      subtrahend = MUL_NN_N(secondNumber, resultMulNkN);
  }
  resultDiv = ADD_NN_N(resultDiv, resultMulNkN);
  firstNumber = SUB_NN_N(firstNumber, subtrahend);
 }
 if (COM_NN_D(firstNumber, secondNumber) == 0){
     resultDiv = ADD_NN_N(resultDiv, 1);
 }
 return resultDiv;
}



