#include <bits/stdc++.h>
#include <conio.h>
// #include <Project_Data.h>
using namespace std;

struct Patient
{
    string name;
    int age;
    bool gender;
};

struct appointment 
{
    string date;
    string doctorName;
};

map<int, pair<Patient, appointment>> patient_appointment_data = 
{
    {1, { Patient{"Ahmed Ali", 34, true},  appointment{"2024-06-10", "Dr. Mariam"   } } },
    {2, { Patient{"Abduk karim", 56,  false},  appointment{"2024-06-15", "Dr. Shezad" } } },
    {3, { Patient{"Abdulullah", 95, true},  appointment{"2024-06-20", "Dr. Umar"   } } },
    {4, { Patient{"Kamran", 25,    false},  appointment{"2024-06-25", "Dr. Adnan"} } },
    {5, { Patient{"Nasir", 30,       true},  appointment{"2024-06-30", "Dr. Jamil"} } },
    {6, { Patient{"Junaid", 40,   true},  appointment{"2024-07-05", "Dr. Basil"  } } }
};

class System
{
public:
//--------------------------------------------------
// Patient Data
//--------------------------------------------------
    void patients_menu()
    {
        string input;
        char choice;
        bool validInput = false;
        
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |         Patients         |\n\n\n\n";
        cout<<"1) Add Patient"<<endl;
        cout<<"2) Remove Patient"<<endl;
        cout<<"3) View All Patients"<<endl;
        cout<<"4) Search Patient"<<endl;
        cout<<"5) Main Menu"<<endl;
        cout<<endl;
        
            while (!validInput) 
            {
                cout << "Choose: ";
                cin >> input;
                system("cls");
        
                if (input.length() == 1 && isdigit(input[0]))
                {
                    choice = input[0];
                    validInput = true;
                } else {
                    cout<<"Invalid Input...\n\n"<<endl;
                    system("pause");
                    patients_menu();
                    cin.ignore();
                }
            }
        
            switch(choice)
            {
            case '1':
            addPatient_map();
            break;
            
            case '2':
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |  Deleting Patient Record |\n\n\n\n";
            int id;
            cout << "Enter patient ID to remove: ";
            cin >> id;
            removePatient_map(id);
            break;
        
            case '3':
            viewAllPatients();
            break;

            case '4':
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |      Search Patient      |\n\n\n\n";
            cout << "Enter patient ID to Search: ";
            cin >> id;
            searchPatient(id);
            break;

            case '5':
            main_menu();
            break;
        
            default:
            system("cls");
            cout<<"Invalid Input...\n\n";
            system("pause");
            patients_menu();
            }
    }

    void addPatient_map()
    {
        
        Patient tmp_obj;
        appointment tmp_obj1;
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |    New Patient Record    |\n\n\n\n";
        cin.ignore();
        cout << "Patient Name: ";
        getline(cin, tmp_obj.name);
        cout << "\nAge: ";
        cin >> tmp_obj.age;
        cout << "\nGender: \nPress: 1) Male 0) Female \nChoose: ";
        cin >> tmp_obj.gender;

        auto x = patient_appointment_data.end();
        patient_appointment_data.insert({x->first+1,{tmp_obj,tmp_obj1}});
        cout<<"\nID: "<<x->first<<endl;
        cout << "Patient Added...\n";
        system("pause");
        patients_menu();
        cout << endl;
    }

    void removePatient_map(int &id)
    {
        auto person = patient_appointment_data.find(id);
        
        if (person != patient_appointment_data.end())
        {
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |  Patient Record Deleted  |\n\n\n\n";
            patient_appointment_data.erase(person);
            cout<<"Patient Removed:"<<endl;
            cout<<"Name: "<<person->second.first.name<<endl;
            cout<<"ID: "<<id;
            cout<<"\n\n"<<endl;
            system("pause");
            patients_menu();
        }
        else
        {
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |    Patient Not Found     |\n\n\n";
            cout<<"No Patient Found with ID: "<<id;
            cout<<endl<<endl<<endl;
            system("pause");
            patients_menu();
        }
    }

    void searchPatient(int &id)
    {
        
        auto person = patient_appointment_data.find(id);
        if(person != patient_appointment_data.end())
        {
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |      Patient Found       |\n\n\n";
            cout<<"Patient Details"<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<person->second.first.name<<endl;
            cout<<"Age:"<<person->second.first.age<<endl;
            if(person->second.first.gender == 1)
            {
                cout<<"Gender: Male"<<endl;
            }
            else
            {
                cout<<"Gender: Female"<<endl;
            }
            cout<<"\n\n\n\n"<<endl;
            system("pause");
            patients_menu();
        }
        else
        {
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |     No Patient Found     |\n\n\n";
            cout<<"No Patient Found with ID: "<<id;
            cout<<endl<<endl<<endl;
            system("pause");
            patients_menu();
        }
    }

