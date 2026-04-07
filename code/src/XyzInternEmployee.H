#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

#include <string>
#include "XyzEmployee.H"

using namespace std;

class XyzInternEmployee:public XyzEmployee
{

    private:
        string mHiringClg;
        string mHiringBranch;


    public:

        XyzInternEmployee(unsigned int);
                
        ~XyzInternEmployee();

        string getCollegeName();
        string getBranchName();
        void setCollegeName(string collegeParm);
        void setBranchName(string branchParm);


        
};

#endif