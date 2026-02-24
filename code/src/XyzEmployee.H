#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include "string.h"

class XyzEmployee :: public XyzEmployeeIF
{
    protected:

    std::string mEmployeeName;
    std::string mEmployeeGender;
    EmployeeType mEmployeeType;
    std::String mEmployeeId;
    EmployeeStatus mEmployeeStatus;
    std::string mDateOfBirth;
    std::string mDateOfJoining;
    std::string mDateOfLeaving;

    public:
    XyzEmployee(string empNameParam,
                string empGenderParm, 
                string empTypeParm, 
                EmployeeType empTypeParm, 
                string empIdParm, 
                EmployeeStatus empStatusParam,
                string DateOfBirthParm,
                string DateOfJoiningParm,
                string DateOfLeavingParm);
                
    ~XyzEmployee();
    std::string getEmployeeName();
    std::string getEmployeeGender();
    std::string getEmployeeId();
    EmployeeType getEmployeeType();
    EmployeeStatus getEmployeeStatus();
    std::string getDOJ();
    std::string getDOB();
    std::string getDOL();

}

#endif