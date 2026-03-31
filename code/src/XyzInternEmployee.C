#include "XyzInternEmployee.H"
#include "RandomData.H"


XyzInternEmployee :: XyzInternEmployee(unsigned int idParm):XyzEmployee(idParm, INTERN)

{
    // cout << "XyzIntern Employee Constructor\n";
    mHiringClg = EmpRandDataGen::getRandomEmpCollege();
    mHiringBranch = EmpRandDataGen::getRandomEmpBranch();
}

XyzInternEmployee :: ~XyzInternEmployee()
{
    // cout << "XyzIntern Employee Destructor\n";
}

string XyzInternEmployee::getCollegeName()
{
    return mHiringClg;
}

string XyzInternEmployee::getBranchName()
{
    return mHiringBranch;
}

void XyzInternEmployee::setBranchName(string branchParm)
{
    mHiringBranch = branchParm;
}

void XyzInternEmployee::setCollegeName(string collegeParm)
{
    mHiringClg = collegeParm;
}
