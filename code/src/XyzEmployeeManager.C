
#include "XyzEmployeeManager.H"

XyzEmployeeManager::XyzEmployeeManager() : mEmpIdCounter(1)
{
    cout << "XyzEmployeeManger constructor" << endl;
}


XyzEmployeeManager::~XyzEmployeeManager() 
{ 
    cout << "XyzEmployeeManger destructor" << endl;
    delete mActiveInactiveEmpDeue;
    delete mResignedEmpDeque;
}

void XyzEmployeeManager::pAddFullTimeEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzFullTimeEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeue->pushBack(sNewEmp);
    }

    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;

}

void XyzEmployeeManager::pAddContractEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzContractEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeue->pushBack(sNewEmp);
    }
    
    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;
}

void XyzEmployeeManager::pAddInternEmployee()
{
    XyzEmployeeIF* sNewEmp = new XyzInternEmployee(mEmpIdCounter);
    unsigned int sEmpStatus = sNewEmp->getEmployeeStatus();

    if(sEmpStatus == ACTIVE || sEmpStatus == INACTIVE)
    {
        mActiveInactiveEmpDeue->pushBack(sNewEmp);
    }
    
    if(sEmpStatus == RESIGNED)
    {
        mResignedEmpDeque->pushBack(sNewEmp);
    }
    mEmpIdCounter++;

}


void XyzEmployeeManager::processEmployees()
{
    bool sRun = true;
    while(sRun)
    {
        printMainMenu();
        int sChoice = 0;
        cin >> sChoice;
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
                unsigned int sEmployeeID;
                if(sEmpChoice == EmployeeDetailsMenuChoice::ByID)
                {
                    // print employee details as per employee ID
                    sEmployeeID = safeInput<unsigned int>("Employee ID: ");

                }
                else
                {
                    // print employee details

                }

                break;
            }

            case MainMenu::OTHERS:
            {
                unsigned int sChoice = chooseOthersMenuOption();
                if(sChoice == ADD_LEAVES)
                {
                    addLeavesForFullTimers();
                }
                else if (sChoice == CONVERT_INTERN)
                {
                    convertInternToFulltimer();
                }
                else if (sChoice == SEARCH_BY_ID)
                {

                }
                else if (sChoice == SEARCH_BY_NAME)
                {

                }
                else
                {
                    
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
                cout << "Invaluid choice! Try again. \n";
                break;
            }
        }
    }

}

EDLL<XyzEmployeeIF*> * XyzEmployeeManager::getActInactEmpDeque() 
{
    return mActiveInactiveEmpDeue;
}

EDLL<XyzEmployeeIF*> * XyzEmployeeManager::getResignedEmpDeque() 
{
    return mResignedEmpDeque;
}

void XyzEmployeeManager::removeEmployee(unsigned int idParm)
{

}

void XyzEmployeeManager::convertInternToFulltimer(unsigned int)
{

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


void XyzEmployeeManager::addLeavesForFullTimers(unsigned int )
{


}

void XyzEmployeeManager:: printEmpsInfo(unsigned int)
{
    

}


void XyzEmployeeManager:: printEmpInfo(unsigned int)
{


}

void XyzEmployeeManager:: printEmpInfo(string)
{


}

