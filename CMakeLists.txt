cmake_minimum_required(VERSION 3.27)
project(Project_Yesodot)

set(CMAKE_CXX_STANDARD 23)
add_executable(Project_Yesodot
        main.cpp
        User.cpp
        Doctor.cpp
        Patient.cpp
        Appointment.cpp
)