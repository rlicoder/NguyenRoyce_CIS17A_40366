#include <bits/stdc++.h>

using namespace std;

class TestScores
{
private:
    int test1;
    int test2;
    int test3;
public:
    TestScores();
    void outputTestScores() const;
    void outputAverage() const;
    void inputTestScores(int a, int b, int c);
};

main()
{
    TestScores test;
    cout << "Values after default constructor: " << endl;
    test.outputTestScores();
    test.outputAverage();
    int a, b, c;
    
    cout << "Enter test score 1: ";
    cin >> a;
    cout << "Enter test score 2: ";
    cin >> b;
    cout << "Enter test score 3: ";
    cin >> c;

    test.inputTestScores(a, b, c);
    test.outputTestScores();
    test.outputAverage();
}

TestScores::TestScores()
{
    test1 = 0;
    test2 = 0;
    test3 = 0;
}

void TestScores::outputAverage() const
{
    float average;
    average = static_cast<float>((test1 + test2 + test3)) / 3;
    cout << "The average of all test scores is: " << fixed << setprecision(2) << average << endl;
}

void TestScores::inputTestScores(int a, int b, int c)
{
    test1 = a;
    test2 = b;
    test3 = c;
}

void TestScores::outputTestScores() const
{
    cout << "Test score 1 is: " << test1 << endl;
    cout << "Test score 2 is: " << test2 << endl;
    cout << "Test score 3 is: " << test3 << endl;
}