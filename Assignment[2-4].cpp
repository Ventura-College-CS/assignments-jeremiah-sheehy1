#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 20;
const int NUM_SCORES = 3;

struct Students{
    int sid;
    char sname[MAX_LEN];
    double scores[NUM_SCORES];
};

Students *makeStudents(int);
void printStudents(Students * const, int);
void sortStudents(Students * const, int);

int main(){
    const int N = 10;
    Students *ptr;

    ptr = makeStudents(N);
    printStudents(ptr, N);
    sortStudents(ptr, N);
    printStudents(ptr, N);
    delete ptr; 
}

Students *makeStudents(int N){
    ifstream ifs;
    Students *ptr = new Students[N];

    ifs.open("student.txt");
    if (ifs.fail()){
        cerr << "Error, Cannot Open\n";
        exit(0);
    }

    for (int i = 0; i < N; i++){
        ifs >> (ptr+i) ->sid >> (ptr+i)->sname;
        for (int j = 0; j < NUM_SCORES; j++){
            ifs >> (ptr+i)->scores[j];
            if (ifs.fail()){
                cerr << "File Error";
                exit(0);
            }
        }
    }
    ifs.close();
    return ptr;
}

void printStudents(Students * const ptr, int N){
    for (int i = 0; i < N; i++){
        cout << (ptr+i)->sid << " ";
        cout << (ptr+i)->sname << " ";
        for (int j = 0; j < NUM_SCORES; j++)
            cout << (ptr+i)-> scores[j] << " ";
        cout << endl;
    }
}

void sortStudents(Students *x, int N){
    int sum1=0, sum2=0;
    for( int i=0; i< N-1; i++ ) {
	    for( int j=0; j<N-1; j++) {
		    for(int k=0; k<3; k++) {
                sum1 += x[j].scores[k];
                sum2 += x[j+1].scores[k]; }    
		    if ( sum1 > sum2)
                swap(x[j], x[j+1]);
			sum1 = 0;
	        sum2 = 0;
	    }
    }
}
