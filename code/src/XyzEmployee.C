#include "XyzEmployee.H"
#include "RandomData.H"

XyzEmployee::XyzEmployee(unsigned int idParm, unsigned int employeeTypeParm)
{
    // cout << " XyzEmployee Constructor called \n";
    mEmployeeType = employeeTypeParm;

    mEmployeeGender = EmpRandDataGen::getRandomEmpGender();
    mEmployeeName = EmpRandDataGen::getRandomEmpName(mEmployeeGender);
    mEmployeeId = EmpRandDataGen::getRandomEmpId(idParm, employeeTypeParm);
    mDateOfBirth = EmpRandDataGen::getRandomEmpDob();
    mDateOfJoining = EmpRandDataGen::getRandomEmpDoJ();
    mEmployeeStatus = EmpRandDataGen::getRandomEmpStatus();
    // Calculate DoL based on employee type and DOJ
    mDateOfLeaving = EmpRandDataGen::getRandomEmpDoL(mDateOfJoining, mEmployeeType);
}


XyzEmployee::~XyzEmployee()
{
    cout << " XyzEmployee Destructor called \n";
}

string XyzEmployee::getEmployeeName()
{
    return mEmployeeName;
}

unsigned int XyzEmployee::getEmployeeGender()
{
    return mEmployeeGender;
}

string XyzEmployee::getEmployeeId()
{
    return mEmployeeId;
}

unsigned int XyzEmployee::getEmployeeType()
{
    return mEmployeeType;
}

unsigned int XyzEmployee::getEmployeeStatus()
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

unsigned int XyzEmployee::getTotalLeaves()
{
    return 0;
}

void XyzEmployee::setTotalLeaves(unsigned int totalLeavesParm)
{
    
}

unsigned int XyzEmployee::getAvailedLeaves()
{
    return 0;
}

void XyzEmployee::setAvailedLeaves(unsigned int availedLeavesParm)
{

}

string XyzEmployee::getAgencyName()
{
    return "";
}
string XyzEmployee::getCollegeName()
{
    return "";
}

string XyzEmployee::getBranchName()
{
    return "";
}
// Not applicable for base class
void XyzEmployee::setAgencyName(string agencyNameParm){}
void XyzEmployee::setCollegeName(string clgNameParm){}
void XyzEmployee::setBranchName(string BranchParm){}


