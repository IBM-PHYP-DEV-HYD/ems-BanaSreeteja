#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include <string>
#include "XyzEmployeeIF.H"

using namespace std;

class XyzEmployee:public XyzEmployeeIF
{
    private:

    string mEmployeeName;  
    EmpGender mEmployeeGender;
    string mEmployeeId;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;

    EmployeeType mEmployeeType;
    EmployeeStatus mEmployeeStatus;
    

    public:

    XyzEmployee(unsigned int, unsigned int);

    ~XyzEmployee();
    string getEmployeeName();
    EmpGender getEmployeeGender();
    string getEmployeeId();
    EmployeeType getEmployeeType();
    EmployeeStatus getEmployeeStatus();
    string getDOJ();
    string getDOB();
    string getDOL();

    virtual unsigned int getTotalLeaves();
	virtual void setTotalLeaves(unsigned int);
	virtual unsigned int getAvailedLeaves();
	virtual void setAvailedLeaves(unsigned int);

	virtual string getAgencyName();
	virtual void setAgencyName(string);
	
	virtual string getCollegeName();
	virtual string getBranchName();
	virtual void setCollegeName(string);
	virtual void setBranchName(string);
	virtual ostream & print(ostream &);
	// virtual ostream & print(ostream &, unsigned int);

};

#endif