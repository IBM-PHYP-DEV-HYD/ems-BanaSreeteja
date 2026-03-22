#ifndef XYZCONTRACTEMPLOYEE_H
#define XYZCONTRACTEMPLOYEE_H

#include "Utility.H"
#include "XyzEmployee.H"
using namespace std;

class XyzContractEmployee:public XyzEmployee
{
    private:

        string mExtAgency;
        
        
    public:

        XyzContractEmployee(unsigned int);
        ~XyzContractEmployee();
        
        void setAgencyName(string agencyNameParm);
        string getAgencyName();
        
        
};


#endif