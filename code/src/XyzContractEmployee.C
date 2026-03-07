
#include "XyzContractEmployee.H"



XyzContractEmployee::XyzContractEmployee(unsigned int idParm):XyzEmployee(idParm, CONTRACT)
{
    std::cout << "XyzContractEmployee Constructor called\n";
    //TODO: generate agency 
    //mExtAgency = 
}


ExternalAgency XyzContractEmployee::getExternalAgency()
{
    return mExtAgency;
}

void XyzContractEmployee::setExternalAgency(ExternalAgency externalAgencyParm)
{
    mExtAgency = externalAgencyParm;
}


ostream &  XyzContractEmployee::print(ostream & out)
{
    XyzEmployee::print(out);

    if(RESIGNED == getEmployeeStatus())
    {
        return out;
    }
    out << "Agency Name\t: " << getExternalAgency() << "\n";

    return out;
}

