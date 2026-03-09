
#include "Utility.H"



using namespace std;


static string first_names[2][NUM_NAMES] = {{"Sai", "Sri", "Ram"},{"Meena", "Sree", "Sai"}};
static string last_names[2][NUM_NAMES] = {{"Teja", "Krishna", "Aravind"},{"Lakshmi", "Priya", "sharma"}};

static string AGENCY_NAMES[] = {"Avengers", "Justice League", "X-Men"};
static string COLLEGE_NAMES[] = {"IIT Delhi", "IIT Mumbai", "IIT Hyderabad", "IIT Kanpur", "NIT Warangal", "NIT Tiruchi", "IIIT Hyderabad"};
static string BRANCH_NAMES[] = {"ECE","CSE","CSIT"};


void printMainMenu()
{
    cout << "|--------------------------------------|\n"
        << "| Choose any below option              |\n"
        << "|--------------------------------------|\n"
        << "| 1. Add an Employee.                  |\n"
        << "| 2. Remove an employee.               |\n"
        << "| 3. Employee Details                  |\n"
        << "| 4. Others.                           |\n"
        << "|----------------------------------    |\n"
        << "|      Press -1 to exit                |\n"
        << "|----------------------------------    |\n";
}

void printAddEmployeeOption()
{
    cout << "|--------------------------------------|\n"
         << "| Choose any option below.             |\n"
         << "|--------------------------------------|\n"
         << "| 1. Add Employee at Random            |\n"
         << "| 2. Add an Employee (F/C/I)           |\n"
         << "| -------------------------------------|\n"
         << "|   Press -1 to Exit.                  |\n"
         << "|--------------------------------------|\n";
}

void printXyzEmpSummaryMenu()
{
   cout  << "--------------------------------------------------\n"
         << "|             Employee Details Menu              |\n"
         << "--------------------------------------------------\n"
         << "| 1. All Employees Summary                       |\n"
         << "| 2. Employee Summary (F/C/I)                    |\n"
         << "| 3. Employee Summary (M/F)                      |\n"
         << "| 4. Employee Summary (A/I/R)                    |\n"
         << "| 5. Display Employee Details                    |\n"
         << "| (-1 to Go Back)                                |\n"
         << "--------------------------------------------------\n";
}

void printOthersMenu()
{
    cout << "---------------------------------------------------\n"
         << "|             Other Operations Menu               |\n"
         << "---------------------------------------------------\n"
         << "| 1. Add 'n' Leaves to Full-Time Employees        |\n"
         << "| 2. Convert an Intern to Full-Time Employee      |\n"
         << "| 3. Search Employee by ID                        |\n"
         << "| 4. Search Employee by Name                      |\n"
         << "| (-1 to Go Back)                                 |\n"
         << "---------------------------------------------------\n";
}

unsigned int chooseMainMenuChoice()
{
    unsigned int sChoice;
    printMainMenu();
    sChoice = safeInput<int>("Your Choice");
    return sChoice;
} 

unsigned int chooseAddEmpOption()
{
    unsigned int sChoice;
    printAddEmployeeOption();
    sChoice = safeInput<int>("Your Choice");
    if(sChoice == ADD_RANDOM_EMPLOYEE)
    {
        return EmpRandDataGen::getRandomEmpType();
    }
    else if(sChoice == ADD_SPECIFIC_EMPLOYEE)
    {
        sChoice = safeInput<int>("Employee type : (1=FullTime,2=Contractor,3=Intern)\n");
        if(sChoice == EmployeeType::FULL_TIME);
        else if(sChoice == EmployeeType::CONTRACT);
        else if(sChoice == EmployeeType::INTERN);
        else
        {
            cout << "Invalid add specific employee choice\n";
            return chooseAddEmpOption();
        }
    }
    else
    {
        cout << "Invalid add employee option type\n";
        return chooseAddEmpOption();
    }
    return sChoice;
}

unsigned int chooseXyzEmpSummaryOption()
{
    unsigned int sChoice;
    printXyzEmpSummaryMenu();
    sChoice = safeInput<int>("Your Choice");
    //todo
    return sChoice;
}

unsigned int chooseOthersMenuOption()
{
    unsigned int sChoice;
    printOthersMenu();
    sChoice = safeInput<int>("Your Choice");
    return sChoice;
}

template <typename T>
T safeInput(const string& promptMsg)
{
    T value;
    bool isValid = false;
    while (!isValid)
    {
        cout << promptMsg;
        cin >> value;
        if (!cin.fail())
        {
            isValid = true;
        }
        else
        {
            cout << "Invalid input! Try again." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}



namespace EmpRandDataGen
{
    int getRandomNumber(int startNumParm, int endNumParm)
    {
        random_device sRandomDevice;
        mt19937 sRandomNumberGenerator(sRandomDevice());
        uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
        int sRandomNumber = sGenerate(sRandomNumberGenerator);
        return sRandomNumber;
    }

    string getRandomEmpName(unsigned int employeeGenderParm)
    {
        string sName = first_names[employeeGenderParm-1][getRandomNumber(0,NUM_NAMES)];
        sName += " ";
        sName += last_names[employeeGenderParm-1][getRandomNumber(0,NUM_NAMES)];
        cout << "Name : " << sName << "\n";
        return sName;
    }

    int getRandomEmpGender()
    {
        return getRandomNumber(1,2);
    }

    int getRandomEmpType()
    {
        return getRandomNumber(1,3);
    }

    string getRanomEmpAgency()
    {
        return AGENCY_NAMES[getRandomNumber(0,sizeof(AGENCY_NAMES))];
    }

    string getRandomEmpCollege()
    {
        return COLLEGE_NAMES[getRandomNumber(0,sizeof(COLLEGE_NAMES))];
    }

    string getRandomEmpBranch()
    {
        return BRANCH_NAMES[getRandomNumber(0,sizeof(BRANCH_NAMES))];
    }

    string getRandomEmpId(unsigned int idParm, int empTypeParm)
    {
        // Xyz+ Id + Employeetype
        string sType = "\0";
        if(empTypeParm == FULL_TIME)
        {
            sType = "F";
        }
        else if(empTypeParm == CONTRACT)
        {
            sType = "C";
        }
        else if(empTypeParm == INTERN)
        {
            sType = "I";
        }

        return "Xyz"+ to_string(idParm) + sType;
    }

    int getRandomEmpStatus()
    {
        return getRandomNumber(1,3);
    }

    string getRandomEmpDob()
    {
        return "";
    }

}




