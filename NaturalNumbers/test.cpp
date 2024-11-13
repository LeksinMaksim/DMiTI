#include "ADD_NN_N.h"
#include "COM_NN_D.h"
#include "MUL_ND_N.h"
#include "SUB_NDN_N.h"
#include "SUB_NN_N.h"

int main()
{
    NaturalNumbers a = {"1232432"};
    NaturalNumbers b = {"1233242999999"};

    std::cout<<"COM_NN_D: "<<compareNaturalNaturalNumbers(a, b)<<std::endl;
    std::cout<<"ADD_NN_N: "<<ADD_NN_N(a, b).getStrReference()<<std::endl;
    std::cout<<"SUB_NN_N: "<<SUB_NN_N(a, b).getStrReference()<<std::endl;
    std::cout<<"MUL_ND_N: "<<multNaturalNumberToDigit(a, 3).getStrReference()<<std::endl;
    std::cout<<"SUB_NDN_N: "<<SUB_NDN_N(b, a, 3).getStrReference()<<std::endl;
}