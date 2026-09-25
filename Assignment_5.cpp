#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

class Patient
{
private:
    int patientId;
    char patientName[30];
    int age;

    static int totalPatients;

public:

    // Constructor
    Patient()
    {
        patientId = 0;
        age = 0;
    }

    // Member function
    void getData()
    {
        cout << "\nEnter Patient ID: ";
        cin >> patientId;

        cout << "Enter Patient Name: ";
        cin >> patientName;

        cout << "Enter Age: ";
        cin >> age;

        try
        {
            if (age <= 0)
            {
                throw age;
            }

            assert(age > 0);

            totalPatients++;

            cout << "Record Saved Successfully.";

            // File handling
            ofstream fout("patient.txt", ios::app);

            fout << patientId << endl;
            fout << patientName << endl;
            fout << age << endl;

            fout.close();
        }
        catch (int)
        {
            cout << "Invalid Age Entered.";

            patientId = 0;
            age = 0;
        }
    }

    // Display function
    void display()
    {
        if (patientId == 0)
        {
            return;
        }

        cout << "\nPatient ID: " << patientId;
        cout << "\nPatient Name: " << patientName;
        cout << "\nAge: " << age << endl;
    }

    // Static member function
    static void showTotalPatients()
    {
        cout << "\nTotal Valid Patients: "
             << totalPatients << endl;
    }
};

// Static member definition
int Patient::totalPatients = 0;

int main()
{
    // Array of objects
    Patient p[3];

    cout << "===== HOSPITAL MANAGEMENT SYSTEM =====\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nPatient " << i + 1 << endl;

        p[i].getData();
    }

    cout << "\n===== PATIENT DETAILS =====";

    for (int i = 0; i < 3; i++)
    {
        p[i].display();
    }

    Patient::showTotalPatients();

    return 0;
}