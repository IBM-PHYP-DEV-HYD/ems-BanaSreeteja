#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>

#include <limits>
#include <random>


using namespace std;

#define EMP_TOTAL_LEAVES        22
#define NUM_NAMES               3


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
    ADD_EMPLOYEE       = 1,
    REMOVE_EMPLOYEE    = 2,
    PRINT_EMPLOYEE     = 3,
    OTHERS             = 4,
    EXIT               = -1
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

template <typename T>
T safeInput(const std::string& promptMsg);

void printMainMenu();
void printAddEmployeeOption();
void printXyzEmpSummaryMenu();
void printOthersMenu();

unsigned int chooseMainMenuChoice();
unsigned int chooseAddEmpOption();
unsigned int chooseXyzEmpSummaryOption();
unsigned int chooseOthersMenuOption();


using EmpRandDataGen
{

    int getRandomNumber(int startNumParm, int endNumParm);
    int getRandomEmpGender();
    int getRandomEmpType();
    string getRandomEmpName(unsigned int employeeGenderParm);




    string getRanomEmpAgency();
	string getRandomEmpCollege();
	string getRandomEmpBranch();




}


#endif