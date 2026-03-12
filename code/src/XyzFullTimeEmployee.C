
#include "XyzFullTimeEmployee.H"



XyzFullTimeEmployee::XyzFullTimeEmployee(unsigned int idParm):XyzEmployee(idParm, FULL_TIME)
{
    cout << "XyzFullTimeEmployee constructor \n";
    mTotalLeaves = EMP_TOTAL_LEAVES;
    //generate random leaves availed
    mLeavesAvailed = EmpRandDataGen::getRandomNumber(0, EMP_TOTAL_LEAVES);
}

XyzFullTimeEmployee::~XyzFullTimeEmployee()
{
    cout << "XyzFullTimeEmployee destructor called \n";
}

unsigned int XyzFullTimeEmployee::getAvailedLeaves()
{
    return mLeavesAvailed;
}

unsigned int XyzFullTimeEmployee::getTotalLeaves()
{
    return mTotalLeaves;
}

void XyzFullTimeEmployee:: setTotalLeaves(unsigned int totalLeavesParm)
{
    mTotalLeaves = totalLeavesParm;
}

void XyzFullTimeEmployee:: setAvailedLeaves(unsigned int leavesAvailedParm)
{
    mLeavesAvailed = leavesAvailedParm;
}

// ostream& XyzFullTimeEmployee::print(ostream &out)
// {

//     XyzEmployee::print(out);

//     if(RESIGNED == getEmployeeStatus())
//     {
//         return out;
//     }

//     out << "Total Leaves\t: " << getTotalLeaves() << "\n";
//     out << "Availed Leaves\t: " << getAvailedLeaves() << "\n";

//     return out;
// }

// ostream & XyzFullTimeEmployee::print(ostream &)(ostream & out, unsigned int)
// {


// }
