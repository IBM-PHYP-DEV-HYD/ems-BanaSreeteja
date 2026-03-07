#include "XyzInternEmployee.H"


XyzInternEmployee :: XyzInternEmployee(unsigned idParm):XyzEmployee(idParm, INTERN)

{
    std::cout << "XyzIntern Employee Constructor\n";

}

XyzInternEmployee :: ~XyzInternEmployee()
{

}

string XyzInternEmployee::getCollege()
{
    return mHiringClg;
}

string XyzInternEmployee::getBranch()
{
    return mHiringBranch;
}

void XyzInternEmployee::setBranch(string branchParm)
{
    mHiringBranch = branchParm;
}

void XyzInternEmployee::setCollege(string collegeParm)
{
    mHiringClg = collegeParm;
}

ostream & XyzInternEmployee::print(ostream & out) 
{

	XyzEmployee::print(out);
	if(RESIGNED == getEmployeeStatus())
    {
		return out;
    }
	out << "College Name\t\t: " << getCollege() << "\n";
	out << "Branch Name\t\t: " << getBranch() << "\n";
    
	return out;
}