#ifndef XYZCONTRACTEMPLOYEE_H
#define XYZCONTRACTEMPLOYEE_H

#include "Utility.H"

class XyzContractEmployee :: public XyzEmployee
{
    private:

        ExternalAgency mExtAgency;
        
        
    public:

        XyzContractEmployee(string empNameParam,
                            string empGenderParm, 
                            EmployeeType empTypeParm, 
                            string empIdParm, 
                            EmployeeStatus empStatusParam,
                            string DateOfBirthParm,
                            string DateOfJoiningParm,
                            string DateOfLeavingParm,
                            ExternalAgency extAgencyParm);

        ~XyzContractEmployee();

        ExternalAgency getEmpExternalAgency();
        void getEmpExternalAgency(ExternalAgency externalAgencyParm);
        
};


#endif