#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

float gradeToPoint(const string &grade)
{
    if (grade == "EX")
        return 10.0;
    else if (grade == "AA")
        return 9.0;
    else if (grade == "AB")
        return 8.5;
    else if (grade == "BB")
        return 8.0;
    else if (grade == "BC")
        return 7.5;
    else if (grade == "CC")
        return 7.0;
    else if (grade == "CD")
        return 6.5;
    else if (grade == "DD")
        return 6.0;
    else if (grade == "DE")
        return 5.5;
    else if (grade == "EE")
        return 5.0;
    else if (grade == "FF")
        return 0.0;
    else
        return 0.0;
}
float calculateCGPA(const vector<string> &grades, const vector<int> &credits)
{
    float totalPoints = 0.0;
    int totalCredits = 0;
    for (size_t i = 0; i < grades.size(); ++i)
    {
        totalPoints += gradeToPoint(grades[i]) * credits[i];
        totalCredits += credits[i];
    }
    cout << endl;
    cout << "Total Credits " << totalCredits << endl;
    cout << "Total Points  " << totalPoints << endl;
    return totalCredits > 0 ? totalPoints / totalCredits : 0.0;
}
void inputSemester(vector<string> &grades, vector<int> &credits, const vector<string> &subjects, const vector<int> &subjectCredits)
{
    for (size_t i = 0; i < subjects.size(); ++i)
    {
        string grade;
        int credit = subjectCredits[i];

        while (true)
        {
            cout << subjects[i] << " - Grade: ";
            cin >> grade;

            // Convert grade to uppercase manually
            for (char &c : grade)
            {
                if (c >= 'a' && c <= 'z')
                {
                    c = c - 'a' + 'A';
                }
            }

            if (gradeToPoint(grade) == 0.0 && grade != "FF")
            {
                cout << "Invalid grade. Please enter a valid grade." << endl;
                continue;
            }
            break;
        }

        grades.push_back(grade);
        credits.push_back(credit);
    }
}

