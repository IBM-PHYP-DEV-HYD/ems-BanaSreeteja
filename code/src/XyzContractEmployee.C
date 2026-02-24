
#include "XyzContractEmployee.H"



XyzContractEmployee::XyzContractEmployee(string empNameParam,
                                        string empGenderParm, 
                                        EmployeeType empTypeParm, 
                                        string empIdParm, 
                                        EmployeeStatus empStatusParam,
                                        string DateOfBirthParm,
                                        string DateOfJoiningParm,
                                        string DateOfLeavingParm,
                                        ExternalAgency extAgencyParm)
:XyzEmployee(empNameParam
            ,empGenderParm
            ,empTypeParm
            ,empIdParm
            ,empStatusParam
            ,DateOfBirthParm
            ,DateOfJoiningParm
            ,DateOfLeavingParm)
,mExtAgency(extAgencyParm)
{
    std::cout << "XyzContractEmployee Constructor called\n";
}


XyzContractEmployee:: ~XyzContractEmployee()
{

}

ExternalAgency XyzContractEmployee:: ()
{

}
