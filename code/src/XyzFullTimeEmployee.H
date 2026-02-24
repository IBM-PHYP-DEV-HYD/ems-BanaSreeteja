#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

class XyzFullTimeEmployee :: public XyzEmployee
{
    protected:
        int mLeavesAvailed;
        int mLeavesLeft;

    public:
    
    XyzFullTimeEmployee(string empNameParam,
                    string empGenderParm, 
                    EmployeeType empTypeParm, 
                    string empIdParm, 
                    EmployeeStatus empStatusParam,
                    string DateOfBirthParm,
                    string DateOfJoiningParm,
                    string DateOfLeavingParm,
                    int leavesAvailedParm,
                    int leavesLeftParm);

    ~XyzFullTimeEmployee();
    

    void setLeavesDetails(int leavesAvailedParm);
    int getEmpLeavesAvailed();
    int getEmpLeavesLeft();
    

};

#endif