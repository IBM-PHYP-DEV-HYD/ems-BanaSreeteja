#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include "string.h"

class XyzEmployee :: public XyzEmployeeIF
{
    private:

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
    std::string getEmployeeName override;
    std::string getEmployeeGender override;
    std::string getEmployeeId override;
    EmployeeType getEmployeeType override;
    EmployeeStatus getEmployeeStatus override;
    std::string getDOJ override;
    std::string getDOB override;
    std::string getDOL override;

}

#endif