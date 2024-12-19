#include "iostream"
#include "Appointment.h"
#include "Patient.h"
#include "Doctor.h"
#include "fstream"
#include "string"
#include "vector"
#include "limits"

#define PATIENTSFILE "Patients.txt"
#define DOCTORSFILE "Doctors.txt"
#define APPOINTMENTSFILE "Appointments.txt"

using namespace std;

vector<Patient> Patients = Patient::readFromFile(PATIENTSFILE);
vector<Doctor> Doctors = Doctor::readFromFile(DOCTORSFILE);
vector<Appointment> Appointments = Appointment::readFromFile(APPOINTMENTSFILE);


bool validate_id(long id){
    string id_str= to_string(id);
    if (id_str.length()!=9){
        return false;
    }
    for (int i = 0; i < Patients.size(); ++i){
        if (Patients[i].get_id()==id){
            return false;
        }
    }
    for (int i = 0; i < Doctors.size(); ++i){
        if (Doctors[i].get_id()==id){
            return false;
        }
    }
    return true;
}
bool validate_phone_number(string phone_num){
    if (phone_num.length()!=10){
        return false;
    }
    return true;
}
Patient Register_patient(){
    string Name,Phone_number,Health_provider;
    long long id,password;
    cout<<endl;
    cout<<"*=====================[Patient Registration]=====================*"<<endl;
    cout<<"System is ready to start registration process!"<<endl;
    cout<<"Please Enter you full name:"<<endl;
    cin.ignore();
    getline(cin,Name);
    do {
        cout<<"Please Enter your id number(9-Digits number):"<<endl;
        cin >> id;
        if (!validate_id(id)) {
            cout << "Invalid ID. Please try again." << endl;
        }
    } while(!validate_id(id));
    cout<<"Please Enter your health care provider:"<<endl;
    cin>>Health_provider;
    do {
        cout << "Please Enter your phone number:" << endl;
        cin >> Phone_number;
        if (!validate_phone_number(Phone_number)) {
            cout << "Invalid Phone number,please try again" << endl;
        }
    } while (!validate_phone_number(Phone_number));
    cout<<"Enter a strong password for you account (password must consist of numbers only):"<<endl;
    cin>>password;
    cout<<"Registration is OK!"<<endl;
    cout<<"*===================[Patient Registration Completed!]===================*"<<endl;
    Patient returned_patient(Name,id,Phone_number,password,Health_provider);
    returned_patient.saveToFile(PATIENTSFILE);
    return returned_patient;
}

Doctor Register_doctor(){
    string Name,Phone_number,area,specialization;
    long long id,password,licence;
    cout<<endl;
    cout<<"*=====================[Doctors Registration]=====================*"<<endl;
    cout<<"System is ready to start registration process!"<<endl;
    cout<<"Please Enter you full name:"<<endl;
    cin.ignore();
    getline(cin,Name);
    do {
        cout<<"Please Enter your id number(9-Digits number):"<<endl;
        cin >> id;
        if (!validate_id(id)){
            cout << "Invalid ID. Please try again." << endl;
        }
    } while (!validate_id(id));
    cout<<"Please Enter your medical licence number:"<<endl;
    cin>>licence;
    cout<<"Please Enter your medical specialization:"<<endl;
    cin>>specialization;
    cout<<"Please Enter where you receive your patients (area):"<<endl;
    cin>>area;
    do {
        cout << "Please Enter your phone number:" << endl;
        cin >> Phone_number;
        if (!validate_phone_number(Phone_number)) {
            cout << "Invalid Phone number,please try again" << endl;
        }
    } while (!validate_phone_number(Phone_number));
    cout<<"Enter a strong password for you account (password must consist of numbers only):"<<endl;
    cin>>password;
    cout<<"Registration is OK!"<<endl;
    cout<<"*===================[Doctors Registration Completed!]===================*"<<endl;
    Doctor returned_doctor(Name,id,Phone_number,password,area,specialization,licence);
    returned_doctor.saveToFile(DOCTORSFILE);
    return returned_doctor;
}
void displayWelcomeScreen() {
    cout<<endl;
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*             WELCOME TO HEALTH4U                *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*  Your health, your priority. Anytime, Anywhere *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << endl;
    cout<<  "==================================================" <<endl;
    cout << "                 Are you a: " << endl;
    cout << "                 1. Doctor" << endl;
    cout << "                 2. Patient" << endl;
    cout << "==================================================" << endl;
    cout << "          [To turn off system select 3]          " << endl;
    cout << endl;
    cout << "Please select your role (1-2): ";
}
void displayFirstScreen() {
    cout<<endl;
    cout << "==============================================" << endl;
    cout << "       Welcome to the Appointment System " << endl;
    cout << "==============================================" << endl;
    cout<<  "         What would you like to do?"<<endl;
    cout << "              1. Login" << endl;
    cout << "              2. Register" << endl;
    cout << "              3. Exit to main menu" << endl;
    cout << "==============================================" << endl;
    cout << "Please select an option (1-3): ";
}
int Login_Doctor() {
    long id = 0, password = 0;
    cout << "===============================" << endl;
    cout << "Enter your ID (9-Digits):" << endl;
    cin >> id;
    cout << "Enter your password:" << endl;
    cin >> password;
    cout << "===============================" << endl;
    for (int i = 0; i < Doctors.size(); ++i) {
        if (Doctors[i].get_id() == id && Doctors[i].get_password() == password) {
            cout << "Login successful!" << endl;
            return i;
        }
    }
    return -1;
}

