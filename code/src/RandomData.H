#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H

#include <string>
#include <limits>
#include <random>

#include "Utility.H"

using namespace std;

namespace EmpRandDataGen
{

    int getRandomNumber(int startNumParm, int endNumParm);
    int getRandomEmpGender();
    int getRandomEmpType();
    int getRandomEmpStatus();

    string getRandomEmpDob();
    string getRandomEmpDoJ();
    string getRandomEmpDoL(const string& dojParm, int empTypeParm);

    
    string getRandomEmpName(unsigned int employeeGenderParm);
    string getRandomEmpId(unsigned int idParm, int empTypeParm);


    string getRandomEmpAgency();
    string getRandomEmpCollege();
    string getRandomEmpBranch();



}




#endif // RANDOM_DATA_H