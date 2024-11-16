#include "all_my_funcs.h"

int main()
{
    NaturalNumbers n1 = {"8932892"};
    NaturalNumbers n2 = {"993"};
    Integer i1 = {"-1321321"};
    Integer i2 = {"6531"};
    Rationals r1 = {Integer(0)};
    Rationals r2 = {Integer("5"), NaturalNumbers("18")};
    Polynomials p1 = {"-1/1x^0+1/1x^100"};
    Polynomials p2 = {"1/1x^0+1/1x^1"};
    std::cout<<DIV_PP_P(p1, p2).first.getStrReference()<<std::endl;
    std::cout<<DIV_PP_P(p1, p2).second.getStrReference()<<std::endl;
    //std::cout<<p1.getStrReference()<<std::endl;
    //std::cout<<p2.getStrReference()<<std::endl;
    //std::cout<<ADD_NN_N(n1, n2).getStrReference()<<std::endl;
    //std::cout<<SUB_NDN_N(n1, n2, 4).getStrReference()<<std::endl;
    //std::cout<<LCM_NN_N(n1, n2).getStrReference()<<std::endl;
    //std::cout<<MOD_ZZ_Z(i1, i2).getStrReference()<<std::endl;
    //std::cout<<ADD_QQ_Q(r1, r2).getStrReference()<<std::endl;
    //std::cout<<MUL_PQ_P(p1, Rationals(Integer(1), NaturalNumbers(2))).getStrReference()<<std::endl;
    //std::cout<<DIV_QQ_Q(r1, r2).getStrReference()<<std::endl;
    //std::cout<<MUL_Pxk_P(MUL_PQ_P(p1, Rationals(Integer(1), NaturalNumbers(2))), Elem(Rationals(1), Integer(0))).getStrReference()<<std::endl;
    
    //std::cout<<LED_P_Q(p1).getStrReference()<<std::endl;
    //std::cout<<DER_P_P(p1).getStrReference()<<std::endl;
    //std::cout<<FAC_P_Q(p1).first.getStrReference()<<" * "<<FAC_P_Q(p1).second.getStrReference()<<std::endl;
}