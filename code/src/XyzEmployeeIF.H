#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "Utility.H"

// Interface : uses pure virtual functions , no attributes

class XyzEmployeeIF
{
    public:
    virtual string getEmployeeName() = 0;
    virtual EmpGender getEmployeeGender() = 0;
    virtual string getEmployeeId() = 0;
    virtual EmployeeType getEmployeeType() = 0;
    virtual EmployeeStatus getEmployeeStatus() = 0;
    virtual string getDOJ() = 0;
    virtual string getDOB() = 0;
    virtual string getDOL() = 0;

    virtual unsigned int getTotalLeaves() = 0;
	virtual void setTotalLeaves(unsigned int) = 0;
	virtual unsigned int getAvailedLeaves() = 0;
	virtual void setAvailedLeaves(unsigned int) = 0;

	virtual string getAgencyName() = 0;
	virtual void setAgencyName(string) = 0;

	virtual string getCollegeName() = 0;
	virtual string getBranchName() = 0;
	virtual void setCollegeName(string) = 0;
	virtual void setBranchName(string) = 0;

	virtual ostream & print(ostream &) = 0;
    
};


#endif

