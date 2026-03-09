#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

#include <string>
#include "XyzEmployeeIF.H"

using namespace std;

class XyzEmployee:public XyzEmployeeIF
{
    private:

    string mEmployeeName;  
    string mEmployeeId;
    string mDateOfBirth;
    string mDateOfJoining;
    string mDateOfLeaving;
    
    unsigned int mEmployeeGender;
    unsigned int mEmployeeType;
    unsigned int mEmployeeStatus;
    

    public:

    XyzEmployee(unsigned int, unsigned int);

    ~XyzEmployee();
    string getEmployeeName();
    string getEmployeeId();
    unsigned int getEmployeeGender();
    unsigned int getEmployeeType();
    unsigned int getEmployeeStatus();
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
	// virtual ostream & print(ostream &);
	// virtual ostream & print(ostream &, unsigned int);

};

#endif