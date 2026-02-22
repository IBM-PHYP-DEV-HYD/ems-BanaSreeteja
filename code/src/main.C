#include <iostream>

#include "Utility.H"
#include "XyzEmployeeManager.H"

using namespace std;

int main()
{
    XyzEmployeeManager sXyzEmpMgr;
    int sChoice = 0;

    while(1)
    {
        printMainMenu();
        std::cin >> sChoice;

        switch(sChoice)
        {
            case MainMenu::ADD_EMPLOYEE:
            {

                break;
            }

            case MainMenu::REMOVE_EMPLOYEE:
            {

                break;
            }

            case MainMenu::PRINT_EMPLOYEE:
            {

                break;
            }

            case MainMenu::OTHERS:
            {

                break;
            }

            case MainMenu::EXIT:
            {

                break;
            }

            default:
            {
                std::cout << "Invaluid choice\n";
                break;
            }
        }


    }



    return 0;
}