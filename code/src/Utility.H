#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

#include <limits>
#include <random>


using namespace std;

#define NUM_NAMES               7
#define NUM_OF_AGENCIES         3
#define NUM_OF_COLLEGES         7
#define NUM_OF_BRANCHES         2
#define CURRENT_YEAR            2026


enum EmployeeType
{
    TYPE_UNDEFINED     = 0,
    FULL_TIME          = 1,
    CONTRACT           = 2,
    INTERN             = 3
};

enum EmployeeStatus
{
    STATUS_UNDEFINED   = 0,
    ACTIVE             = 1,
    INACTIVE           = 2,
    RESIGNED           = 3
};

enum MainMenu
{
    ADD_EMPLOYEE                    = 1,
    ADD_MULTIPLE_RANDOM_EMPLOYEES   = 2,
    REMOVE_EMPLOYEE                 = 3,
    PRINT_EMPLOYEE                  = 4,
    OTHERS                          = 5,
    EXIT                            = -1
};

enum HiringFromColleges
{
    IIT_DELHI                  = 0,
    IIT_MUMBAI                 = 1,
    IIT_HYDERABAD              = 2,
    IIT_KANPUR                 = 3,
    NIT_WARANGAL               = 4,
    NIT_TIRUCHI                = 5,
    IIIT_HYDERABAD             = 6,
    COLLEGE_UNDEFINED          = 7
};

enum HiringFromBranches
{
    CSE               = 0,
    CSIT              = 1,
    ECE               = 2,
    UNDEFINED_BRANCH  = 3
};

enum ExternalAgency
{
    AVENGERS                   = 0,
    JUSTICE_LEAUGE             = 1,
    X_MEN                      = 2,
    AGENCY_UNDEFINED           = 3,
};

enum AddEmployeeChoice
{
    ADD_RANDOM_EMPLOYEE          = 1,
    ADD_SPECIFIC_EMPLOYEE        = 2,
};

enum EmpGender 
{
	MALE=1,
	FEMALE,
};


enum EmployeeDetailsMenuChoice
{
    AllEmployees    = 1,
    ByType          = 2,
    ByGender        = 3,
    ByStatus        = 4,
    ByID            = 5,

};

enum OtherMenuChoice
{
    ADD_LEAVES        = 1,
    CONVERT_INTERN    = 2,
    SEARCH_BY_ID       = 3,
    SEARCH_BY_NAME     = 4,

};

enum Leaves
{
    MINIMUM_LEAVES      = 0,
    EMP_TOTAL_LEAVES    = 22,
    INVALID_LEAVES 
};

template <typename T>
T safeInput(const string& promptMsg)
{
    T value;
    bool isValid = false;
    while (!isValid)
    {
        cout << promptMsg;
        cin >> value;
        if (!cin.fail())
        {
            isValid = true;
        }
        else
        {
            cout << "Invalid input! Try again." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void printMainMenu();
void printAddEmployeeOption();
void printXyzEmpSummaryMenu();
void printOthersMenu();

int chooseMainMenuChoice();
int chooseAddEmpOption();
int chooseXyzEmpSummaryOption();
int chooseOthersMenuOption();


namespace EmpRandDataGen
{

    int getRandomNumber(int startNumParm, int endNumParm);
    int getRandomEmpGender();
    int getRandomEmpType();
    int getRandomEmpStatus();

    string getRandomEmpDob();
    string getRandomEmpDoJ();
    string getRandomEmpDoL();

    
    string getRandomEmpName(unsigned int employeeGenderParm);
    string getRandomEmpId(unsigned int idParm, int empTypeParm);


    string getRanomEmpAgency();
	string getRandomEmpCollege();
	string getRandomEmpBranch();



}

#endif