#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void ProgramGreeting();
int Menu();

// -----------------------------------------Class Definitions-----------------------------------------
class Student
{
    private:
      int studentID;
    public:
    int studentGrades[];

    void setstudentID(int ID)
    {
      studentID = ID;
    };

    int getstudentID()
    {
      return studentID;
    };

    void setStudentGrades(int *pointer)
    {
      int size = sizeof(pointer);
    }

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
    public:
    string failing;
      
};

// Specification A1 - Date class
class Date
{    public:
          
        void compTest(int m, int y, int d)
        {
          
        };
        void SetDate (int month, int day, int year)
        {
          
        };

};

int main() 
{
  // Variables
  int ID, testGrade, choice;
  
  // Program Greeting 
  ProgramGreeting();

  // Unit Test
  
  // Create student object
  Student Student1;
  cout << "Please enter Student ID: ";
  cin >> ID;
  Student1.setstudentID(ID);
  cout << Student1.getstudentID();
  cout << endl;
  
  // Initalize new array - pGrades
  int *pGrades = nullptr;
  int size = 1;

  // Specification B1 - Dynamic Array
  pGrades = new int[size];

  // Prompt for student grade
  cout << "Please enter the first grade for Student ID: " << Student1.getstudentID() << endl;
  cin >> testGrade;
  pGrades[0] = testGrade;

  for (int i = 0; i < size; i++)
    cout << pGrades[i] << endl;

  // Insert menu, prompt for choice
  choice = Menu();

  // switch choice - add grade, delete grade, calculate gpa
  do {
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
          
          cout << "Please enter the next grade: "; 
          cin >> testGrade;
          cout << endl;
          
          pTemp[size-1] = testGrade;
          delete[] pGrades;

          pGrades = pTemp;
          pTemp = nullptr;

          for (int i = 0; i < size; i++)
            cout << pGrades[i] << endl;

          choice = Menu();
          break;
        }
  
      case 2:
        {
          // Display all Grades of pointer
          for (int i = 0; i < size; i++)
            cout << pGrades[i] << endl;

          choice = Menu();
          break;
        }
      case 3:
        // Call function to process grades Grade2Letter- output failing grades
        // Call fancyText Class
      break;

      case 4: 
      // Delete a grade by 1
      {
        int *pTemp = nullptr;
        int gradePosition;

        for (int i = 0; i < size; i++)
          cout << pGrades[i] << " " << endl;

        size--;
        pTemp = new int[size];

        // Takes in grade position and subtracts one to get index
        cout << "Enter the position of the grade you wish to delete: ";
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

        for (int i = 0; i < size; i++)
          cout << pGrades[i] << " " << endl;

        choice = Menu();
      }
    case 5:
        // exit the program and loop
      break;
    }
    } while (choice != 5);
}

// -------------------------------------Function Defintions-------------------------------------

void ProgramGreeting()
{
  cout << "This program allows manual input of grades for a student and calculates the GPA. \n\n";
  cout << "_________________________________________________________________________ \n\n\n";
}

int Menu()
{
  int choice;
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

  return choice;
};

void UnitTest()
{
  
};