int Login_Patient(){
    long id=0,password=0;
    cout << "===============================" << endl;
    cout << "Enter your ID (9-Digits):"<<endl;
    cin >>id;
    cout << "Enter your password:"<<endl;
    cin>> password;
    cout << "===============================" << endl;
    for (int i = 0; i < Patients.size(); ++i){
        if (Patients[i].get_id()==id && Patients[i].get_password()==password){
            cout<<"Login successful!"<<endl;
            return i;
        }
    }
    return -1;
}
void displayDoctorMenu(){
    cout << "*************************************************" << endl;
    cout << "*              WELCOME, DOCTOR!                 *" << endl;
    cout << "*************************************************" << endl;
    cout << "*       Here are your available options:        *" << endl;
    cout << "*************************************************" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View Appointments" << endl;
    cout << "3. Mark Unavailable Dates" << endl;
    cout << "4. Update Past Appointments and Add Summary" << endl;
    cout << "5. Add Appointments" << endl;
    cout << "6. View Patient Ratings" << endl;
    cout << "7. Logout and save your actions" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice (1-7): "<<endl;
    cout << "-------------------------------------------------" << endl;
}
void displayPatientMenu(){
    cout << "*************************************************" << endl;
    cout << "*              WELCOME, PATIENT!                *" << endl;
    cout << "*************************************************" << endl;
    cout << "*        Here are your available options:       *" << endl;
    cout << "*************************************************" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View My Scheduled Appointments" << endl;
    cout << "3. View All Available Appointments (with Filters)" << endl;
    cout << "4. Book an Appointment" << endl;
    cout << "5. Cancel an Appointment" << endl;
    cout << "6. View Past Appointment Summaries" << endl;
    cout << "7. Rate a Doctor for a Past Appointment" << endl;
    cout << "8. View First Aid Instructions" << endl;
    cout << "9. Logout and save your actions" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter your choice (1-9): "<<endl;
    cout << "-------------------------------------------------" << endl;
}
void createAppointmentsForDate(const string &date, long doctorID, const string &area,string specialization){
    for (int hour = 9; hour <= 17; ++hour) {
        string time = (hour < 10 ? "0" : "") + to_string(hour) + ":00";
        Appointment newAppointment(date, time,area,doctorID,specialization);
        newAppointment.saveToFile(APPOINTMENTSFILE);
        Appointments.push_back(newAppointment);
    }
    cout << "Appointments created successfully for date " << date << " from 9:00 to 17:00." << endl;
}
void display_my_profile(){
    cout << "*************************************************" << endl;
    cout << "*                 My Profile                    *" << endl;
    cout << "*************************************************" << endl;
    cout << "*             1.View My Profile                 *" <<endl;
    cout << "*             2.Edit my profile                 *" <<endl;
    cout << "*************************************************" <<endl;
}
void display_doctors_details(int index){
    cout << "*************************************************" <<endl;
    cout << "*                Doctors Details:               *" <<endl;
    cout << "*************************************************" <<endl;
    cout << "*Name: "<<Doctors[index].get_name()<<endl;
    cout << "*Phone number: "<<Doctors[index].get_phone()<<endl;
    cout << "*Specialization: "<<Doctors[index].get_specialization()<<endl;
    cout << "*Area of reception: "<<Doctors[index].get_receptionarea()<<endl;
    cout << "*Licence number: "<<Doctors[index].get_licence()<<endl;
    cout << "*ID: "<<Doctors[index].get_id()<<endl;
    cout << "*************************************************" <<endl;
}
void display_patients_details(int index){
    cout << "*************************************************" <<endl;
    cout << "*                Patients Details               *" <<endl;
    cout << "*************************************************" <<endl;
    cout << "*Name: "<<Patients[index].get_name()<<endl;
    cout << "*Phone number: "<<Patients[index].get_phone()<<endl;
    cout << "*Health Care Provider: "<<Patients[index].get_health_provider()<<endl;
    cout << "*ID: "<<Patients[index].get_id()<<endl;
    cout << "*************************************************" <<endl;
}
void display_doctors_changes() {
    cout << "*************************************************" << endl;
    cout << "*                Edit my profile                *" << endl;
    cout << "*************************************************" << endl;
    cout << "*         What would you like to change?:       *" << endl;
    cout << "*            1. Phone number                    *" << endl;
    cout << "*            2. Specialization                  *" << endl;
    cout << "*            3. Area of Reception               *" << endl;
    cout << "*************************************************" << endl;
    cout<<endl;
}
void display_patient_changes(){
    cout << "*************************************************" << endl;
    cout << "*                Edit my profile                *" << endl;
    cout << "*************************************************" << endl;
    cout << "*         What would you like to change?:       *" << endl;
    cout << "*            1. Phone number                    *" << endl;
    cout << "*            2. Health Care provider            *" << endl;
    cout << "*************************************************" << endl;
    cout << endl;
}

