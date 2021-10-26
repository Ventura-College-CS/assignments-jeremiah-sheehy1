#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void makeArray(int array[], int N);
void printArray(int array[], int N);
void bubbleSort(int array[], int N);
int  binarySearch(int [], int, int);
int  linearSearch(int [], int, int);

int main(){
    const int N= 1024; 
	const int tries = 10000;
    int array[N]; 
    int target, foundindex;
	int total_linear = 0;
    int total_binary = 0;
	


	srand(time(0));
	makeArray(array, N);

	for (int i = 0; i < tries; i++){
        target = array[rand() % N];
        total_linear += linearSearch(array, N, target);
    }

	bubbleSort(array, N);
	printArray(array, N);
	for(int trynumber = 0; trynumber < tries; trynumber++){
		target = array[rand() % N];
		total_binary += binarySearch(array, N, target);
	}
	
    cout << "The average comparision numbers of Linear Search is " << total_linear / tries << endl;
    cout << "The average comparision numbers of binary Search is " << total_binary / tries << endl;
}
void makeArray(int array[], int N){
		for(int i = 0; i < N; i++){
			array[i] = rand() % (100000) + 1; 
        }
}
void printArray(int array[], int N){
    for (int i = 0; i < N; i++){
        cout << array[i] << "\t";
        if(i % 8 == 7){
            cout << endl;
        }
    }
}
void bubbleSort(int array[], int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j + 1]);
            }
        }
    }
}
int binarySearch(int array[], int N, int target){
	int first, last, mid, comp;

	first = comp = 0;
	last = N - 1;

	while(first <= last){
		mid = (first + last ) / 2;
		comp++;
		if(target == array[mid]){
			return comp;
		}
		else if(target < array[mid]){ 
			last = mid - 1;
        }
		else{ 
		 	first = mid + 1;
        }
	}
	return comp;
}
int linearSearch(int array[], int N, int target){
    for(int i = 0; i < N; i++)
        if(array[i] == target)
            return i + 1;
    return 0;
}