int main()
{
    vector<string> grades;
    vector<int> credits;
    vector<vector<string>> allSubjects = {
        {"EM-1     ", "Chemistry", "Mechanics", "C        ", "WorkShop ", "Che-lab  ", "Mech Lab "},                           // Semester 1
        {"Em-2     ", "Physics  ", "Graphic  ", "CS       ", "EEE      ", "Phy-lab  ", "Grap-lab ", "cs lab   ", "Seminar  "}, // Semester 2
        {"EM-3     ", "IPC      ", "CAO      ", "OOP-c++  ", "DSA      ", "OOP Lab  ", "DSA Lab  ", "Seminar-1"},              // Semester 3
        {"OB       ", "Pro.&sat.", "Dis. Math", "DAA      ", "Web-Tech ", "DAA-LAB  ", "Web-Lab  ", "Seminar-2"},              // Semester 4
        {"SE       ", "CNIP     ", "ITSM/EMB.", "JAVA     ", "CNIP-lab ", "SE&JA-LAB", "Mini-project-1"},                      // semester 5
        {"OS       ", "DBMS     ", "ST/DWDM  ", "ERP      ", "DBMS-lab ", "OS-lab   ", "Mini-Project-2"},                      // semester 6
        {"CCSM	   ", "AI	    ", "PR       ", "ML       ", "IS       ", "CCSM-lab ", "PR-lab   ", "IS-lab   ", "Project 1"},
        {"IOT	   ", "MC	    ", "Project 2"}

    };

    vector<vector<int>> allCredits = {
        {4, 4, 3, 3, 2, 1, 1},       // Credits for Semester 1
        {4, 4, 2, 2, 2, 1, 2, 1, 1}, // Credits for Semester 2
        {4, 2, 4, 4, 4, 1, 1, 2},    // Credits for Semester 3
        {3, 4, 4, 4, 3, 1, 1, 2},    // Credits for Semester 4
        {4, 4, 3, 3, 1, 2, 4},       // credits for semester 5
        {4, 4, 3, 3, 1, 2, 4},       // credits for semester 5
        {2, 3, 3, 3, 3, 2, 2, 2, 4},
        {3, 3, 24}

    };

    int n = 6; // semester wise increase it
    int choice;
    cout << "\nSelect an option:\n\nSemester (SGPA)---> 1-";
    cout << n;
    cout << " (SGPA)\nCGPA           ---> 9\nDSY CGPA       ---> 10\nSem Wise SGPA  ---> 11\nSem Wise CGPA  ---> 12\n\nEnter Choice: ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        inputSemester(grades, credits, allSubjects[0], allCredits[0]);
        break;
    case 2:
        inputSemester(grades, credits, allSubjects[1], allCredits[1]);
        break;
    case 3:
        inputSemester(grades, credits, allSubjects[2], allCredits[2]);
        break;
    case 4:
        inputSemester(grades, credits, allSubjects[3], allCredits[3]);
        break;
    case 5:
        inputSemester(grades, credits, allSubjects[4], allCredits[4]);
        break;
    case 6:
        inputSemester(grades, credits, allSubjects[5], allCredits[5]);
        break;
    case 7:
        inputSemester(grades, credits, allSubjects[6], allCredits[6]);
        break;
    case 8:
        inputSemester(grades, credits, allSubjects[7], allCredits[7]);
        break;
    case 9:
        for (int i = 0; i < n; ++i)
        {
            inputSemester(grades, credits, allSubjects[i], allCredits[i]);
        }
        break;
    case 10:
        for (int i = 2; i < n; ++i)
        {
            inputSemester(grades, credits, allSubjects[i], allCredits[i]);
        }
        break;
    case 11:
        cout << "Enter All Grades It will SGPA" << endl;
        for (int i = 0; i < n; ++i)
        {
            inputSemester(grades, credits, allSubjects[i], allCredits[i]);
            float cgpa = calculateCGPA(grades, credits);
            cout << "Semester [" << i + 1 << "] SGPA = " << cgpa << endl;
            cout << endl;
            grades.clear();
            credits.clear();
        }
        break;
    case 12:
        cout << "Enter All Grades it will CGPA" << endl;
        for (int i = 0; i < n; ++i)
        {
            inputSemester(grades, credits, allSubjects[i], allCredits[i]);
            float cgpa = calculateCGPA(grades, credits);
            cout << "Semester [" << i + 1 << "] CGPA = " << cgpa << endl;
            cout << endl;
        }
        break;
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    if (grades.empty())
    {
        cout << "No data entered. Cannot calculate CGPA." << endl;
        return 1;
    }

    float cgpa = calculateCGPA(grades, credits);
    if (choice == 9 || choice == 10)
    {
        cout << "Overall CGPA is: " << cgpa << endl;
    }
    else
    {
        cout << "Your SGPA is: " << cgpa << endl;
    }
    cout << endl;
    cout << endl;
    getch();
    return 0;
}
/*                                                                       sgpa                         cgpa
viraj =                 {(ee, ee, cd, de, ab, bb, ab),          Semester [1] = 6.08333    Semester [1] = 6.08333
                         (ee, de, bc, cd, ee, ab, aa, dd, bb),  Semester [2] = 6.34211    Semester [2] = 6.21622
                         (ee, cd, ee, ee, de, aa, ex, ee),      Semester [3] = 5.63636    Semester [3] = 5.9661
                         (dd, de, cd, bc, cd, aa, bb, ab),      Semester [4] = 6.79545    Semester [4] = 6.21605
                         (de, de, cc, de, bb, bc, ab),          Semester [5] = 6.59524    Semester [5] = 6.29412
                         (ee, dd, ee, cd, ab, ex, ex)}          Semester [6] = 7.00000    Semester [6] = 6.41463

Sunit =                 {(aa, cc, bc, bc, ab, bb, aa),          Semester [1] = 7.94444    Semester [1] = 7.94444
                         (cd, bc, aa, bc, cc, aa, aa, cd, ab),  Semester [2] = 7.63158    Semester [2] = 7.78378
                         (bc, bc, cc, bc, bb, aa, ex, ex),      Semester [3] = 7.90909    Semester [3] = 7.83051
                         (de, bc, ab, bb, ex, ex, ex, ab),      Semester [4] = 8.15909    Semester [4] = 7.91975
                         (bb, bb, bb, ab, ex, aa, ab),          Semester [5] = 8.35714    Semester [5] = 8.0098
                         (bb, bb, bb, bb, ex, ex, ex)}          Semester [6] = 8.66667    Semester [6] = 8.12195

EKanth =                {(cd, bc ,cc, cd, aa, aa, aa),          Semester [1] = 7.36111    Semester [1] = 7.36111
                         (bc, cc, cd, de, cc, ab, aa, bb, bb),  Semester [2] = 7.28947    Semester [2] = 7.32432
                         (bb, cc, cc, de, dd, ex, ex, ex),      Semester [3] = 7.27273    Semester [3] = 7.30508
                         (cd, cc, bc, cc, bc, ex, aa, ab),      Semester [4] = 7.45455    Semester [4] = 7.34568
                         (bb, de, de, cd, ab, aa, ex),          Semester [5] = 7.45238    Semester [5] = 7.36765
                         (bc, dd, bc, bb, bc, ex, bc)}          Semester [6] = 7.52381    Semester [6] = 7.39431

vaibhavi =             {(cd, bb, bb, cd, ab, aa, aa),            Semester [1] = 7.58333    Semester [1] = 7.58333
                        (cd, bb, cd, bb, cc, ex, bb, ab, bb),    Semester [2] = 7.55263    Semester [2] = 7.56757
                        (ab, ab, cd, cc, cc, aa, ex, aa),        Semester [3] = 7.72727    Semester [3] = 7.62712
                        (ab, bc, bc, cc, aa, aa, ex, ab),        Semester [4] = 8.02273    Semester [4] = 7.73457
                        (ab, dd, bb, bc, ex, ex, ex),            Semester [5] = 8.30952    Semester [5] = 7.85294
                        (ab, aa, ab, bb, ex, ex, ex)}            Semester [6] = 9.02381    Semester [6] = 8.05285
*/
