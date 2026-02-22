#ifndef XYZEMPLOYEEIMPL_H
#define XYZEMPLOYEEIMPL_H

class XyzEmployee :: public XyzEmployeeIF
{
    protected:

    std::string mEmployeeName;
    std::string mEmployeeGender;
    EmployeeType mEmployeeType;
    std::String mEmployeeId;
    EmployeeStatus mEmployeeStatus;
    std::string mDateOfBirth;
    std::string mDateOfJoining;
    std::string mDateOfLeaving;

    public:
    XyzEmployee();
    ~XyzEmployee();
    std::string getEmployeeName();
    std::string getEmployeeGender();
    std::string getEmployeeId();
    EmployeeType getEmployeeType();
    EmployeeStatus getEmployeeStatus();
    std::string getDOJ();
    std::string getDOB();
    std::string getDOL();

}

#endif