    void viewAllPatients()
    {
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |     Patients Records     |\n\n\n";

        cout << setw(4) << left << "ID"
             << setw(15) << left << "Name"
             << setw(10) << left << "Gender"
             << setw(4) << left << "Age" << endl;
        cout << "-------------------------------------" << endl;

        for (auto &i : patient_appointment_data)
        {
            cout << setw(4) << left << i.first
                 << setw(15) << left << i.second.first.name;
            if (i.second.first.gender == 1)
            {
                cout << setw(10) << left << "Male";
            }
            else
            {
                cout << setw(10) << left << "Female";
            }
            cout << setw(4) << left << i.second.first.age << endl;
        }
        cout << endl;
        cout << endl;
        system("pause");
        patients_menu();
    }
//--------------------------------------------------
// Appointment Manipulation
//--------------------------------------------------
    void appointments()
    {
        string input;
        char choice;
        bool validInput = false;

        system("cls");
        cout << "----------------------------------------------" << endl;
        cout << "        Health Care Management System\n";
        cout << "----------------------------------------------" << endl << endl;
        cout << "          |        Appointments       |\n\n\n\n";
        cout << "1) Add New" << endl;
        cout << "2) View" << endl;
        cout << "3) Edit" << endl;
        cout << "4) Remove" << endl;
        cout << "5) Main Menu" << endl;
        cout << endl;

        while (!validInput) 
        {
        cout << "Choose: ";
        cin >> input;
        system("cls");

        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0];
            validInput = true;
        } 
        else 
        {
            cout<<"Invalid Input...\n\n";
            system("pause");
            appointments();
            cin.ignore();
        }
        }

        switch (choice)
        {
        case '1':
            addAppointment();
            break;
            
        case '2':
            viewAppointments();
            break;

        case '3':
            editAppointments();
            break;

        case '4':
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |   Deleting Appointment   |\n\n\n\n";
            int id;
            cout << "Enter Appointment ID to remove: ";
            cin >> id;
            removeAppointments(id);
            break;

        case '5':
            main_menu();
            break;
            
        default:
            cout << "Invalid Input...\n\n";
            system("pause");
            appointments();
            break;
        }
    }

    void addAppointment()
    {
        Patient tmp_pat;
        appointment tmp_app;

        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |      New Appointment     |\n\n";

        cout << "\nPatient Name: ";
        cin.ignore();
        getline(cin, tmp_pat.name);
        cout << "\nAge: ";
        cin >> tmp_pat.age;
        cout << "\nGender: \nPress: 1) Male 0) Female \nChoose: ";
        cin >> tmp_pat.gender;

        cout<<"\nDate: YYYY-MM-DD > ";
        cin>>tmp_app.date;
        cout << "Doctor Name: ";
        cin.ignore();
        getline(cin, tmp_app.doctorName);

        int id;
        for(auto &i : patient_appointment_data)
        {
            id = i.first;
        }
        patient_appointment_data.insert({id+1,{tmp_pat,tmp_app}});
        cout << endl;
        cout<<"ID: "<<id<<endl;
        cout << "Appointment Scheduled...";
        getch();
        appointments();

    }

    void viewAppointments() 
    {
        system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |     All Appointments     |\n\n\n";

        cout << setw(4) << left << "ID"
             << setw(15) << left << "Name"
             << setw(15) << left << "Doctor Name"
             << setw(12) << left << "Date" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto &person : patient_appointment_data)
        {
            cout << setw(4) << left << person.first
                 << setw(15) << left << person.second.first.name
                 << setw(15) << left << person.second.second.doctorName
                 << setw(12) << left << person.second.second.date << endl;
        }
        cout << endl;
        system("pause");
        appointments();
    }

    void removeAppointments(int &id)
    {
        system("cls");
        auto app = patient_appointment_data.find(id);

        if (app != patient_appointment_data.end())
        {
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |   Appointment Deleted    |\n\n\n\n";
            patient_appointment_data.erase(app);
            cout<<"Appointment Removed:"<<endl;
            cout<<"Patient Name: "<<app->second.first.name<<endl;
            cout<<"ID: "<<id;
            cout<<"\n\n"<<endl;
            system("pause");
            appointments();
        }
        else
        {
            system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |  Appointment Not Found   |\n\n\n";
            cout<<"No Appointment Found with ID: "<<id;
            cout<<endl<<endl<<endl;
            system("pause");
        system("pause");
        appointments();
        }

    }

    void editAppointments()
    {
        int id;
    system("cls");
    cout<<"----------------------------------------------"<<endl;
    cout<<"        Health Care Management System\n";
    cout<<"----------------------------------------------"<<endl<<endl;
    cout<<"          |  Edit Appointment Data   |\n\n\n";
    cout<<"Enter Appointment ID to edit: ";
    cin>>id;

    auto it = patient_appointment_data.find(id);
    if (it != patient_appointment_data.end())
    {
        Patient &patient = it->second.first;
        appointment &appt = it->second.second;

        cout<<"\nCurrent Patient Name: "<<patient.name<<endl;
        cout<<"Enter New Patient Name (or press enter to keep current): ";
        cin.ignore();
        string newName;
        getline(cin, newName);
        if (!newName.empty())
        {
            patient.name = newName;
        }

        cout<<"\nCurrent Age: "<<patient.age<<endl;
        cout<<"Enter New Age (or 0 to keep current): ";
        int newAge;
        cin>>newAge;
        if (newAge != 0)
        {
            patient.age = newAge;
        }

        cout<<"\nCurrent Gender: "<<(patient.gender ? "Male" : "Female")<<endl;
        cout<<"Enter New Gender (1 for Male, 0 for Female, or -1 to keep current): ";
        int newGender;
        cin>>newGender;
        if (newGender != -1)
        {
            patient.gender = newGender;
        }

        cout<<"\nCurrent Appointment Date: "<<appt.date<<endl;
        cout<<"Enter New Date (or press enter to keep current): ";
        cin.ignore();
        string newDate;
        getline(cin, newDate);
        if (!newDate.empty())
        {
            appt.date = newDate;
        }

        cout<<"\nCurrent Doctor Name: "<<appt.doctorName<<endl;
        cout<<"Enter New Doctor Name (or press enter to keep current): ";
        string newDoctorName;
        getline(cin, newDoctorName);
        if (!newDoctorName.empty())
        {
            appt.doctorName = newDoctorName;
        }

        cout<<"\nAppointment Updated Successfully!"<<endl;
    }
    else
    {
        cout<<"No Appointment Found with ID: "<<id<<endl;
    }

    system("pause");
    appointments();
    }

