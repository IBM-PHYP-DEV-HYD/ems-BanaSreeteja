
#include "XyzContractEmployee.H"



XyzContractEmployee::XyzContractEmployee(unsigned int idParm):XyzEmployee(idParm, CONTRACT)
{
    // cout << "XyzContractEmployee Constructor called\n";
    mExtAgency = EmpRandDataGen::getRanomEmpAgency();
}


void XyzContractEmployee::setAgencyName(string agencyNameParm)
{
    mExtAgency = agencyNameParm;
}

string XyzContractEmployee::getAgencyName()
{
    return mExtAgency;
}


