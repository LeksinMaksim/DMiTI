#include "../Source/NaturalNumbers.h"
#include "../Functions/COM_NN_D/COM_NN_D.h"
#include "../Functions/NZER_N_B/NZER_N_B.h"
#include "../Functions/ADD_1N_N/ADD_1N_N.h"
#include "../Functions/ADD_NN_N/ADD_NN_N.h"
#include "../Functions/SUB_NN_N/SUB_NN_N.h"
#include "../Functions/MUL_ND_N/MUL_ND_N.h"
#include "../Functions/MUL_Nk_N/MUL_Nk_N.h"
#include "../Functions/MUL_NN_N/MUL_NN_N.h"
#include "../Functions/SUB_NDN_N/SUB_NDN_N.h"
#include "../Functions/DIV_NN_Dk/DIV_NN_Dk.h"
#include "../Functions/DIV_NN_N/DIV_NN_N.h"
#include "../Functions/MOD_NN_N/MOD_NN_N.h"
#include "../Functions/GCF_NN_N/GCF_NN_N.h"
#include "../Functions/LCM_NN_N/LCM_NN_N.h"
#include <iostream>

int main(){
	NaturalNumbers firstNumber = NaturalNumbers(3315);
	NaturalNumbers secondNumber = NaturalNumbers(120);
	std::cout << LCM_NN_N(secondNumber,firstNumber).getStrReference() << '\n';
	return 0;
}
