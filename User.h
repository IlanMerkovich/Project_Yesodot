
#ifndef PROJECT_USER_H
#define PROJECT_USER_H
#include "string"
#include "vector"
#include "Appointment.h"
using namespace std;
class User{
protected:
    string Name;
    long long id;
    long Password;
    string Phone_Number;
public:
    User(string Name,long Id,string Phone_num,long Password);
    virtual char *get_type()const=0;
    string get_name()const;
    long long get_id()const;
    long get_password()const;
    string get_phone()const;
};


#endif //PROJECT_USER_H