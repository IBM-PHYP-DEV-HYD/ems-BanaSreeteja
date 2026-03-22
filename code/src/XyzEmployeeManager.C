
#include "XyzEmployeeManager.H"
#include "RandomData.H"
#include <algorithm>
#include <iomanip>

// Column widths for table formatting
namespace {
    const int NameWidth = 20;
    const int IdWidth = 10;
    const int GenderWidth = 8;
    const int DobWidth = 12;
    const int DojWidth = 12;
    const int DolWidth = 12;
    const int TypeWidth = 12;
    const int StatusWidth = 10;
    const int CollegeWidth = 16;
    const int BranchWidth = 10;
    const int LeavesAvailedWidth = 16;
    const int TotalLeavesWidth = 16;
    const int AgencyWidth = 14;
}

XyzEmployeeManager::XyzEmployeeManager() : mEmpIdCounter(1)
{
    cout << "XyzEmployeeManager constructor" << endl;
    mActiveInactiveEmpDeque = new Edll<XyzEmployeeIF*>();
    mResignedEmpDeque = new Edll<XyzEmployeeIF*>();
}


XyzEmployeeManager::~XyzEmployeeManager()
{
    cout << "XyzEmployeeManager destructor" << endl;
    
    // Delete all employee objects in active/inactive deque
    for (size_t index = 0; index < mActiveInactiveEmpDeque->size(); index++)
    {
        delete (*mActiveInactiveEmpDeque)[index];
    }

    // Delete all employee objects in resigned deque
    for (size_t index = 0; index < mResignedEmpDeque->size(); index++)
    {
        delete (*mResignedEmpDeque)[index];
    }
    
    delete mActiveInactiveEmpDeque;
    delete mResignedEmpDeque;
}

void XyzEmployeeManager::pAddFullTimeEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzFullTimeEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeque->pushBack(sNewEmp);
    }

    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;
    
    // Print employee summary after adding
    printEmployeeSummary(sNewEmp);

}

void XyzEmployeeManager::pAddContractEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzContractEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeque->pushBack(sNewEmp);
    }
    
    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;
    
    // Print employee summary after adding
    printEmployeeSummary(sNewEmp);
}

void XyzEmployeeManager::pAddInternEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzInternEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeque->pushBack(sNewEmp);
    }
    
    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;
    
    // Print employee summary after adding
    printEmployeeSummary(sNewEmp);

}


