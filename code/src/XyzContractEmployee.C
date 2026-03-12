
#include "XyzContractEmployee.H"



XyzContractEmployee::XyzContractEmployee(unsigned int idParm):XyzEmployee(idParm, CONTRACT)
{
    cout << "XyzContractEmployee Constructor called\n";
    mExtAgency = static_cast<ExternalAgency>(EmpRandDataGen::getRandomNumber(0, NUM_OF_AGENCIES-1));
}


ExternalAgency XyzContractEmployee::getExternalAgency()
{
    return mExtAgency;
}

void XyzContractEmployee::setExternalAgency(ExternalAgency externalAgencyParm)
{
    mExtAgency = externalAgencyParm;
}


// ostream &  XyzContractEmployee::print(ostream & out)
// {
//     XyzEmployee::print(out);

//     if(RESIGNED == getEmployeeStatus())
//     {
//         return out;
//     }
//     out << "Agency Name\t: " << getExternalAgency() << "\n";

//     return out;
// }

