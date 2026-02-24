#include "XyzInternEmployee.H"


XyzInternEmployee :: XyzInternEmployee(string empNameParam,
                                        string empGenderParm, 
                                        EmployeeType empTypeParm, 
                                        string empIdParm, 
                                        EmployeeStatus empStatusParam,
                                        string DateOfBirthParm,
                                        string DateOfJoiningParm,
                                        string DateOfLeavingParm,
                                        HiringFromColleges HiringClgParm,
                                        HiringFromBranches HiringBranchParm)
:XyzEmployee(empNameParam
            ,empGenderParm
            ,empTypeParm
            ,empIdParm
            ,empStatusParam
            ,DateOfBirthParm
            ,DateOfJoiningParm
            ,DateOfLeavingParm)
,mHiringClg(HiringClgParm)
,mHiringBranch(HiringBranchParm)
{
    std::cout << "XyzIntern Employee Constructor\n";
}

XyzInternEmployee :: ~XyzInternEmployee
{

}

HiringFromColleges XyzInternEmployee::getCollege()
{
    return mHiringClg;
}

HiringFromBranches XyzInternEmployee::getBranch()
{
    return mHiringBranch;
}

void XyzInternEmployee::setBranch(HiringFromBranches branchParm)
{
    mHiringBranch = branchParm;
}

void XyzInternEmployee::setCollege(HiringFromColleges collegeParm)
{
    mHiringClg = collegeParm;
}

