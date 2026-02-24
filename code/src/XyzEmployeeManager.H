#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include "XyzEmployeeIF.H"
#include "Edll.H"

class XyzEmployeeManager
{
    private:

    Edll<XyzEmployeeIF*> mActiveInactiveEmpDeue;
    Edll<XyzEmployeeIF*> mResignedEmpDeque;
    void pAddFullTimeEmployee()
    void pAddInternEmployee();
    void pAddContractEmployee();

    public:
        XyzEmployeeManager();
        ~XyzEmployeeManager();



};

#endif