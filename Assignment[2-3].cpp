#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double *makeNumbers(){
	double *p = new double[10];

	srand(time(NULL));
	for(int i=0; i<10; i++){
		p[i] = rand() % 100; 
	}
	return p;

}

void sortNumbers(double *values, int numValues){
  int i, j;
  double temp;

  for (i = 0; i < numValues-1; i++){
    for (j = 0; j < numValues-i-1; j++){
      if(values[j] > values[j+1]){
        temp = values[j];
        values[j] = values[j+1];
        values[j+1] = temp;
      }
    }
  }
}

void printNumbers(double *arr, int N){
	for(int i=0; i<N;i++)
		cout << arr[i] << " ";
	cout << endl;
}

void deleteNumbers(double *arr){
	delete arr;
}

int main(){
	const int N=10;
	double *ptr = makeNumbers();
  printNumbers(ptr,N);
  sortNumbers(ptr,N);
  printNumbers(ptr,N);
  deleteNumbers(ptr);
}