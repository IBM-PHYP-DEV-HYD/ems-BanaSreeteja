
#include "XyzFullTimeEmployee.H"



XyzFullTimeEmployee::XyzFullTimeEmployee(string empNameParam,
                                        string empGenderParm, 
                                        string empTypeParm, 
                                        EmployeeType empTypeParm, 
                                        string empIdParm, 
                                        EmployeeStatus empStatusParam,
                                        string DateOfBirthParm,
                                        string DateOfJoiningParm,
                                        string DateOfLeavingParm,
                                        int leavesAvailedParm,
                                        int leavesLeftParm)
:XyzEmployee(empNameParam
            ,empGenderParm
            ,empTypeParm
            ,empIdParm
            ,empStatusParam
            ,DateOfBirthParm
            ,DateOfJoiningParm
            ,DateOfLeavingParm)
,mLeavesAvailed(leavesAvailedParm)
,mLeavesLeft(leavesLeftParm)

{
    std::cout << "XyzFullTimeEmployee constructor called \n";
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
    std::cout << "XyzFullTimeEmployee destructor called \n";
}

XyzFullTimeEmployee::getEmpLeavesAvailed()
{
    return mLeavesAvailed;
}

XyzFullTimeEmployee::getEmpLeavesLeft()
{
    return mLeavesLeft;
}