void XyzEmployeeManager::processEmployees()
{
    bool sRun = true;
    while(sRun)
    {
        int sChoice = chooseMainMenuChoice();
        switch(sChoice)
        {
            case MainMenu::ADD_EMPLOYEE:
            {
                unsigned int sEmpChoice = chooseAddEmpOption();
                switch(sEmpChoice)
                {
                    case EmployeeType::FULL_TIME:
                    {
                        // add full time employee
                        pAddFullTimeEmployee();
                        break;
                    }

                    case EmployeeType::CONTRACT:
                    {
                        // add contract employee
                        pAddContractEmployee();
                        break;
                    }

                    case EmployeeType::INTERN:
                    {
                        // add intern 
                        pAddInternEmployee();
                        break;
                    }

                    default:
                    break;
                }
                break;
            }
            
            case MainMenu::ADD_MULTIPLE_RANDOM_EMPLOYEES:
            {
                pAddRandomMultipleEmployees();
                break;
            }

            case MainMenu::REMOVE_EMPLOYEE:
            {
                unsigned int sEmployeeID;
                sEmployeeID = safeInput<unsigned int>("Employee ID: ");
                removeEmployee(sEmployeeID);
                break;
            }

            case MainMenu::PRINT_EMPLOYEE:
            {
                unsigned int sEmpChoice = chooseXyzEmpSummaryOption();
                if(sEmpChoice == EmployeeDetailsMenuChoice::ByID)
                {
                    // print employee details as per employee ID
                    unsigned int sEmployeeID = safeInput<unsigned int>("Employee ID: ");
                    printEmpInfo(sEmployeeID);
                }
                else if(sEmpChoice == EmployeeDetailsMenuChoice::AllEmployees)
                {
                    // print all employee details
                    printEmpsInfo(AllEmployees);
                }
                else if(sEmpChoice == EmployeeDetailsMenuChoice::ByGender)
                {
                    // print employee details with other filters
                    printEmpsInfo(sEmpChoice);
                }
                else if(sEmpChoice == EmployeeDetailsMenuChoice::ByStatus)
                {
                    // print employee details with other filters
                    printEmpsInfo(sEmpChoice);
                }
                else if(sEmpChoice == EmployeeDetailsMenuChoice::ByType)
                {
                    // print employee details with other filters
                    printEmpsInfo(sEmpChoice);
                }


                break;
            }

            case MainMenu::OTHERS:
            {
                unsigned int sChoice = chooseOthersMenuOption();
                if(sChoice == ADD_LEAVES)
                {
                    unsigned int sEmployeeID = safeInput<unsigned int>("Enter Employee ID: ");
                    addLeavesForFullTimers(sEmployeeID);
                }
                else if (sChoice == CONVERT_INTERN)
                {
                    unsigned int sEmployeeID = safeInput<unsigned int>("Enter Employee ID: ");
                    convertInternToFulltimer(sEmployeeID);
                }
                else if (sChoice == SEARCH_BY_ID)
                {
                    unsigned int sEmployeeID = safeInput<unsigned int>("Enter Employee ID: ");
                    printEmpInfo(sEmployeeID);
                }
                else if (sChoice == SEARCH_BY_NAME)
                {
                    string sEmployeeName = safeInput<string>("Enter Employee Name: ");
                    printEmpInfo(sEmployeeName);
                }
                else
                {
                    cout << "Invalid choice! Try again. \n";

                }
                break;
            }

            case MainMenu::EXIT:
            {
                sRun = false;
                break;
            }

            default:
            {
                cout << "Invalid choice! Try again. \n";
                break;
            }
        }
    }

}

Edll<XyzEmployeeIF*> * XyzEmployeeManager::getActInactEmpDeque()
{
    return mActiveInactiveEmpDeque;
}

Edll<XyzEmployeeIF*> * XyzEmployeeManager::getResignedEmpDeque()
{
    return mResignedEmpDeque;
}

void XyzEmployeeManager::removeEmployee(unsigned int idParm)
{
    // Format ID as 4-digit with leading zeros (e.g., 1 -> "0001")
    string sIdStr = to_string(idParm);
    while(sIdStr.length() < 4)
    {
        sIdStr = "0" + sIdStr;
    }
    string sSearchId = "Xyz" + sIdStr;
    bool sFound = false;
    
    // Search in active/inactive employees
    for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
    {
        string sEmployeeId = (*mActiveInactiveEmpDeque)[i]->getEmployeeId();
        // Extract numeric part from employee ID (e.g., "Xyz0123F" -> "Xyz0123")
        size_t sTypePos = sEmployeeId.find_last_of("FCI");
        string sIdWithoutType = (sTypePos != string::npos) ? sEmployeeId.substr(0, sTypePos) : sEmployeeId;
        
        if(sIdWithoutType == sSearchId)
        {
            XyzEmployeeIF* sEmp = (*mActiveInactiveEmpDeque)[i];
            
            // Move to resigned deque
            mResignedEmpDeque->pushBack(sEmp);
            mActiveInactiveEmpDeque->removeAtMiddle(i);
            
            cout << "Employee " << sEmployeeId << " has been removed and moved to resigned list.\n";
            sFound = true;
            break;
        }
    }
    if(!sFound)
    {
        cout << "Employee with ID " << idParm << " not found in active/inactive list!\n";
    }
}

