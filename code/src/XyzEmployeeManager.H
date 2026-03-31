#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include "XyzEmployeeIF.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

#include "Edll.H"

using namespace std;

class XyzEmployeeManager
{
    private:

    Edll<XyzEmployeeIF*> * mActiveInactiveEmpDeque;
    Edll<XyzEmployeeIF*> * mResignedEmpDeque;
    int mEmpIdCounter;

    void pAddFullTimeEmployee();
    void pAddInternEmployee();
    void pAddContractEmployee();
    void pAddRandomMultipleEmployees();
    void printEmployeeDetails(XyzEmployeeIF* empParm);
    void printEmployeeSummary(XyzEmployeeIF* empParm);
    void printEmployeeTableRow(XyzEmployeeIF* empParm, bool typeSpecific = false);
    
    void printTableHeader(unsigned int empType = 0);
    void printTableHeaderForFullTimer();
    void printTableHeaderForContractEmp();
    void printTableHeaderForIntern();
    
    public:
    XyzEmployeeManager();
    ~XyzEmployeeManager();
    
    void processEmployees();
    void removeEmployee(string);
    Edll<XyzEmployeeIF*> * getActInactEmpDeque();
    Edll<XyzEmployeeIF*> * getResignedEmpDeque();


    void printEmpsInfo(unsigned int);
    void printEmpInfo(unsigned int);
    void printEmpInfo(string);
    void printEmpInfoByIdString(string);

    void convertInternToFulltimer(unsigned int);
    void addLeavesForFullTimers(unsigned int);
};

#endif