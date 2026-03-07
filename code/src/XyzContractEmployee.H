#ifndef XYZCONTRACTEMPLOYEE_H
#define XYZCONTRACTEMPLOYEE_H

#include "Utility.H"
#include "XyzEmployee.H"
using namespace std;

class XyzContractEmployee:public XyzEmployee
{
    private:

        ExternalAgency mExtAgency;
        
        
    public:

        XyzContractEmployee(unsigned int);
        
        ostream & print(ostream &);
		// ostream & print(ostream &, unsigned int);

        ExternalAgency getExternalAgency();
        void setExternalAgency(ExternalAgency externalAgencyParm);
        
};


#endif