void XyzEmployeeManager::convertInternToFulltimer(unsigned int idParm)
{
    // Format ID as 4-digit with leading zeros
    string sIdStr = to_string(idParm);
    while(sIdStr.length() < 4)
    {
        sIdStr = "0" + sIdStr;
    }
    string sSearchId = "Xyz" + sIdStr + "I";
    bool sFound = false;
    
    // Search for intern in active/inactive employees
    for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
    {
        XyzEmployeeIF* sEmp = (*mActiveInactiveEmpDeque)[i];
        
        if(sEmp->getEmployeeId() == sSearchId && sEmp->getEmployeeType() == INTERN)
        {
            string sName = sEmp->getEmployeeName();
            
            cout << "Converting Intern " << sName << " (ID: " << sSearchId << ") to Full-Time Employee...\n";
            
            // Create new full-time employee
            XyzEmployeeIF* sNewFullTimer = new XyzFullTimeEmployee(mEmpIdCounter);
            mEmpIdCounter++;
            
            // Remove intern 
            mActiveInactiveEmpDeque->removeAtMiddle(i);
            delete sEmp;
            
            // Add new full-timer
            mActiveInactiveEmpDeque->pushBack(sNewFullTimer);
            
            cout << "Conversion successful! New Full-Time Employee ID: " << sNewFullTimer->getEmployeeId() << "\n";
            sFound = true;
            break;
        }
    }
    
    if(!sFound)
    {
        cout << "Intern with ID " << idParm << " not found or not an intern!\n";
    }
}

void XyzEmployeeManager::pAddRandomMultipleEmployees()
{
    int sRandomEmployeeCount = safeInput<int>("Random Employee count\n");

    for(int index = 1; index <= sRandomEmployeeCount ; index++)
    {
        unsigned int sEmpType = EmpRandDataGen::getRandomEmpType();
        if(sEmpType == FULL_TIME)
        {
            // add full time employee
            pAddFullTimeEmployee();
        }
        else if(sEmpType == CONTRACT)
        {
            // add contract employee
            pAddContractEmployee();
        }
        else if(sEmpType == INTERN)
        {
            // add intern 
            pAddInternEmployee();
        }
    }
}


void XyzEmployeeManager::addLeavesForFullTimers(unsigned int idParm)
{
    // Format ID as 4-digit with leading zeros
    string sIdStr = to_string(idParm);
    while(sIdStr.length() < 4)
    {
        sIdStr = "0" + sIdStr;
    }
    string sSearchId = "Xyz" + sIdStr + "F";
    bool sFound = false;
    
    // Search for full-time employee
    for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
    {
        XyzEmployeeIF* sEmp = (*mActiveInactiveEmpDeque)[i];
        
        if(sEmp->getEmployeeId() == sSearchId && sEmp->getEmployeeType() == FULL_TIME)
        {
            unsigned int sLeavesToAdd = safeInput<unsigned int>("Enter number of leaves to add: ");
            unsigned int sCurrentTotal = sEmp->getTotalLeaves();
            unsigned int sNewTotal = sCurrentTotal + sLeavesToAdd;
            
            sEmp->setTotalLeaves(sNewTotal);
            
            cout << "Added " << sLeavesToAdd << " leaves to employee " << sEmp->getEmployeeName() << "\n";
            cout << "Previous Total: " << sCurrentTotal << ", New Total: " << sNewTotal << "\n";
            
            sFound = true;
            break;
        }
    }
    
    if(!sFound)
    {
        cout << "Full-Time Employee with ID " << idParm << " not found!\n";
    }
}

