#ifndef NUMBER_INPUT_HEADER
#define NUMBER_INPUT_HEADER

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

#include "../Integer/Source/Integer.h"
#include "../NaturalNumbers/Source/NaturalNumbers.h"
#include "../Polynomials/Source/Polynomials.h"
#include "../Rationals/Source/Rationals.h"

class NumberInput
{
   public:
    static std::string readString(const std::string& prompt)
    {
        std::string input;
        while (true)
        {
            std::cout << prompt;
            std::getline(std::cin, input);

            // Удаляем пробелы из строки
            input.erase(remove_if(input.begin(), input.end(), isspace),
                        input.end());

            if (!input.empty())
            {
                return input;
            }
            std::cout << "Ошибка: пустой ввод\n";
        }
    }

    static NaturalNumbers readNaturalNumber(const std::string& prompt)
    {
        while (true)
        {
            std::string input = readString(prompt);

            bool valid = true;
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    valid = false;
                    break;
                }
            }

            if (valid && input[0] != '0')
            {
                return NaturalNumbers(input);
            }
            std::cout << "Ошибка: введите корректное натуральное число (без "
                         "ведущих нулей)\n";
        }
    }

    static Integer readInteger(const std::string& prompt)
    {
        while (true)
        {
            std::string input = readString(prompt);

            bool valid = true;
            size_t startPos = (input[0] == '-' || input[0] == '+') ? 1 : 0;

            if (input.length() <= startPos)
            {
                valid = false;
            }
            else
            {
                for (size_t i = startPos; i < input.length(); i++)
                {
                    if (!isdigit(input[i]))
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid)
            {
                return Integer(input);
            }
            std::cout << "Ошибка: введите корректное целое число\n";
        }
    }

    static Rationals readRational(const std::string& prompt = "")
    {
        if (!prompt.empty())
        {
            std::cout << prompt << std::endl;
        }

        while (true)
        {
            try
            {
                std::string input = readString(
                    "Введите дробь (формат: числитель/знаменатель): ");
                if (input.find('/') == std::string::npos)
                {
                    std::cout << "Используйте формат числитель/знаменатель\n";
                    continue;
                }
                return Rationals(input);
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        }
    }

    static Polynomials readPolynomial(std::string prompt)
    {
        while (true)
        {
            std::string input = readString(prompt);
            try
            {
                return Polynomials(input);
            }
            catch (...)
            {
                std::cout << "Ошибка: введите корректный многочлен (например: "
                             "1x^2+2x^1-3x^0 или 2x^2-1)\n";
            }
        }
    }
};

#endif