int calculate_doc_app_num(int index){
    int counter=0;
    for (int i = 0; i <Appointments.size(); ++i){
        if (Appointments[i].check_if_booked() && Appointments[i].get_doc_id()==Doctors[index].get_id() && !Appointments[i].check_if_over()){
            counter++;
        }
    }
    return counter;
}
float calculate_doc_rating(int index){
    float counter=0;
    float rating=0;
    for (int i = 0; i < Appointments.size(); ++i) {
        if (Appointments[i].get_doc_id()==Doctors[index].get_id() && Appointments[i].check_if_over() && Appointments[i].get_rating()!=0){
            counter++;
            rating+=Appointments[i].get_rating();
        }
    }
    return rating/counter;
}
void Save_all_data(){
    ofstream file1(PATIENTSFILE, ios::out);
    if (!file1) {
        cout<<"Error: Could not open the file: " << PATIENTSFILE << std::endl;
        return;
    }
    file1.close();
    ofstream file2(DOCTORSFILE, ios::out);
    if (!file2) {
        cout<<"Error: Could not open the file: " << PATIENTSFILE << std::endl;
        return;
    }
    file2.close();
    ofstream file3(APPOINTMENTSFILE, ios::out);
    if (!file3) {
        cout<<"Error: Could not open the file: " << PATIENTSFILE << std::endl;
        return;
    }
    file3.close();
    for (int i = 0; i < Doctors.size(); ++i){
        Doctors[i].saveToFile(DOCTORSFILE);
    }
    for (int i = 0; i < Patients.size(); ++i){
        Patients[i].saveToFile(PATIENTSFILE);
    }
    for (int i = 0; i < Appointments.size(); ++i){
        Appointments[i].saveToFile(APPOINTMENTSFILE);
    }
}
string Get_Doctors_Name(long doc_id){
    for (int i = 0; i < Doctors.size(); ++i){
        if (Doctors[i].get_id()==doc_id){
            return Doctors[i].get_name();
        }
    }
}
string Get_Patients_Name(long pat_id){
    for (int i = 0; i < Patients.size(); ++i){
        if (Patients[i].get_id()==pat_id){
            return Patients[i].get_name();
        }
    }
}
void Print_Appointments(int index){
    int counter=0;
    for (int i = 0; i < Appointments.size(); ++i){
        if (Appointments[i].get_pat_id() == Patients[index].get_id() && !Appointments[i].check_if_over() && Appointments[i].check_if_booked()){
            Appointments[i].Print_Details();
            cout<<" INDEX - "<<i<<" .Dr- "<<Get_Doctors_Name(Appointments[i].get_doc_id())<<endl;
            counter++;
            cout<<"********************************************"<<endl;
        }
    }
    if (counter==0){
        cout<<"No appointments to display!"<<endl;
    }
}
void Print_Past_Appointments(int index){
    int counter=0;
    for (int i = 0; i < Appointments.size(); ++i){
        if (Appointments[i].get_pat_id()==Patients[index].get_id() && Appointments[i].check_if_over()){
            cout<<"Appointment summary of: "<<Appointments[i].get_date()<<" at "<<Appointments[i].get_time()<<endl;
            cout<<"Doctor said: "<<endl;
            Appointments[i].Print_Summary();
            counter++;
            cout<<endl;
        }
    }
    if (counter==0){
        cout<<"No appointments to display!"<<endl;
    }
}
int Find_Appointment_Index(string date,string time){
    for (int i = 0; i < Appointments.size(); ++i){
        if (Appointments[i].get_time()==time && Appointments[i].get_date()==date){
            return i;
        }
    }
}

