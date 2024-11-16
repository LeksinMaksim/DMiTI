#ifndef MENU_MANAGER_HEADER
#define MENU_MANAGER_HEADER

#include <functional>
#include <iostream>
#include <limits>
#include <map>

#include "NumberInput.h"

// Натуральные числа
#include "../NaturalNumbers/Functions/ADD_1N_N/ADD_1N_N.h"
#include "../NaturalNumbers/Functions/ADD_NN_N/ADD_NN_N.h"
#include "../NaturalNumbers/Functions/COM_NN_D/COM_NN_D.h"
#include "../NaturalNumbers/Functions/DIV_NN_Dk/DIV_NN_Dk.h"
#include "../NaturalNumbers/Functions/DIV_NN_N/DIV_NN_N.h"
#include "../NaturalNumbers/Functions/GCF_NN_N/GCF_NN_N.h"
#include "../NaturalNumbers/Functions/LCM_NN_N/LCM_NN_N.h"
#include "../NaturalNumbers/Functions/MOD_NN_N/MOD_NN_N.h"
#include "../NaturalNumbers/Functions/MUL_ND_N/MUL_ND_N.h"
#include "../NaturalNumbers/Functions/MUL_NN_N/MUL_NN_N.h"
#include "../NaturalNumbers/Functions/MUL_Nk_N/MUL_Nk_N.h"
#include "../NaturalNumbers/Functions/NZER_N_B/NZER_N_B.h"
#include "../NaturalNumbers/Functions/SUB_NDN_N/SUB_NDN_N.h"
#include "../NaturalNumbers/Functions/SUB_NN_N/SUB_NN_N.h"

// Целые числа
#include "../Integer/Functions/ABS_Z_N/ABS_Z_N.h"
#include "../Integer/Functions/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "../Integer/Functions/DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "../Integer/Functions/MOD_ZZ_Z/MOD_ZZ_Z.h"
#include "../Integer/Functions/MUL_ZM_Z/MUL_ZM_Z.h"
#include "../Integer/Functions/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "../Integer/Functions/POZ_Z_D/POZ_Z_D.h"
#include "../Integer/Functions/SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "../Integer/Functions/TRANS_N_Z/TRANS_N_Z.h"
#include "../Integer/Functions/TRANS_Z_N/TRANS_Z_N.h"

// Рациональные числа
#include "../Rationals/Functions/ADD_QQ_Q/ADD_QQ_Q.h"
#include "../Rationals/Functions/DIV_QQ_Q/DIV_QQ_Q.h"
#include "../Rationals/Functions/INT_Q_B/INT_Q_B.h"
#include "../Rationals/Functions/MUL_QQ_Q/MUL_QQ_Q.h"
#include "../Rationals/Functions/RED_Q_Q/RED_Q_Q.h"
#include "../Rationals/Functions/SUB_QQ_Q/SUB_QQ_Q.h"
#include "../Rationals/Functions/TRANS_Q_Z/TRANS_Q_Z.h"
#include "../Rationals/Functions/TRANS_Z_Q/TRANS_Z_Q.h"

// Полиномы
#include "../Polynomials/Functions/ADD_PP_P/ADD_PP_P.h"
#include "../Polynomials/Functions/DEG_P_N/DEG_P_N.h"
#include "../Polynomials/Functions/DER_P_P/DER_P_P.h"
#include "../Polynomials/Functions/DIV_PP_P/DIV_PP_P.h"
#include "../Polynomials/Functions/FAC_P_Q/FAC_P_Q.h"
#include "../Polynomials/Functions/GCF_PP_P/GCF_PP_P.h"
#include "../Polynomials/Functions/LED_P_Q/LED_P_Q.h"
#include "../Polynomials/Functions/MOD_PP_P/MOD_PP_P.h"
#include "../Polynomials/Functions/MUL_PP_P/MUL_PP_P.h"
#include "../Polynomials/Functions/MUL_PQ_P/MUL_PQ_P.h"
#include "../Polynomials/Functions/MUL_Pxk_P/MUL_Pxk_P.h"
#include "../Polynomials/Functions/NMR_P_P/NMR_P_P.h"
#include "../Polynomials/Functions/SUB_PP_P/SUB_PP_P.h"

