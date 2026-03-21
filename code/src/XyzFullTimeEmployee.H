#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include <string>
#include "XyzEmployee.H"

using namespace std;

class XyzFullTimeEmployee:public XyzEmployee
{
    private:
        int mLeavesAvailed;
        int mTotalLeaves;

    public:
    
    XyzFullTimeEmployee(unsigned int);

    ~XyzFullTimeEmployee();
    

    unsigned int getTotalLeaves();
    unsigned int getAvailedLeaves();
    void setTotalLeaves(unsigned int);
    void setAvailedLeaves(unsigned int);
    

};

#endif