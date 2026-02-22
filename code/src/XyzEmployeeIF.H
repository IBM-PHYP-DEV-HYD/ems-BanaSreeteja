#ifndef XYZEMPLOYEEIF_H
#define XYZEMPLOYEEIF_H

#include "Utility.H"

class XyzEmployeeIF
{
    public:
    XyzEmployeeIF();
    ~XyzEmployeeIF();
    virtual std::string getEmployeeName() = 0;
    virtual std::string getEmployeeGender() = 0;
    virtual std::string getEmployeeId() = 0;
    virtual EmployeeType getEmployeeType() = 0;
    virtual EmployeeStatus getEmployeeStatus() = 0;
    virtual std::string getDOJ() = 0;
    virtual std::string getDOB() = 0;
    virtual std::string getDOL() = 0;

};


#endif

