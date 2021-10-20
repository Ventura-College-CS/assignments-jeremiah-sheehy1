#include <iostream>
#include <cstring>
using namespace std;

int main(){

//string mainstr="chocolate";
//string substr="col";

char mainstr[10]="chocolate";
char substr[10]="lat";
int pos, i, j;
int flag = 0;

//pos = mainstr.find(substr);
cout << sizeof(mainstr) << endl;
cout << sizeof(substr) << endl;

cout << strlen(mainstr) << endl;
cout << strlen(substr) << endl;

for(i = 0; i < strlen(mainstr) - strlen(substr) + 1; i++){
    for(j=0; j < strlen(substr); j++){
        if(substr[j] != mainstr[i+j]){
            break;
        }
    }
    if(j == strlen(substr)){
        flag = 1;
        cout << " matched at the position " << i << endl;
    }
}
if(!flag){
    cout << "Couldn't find Substring" << endl;
}
}