class MenuManager
{
   private:
    std::map<int, std::pair<std::string, std::function<void()>>> functions;

    void displayResult(NaturalNumbers result)
    {
        std::cout << "\nРезультат: " << result.getStrReference() << std::endl;
    }

    void displayResult(Integer result)
    {
        std::cout << "\nРезультат: " << result.getStrReference() << std::endl;
    }

    void displayResult(Rationals result)
    {
        std::cout << "\nРезультат: " << result.getStrReference() << std::endl;
    }

    void displayResult(Polynomials result)
    {
        std::cout << "\nРезультат: " << result.getStrReference() << std::endl;
    }

    void displayResult(std::pair<Rationals, Polynomials> result)
    {
        std::cout << "\nРезультат:" << std::endl;
        std::cout << "Рациональный множитель: "
                  << result.first.getStrReference() << std::endl;
        std::cout << "Многочлен: " << result.second.getStrReference()
                  << std::endl;
    }

   public:
    MenuManager()
    {
        // Натуральные числа (1-14)
        functions[1] = { "Сравнение натуральных чисел (COM_NN_D)", [this]()
                         {
                             int result = COM_NN_D_Interactive();
                             std::cout << "\nРезультат: ";
                             switch (result)
                             {
                                 case 2:
                                     std::cout << "первое больше второго";
                                     break;
                                 case 1:
                                     std::cout << "второе больше первого";
                                     break;
                                 case 0:
                                     std::cout << "числа равны";
                                     break;
                             }
                             std::cout << std::endl;
                         } };

        functions[2] = { "Проверка на ноль (NZER_N_B)", [this]()
                         {
                             bool result = NZER_N_B_Interactive();
                             std::cout << "\nРезультат: "
                                       << (result ? "число не равно нулю"
                                                  : "число равно нулю")
                                       << std::endl;
                         } };

        functions[3] = { "Добавление 1 к натуральному числу (ADD_1N_N)",
                         [this]() { displayResult(ADD_1N_N_Interactive()); } };

        functions[4] = { "Сложение натуральных чисел (ADD_NN_N)",
                         [this]() { displayResult(ADD_NN_N_Interactive()); } };

        functions[5] = {
            "Вычитание из первого большего натурального числа второго меньшего "
            "(SUB_NN_N)",
            [this]() { displayResult(SUB_NN_N_Interactive()); }
        };

        functions[6] = { "Умножение натурального числа на цифру (MUL_ND_N)",
                         [this]() { displayResult(MUL_ND_N_Interactive()); } };

        functions[7] = { "Умножение натурального числа на 10^k (MUL_Nk_N)",
                         [this]() { displayResult(MUL_Nk_N_Interactive()); } };

        functions[8] = { "Умножение натуральных чисел (MUL_NN_N)",
                         [this]() { displayResult(MUL_NN_N_Interactive()); } };

        functions[9] = {
            "Вычитание из натурального числа другого умноженного на цифру "
            "(SUB_NDN_N)",
            [this]() { displayResult(SUB_NDN_N_Interactive()); }
        };

        functions[10] = {
            "Вычисление первой цифры деления большего натурального на меньшее "
            "(DIV_NN_Dk)",
            [this]() { displayResult(DIV_NN_Dk_Interactive()); }
        };

        functions[11] = {
            "Частное от деления большего натурального числа на меньшее "
            "(DIV_NN_N)",
            [this]() { displayResult(DIV_NN_N_Interactive()); }
        };

        functions[12] = {
            "Остаток от деления большего натурального числа на меньшее "
            "(MOD_NN_N)",
            [this]() { displayResult(MOD_NN_N_Interactive()); }
        };

        functions[13] = { "НОД натуральных чисел (GCF_NN_N)",
                          [this]() { displayResult(GCF_NN_N_Interactive()); } };

        functions[14] = { "НОК натуральных чисел (LCM_NN_N)",
                          [this]() { displayResult(LCM_NN_N_Interactive()); } };

        // Целые числа (15-24)
        functions[15] = { "Абсолютная величина числа (ABS_Z_N)",
                          [this]() { displayResult(ABS_Z_N_Interactive()); } };

        functions[16] = { "Определение положительности числа (POZ_Z_D)",
                          [this]()
                          {
                              int result = POZ_Z_D_Interactive();
                              std::cout << "\nРезультат: ";
                              switch (result)
                              {
                                  case 2:
                                      std::cout << "положительное";
                                      break;
                                  case 1:
                                      std::cout << "отрицательное";
                                      break;
                                  case 0:
                                      std::cout << "число равно нулю";
                                      break;
                              }
                              std::cout << std::endl;
                          } };

        functions[17] = { "Умножение целого на (-1) (MUL_ZM_Z)",
                          [this]() { displayResult(MUL_ZM_Z_Interactive()); } };

        functions[18] = { "Преобразование натурального в целое (TRANS_N_Z)",
                          [this]()
                          { displayResult(TRANS_N_Z_Interactive()); } };

        functions[19] = {
            "Преобразование целого неотрицательного в натуральное (TRANS_Z_N)",
            [this]() { displayResult(TRANS_Z_N_Interactive()); }
        };

        functions[20] = { "Сложение целых чисел (ADD_ZZ_Z)",
                          [this]() { displayResult(ADD_ZZ_Z_Interactive()); } };

        functions[21] = { "Вычитание целых чисел (SUB_ZZ_Z)",
                          [this]() { displayResult(SUB_ZZ_Z_Interactive()); } };

        functions[22] = { "Умножение целых чисел (MUL_ZZ_Z)",
                          [this]() { displayResult(MUL_ZZ_Z_Interactive()); } };

        functions[23] = { "Частное от деления целого на целое (DIV_ZZ_Z)",
                          [this]() { displayResult(DIV_ZZ_Z_Interactive()); } };

        functions[24] = { "Остаток от деления целого на целое (MOD_ZZ_Z)",
                          [this]() { displayResult(MOD_ZZ_Z_Interactive()); } };

        // Рациональные числа (25-32)
        functions[25] = { "Сокращение дроби (RED_Q_Q)",
                          [this]() { displayResult(RED_Q_Q_Interactive()); } };

        functions[26] = { "Проверка на целое (INT_Q_B)", [this]()
                          {
                              bool result = INT_Q_B_Interactive();
                              std::cout << "\nРезультат: "
                                        << (result ? "да, число целое"
                                                   : "нет, число не целое")
                                        << std::endl;
                          } };

        functions[27] = { "Преобразование целого в дробное (TRANS_Z_Q)",
                          [this]()
                          { displayResult(TRANS_Z_Q_Interactive()); } };

        functions[28] = { "Преобразование дробного в целое (TRANS_Q_Z)",
                          [this]()
                          { displayResult(TRANS_Q_Z_Interactive()); } };

        functions[29] = { "Сложение дробей (ADD_QQ_Q)",
                          [this]() { displayResult(ADD_QQ_Q_Interactive()); } };

        functions[30] = { "Вычитание дробей (SUB_QQ_Q)",
                          [this]() { displayResult(SUB_QQ_Q_Interactive()); } };

        functions[31] = { "Умножение дробей (MUL_QQ_Q)",
                          [this]() { displayResult(MUL_QQ_Q_Interactive()); } };

        functions[32] = { "Деление дробей (DIV_QQ_Q)",
                          [this]() { displayResult(DIV_QQ_Q_Interactive()); } };

        // Полиномы (33-45)
        functions[33] = { "ADD_PP_P - Сложение многочленов",
                          [this]() { displayResult(ADD_PP_P_Interactive()); } };

        functions[34] = { "SUB_PP_P - Вычитание многочленов",
                          [this]() { displayResult(SUB_PP_P_Interactive()); } };

        functions[35] = {
            "MUL_PQ_P - Умножение многочлена на рациональное число",
            [this]() { displayResult(MUL_PQ_P_Interactive()); }
        };

        functions[36] = { "MUL_Pxk_P - Умножение многочлена на x^k", [this]()
                          { displayResult(MUL_Pxk_P_Interactive()); } };

        functions[37] = { "LED_P_Q - Старший коэффициент многочлена",
                          [this]() { displayResult(LED_P_Q_Interactive()); } };

        functions[38] = { "DEG_P_N - Степень многочлена",
                          [this]() { displayResult(DEG_P_N_Interactive()); } };

        functions[39] = {
            "FAC_P_Q - Вынесение из многочлена НОК знаменателей коэффициентов "
            "и НОД числителей",
            [this]() { displayResult(FAC_P_Q_Interactive()); }
        };

        functions[40] = { "MUL_PP_P - Умножение многочленов",
                          [this]() { displayResult(MUL_PP_P_Interactive()); } };

        functions[41] = {
            "DIV_PP_P - Частное от деления многочлена на многочлен при делении "
            "с остатком",
            [this]() { displayResult(DIV_PP_P_Interactive()); }
        };

        functions[42] = {
            "MOD_PP_P - Остаток от деления многочлена на многочлен при делении "
            "с остатком",
            [this]() { displayResult(MOD_PP_P_Interactive()); }
        };

        functions[43] = { "GCF_PP_P - НОД многочленов",
                          [this]() { displayResult(GCF_PP_P_Interactive()); } };

        functions[44] = { "DER_P_P - Производная многочлена",
                          [this]() { displayResult(DER_P_P_Interactive()); } };

        functions[45] = {
            "NMR_P_P - Преобразование многочлена — кратные корни в простые",
            [this]() { displayResult(NMR_P_P_Interactive()); }
        };
    }

