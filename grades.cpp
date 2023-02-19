#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

// Function Prototypes
void ProgramGreeting();
int Menu();
double gpaConvert(char array[], int size);
void FailGrade();
void UnitTest();

// -----------------------------------------Class Definitions-----------------------------------------
class Student
{
    private:
      int studentID;
    public:
    int studentGrades[50];

    void setstudentID(int ID)
    {
      studentID = ID;
    };

    int getstudentID()
    {
      return studentID;
    };

    void setStudentGrades(int *pointer, int size)
    {
      for (int i = 0; i < size; i++)
        {
          pointer[i] = studentGrades[i];
          cout << studentGrades[i] << " ";
        }
    };

    // Specification C3 - Letter Grades
    char Grade2Lttr (int numberGrade)
    {
      char LetterGrade;
      if ((numberGrade >= 90) && (numberGrade <= 100))
        LetterGrade = 'A';
      else if ((numberGrade >= 80) && (numberGrade <= 89))
        LetterGrade = 'B';
      else if ((numberGrade >= 70) && (numberGrade <= 79))
        LetterGrade = 'C';
      else if ((numberGrade >= 60) && (numberGrade <= 69))
        LetterGrade = 'D';
      else if (numberGrade <= 60 && (numberGrade >= 1))
        LetterGrade = 'F';
      else if ((numberGrade < 1) || (numberGrade > 100))
        LetterGrade = 'X';
      return LetterGrade;
    };
      
};
// Specification B4 - Highlight Failing Grades
class FancyText
{
  private: 
  int ANSIcode = 0;
  public:
    void setColor (int c) { ANSIcode = c;};
    string redPrint(string s) {
      string sout;
      sout += "\033[0;";
      sout += to_string(ANSIcode);
      sout += "m";
      sout += s;
      sout += "\033[0m\n";
      return sout;
    }
      
};

// Specification A1 - Date class
class Date
{    
  private:
  int month, day, year;
  time_t realTime = time(NULL);
  struct tm *pTime = localtime(&realTime);
  public:  
    void SetDate (int mth, int dy, int ye)
      {
        month = mth;
        day = dy;
        year = ye;
      }
    void printDate()
      {
        cout << month << "/" << day << "/" << year;
      }
    string getDate()
      {
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
      }
    // Specification A3 - Component Test Method in Date
    void compTest()
      {
        Date tester;
        tester.SetDate(2, 18, 2023);
        if (tester.getDate() == "2/18/2023")
          cout << "Pass" << endl;
        else
          cout << "Fail" << endl;
      }
    void RealDate()
      {
        month = pTime->tm_mon + 1;
        day = pTime->tm_mday+1;
        year = pTime->tm_year + 1900;
      }
};

