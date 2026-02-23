#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

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


void printMainMenu();
void printEmployeeOption();


#endif