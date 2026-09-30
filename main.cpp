#include <iostream>
#include <string>

const std::string COLORS[10] = {"черный", "коричневый", "красный", "оранжевый", "желтый", "зеленый", "синий", "фиолетовый", "серый", "белый"};

int colorToDigit(std::string color)
{
    for (int i = 0; i < 10; i++)
    {
        if (COLORS[i] == color)
        {
            return i;
        }
    }
    return -1;
}

double calcCurrent(double voltage, double resistance)
{
    return voltage / resistance;
}

void printMenu()
{
    std::cout << "=== Помощник электронщика ===" << std::endl;
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Рассчитать ток" << std::endl;
    // std::cout << "2. Узнать номинал резистора" << std::endl;
    std::cout << "2. Номинал по 3 первым полоскам" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

int main()
{
    double voltage;
    double resistance;
    double current;
    int choice = 1;
    std::string color;

    while (choice != 0)
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Напряжение (V): ";
            std::cin >> voltage;
            std::cout << "Сопротивление (Ом): ";
            std::cin >> resistance;
            if (resistance <= 0)
            {
                std::cout << "Ошибка: должно быть больше нуля." << std::endl;
                break;
            }
            current = calcCurrent(voltage, resistance);
            std::cout << "Ток (A): " << current << std::endl;
            std::cout << "Ток (мА): " << current * 1000 << std::endl;
            break;
        // case 2:
        // {
        //     std::cout << "Введите цвета резистора: ";
        //     std::cin >> color;
        //     int digit = colorToDigit(color);
        //     if (digit == -1)
        //     {
        //         std::cout << "Нет такого цвета" << std::endl;
        //     }
        //     else
        //     {
        //         std::cout << digit << std::endl;
        //     }
        //     break;
        // }
        case 2:
        {
            std::string bands[3];
            for (int i = 0; i < 3; i++)
            {
                std::cin >> bands[i];
            }

            int digits[3];
            bool allFound = true;

            for (int i = 0; i < 3; i++)
            {
                digits[i] = colorToDigit(bands[i]);
                if (digits[i] == -1)
                {
                    allFound = false;
                    std::cout << "Ошибка: нет такого цвета/Опечатка" << std::endl;
                    break;
                }
            }
            if (allFound)
            {
                // std::cout << digits[0] << digits[1] << digits[2] << std::endl;
                long long multiplier = 1;
                for (int i = 0; i < digits[2]; i++)
                {
                    multiplier = multiplier * 10;
                }
                long long value = (digits[0] * 10 + digits[1]) * multiplier;
                std::cout << value << " Ом" << std::endl;
                std::cout << value / 1000.0 << " кОм" << std::endl;
                std::cout << value / 1000000.0 << " МОм" << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, выберите 1,2 или 0." << std::endl;
            break;
        }
    }
}
