#include <bits/stdc++.h>

using namespace std;

class GradedActivity
{
protected:
   char letter;            // To hold the letter grade
   double score;           // To hold the numeric score
   void determineGrade()
   {
        if (score > 89)
           letter = 'A';
        else if (score > 79)
           letter = 'B';
        else if (score > 69)
           letter = 'C';
        else if (score > 59)
           letter = 'D';
        else
           letter = 'F';
    }  // Determines the letter grade
public:
   // Default constructor
   GradedActivity()
      { letter = ' '; score = 0.0; }

   // Mutator function
   void setScore(double s) 
      { score = s;
        determineGrade();}
   
   // Accessor functions
   double getScore() const
      { return score; }
   
   char getLetterGrade() const
      { return letter; }
};



class Essay : public GradedActivity
{
private:
    int grammar;
    int spelling;
    int length;
    int content;
public:
    Essay()
    {
        grammar = 0;
        spelling = 0;
        length = 0;
        content = 0;
    }
    
    Essay(int sgrammar, int sspelling, int slength, int scontent)
    {
        grammar = sgrammar;
        spelling = sspelling;
        length = slength;
        content = scontent;
        setScore();
    }
    
    void setRubric(int sgrammar, int sspelling, int slength, int scontent)
    {
        grammar = sgrammar;
        spelling = sspelling;
        length = slength;
        content = scontent;
        setScore();
    }
    
    void setScore()
    {
        GradedActivity::setScore(grammar + spelling + length + content);
    }
    
    
    
};

int main()
{
    int sgrammar, sspelling, slength, scontent;
    
    cout << "What is the grammar score for the essay: ";
    cin >> sgrammar;
    
    cout << "What is the spelling score for the essay: ";
    cin >> sspelling;
    
    cout << "What is the length score for the essay: ";
    cin >> slength;
    
    cout << "What is the content score for the essay: ";
    cin >> scontent;
    
    Essay student;
    
    student.setRubric(sgrammar, sspelling, slength, scontent);
    
    cout << "The score of the essay is " << student.getScore() << endl;
    cout << "The letter grade of the essay is: " << student.getLetterGrade() << endl;
}