void digitalFirstAidGuide() {
    int choice;
    do {
        cout << "Digital First Aid Guide" << endl;
        cout << "Please choose an emergency to see the instructions:" << endl;
        cout << "1. Choking" << endl;
        cout << "2. Heart Attack" << endl;
        cout << "3. Stroke" << endl;
        cout << "4. Severe Bleeding" << endl;
        cout << "5. Burns" << endl;
        cout << "6. Fainting" << endl;
        cout << "7. Fractures" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Choking:" << endl;
                cout << "- Ask the person if they can cough or speak. If they cannot, they are choking." << endl;
                cout << "- Perform the Heimlich maneuver: Stand behind them, wrap your arms around their waist, and give quick upward thrusts." << endl;
                cout << "- If the object is not expelled, call emergency services immediately." << endl;
                cout << "- For infants: Use gentle back blows and chest compressions." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 2:
                cout << "Heart Attack:" << endl;
                cout << "- Help the person to sit down and keep calm." << endl;
                cout << "- Ask if they have medication like aspirin; if yes, let them take it unless allergic." << endl;
                cout << "- Call emergency services immediately and provide details of the symptoms." << endl;
                cout << "- Monitor their breathing and be ready to perform CPR if necessary." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 3:
                cout << "Stroke:" << endl;
                cout << "- Use the FAST method: Face drooping, Arm weakness, Speech difficulty, Time to call emergency services." << endl;
                cout << "- Do not give the person food or drink." << endl;
                cout << "- Keep them calm and in a comfortable position until help arrives." << endl;
                cout << "- Monitor their breathing and be prepared to perform CPR if they lose consciousness." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 4:
                cout << "Severe Bleeding:" << endl;
                cout << "- Apply firm pressure directly to the wound with a clean cloth or bandage." << endl;
                cout << "- If possible, elevate the injured area above heart level to reduce bleeding." << endl;
                cout << "- Do not remove the cloth if it becomes soaked; instead, add another layer." << endl;
                cout << "- Call emergency services immediately and keep the person calm." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 5:
                cout << "Burns:" << endl;
                cout << "- Cool the burn under running water for at least 10 minutes." << endl;
                cout << "- Do not apply ice, creams, or ointments to the burn." << endl;
                cout << "- Cover the burn with a clean, non-stick dressing or cloth." << endl;
                cout << "- For severe burns, call emergency services and do not remove any clothing stuck to the burn." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 6:
                cout << "Fainting:" << endl;
                cout << "- Lay the person down flat and elevate their legs to improve blood flow." << endl;
                cout << "- Ensure there is fresh air; loosen any tight clothing." << endl;
                cout << "- If the person does not regain consciousness within 1-2 minutes, call emergency services." << endl;
                cout << "- Monitor their breathing and keep them calm when they regain consciousness." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 7:
                cout << "Fractures:" << endl;
                cout << "- Immobilize the injured area by using a splint or padding to reduce movement." << endl;
                cout << "- Do not try to straighten the bone or push it back in place." << endl;
                cout << "- Apply an ice pack to reduce swelling, but do not apply it directly to the skin." << endl;
                cout << "- Call emergency services and keep the person calm until help arrives." << endl;
                cout << "Emergency Number: 101" << endl;
                break;
            case 0:
                cout << "Exiting the guide. Stay safe!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
        cout << endl;
    } while (choice != 0);
}
void BookAppointmentByIndex(int pat_index){
    int appointment_index;
    cout << "******* Appointment Booking *******" << endl;
    cout << "Enter the index of the appointment you want to book:" << endl;
    cin >> appointment_index;
    if (appointment_index < 0 || appointment_index >= Appointments.size()) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }
    if (Appointments[appointment_index].check_if_booked() || Appointments[appointment_index].check_if_unvail()){
        cout << "The selected appointment is not available. Please choose a different one." << endl;
        return;
    }
    Appointments[appointment_index].Book_Appointment(Patients[pat_index].get_id());
    cout << "Appointment booked successfully!" << endl;
}
void display_doctors_scheduled_app(int index){
    cout<<"===================================================" <<endl;
    cout<<" Printing all appointments for "<<Doctors[index].get_name()<<""<<endl;
    for (int i = 0; i < Appointments.size(); ++i){
        if (Appointments[i].get_doc_id() == Doctors[index].get_id() && Appointments[i].check_if_booked() && !Appointments[i].check_if_over()){
            Appointments[i].Print_Details();
            cout<<" INDEX -"<<i<<" .Patient - "<<Get_Patients_Name(Appointments[i].get_pat_id())<<endl;
            cout<<endl;
        }
    }
}
