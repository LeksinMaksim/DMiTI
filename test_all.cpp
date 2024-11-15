#include "all_my_funcs.h"

int main()
{
    NaturalNumbers n1 = {"8932892"};
    NaturalNumbers n2 = {"993"};
    Integer i1 = {"-1321321"};
    Integer i2 = {"6531"};
    Rationals r1 = {Integer("24"), NaturalNumbers("18")};
    Rationals r2 = {Integer("5"), NaturalNumbers("18")};
    Polynomials p1 = Polynomials();
    p1.insertElem(Rationals({"24"}, {"18"}), Integer("1"));
    p1.insertElem(Rationals({"8"}, {"21"}), Integer("3"));
    Polynomials p2 = Polynomials();
    p2.insertElem(Rationals({"5"}, {"18"}), Integer("1"));
    p2.insertElem(Rationals({"3"}, {"21"}), Integer("3"));
    //std::cout<<ADD_NN_N(n1, n2).getStrReference()<<std::endl;
    //std::cout<<SUB_NDN_N(n1, n2, 4).getStrReference()<<std::endl;
    //std::cout<<LCM_NN_N(n1, n2).getStrReference()<<std::endl;
    //std::cout<<MOD_ZZ_Z(i1, i2).getStrReference()<<std::endl;
    //std::cout<<ADD_QQ_Q(r1, r2).getStrReference()<<std::endl;
    std::cout<<r1.getStrReference()<<" "<<r2.getStrReference()<<std::endl;
    std::cout<<SUB_QQ_Q(r1, r2).getStrReference()<<std::endl;
    //std::cout<<SUB_PP_P(p1, p2).getStrReference()<<std::endl;
    //std::cout<<LED_P_Q(p1).getStrReference()<<std::endl;
    //std::cout<<DER_P_P(p1).getStrReference()<<std::endl;
    //std::cout<<FAC_P_Q(p1).first.getStrReference()<<" * "<<FAC_P_Q(p1).second.getStrReference()<<std::endl;
}