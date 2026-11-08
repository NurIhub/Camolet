
#include <iostream>
#include <Windows.h>
#include <cstdlib>

int fuel[2][3] =
{
    {1, 4, 7},
    {2, 4, 6}
};

int WeightLimits[2][3] =
{
    {750, 1500, 2000},
    {1000, 2000, 3000}
};

int tankCapacity[2] = { 300, 1000 };

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::system("cls");

    int Camolet = 0;
    int Ves = 0;
    double AB;
    double BC;
    int Rashod = 0;

    while (true)
    {
        std::cout << "Выберите самолет\n";
        std::cout << "1. Самолет 1\n";
        std::cout << "2. Самолет 2\n";
        std::cin >> Camolet;

        if (Camolet == 1 || Camolet == 2)
        {
            break;
        }

        std::cout << "Выберите самолет 1 или 2\n";
    }

    std::cout << "Введите расстояние между A и B (км): ";
    std::cin >> AB;

    std::cout << "Введите расстояние между B и C (км): ";
    std::cin >> BC;

    std::cout << "Введите вес груза (кг): ";
    std::cin >> Ves;

    if (AB < 0 || BC < 0 || Ves < 0)
    {
        std::cout << "Введены некорректные данные!";
        return 0;
    }

    Camolet--;

    for (int i = 0; i < 3; i++)
    {
        if (Ves <= WeightLimits[Camolet][i])
        {
            Rashod = fuel[Camolet][i];
            break;
        }
    }

    if (Rashod == 0)
    {
        std::cout << "Самолет не может поднять такой груз!";
        return 0;
    }

    double FuelAB = AB * Rashod;
    double FuelBC = BC * Rashod;

    double Ostatok = 0;
    double Dozapravka = 0;

    if (Camolet == 0)
    {
        if (FuelAB > tankCapacity[Camolet])
        {
            std::cout << "Невозможно долететь до точки B!";
            return 0;
        }

        Ostatok = tankCapacity[Camolet] - FuelAB;

        Dozapravka = FuelBC - Ostatok;

        if (Dozapravka < 0)
        {
            Dozapravka = 0;
        }

        if (Dozapravka > tankCapacity[Camolet] - Ostatok)
        {
            std::cout << "Невозможно долететь до точки C!";
            return 0;
        }
    }
    else
    {
        double VremBac = 100;

        if (FuelAB > tankCapacity[Camolet] + VremBac)
        {
            std::cout << "Невозможно долететь до точки B!";
            return 0;
        }

        if (FuelAB <= VremBac)
        {
            VremBac -= FuelAB;
            Ostatok = tankCapacity[Camolet];
        }
        else
        {
            FuelAB -= VremBac;
            VremBac = 0;
            Ostatok = tankCapacity[Camolet] - FuelAB;
        }

        Dozapravka = FuelBC - Ostatok - VremBac;

        if (Dozapravka < 0)
        {
            Dozapravka = 0;
        }

        if (Dozapravka > tankCapacity[Camolet] - Ostatok)
        {
            std::cout << "Невозможно долететь до точки C!";
            return 0;
        }

        std::cout << "\nОстаток временного бака: " << VremBac << " л";
        std::cout << "\nОстаток основного бака: " << Ostatok << " л";
    }

    std::cout << "\nРасход топлива: " << Rashod << " л/км";
    std::cout << "\nТопливо на участке A-B: " << AB * Rashod << " л";
    std::cout << "\nТопливо на участке B-C: " << BC * Rashod << " л";
    std::cout << "\nМинимальная дозаправка в точке B: " << Dozapravka << " л";

    return 0;
}





















	
	

	