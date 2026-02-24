#include "XyzEmployee.H"

XyzEmployee::XyzEmployee(string empNameParam,
                        string empGenderParm, 
                        string empTypeParm,  
                        string empIdParm, 
                        EmployeeStatus empStatusParam,
                        string DateOfBirthParm,
                        string DateOfJoiningParm,
                        string DateOfLeavingParm)
:mEmployeeName(empNameParam)
,mEmployeeGender(empGenderParm)
,mEmployeeType(empTypeParm)
,mEmployeeId(empIdParm)
,mEmployeeStatus(empStatusParam)
,mDateOfBirth(DateOfBirthParm)
,mDateOfJoining(DateOfJoiningParm)
,mDateOfLeaving(DateOfLeavingParm)
{
    std::cout << " XyzEmployee Constructor called \n";
}


XyzEmployee::~XyzEmployee()
{
    std::cout << " XyzEmployee Destructor called \n";
}

string XyzEmployee::getEmployeeName()
{
    return mEmployeeName;
}

string XyzEmployee::getEmployeeGender()
{
    return mEmployeeGender;
}

string XyzEmployee::getEmployeeId()
{
    return mEmployeeId;
}

EmployeeType XyzEmployee::getEmployeeType()
{
    return mEmployeeType;
}

EmployeeStatus XyzEmployee::getEmployeeStatus()
{
    return mEmployeeStatus;
}

string XyzEmployee::getDOJ()
{
    return mDateOfJoining;
}

string XyzEmployee::getDOB()
{
    return mDateOfBirth;
}

string XyzEmployee::getDOL()
{
    return mDateOfLeaving;
}