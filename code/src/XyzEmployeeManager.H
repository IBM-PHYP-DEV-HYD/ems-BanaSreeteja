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

    Edll<XyzEmployeeIF*> * mActiveInactiveEmpDeue;
    Edll<XyzEmployeeIF*> * mResignedEmpDeque;
    int mEmpIdCounter;

    void pAddFullTimeEmployee();
    void pAddInternEmployee();
    void pAddContractEmployee();

    public:
        XyzEmployeeManager();
        ~XyzEmployeeManager();

        void processEmployees();


};

#endif