#include "XyzEmployee.H"

XyzEmployee::XyzEmployee(unsigned int idParm, unsigned int employeeTypeParm)
{
    std::cout << " XyzEmployee Constructor called \n";
    mEmployeeType = employeeTypeParm;
    
}


XyzEmployee::~XyzEmployee()
{
    std::cout << " XyzEmployee Destructor called \n";
}

string XyzEmployee::getEmployeeName()
{
    return mEmployeeName;
}

EmpGender XyzEmployee::getEmployeeGender()
{
    return mEmployeeGender;
}

string XyzEmployee::getEmployeeId()
{
    return mEmployeeId;
}

EmployeeType XyzEmployee::getEmployeeType()
{
    return mEmployeeType;
}

EmployeeStatus XyzEmployee::getEmployeeStatus()
{
    return mEmployeeStatus;
}

string XyzEmployee::getDOJ()
{
    return mDateOfJoining;
}

string XyzEmployee::getDOB()
{
    return mDateOfBirth;
}

string XyzEmployee::getDOL()
{
    return mDateOfLeaving;
}

unsigned int XyzEmployee::getTotalLeaves()
{
    return 0;
}

void XyzEmployee::setTotalLeaves(unsigned int totalLeavesParm)
{
    
}

unsigned int XyzEmployee::getAvailedLeaves()
{
    return 0;
}

void XyzEmployee::setAvailedLeaves(unsigned int availedLeavesParm)
{

}

string XyzEmployee::getAgencyName()
{
    return "";
}

void XyzEmployee::setAgencyName(string agencyNameParm)
{

}


string XyzEmployee::getCollegeName()
{
    return "";
}

string XyzEmployee::getBranchName()
{
    return "";
}

void XyzEmployee::setCollegeName(string clgNameParm)
{

}

void XyzEmployee::setBranchName(string BranchParm)
{

}

ostream& XyzEmployee::print(ostream &out)
{
    // prints common employee details 
    out << "XyzEmployee print function" << endl;

	out << "Name\t\t: " << mEmployeeName << endl;
	out << "ID\t\t: " << mEmployeeId << endl;

	if(mEmployeeType == FULL_TIME) out << "Type\t\t: " << "FULLTIMER" << endl;
	else if(mEmployeeType == CONTRACT) out << "Type\t\t: " << "CONTRACTOR" << endl;
	else if(mEmployeeType == INTERN) out << "Type\t\t: " << "INTERN" << endl;

	if(mEmployeeStatus == ACTIVE) out << "Status\t\t: ACTIVE" << endl;
	else if(mEmployeeStatus == INACTIVE) out << "Status\t\t: INACTIVE" << endl;
	else if(mEmployeeStatus == RESIGNED) out << "Status\t\t: RESIGNED" << endl;

	if(mEmployeeGender == MALE) out << "Gender\t\t: MALE" << endl;
	else if(mEmployeeGender == FEMALE) out << "Gender\t\t: FEMALE" << endl;

	out << "DOB\t\t: " << mDateOfBirth << endl;
	out << "DOJ\t\t: " << mDateOfJoining << endl;
	return out;
}