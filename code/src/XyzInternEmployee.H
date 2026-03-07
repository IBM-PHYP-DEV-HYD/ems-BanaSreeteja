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

        string getCollege();
        string getBranch();
        

        void setCollege(string collegeParm);
        void setBranch(string branchParm);


        ostream & print(ostream &);
		// ostream & print(ostream &, unsigned int);
        
};

#endif