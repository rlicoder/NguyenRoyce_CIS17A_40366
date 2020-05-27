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
