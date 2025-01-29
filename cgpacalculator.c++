#include <iostream>
using namespace std;

int main() {
    int numSubjects;
    double totalGradePoints = 0.0, totalCredits = 0.0;

    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    for (int i = 1; i <= numSubjects; i++) {
        double gpa, credit;
        cout << "Enter GPA for subject " << i << ": ";
        cin >> gpa;
        cout << "Enter Credit Hours for subject " << i << ": ";
        cin >> credit;

        totalGradePoints += (gpa * credit);
        totalCredits += credit;
    }

    if (totalCredits == 0) {
        cout << "Invalid input. Total credits cannot be zero." << endl;
    } else {
        double cgpa = totalGradePoints / totalCredits;
        cout << "Your CGPA is: " << cgpa << endl;
    }

    return 0;
}
