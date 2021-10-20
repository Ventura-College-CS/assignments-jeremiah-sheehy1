#include <iostream>
using namespace std;

int main(){

const int N = 10;
int numbers[N] = {5,7,2,4,6,7,10,1,3,9};

for(int i=1; i<N-1; i++){
  if((numbers[i-1] < numbers[i]) && (numbers[i] < numbers[i+1]))
    cout << numbers[i] << " has the increasing order\n";


}

}
