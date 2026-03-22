
#include "XyzContractEmployee.H"
#include "RandomData.H"



XyzContractEmployee::XyzContractEmployee(unsigned int idParm):XyzEmployee(idParm, CONTRACT)
{
    // cout << "XyzContractEmployee Constructor called\n";
    mExtAgency = EmpRandDataGen::getRandomEmpAgency();
}

XyzContractEmployee::~XyzContractEmployee()
{
    cout << "XyzContractEmployee destructor called\n";
}

void XyzContractEmployee::setAgencyName(string agencyNameParm)
{
    mExtAgency = agencyNameParm;
}

string XyzContractEmployee::getAgencyName()
{
    return mExtAgency;
}