//--------------------------------------------------
// Main Menu
//--------------------------------------------------
void main_menu()
{
    string input;
    char choice;
    bool validInput = false;

    system("cls");
    cout << "----------------------------------------------" << endl;
    cout << "        Health Care Management System\n";
    cout << "----------------------------------------------" << endl << endl;
    cout << "          |        Admin Menu        |\n\n\n\n";
    
    cout << "1) Patients" << endl;
    cout << "2) Appointments" << endl;
    cout << "3) Logout" << endl;

    while (!validInput)
    {
        cout << "\nChoose: ";
        cin >> input;
        system("cls");

        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0];
            validInput = true;
        }
        else
        {
            cout << "**Invalid Input**\n\n";
            system("pause");
            main_menu();
            cin.ignore();
        }
    }

    switch (choice)
    {
    case '1':
        patients_menu();
        break;

    case '2':
        appointments();
        break;

    case '3':
        cout << "----------------------------------------------" << endl;
        cout << "        Health Care Management System\n";
        cout << "----------------------------------------------" << endl << endl;
        cout << "          |       System Closed      |\n\n\n\n";
        cout << "                    Logged Out      \n\n\n\n\n";
        exit(0);
    default:
        system("cls");
        cout << "**Invalid Input**\n\n";
        system("pause");
        main_menu();
    }
}

}; //System class ends

int main()
{
    System run;
    // run.main_menu(); 

    string storedUsername , storedPassword,
           inputUsername  , inputPassword;
    bool access = false;

    system("cls");
    while (!access)
    {
        cout << "----------------------------------------------" << endl;
        cout << "        Health Care Management System\n";
        cout << "----------------------------------------------" << endl << endl;
        cout << "          |      System Started      |\n\n\n\n";
        system("pause");

        system("cls");
        cout << "----------------------------------------------" << endl;
        cout << "        Health Care Management System\n";
        cout << "----------------------------------------------" << endl << endl;
        cout << "          |Admin Login Authentication|\n\n";
        cout << "Username: ";
        cin >> inputUsername;
        cout << "Password: ";
        cin >> inputPassword;

        // Read the stored credentials from the file
        ifstream inFile("data.txt");
        string line;
        getline(inFile, line);
        storedUsername = line.substr(line.find(": ") + 2);
        storedPassword = line.substr(line.find(": ") + 2);
        getline(inFile, line);
        inFile.close();
   
        if (inputUsername == storedUsername && inputPassword == storedPassword)
        {
            system("cls");
            cout << "----------------------------------------------" << endl;
            cout << "        Health Care Management System\n";
            cout << "----------------------------------------------" << endl << endl;
            cout << "          |        Login Done        |\n\n";
            access = true;
            cout << endl;
            cout << endl;
            system("pause");
            run.main_menu();
        }
        else
        {
            system("cls");
            cout << "Username or password is incorrect." << endl;
            system("pause");
        }
    }

    return 0;
}