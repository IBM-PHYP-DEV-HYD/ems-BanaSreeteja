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
    void printEmployeeTableRow(XyzEmployeeIF* empParm);
    void printTableHeader();
    
    public:
    XyzEmployeeManager();
    ~XyzEmployeeManager();
    
    void processEmployees();
    void removeEmployee(unsigned int);
    Edll<XyzEmployeeIF*> * getActInactEmpDeque();
    Edll<XyzEmployeeIF*> * getResignedEmpDeque();


    void printEmpsInfo(unsigned int);
    void printEmpInfo(unsigned int);
    void printEmpInfo(string);

    void convertInternToFulltimer(unsigned int);
    void addLeavesForFullTimers(unsigned int);
};

#endif