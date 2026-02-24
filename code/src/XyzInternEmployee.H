#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

class XyzInternEmployee :: public XyzEmployee
{

    protected:
        HiringFromColleges mHiringClg;
        HiringFromBranches mHiringBranch;


    public:

        XyzInternEmployee(string empNameParam,
                string empGenderParm, 
                EmployeeType empTypeParm, 
                string empIdParm, 
                EmployeeStatus empStatusParam,
                string DateOfBirthParm,
                string DateOfJoiningParm,
                string DateOfLeavingParm,
                HiringFromColleges HiringClgParm,
                HiringFromBranches HiringBranchParm);
                
        ~XyzInternEmployee();

};

#endif