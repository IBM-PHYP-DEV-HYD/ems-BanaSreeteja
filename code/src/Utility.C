
#include "Utility.H"
#include "RandomData.H"

using namespace std;


void printMainMenu()
{
    cout << "|--------------------------------------|\n"
        << "| Choose any below option              |\n"
        << "|--------------------------------------|\n"
        << "| 1. Add an Employee.                  |\n"
        << "| 2. Add n Random employees            |\n"
        << "| 3. Remove an employee                |\n"
        << "| 4. Get Employee Details              |\n"
        << "| 5. Others.                           |\n"
        << "|--------------------------------------|\n"
        << "|      Press -1 to exit                |\n"
        << "|--------------------------------------|\n";
}

void printAddEmployeeOption()
{
    cout << "\n"
         << "|--------------------------------------|\n"
         << "| Choose any option below.             |\n"
         << "|--------------------------------------|\n"
         << "| 1. Add Employee at Random            |\n"
         << "| 2. Add an Employee (F/C/I)           |\n"
         << "| -------------------------------------|\n"
         << "|   Press -1 to Exit.                  |\n"
         << "|--------------------------------------|\n";
}

void printXyzEmpSummaryMenu()
{
   cout  << "\n"
         << "--------------------------------------------------\n"
         << "|             Employee Details Menu              |\n"
         << "--------------------------------------------------\n"
         << "| 1. All Employees Summary                       |\n"
         << "| 2. Employee Summary (F/C/I)                    |\n"
         << "| 3. Employee Summary (M/F)                      |\n"
         << "| 4. Employee Summary (A/I/R)                    |\n"
         << "| 5. Display Employee Details                    |\n"
         << "| (-1 to Go Back)                                |\n"
         << "-------------------------------------------------|\n";
}

void printOthersMenu()
{
    cout << "\n"
         << "---------------------------------------------------\n"
         << "|             Other Operations Menu               |\n"
         << "---------------------------------------------------\n"
         << "| 1. Add 'n' Leaves to Full-Time Employees        |\n"
         << "| 2. Convert an Intern to Full-Time Employee      |\n"
         << "| 3. Search Employee by ID                        |\n"
         << "| 4. Search Employee by Name                      |\n"
         << "| (-1 to Go Back)                                 |\n"
         << "--------------------------------------------------|\n";
}

int chooseMainMenuChoice()
{
    int sChoice;
    printMainMenu();
    sChoice = safeInput<int>("Your Choice : ");
    return sChoice;
} 

int chooseAddEmpOption()
{
    int sChoice;
    printAddEmployeeOption();
    sChoice = safeInput<int>("Your Choice : ");
    if(sChoice == ADD_RANDOM_EMPLOYEE)
    {
        return EmpRandDataGen::getRandomEmpType();
    }
    else if(sChoice == ADD_SPECIFIC_EMPLOYEE)
    {
        sChoice = safeInput<int>("Employee type : (1=FullTime,2=Contractor,3=Intern)\n");
        if(sChoice == EmployeeType::FULL_TIME || sChoice == EmployeeType::CONTRACT || sChoice == EmployeeType::INTERN)
        {
            // Valid choice, continue
        }
        else
        {
            cout << "Invalid add specific employee choice\n";
            return chooseAddEmpOption();
        }
    }
    else
    {
        cout << "Invalid add employee option type\n";
        return chooseAddEmpOption();
    }
    return sChoice;
}

int chooseXyzEmpSummaryOption()
{
    int sChoice;
    printXyzEmpSummaryMenu();
    sChoice = safeInput<int>("Your Choice : ");
    //todo
    return sChoice;
}

int chooseOthersMenuOption()
{
    int sChoice;
    printOthersMenu();
    sChoice = safeInput<int>("Your Choice : ");
    return sChoice;
}






