#include "ADD_NN_N.h"
#include "COM_NN_D.h"
#include "MUL_ND_N.h"
#include "MUL_Nk_N.h"
#include "MUL_NN_N.h"
#include "SUB_NDN_N.h"
#include "DIV_NN_Dk.h"
#include "DIV_NN_N.h"
#include "SUB_NN_N.h"

int main()
{
    NaturalNumbers a = {"12345678901234567890"};
    NaturalNumbers b = {"10000"};
    NaturalNumbers c = {"531"};

    std::cout<<"COM_NN_D: "<<COM_NN_D(a, b)<<std::endl;
    std::cout<<"ADD_NN_N: "<<ADD_NN_N(a, b).getStrReference()<<std::endl;
    std::cout<<"SUB_NN_N: "<<SUB_NN_N(a, b).getStrReference()<<std::endl;
    std::cout<<"MUL_ND_N: "<<MUL_ND_N(a, 3).getStrReference()<<std::endl;
    std::cout<<"MUL_Nk_N: "<<MUL_Nk_N(a, 15).getStrReference()<<std::endl;
    std::cout<<"MUL_NN_N: "<<MUL_NN_N(a, c).getStrReference()<<std::endl;
    std::cout<<"SUB_NDN_N: "<<SUB_NDN_N(a, b, 3).getStrReference()<<std::endl;
    std::cout<<"DIV_NN_Dk: "<<DIV_NN_Dk(a, b, 5)<<std::endl;
    std::cout<<"DIV_NN_N: "<<DIV_NN_N(a, c).getStrReference()<<std::endl;
}