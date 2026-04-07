#include "RandomData.H"

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

    string getRandomEmpAgency()
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
        string sType = "";
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

        return "XYZ" + idStr + sType;
    }

    int getRandomEmpStatus()
    {
        return getRandomNumber(1,3);
    }

    int getDaysInMonth(int year, int month)
    {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Check for leap year for February
        if(month == 2)
        {
            bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
            return isLeapYear ? 29 : 28;
        }
        
        return daysInMonth[month - 1];
    }

    string getRandomEmpDob()
    {
        // 21<=age<=60
        int year = getRandomNumber(CURRENT_YEAR-60, CURRENT_YEAR-21);
        int month = getRandomNumber(1, 12);
        int maxDay = getDaysInMonth(year, month);
        int day = getRandomNumber(1, maxDay);
        
        string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
        string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
        
        return sDay + "/" + sMonth + "/" + to_string(year);
    }


    string getRandomEmpDoJ(const string& dobParm)
    {
        // Parse DOB (format: DD/MM/YYYY)
        if(dobParm.length() < 10)
        {
            // Fallback to default range if DOB is invalid
            int year = getRandomNumber(2000, CURRENT_YEAR);
            int month = getRandomNumber(1, 12);
            int maxDay = getDaysInMonth(year, month);
            int day = getRandomNumber(1, maxDay);
            
            string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
            string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
            
            return sDay + "/" + sMonth + "/" + to_string(year);
        }
        
        int dobYear = stoi(dobParm.substr(6, 4));
        
        // Calculate the year when employee turns 21
        int minJoiningYear = dobYear + 21;
        
        // Ensure minJoiningYear is not before 2000 and not after CURRENT_YEAR
        if(minJoiningYear < 2000)
        {
            minJoiningYear = 2000;
        }
        
        // If employee hasn't turned 21 yet, use current year as minimum
        if(minJoiningYear > CURRENT_YEAR)
        {
            minJoiningYear = CURRENT_YEAR;
        }
        
        // Generate DOJ between year when employee turns 21 and current year
        int year = getRandomNumber(minJoiningYear, CURRENT_YEAR);
        int month = getRandomNumber(1, 12);
        int maxDay = getDaysInMonth(year, month);
        int day = getRandomNumber(1, maxDay);
        
        string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
        string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
        
        return sDay + "/" + sMonth + "/" + to_string(year);
    }

    string getRandomEmpDoL(const string& dojParm, int empTypeParm)
    {
        // For FullTime employees, DOL is "NA" (no leaving date)
        if(empTypeParm == FULL_TIME)
        {
            return "NA";
        }
        
        // Parse DOJ (format: DD/MM/YYYY)
        if(dojParm.length() < 10)
        {
            return "NA";
        }
        
        int day = stoi(dojParm.substr(0, 2));
        int month = stoi(dojParm.substr(3, 2));
        int year = stoi(dojParm.substr(6, 4));
        
        // For Contract employees: DOJ + 1 year
        if(empTypeParm == CONTRACT)
        {
            year += 1;
        }
        // For Intern employees: DOJ + 6 months
        else if(empTypeParm == INTERN)
        {
            month += 6;
            if(month > 12)
            {
                year += 1;
                month -= 12;
            }
        }
        
        
        int maxDay = getDaysInMonth(year, month);
        if(day > maxDay)
        {
            day = maxDay;
        }
        
        string sMonth = (month < 10) ? "0" + to_string(month) : to_string(month);
        string sDay = (day < 10) ? "0" + to_string(day) : to_string(day);
        
        return sDay + "/" + sMonth + "/" + to_string(year);
    }
}