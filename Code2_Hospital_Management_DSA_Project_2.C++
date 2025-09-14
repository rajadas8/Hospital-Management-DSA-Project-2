// DSA Project 2: Hospital Management
#include<iostream>
#include<vector>
using namespace std;
int pid,did;
class Patients{
    public:
    string name;
    string gender;
    int age;
    int ID;
    Patients(string name,string gender,int age){
        this->name = name;
        this->gender = gender;
        this->age = age;
        ID = pid++;
    }
};
class Doctors{
    public:
    string name;
    string gender;
    int age;
    int ID;
    Doctors(string name,string gender,int age){
        this->name = name;
        this->gender = gender;
        this->age = age;
        ID = did++;
    }
};
class Appointments{
    public:
    int PatientID;
    int DoctorID;
    string Date;
    Appointments(int pid,int did,string date){
        this->PatientID = pid;
        this->DoctorID = did;
        this->Date = date;
    }
};
vector<Patients>allPatients;
vector<Doctors>allDoctors;
vector<Appointments>allAppointments;
bool IsPatientPresent(int id){
    int n = allPatients.size();
    bool ans = false;
    for(int i=0;i<n;i++){
        if(allPatients[i].ID == id) ans = true;
    }
    return ans;
}
bool IsDoctorPresent(int id){
    int n = allDoctors.size();
    bool ans = false;
    for(int i=0;i<n;i++){
        if(allDoctors[i].ID == id) ans = true;
    }
    return ans;
}
void AddPatients(){
    string name,gender;
    int age;
    cout<<"Enter The Patient Name: ";
    cin>>name;
    cout<<"Enter The Patient Gender: ";
    cin>>gender;
    cout<<"Enter The Patient Age: ";
    cin>>age;
    Patients temp(name,gender,age);
    allPatients.push_back(temp);
}
void AddDoctors(){
    string name,gender;
    int age;
    cout<<"Enter The Doctor Name: ";
    cin>>name;
    cout<<"Enter The Doctor Gender: ";
    cin>>gender;
    cout<<"Enter The Doctor Age: ";
    cin>>age;
    Doctors temp(name,gender,age);
    allDoctors.push_back(temp);
}
void ScheduleAppointment(){
    int PatientID,DoctorID;
    string Date;
    cout<<"Enter The Patient ID: ";
    cin>>PatientID;
    cout<<"Enter The Doctor ID: ";
    cin>>DoctorID;
    cout<<"Enter The Date in DD-MM-YYYY Format: ";
    cin>>Date;
    if(IsPatientPresent(PatientID)==false || IsDoctorPresent(DoctorID)==false){
        cout<<"Invalid PatientID or DoctorID\n";
        cout<<"Appointment Schedule unsuccessful\n";
        return;
    }
    Appointments temp(PatientID,DoctorID,Date);
    allAppointments.push_back(temp);
}
void ViewPatients(){
    int n = allPatients.size();
    for(int i=0;i<n;i++){
        cout<<"Patient ID: "<<allPatients[i].ID<<endl;
        cout<<"Patient Name: "<<allPatients[i].name<<endl;
        cout<<"Patient Gender: "<<allPatients[i].gender<<endl;
        cout<<"Patient Age: "<<allPatients[i].age<<endl;
        cout<<"------------------------------\n";
    }
}
void ViewDoctors(){
    int n = allDoctors.size();
    for(int i=0;i<n;i++){
        cout<<"Doctor ID: "<<allDoctors[i].ID<<endl;
        cout<<"Doctor Name: "<<allDoctors[i].name<<endl;
        cout<<"Doctor Gender: "<<allDoctors[i].gender<<endl;
        cout<<"Doctor Age: "<<allDoctors[i].age<<endl;
        cout<<"------------------------------\n";
    }
}
void ViewAppointments(){
    int n = allAppointments.size();
    for(int i=0;i<n;i++){
        cout<<"Appointment ID: "<<i+1<<endl;
        cout<<"Patient ID: "<<allAppointments[i].PatientID<<endl;
        cout<<"Doctor ID: "<<allAppointments[i].DoctorID<<endl;
        cout<<"Date: "<<allAppointments[i].Date<<endl;
        cout<<"------------------------------\n";
    }
}
int main(){
    int choice;
    pid = 1;
    did = 1;
    cout<<"----------Hospital Management Details----------\n";
    cout<<"1. Add Patients\n";
    cout<<"2. Add Doctors\n";
    cout<<"3. Schedule Appointment\n";
    cout<<"4. View Patients\n";
    cout<<"5. View Doctors\n";
    cout<<"6. View Appointments\n";
    cout<<"0. Exit\n";
    do{
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                AddPatients();
                break;
            case 2:
                AddDoctors();
                break;
            case 3:
                ScheduleAppointment();
                break;
            case 4:
                ViewPatients();
                break;
            case 5:
                ViewDoctors();
                break;
            case 6:
                ViewAppointments();
                break;
            case 0:
                cout<<"Exiting Program......\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }while(choice != 0);
    return 0;
}