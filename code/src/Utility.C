
#include "Utility.H"

using namespace std;



static string first_names[2][NUM_NAMES] = {
    {"Vijay", "Arun", "Kiran", "Ravi", "Suresh", "Manoj", "Rahul"},
    {"Meena", "Sree", "Sai", "Priya", "Divya", "Anjali", "Kavya"}
};
static string last_names[2][NUM_NAMES] = {
    {"Kumar", "Reddy", "Sharma", "Patel", "Singh", "Rao", "Gupta"},
    {"Lakshmi", "Priya", "Sharma", "Reddy", "Devi", "Kumari", "Singh"}
};

static string AGENCY_NAMES[] = {"Avengers", "Justice League", "X-Men"};
static string COLLEGE_NAMES[] = {"IIT Delhi", "IIT Mumbai", "IIT Hyderabad", "IIT Kanpur", "NIT Warangal", "NIT Tiruchi", "IIIT Hyderabad"};
static string BRANCH_NAMES[] = {"ECE","CSE","CSIT"};


void printMainMenu()
{
    cout << "|--------------------------------------|\n"
        << "| Choose any below option              |\n"
        << "|--------------------------------------|\n"
        << "| 1. Add an Employee.                  |\n"
        << "| 2. Add n Random employees            |\n"
        << "| 3. Remove an employee                |\n"
        << "| 4. Get Employee Details              |\n"
        << "| 5. Others.                           |\n"
        << "|----------------------------------    |\n"
        << "|      Press -1 to exit                |\n"
        << "|----------------------------------    |\n";
}

void printAddEmployeeOption()
{
    cout << "\n"
         << "|--------------------------------------|\n"
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
   cout  << "\n"
         << "--------------------------------------------------\n"
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
    cout << "\n"
         << "---------------------------------------------------\n"
         << "|             Other Operations Menu               |\n"
         << "---------------------------------------------------\n"
         << "| 1. Add 'n' Leaves to Full-Time Employees        |\n"
         << "| 2. Convert an Intern to Full-Time Employee      |\n"
         << "| 3. Search Employee by ID                        |\n"
         << "| 4. Search Employee by Name                      |\n"
         << "| (-1 to Go Back)                                 |\n"
         << "---------------------------------------------------\n";
}

int chooseMainMenuChoice()
{
    int sChoice;
    printMainMenu();
    sChoice = safeInput<int>("Your Choice : ");
    return sChoice;
} 

int chooseAddEmpOption()
{
    int sChoice;
    printAddEmployeeOption();
    sChoice = safeInput<int>("Your Choice : ");
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

int chooseXyzEmpSummaryOption()
{
    int sChoice;
    printXyzEmpSummaryMenu();
    sChoice = safeInput<int>("Your Choice : ");
    //todo
    return sChoice;
}

int chooseOthersMenuOption()
{
    int sChoice;
    printOthersMenu();
    sChoice = safeInput<int>("Your Choice : ");
    return sChoice;
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
        string sName = first_names[employeeGenderParm-1][getRandomNumber(0,NUM_NAMES-1)];
        sName += " ";
        sName += last_names[employeeGenderParm-1][getRandomNumber(0,NUM_NAMES-1)];
        // cout << "Name : " << sName << "\n";
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
        return AGENCY_NAMES[getRandomNumber(0,2)];
    }

    string getRandomEmpCollege()
    {
        return COLLEGE_NAMES[getRandomNumber(0,6)];
    }

    string getRandomEmpBranch()
    {
        return BRANCH_NAMES[getRandomNumber(0,2)];
    }

    string getRandomEmpId(unsigned int idParm, int empTypeParm)
    {
        // Xyz+ Id (4 digits with leading zeros) + Employeetype
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

        // Pad ID with leading zeros to make it 4 digits
        string idStr = to_string(idParm);
        while(idStr.length() < 4)
        {
            idStr = "0" + idStr;
        }

        return "Xyz" + idStr + sType;
    }

    int getRandomEmpStatus()
    {
        return getRandomNumber(1,3);
    }

    string getRandomEmpDob()
    {
        // 21<=age<=60
        int year = getRandomNumber(CURRENT_YEAR-60, CURRENT_YEAR-21);
        int month = getRandomNumber(1, 12);
        int day = getRandomNumber(1, 28);
        
        string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
        string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
        
        return to_string(day) + "/" + sMonth + "/" + to_string(year);
    }


    string getRandomEmpDoJ()
    {
        // Generate DOJ between year when employee turns 21 and current year
        int year = getRandomNumber(2000, CURRENT_YEAR);
        int month = getRandomNumber(1, 12);
        int day = getRandomNumber(1, 28);
        
        string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
        string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
        
        return to_string(day) + "/" + sMonth + "/" + to_string(year);
    }

}




