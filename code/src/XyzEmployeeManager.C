
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
    EmployeeStatus sEmpStatus = sNewEmp->getEmployeeStatus();

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
    EmployeeStatus sEmpStatus = sNewEmp->getEmployeeStatus();

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
    EmployeeStatus sEmpStatus = sNewEmp->getEmployeeStatus();

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
    while(1)
    {
        printMainMenu();
        int sChoice = 0;
        std::cin >> sChoice;
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
                        break;
                    }

                    case EmployeeType::INTERN:
                    {
                        // add intern 
                        break;
                    }

                    default:
                    break;
                }
                break;
            }

            case MainMenu::REMOVE_EMPLOYEE:
            {

                break;
            }

            case MainMenu::PRINT_EMPLOYEE:
            {

                break;
            }

            case MainMenu::OTHERS:
            {

                break;
            }

            case MainMenu::EXIT:
            {

                break;
            }

            default:
            {
                std::cout << "Invaluid choice\n";
                break;
            }
        }
    }

}
