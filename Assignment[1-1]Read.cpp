#include <iostream>
#include <fstream>
using namespace std;


struct Student{
  int id;
  char sname[20];
  double score[2];
  double sum;
  double avg;
};

void printStudent(Student s);
void findStudent(Student s[], int numID);

int main(){

    ifstream ifs;

    Student s[10];

    ifs.open("students.txt");

    if(ifs.fail()){
      cout << "Could not open the file\n";
      exit(0);
    }

    for(int i = 0; i < 10; i++){
        ifs.read((char *)&s[i], sizeof(s));
        cout << "ID" << s[i].id << "\t";
        cout << "Name" << s[i].sname << "\t";
        cout << "Average" << s[i].avg << "\t";
    }

    int numID;
    cout << "Enter The Student ID Number: ";
    cin >> numID;
    findStudent(s, numID);



}

void findStudent(Student s[], int std){
    int flag = 0;
    for(int i = 0; i < 10; i++){
        if(s[i].id == std){
            printStudent(s[i]);
            flag = 1;
        }
    }
    if(!flag){
        cout << "No matching ID\n";
    }

}

void printStudent(Student s){
    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.sname << endl;
    cout << "Score1: " << s.score[0] << endl;
    cout << "Score2: " << s.score[1] << endl;
    cout << "Sum: " << s.sum << endl;
    cout << "Avg: " << s.avg << "\n" << endl;
}