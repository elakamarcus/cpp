//06_data_structures
/** 
 * Since arrays can only save same type, structures are convenient
 * 
 * Struct students
 * {
 *  string name;
 *  float GPA;
 * };
 * students students1;
*/

#include <iostream>
using namespace std;

struct students
{
    string name;
    float GPA;
};

int main(){
    students Teacher;
    Teacher.name = "Dr. Cooper";
    Teacher.GPA = "4.0";
    students firstPeriod[10]; //10x students struct
    firstPeriod[0].name = "First Student";
    firstPeriod[0].GPA = "3.1";
    /**
     * cannot print an entire array of struct. need to loop each property.
     */
}