void XyzEmployeeManager::printTableHeader()
{
    cout << left;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << setw(NameWidth)           << "Name"
         << "| " << setw(IdWidth)             << "ID"
         << "| " << setw(GenderWidth)         << "Gender"
         << "| " << setw(DobWidth)            << "DOB"
         << "| " << setw(DojWidth)            << "DOJ"
         << "| " << setw(DolWidth)            << "DOL"
         << "| " << setw(TypeWidth)           << "Type"
         << "| " << setw(StatusWidth)         << "Status"
         << "| " << setw(CollegeWidth)        << "College"
         << "| " << setw(BranchWidth)         << "Branch"
         << "| " << setw(LeavesAvailedWidth)  << "Leaves Availed"
         << "| " << setw(TotalLeavesWidth)    << "Total Leaves"
         << "| " << setw(AgencyWidth)         << "Agency"
         << "|\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void XyzEmployeeManager:: printEmpsInfo(unsigned int filterType)
{
    if(filterType == AllEmployees)
    {
        cout << "\n===== ALL EMPLOYEES SUMMARY (Active/Inactive Only) =====\n";
        printTableHeader();
        
        for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
        {
            printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
        }
        
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    else if(filterType == ByType)
    {
        unsigned int sTypeChoice = safeInput<unsigned int>("Enter Type (1=FullTime, 2=Contractor, 3=Intern): ");
        
        cout << "\n===== EMPLOYEES BY TYPE =====\n";
        printTableHeader();
        
        for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
        {
            if((*mActiveInactiveEmpDeque)[i]->getEmployeeType() == sTypeChoice)
            {
                printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
            }
        }
        
        for(size_t i = 0; i < mResignedEmpDeque->size(); i++)
        {
            if((*mResignedEmpDeque)[i]->getEmployeeType() == sTypeChoice)
            {
                printEmployeeTableRow((*mResignedEmpDeque)[i]);
            }
        }
        
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    else if(filterType == ByGender)
    {
        unsigned int sGenderChoice = safeInput<unsigned int>("Enter Gender (1=Male, 2=Female): ");
        
        cout << "\n===== EMPLOYEES BY GENDER =====\n";
        printTableHeader();
        
        for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
        {
            if((*mActiveInactiveEmpDeque)[i]->getEmployeeGender() == sGenderChoice)
            {
                printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
            }
        }
        
        for(size_t i = 0; i < mResignedEmpDeque->size(); i++)
        {
            if((*mResignedEmpDeque)[i]->getEmployeeGender() == sGenderChoice)
            {
                printEmployeeTableRow((*mResignedEmpDeque)[i]);
            }
        }
        
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    else if(filterType == ByStatus)
    {
        unsigned int sStatusChoice = safeInput<unsigned int>("Enter Status (1=Active, 2=Inactive, 3=Resigned): ");
        
        cout << "\n===== EMPLOYEES BY STATUS =====\n";
        printTableHeader();
        
        if(sStatusChoice == RESIGNED)
        {
            for(size_t i = 0; i < mResignedEmpDeque->size(); i++)
            {
                printEmployeeTableRow((*mResignedEmpDeque)[i]);
            }
        }
        else
        {
            for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
            {
                if((*mActiveInactiveEmpDeque)[i]->getEmployeeStatus() == sStatusChoice)
                {
                    printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
                }
            }
        }
        
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
}

void XyzEmployeeManager:: printEmpInfo(unsigned int idParm)
{
    // Format ID as 4-digit with leading zeros
    string sIdStr = to_string(idParm);
    while(sIdStr.length() < 4)
    {
        sIdStr = "0" + sIdStr;
    }
    string sSearchId = "Xyz" + sIdStr;
    bool sFound = false;
    
    // Search in active/inactive employees
    for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
    {
        if((*mActiveInactiveEmpDeque)[i]->getEmployeeId().find(sSearchId) != string::npos)
        {
            printTableHeader();
            printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            sFound = true;
            break;
        }
    }
    
    // Search in resigned employees
    if(!sFound)
    {
        for(size_t i = 0; i < mResignedEmpDeque->size(); i++)
        {
            if((*mResignedEmpDeque)[i]->getEmployeeId().find(sSearchId) != string::npos)
            {
                printTableHeader();
                printEmployeeTableRow((*mResignedEmpDeque)[i]);
                cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                sFound = true;
                break;
            }
        }
    }
    
    if(!sFound)
    {
        cout << "Employee with ID " << idParm << " not found!\n";
    }
}

void XyzEmployeeManager:: printEmpInfo(string nameParm)
{
    bool sFound = false;
    bool sHeaderPrinted = false;
    
    cout << "\n===== SEARCH RESULTS FOR: " << nameParm << " =====\n";
    
    // Search in active/inactive employees
    for(size_t i = 0; i < mActiveInactiveEmpDeque->size(); i++)
    {
        string sEmpName = (*mActiveInactiveEmpDeque)[i]->getEmployeeName();
        // Convert to lowercase for case-insensitive search
        transform(sEmpName.begin(), sEmpName.end(), sEmpName.begin(), ::tolower);
        string sSearchName = nameParm;
        transform(sSearchName.begin(), sSearchName.end(), sSearchName.begin(), ::tolower);
        
        if(sEmpName.find(sSearchName) != string::npos)
        {
            if(!sHeaderPrinted)
            {
                printTableHeader();
                sHeaderPrinted = true;
            }
            printEmployeeTableRow((*mActiveInactiveEmpDeque)[i]);
            sFound = true;
        }
    }
    
    // Search in resigned employees
    for(size_t i = 0; i < mResignedEmpDeque->size(); i++)
    {
        string sEmpName = (*mResignedEmpDeque)[i]->getEmployeeName();
        transform(sEmpName.begin(), sEmpName.end(), sEmpName.begin(), ::tolower);
        string sSearchName = nameParm;
        transform(sSearchName.begin(), sSearchName.end(), sSearchName.begin(), ::tolower);
        
        if(sEmpName.find(sSearchName) != string::npos)
        {
            if(!sHeaderPrinted)
            {
                printTableHeader();
                sHeaderPrinted = true;
            }
            printEmployeeTableRow((*mResignedEmpDeque)[i]);
            sFound = true;
        }
    }
    
    if(sFound)
    {
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    else
    {
        cout << "No employee found with name containing: " << nameParm << "\n";
    }
}

void XyzEmployeeManager::printEmployeeSummary(XyzEmployeeIF* empParm)
{
    if(!empParm)
    {
        return;
    }
    
    cout << empParm->getEmployeeName() << " | ID: " << empParm->getEmployeeId() << " | Gender: ";
    
    unsigned int sGender = empParm->getEmployeeGender();
    if(sGender == MALE) cout << "M";
    else if(sGender == FEMALE) cout << "F";
    
    cout << " | Type: ";
    unsigned int sType = empParm->getEmployeeType();
    if(sType == FULL_TIME) cout << "Full-Time";
    else if(sType == CONTRACT) cout << "Contractor";
    else if(sType == INTERN) cout << "Intern";
    
    cout << " | DOB: " << empParm->getDOB();
    cout << " | DOJ: " << empParm->getDOJ();
    
    unsigned int sStatus = empParm->getEmployeeStatus();
    if(sType == CONTRACT || sType == INTERN)
    {
        cout << " | DOL: " << empParm->getDOL();
    }
    
    cout << " | Status: ";
    if(sStatus == ACTIVE) cout << "Active";
    else if(sStatus == INACTIVE) cout << "Inactive";
    else if(sStatus == RESIGNED) cout << "Resigned";
    
    cout << "\n";
}

void XyzEmployeeManager::printEmployeeTableRow(XyzEmployeeIF* empParm)
{
    if(!empParm)
    {
        return;
    }
    
    // Get basic info
    string sName = empParm->getEmployeeName();
    string sId = empParm->getEmployeeId();
    
    string sGender;
    unsigned int sGenderVal = empParm->getEmployeeGender();
    if(sGenderVal == MALE) sGender = "M";
    else if(sGenderVal == FEMALE) sGender = "F";
    
    string sDOB = empParm->getDOB();
    string sDOJ = empParm->getDOJ();
    string sDOL = empParm->getDOL();
    if(sDOL.empty()) sDOL = "NA";
    
    string sType;
    unsigned int sTypeVal = empParm->getEmployeeType();
    if(sTypeVal == FULL_TIME) sType = "Full-Time";
    else if(sTypeVal == CONTRACT) sType = "Contractor";
    else if(sTypeVal == INTERN) sType = "Intern";
    
    string sStatus;
    unsigned int sStatusVal = empParm->getEmployeeStatus();
    if(sStatusVal == ACTIVE) sStatus = "Active";
    else if(sStatusVal == INACTIVE) sStatus = "Inactive";
    else if(sStatusVal == RESIGNED) sStatus = "Resigned";
    
    // Get type-specific info
    string sCollege = "NA";
    string sBranch = "NA";
    string sLeavesAvailed = "NA";
    string sTotalLeaves = "NA";
    string sAgency = "NA";
    
    if(sTypeVal == FULL_TIME)
    {
        sLeavesAvailed = to_string(empParm->getAvailedLeaves());
        sTotalLeaves = to_string(empParm->getTotalLeaves());
    }
    else if(sTypeVal == CONTRACT)
    {
        sAgency = empParm->getAgencyName();
    }
    else if(sTypeVal == INTERN)
    {
        sCollege = empParm->getCollegeName();
        sBranch = empParm->getBranchName();
    }
    
    cout << left;
    cout << "| " << setw(NameWidth)           << sName
         << "| " << setw(IdWidth)             << sId
         << "| " << setw(GenderWidth)         << sGender
         << "| " << setw(DobWidth)            << sDOB
         << "| " << setw(DojWidth)            << sDOJ
         << "| " << setw(DolWidth)            << sDOL
         << "| " << setw(TypeWidth)           << sType
         << "| " << setw(StatusWidth)         << sStatus
         << "| " << setw(CollegeWidth)        << sCollege
         << "| " << setw(BranchWidth)         << sBranch
         << "| " << setw(LeavesAvailedWidth)  << sLeavesAvailed
         << "| " << setw(TotalLeavesWidth)    << sTotalLeaves
         << "| " << setw(AgencyWidth)         << sAgency
         << "|\n";
}

void XyzEmployeeManager::printEmployeeDetails(XyzEmployeeIF* empParm)
{
    if(!empParm)
    {
        cout << "Invalid employee pointer\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "Name\t\t: " << empParm->getEmployeeName() << "\n";
    cout << "ID\t\t: " << empParm->getEmployeeId() << "\n";
    
    // Print Type
    cout << "Type\t\t: ";
    unsigned int sType = empParm->getEmployeeType();
    if(sType == FULL_TIME) cout << "FULL-TIME\n";
    else if(sType == CONTRACT) cout << "CONTRACTOR\n";
    else if(sType == INTERN) cout << "INTERN\n";
    
    // Print Status
    cout << "Status\t\t: ";
    unsigned int sStatus = empParm->getEmployeeStatus();
    if(sStatus == ACTIVE) cout << "ACTIVE\n";
    else if(sStatus == INACTIVE) cout << "INACTIVE\n";
    else if(sStatus == RESIGNED) cout << "RESIGNED\n";
    
    // Print Gender
    cout << "Gender\t\t: ";
    unsigned int sGender = empParm->getEmployeeGender();
    if(sGender == MALE) cout << "MALE\n";
    else if(sGender == FEMALE) cout << "FEMALE\n";
    
    cout << "DOB\t\t: " << empParm->getDOB() << "\n";
    cout << "DOJ\t\t: " << empParm->getDOJ() << "\n";
    
    // For resigned employees, print DOL and return
    if(sStatus == RESIGNED)
    {
        cout << "DOL\t\t: " << empParm->getDOL() << "\n";
        cout << "========================================\n";
        return;
    }
    
    // Print type-specific details
    if(sType == FULL_TIME)
    {
        cout << "Total Leaves\t: " << empParm->getTotalLeaves() << "\n";
        cout << "Availed Leaves\t: " << empParm->getAvailedLeaves() << "\n";
        cout << "Remaining Leaves: " << (empParm->getTotalLeaves() - empParm->getAvailedLeaves()) << "\n";
    }
    else if(sType == CONTRACT)
    {
        cout << "Agency\t\t: " << empParm->getAgencyName() << "\n";
        cout << "DOL\t\t: " << empParm->getDOL() << "\n";
    }
    else if(sType == INTERN)
    {
        cout << "College\t\t: " << empParm->getCollegeName() << "\n";
        cout << "Branch\t\t: " << empParm->getBranchName() << "\n";
        cout << "DOL\t\t: " << empParm->getDOL() << "\n";
    }
    
    cout << "========================================\n";
}

