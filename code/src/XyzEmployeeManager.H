#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include "XyzEmployeeIF.H"
#include "Edll.H"

class XyzEmployeeManager
{
    private:

    Edll<XyzEmployeeIF*> mActiveInactiveEmpDeue;
    Edll<XyzEmployeeIF*> mResignedEmpDeque;

    public:
        XyzEmployeeManager();
        ~XyzEmployeeManager();



};

#endif