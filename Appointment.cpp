//
// Created by ilanz on 21/11/2024.
//
#include "iostream"
#include "Appointment.h"
using namespace std;


void Appointment::Add_Summary(string summary){
    Doctor_Summary=summary;
    is_over= true;
}

void Appointment::Book_Appointment(long Patient_ID){
    if (is_booked){
        cout<<"This appointment is already booked"<<endl;
    }
    else{
        this->Patient_ID=Patient_ID;
        is_booked= true;
    }
}

void Appointment::Print_Details(){
    cout<<Date<<" , "<<Time<<" at "<<Area;
}

void Appointment::Print_Summary(){
    cout<<Doctor_Summary;

}

bool Appointment::check_if_booked(){
    return is_booked;
}

bool Appointment::check_if_over() {
    return is_over;
}

void Appointment::Cancel_Appointment(){
    if (is_booked) {
        is_booked = false;
        Patient_ID=0;
    }
    else
        cout<<"This appointment is not booked."<<endl;
}
Appointment::Appointment(const string date, const string time,const string Area,long Doc_id,string specialization){
    this->Date=date;
    this->Time=time;
    this->specialization=specialization;
    is_booked=0;
    is_over=0;
    is_canceled=0;
    Doctor_ID=Doc_id;
    Patient_ID=0;
    this->Area=Area;
    rating=0;
    Doctor_Summary="Not given yet";
}
void Appointment::Make_Appointment_Unavail(){
    is_canceled=1;
}
void Appointment::saveToFile(const string &filename) const{
    ofstream file(filename, ios::app);
    if (file.is_open()){
        file<<Date<<endl;
        file<<Time<<endl;
        file<<Doctor_Summary<<endl;
        file<<is_over<<endl;
        file<<is_booked<<endl;
        file<<is_canceled<<endl;
        file<<Doctor_ID<<endl;
        file<<Patient_ID<<endl;
        file<<Area<<endl;
        file<<rating<<endl;
        file<<specialization<<endl;
        file << "--------------------" << endl;
        file.close();
    }
    else{
        cout<<"Error: Could not open file for writing." << endl;
    }
}

vector<Appointment> Appointment::readFromFile(const string &filename){
    ifstream file(filename);
    vector<Appointment> appointments;
    if (file.is_open()) {
        string date, time, doctorSummary, area,specialization;
        bool isOver, isBooked, isCanceled;
        long doctorID, patientID;
        int rating;
        while (getline(file, date)) {
            if (date == "--------------------"){
                continue;
            }
            getline(file, time);
            getline(file, doctorSummary);
            file >> isOver;
            file.ignore();
            file >> isBooked;
            file.ignore();
            file >> isCanceled;
            file.ignore();
            file >> doctorID;
            file.ignore();
            file >> patientID;
            file.ignore();
            getline(file, area);
            file >> rating;
            file.ignore();
            file >> specialization;
            file.ignore();
            Appointment appointment(date,time,area,doctorID,specialization);
            appointment.Add_Summary(doctorSummary);
            appointment.is_over = isOver;
            appointment.is_booked = isBooked;
            appointment.is_canceled = isCanceled;
            appointment.Doctor_ID = doctorID;
            appointment.Patient_ID = patientID;
            appointment.Area = area;
            appointment.rating=rating;
            appointment.specialization=specialization;
            appointments.push_back(appointment);
        }
        file.close();
    }
    else {
        cout << "Error: Could not open file for reading." << endl;
    }
    return appointments;
}

string Appointment::get_date() const {
    return Date;
}

string Appointment::get_time() const {
    return Time;
}

string Appointment::get_area() const {
    return Area;
}

long Appointment::get_doc_id() const {
    return Doctor_ID;
}

long Appointment::get_pat_id() const {
    return Patient_ID;
}

void Appointment::set_doc_id(long doc_id) {
    this->Doctor_ID=doc_id;
}

void Appointment::set_pat_id(long pat_id) {
    this->Patient_ID=pat_id;
}

int Appointment::get_rating() const {
    return rating;
}

string Appointment::get_specialization() const {
    return specialization;
}

bool Appointment::check_if_unvail() const {
    return this->is_canceled;
}

void Appointment::Rate_doc(int rate){
    this->rating=rate;
}


