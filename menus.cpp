//
// Created by Daniel Abu Ramadan on 2025-01-10.
//

#include <iostream>
#include <fstream>
#include <string>
#include "menus.h"
#define prt(x) std::cout << x << std::endl

void printMainMenu()
{
    //flavour text
#ifdef _WIN32
    system("cls");
#else
    prt("\033[2J\033[1;1H"); // ANSI escape code for clear screen
#endif
    //prints logo
    std::ifstream bardic("../bardic.txt"); // Changed to ifstream for reading
    if (bardic.is_open()) {
        // Print the contents of the file
        std::cout << bardic.rdbuf();
        bardic.close();
    } else {
        std::cerr << "Error: Unable to open bardic.txt" << std::endl;
        prt(std::filesystem::current_path());
    }

    prt("enter the number corresponding to the coice you would like to make.");
    std::cout << std::endl;
    prt("1) start game");
    std::cout << std::endl;
    prt("2) exit game");
    std::cout << std::endl;

    int input = menuInput(2);
    switch (input)
    {
        case 1:
            //start game
                break;

        case 2:
            //exit game
                break;
    }
}

/// <summary>
/// takes number of menu choices as argument. returns int of string inputted by user.
/// </summary>
/// <param name="menuChoices"></param>
/// <returns></returns>
int menuInput(int menuChoices)
{
    std::string strInput;
    int selecting = true;
    int input = 0;

    while (selecting == true) //iterates through a while loop until input is valid
    {
        strInput = "";
        input = 0;
        std::cin >> strInput;

        if (isNumber(strInput) == false)
        {
            prt("Wrong input, press enter to try again.");
            std::cin >> strInput;
            break;
        }

        input = stoi(strInput);

        if (input > 0 || input <= menuChoices)
        {
            selecting = false;
            break;
        }


        prt("Wrong input, press enter to try again.");
        std::cin >> strInput;
    }

    return input;

}


/// <summary>
/// returns false if string argument contains any letters that cannot be converted to int
/// </summary>
/// <param name="input"></param>
/// <returns></returns>
bool isNumber(std::string input)
{
    for (int i = 0; i < input.length(); i++) //iterates through string. returns false if char can't be converted to int.
    {
        if (!isdigit(input[i]))
        {
            return false; //exists for-loop
        }
    }
    return true; //incase for-loop continued (isdigit = true)
}