    void showMenu()
    {
        std::cout << "\nДоступные функции:\n\n";
        std::cout << "=== Натуральные числа ===\n";
        for (int i = 1; i <= 14; i++)
        {
            std::cout << i << ". " << functions[i].first << "\n";
        }

        std::cout << "\n=== Целые числа ===\n";
        for (int i = 15; i <= 24; i++)
        {
            std::cout << i << ". " << functions[i].first << "\n";
        }

        std::cout << "\n=== Рациональные числа ===\n";
        for (int i = 25; i <= 32; i++)
        {
            std::cout << i << ". " << functions[i].first << "\n";
        }

        std::cout << "\n=== Полиномы ===\n";
        for (int i = 33; i <= 45; i++)
        {
            std::cout << i << ". " << functions[i].first << "\n";
        }

        std::cout << "\n0. Выход\n";
    }

    void run()
    {
        std::string input;
        while (true)
        {
            showMenu();
            std::cout << "\nВыберите функцию (0 для выхода): ";
            std::getline(std::cin, input);

            try
            {
                int choice = std::stoi(input);

                if (choice == 0)
                {
                    std::cout << "\nПрограмма завершена.\n";
                    break;
                }

                auto it = functions.find(choice);
                if (it != functions.end())
                {
                    std::cout << "\nВыполняется: " << it->second.first
                              << "\n\n";
                    it->second.second();  // Вызов функции
                    std::cout << "\nДля продолжения нажмите Enter...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cin.get();
                }
                else
                {
                    std::cout
                        << "\nНеверный выбор. Для продолжения нажмите Enter...";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cin.get();
                }
            }
            catch (const std::invalid_argument&)
            {
                std::cout << "\nОшибка: введите число. Для продолжения нажмите "
                             "Enter...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cin.get();
            }
        }
    }
};
#endif
