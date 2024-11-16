#include "ADD_PP_P.h"

bool isinstance(Integer elem, std::vector<Integer> vec){
    for(Integer el:vec){
        if(el==elem){
            return true;
        }
    }
    return false;
}

Polynomials ADD_PP_P(Polynomials poly1, Polynomials poly2) {
    Polynomials result;
    std::vector<Integer> deleted_indexes;
    // Получаем элементы из обоих многочленов


    size_t i = 0, j = 0;

    // Основной цикл сложения
    for(auto el: poly1.getElems()){
        for(auto ir: poly2.getElems()){
            if(el->getNodeDegree() == ir->getNodeDegree()){
                result.insertElem(ADD_QQ_Q(el->getNodeMultiplier(), ir->getNodeMultiplier()), el->getNodeDegree());
                deleted_indexes.push_back(el->getNodeDegree());
                std::cout<<el->getNodeMultiplier().getStrReference()<<std::endl;
                std::cout<<ir->getNodeMultiplier().getStrReference()<<std::endl;
                std::cout<<ADD_QQ_Q(el->getNodeMultiplier(), ir->getNodeMultiplier()).getStrReference()<<std::endl;
            }
        }
    }

    while (i < poly2.getElems().size()) {
        if(!isinstance(poly2.getElems()[i]->getNodeDegree(), deleted_indexes))
        {
            result.insertElem(
                poly2.getElems()[i]->getNodeMultiplier(),
                poly2.getElems()[i]->getNodeDegree()
            );
            
        }
        i++;
    }
    
    // Копируем оставшиеся элементы из первого многочлена
    while (j < poly1.getElems().size()) {
        if(!isinstance(poly1.getElems()[j]->getNodeDegree(), deleted_indexes))
        {
            result.insertElem(
                poly1.getElems()[j]->getNodeMultiplier(),
                poly1.getElems()[j]->getNodeDegree()
            );
            
        }
        j++;
    }
    return result;
}