int main() 
{
  // Variables
  int ID, testGrade, choice;
  int test = 1;

  // Unit Test
  UnitTest();
  
  // Program Greeting 
  ProgramGreeting();

  // // Initialize time
  cout << "Welcome! Today's Date is: "; 
  Date realDay;
  realDay.RealDate();
  realDay.printDate();
  cout << endl << endl;
  
  // Create student object
  Student Student1;
  cout << "Please enter Student ID: ";
  cin >> ID;
  Student1.setstudentID(ID);
  cout << endl;
  
  // Initalize new array - pGrades
  int *pGrades = nullptr;
  int size = 1;

  // Specification B1 - Dynamic Array
  pGrades = new int[size];

  // Prompt for student grade
  cout << "Please enter grade for test " << test << " for Student ID: " << Student1.getstudentID() << endl;
  cin >> testGrade;
  pGrades[0] = testGrade;

  // Insert menu, prompt for choice
  choice = Menu();

  // switch choice - add grade, delete grade, calculate gpa
  do {
  test++;
  switch(choice)
    {
      case 1:
        // Function call for Increasing send pointer
        {
          int *pTemp = nullptr;
          size++;

          pTemp = new int[size];

          for (int i = 0; i < size; i++)
              pTemp[i] = pGrades[i];
          
          cout << "Please enter grade for test number " << test;
          cout << ": ";
          cin >> testGrade;
          cout << endl;
          
          pTemp[size-1] = testGrade;
          delete[] pGrades;

          pGrades = pTemp;
          pTemp = nullptr;

          choice = Menu();
          break;
        }
  
      case 2:
        {
          // Display all Grades of pointer
          cout << "#     Score     Grade     \n";
          cout << "-------------------------\n";
          for (int i = 0; i < size; i++) {
            cout << i+1 << "     ";
            cout << pGrades[i] << "        ";
            if (Student1.Grade2Lttr(pGrades[i]) == 'F')
              FailGrade();
            else
              cout << Student1.Grade2Lttr(pGrades[i]) << endl;
            };

          choice = Menu();
          test--;
          break;
        }
      case 3:
        // Call Grade2Letter, call fancyText, Calculate GPA 
        {
          char letterGrades[size];

          for (int i = 0; i < size; i++)
            letterGrades[i] = Student1.Grade2Lttr(pGrades[i]);
          cout << "Student " << Student1.getstudentID() << "'s GPA: ";     
          cout << fixed << setprecision(1) << gpaConvert(letterGrades, size) << endl;

          // Adds to student's grades in class object
          for (int i = 0; i < size; i++)
            Student1.studentGrades[i] = pGrades[i];

          test--;
          choice = Menu();
          break;
          }
      case 4: 
      // Delete a grade by 1
      {
        int *pTemp = nullptr;
        int gradePosition;

        cout << "Student " << Student1.getstudentID() << "'s Grades \n";
        cout << "--------------------------- \n";
        for (int i = 0; i < size; i++)
          cout << "Test #" << i+1 << ": " << pGrades[i] << "\n";
        cout << endl;

        size--;
        test = test - 2;
        pTemp = new int[size];

        // Takes in grade position and subtracts one to get index
        cout << "Enter the test you wish to delete: ";
        cin >> gradePosition;
        gradePosition--;
    
        // Adding grades from original array to new array w/ altered size
        for (int i = 0; i < gradePosition; i++)
          pTemp[i] = pGrades[i];
        // Replacing grade at index with next grade in array
        for (int i = gradePosition; i < size+1; i++)
          pTemp[i] = pGrades[i+1];


        delete[] pGrades;
        
        // Set memory location of pGrades to new array
        pGrades = pTemp;

        pTemp = nullptr;
        
        choice = Menu();
        break;
      }
    case 5:
      {
        // exit the program and loop, delete pointer, set to null
        cout << "Exiting the program...\n";
        delete pGrades;
        pGrades = nullptr; 
      break;
        }
    }
    } while (choice != 5);
}

// -------------------------------------Function Defintions-------------------------------------

void ProgramGreeting()
{
  cout << "This program allows manual input of grades for a student and calculates the GPA. \n\n";
  cout << "_________________________________________________________________________ \n\n\n";

};

int Menu()
{
  int choice;
  cout << endl;
  cout << "Main Menu \n" << "-------------------------- \n";
  cout << "1. Add Grade \n";
  cout << "2. Display All Grades \n";
  cout << "3. Process all Grades \n";
  cout << "4. Delete a Grade \n";
  cout << "5. Quit Program \n";
 
  // Specification B3 - Menu Input Validation
  do {
    cout << "Please enter a choice (1-5): ";
    cin >> choice;
  } while ((choice < 1) || (choice > 5));
  cout << endl;

  return choice;
};

double gpaConvert(char array[], int size) {
  double dSIZE = size;
  double totalPoint = 0;
  double gpa;
  for (int i = 0; i < size; i++) {
    if (array[i] == 'A')
      totalPoint += 4.0;
    if (array[i] == 'B')
      totalPoint += 3.0;
    if (array[i] == 'C')
      totalPoint += 2.0;
    if (array[i] == 'D')
      totalPoint += 1.0;
    if (array[i] == 'F')
      totalPoint += 0;
  }
  gpa = totalPoint/dSIZE;
  return gpa;
};

void FailGrade()
{
  const int red = 31;
  FancyText coutRed;
  coutRed.setColor(red);
  cout << coutRed.redPrint("F");
}
// Specification A4 - Unit Test
void UnitTest()
{
  cout << "Testing... \n";
  // compTest for Date Class
  cout << "Date Class Testing: ";
  Date testDate1;
  testDate1.compTest();

  // Pass Date into Date Class
  cout << "Pass Date into Date Test: ";
  testDate1.SetDate(12,15,2023);
  if (testDate1.getDate() == "12/15/2023")
    cout << "True" << endl;
  else
    cout << "False" << endl;
  
  // Unit Test for Grade2Lttr Method
  cout << "Grade2Lttr testing: ";
  int unitTestGrades[5] = {101,89,95,78,-1};
  char CorrectGrades[5] = {'X', 'B', 'A', 'C', 'X'};
  Student StudentTest;
  char testLetter;
  bool Pass;
  for (int i = 0; i < 5; i++)
    {
      testLetter = StudentTest.Grade2Lttr(unitTestGrades[i]);
      if (testLetter == CorrectGrades[i])
        Pass = true;
      else 
        Pass = false;
    }
  if (Pass == true)
    cout << "Pass \n";

  cout << "End of testing... \n\n";
};
