#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "Vector3D.h"
#include <cmath>
using namespace std;

int main()
{
    /// Fix pow giving wrong answer
    double E = 0.000001;

    /// Standard input
    char input[10000];
    cin.getline(input, 10000);

    /// Number of vectors extracted from input
    char vectorNumb[5];

    /// Operation extracted from input
    char command[6];

    /// Array of vectors used for calculation
    Vector3D vectors[1000];

    /// Variables used for input extraction
    bool endCommand = false;
    bool endVectorNumb = false;
    int k = 0;
    int currentVec = 0;
    char readVector[20];

    for(int i = 0; i < strlen(input); i++){
        if(!endCommand){
            if(input[i] == ' '){
                command[i] = '\0';
                endCommand = true;
            } else {
                command[i] = input[i];
            }
        }
        else if(!endVectorNumb){
            if(input[i] == ' '){
                vectorNumb[k] = '\0';
                endVectorNumb = true;
                k = 0;
            } else {
                vectorNumb[k] = input[i]; k++;
            }
        }
        else {
            if(input[i] == ')'){
                readVector[k] = ')';
                readVector[k+1] = '\0';
                istringstream iStream(readVector);
                iStream >> vectors[currentVec];
                currentVec++;
                i++;
                k = 0;
            }
             else {
                readVector[k] = input[i];
                k++;
             }
        }
    }

    /// Convert command and vector count to int
    int vectorCount = 0;
    int com;
    int numb = 0;

    for(int i = 0; i < strlen(vectorNumb); i++){
        vectorCount += ((double)(vectorNumb[i] - '0') * pow(10, strlen(vectorNumb) - i - 1) + E);
    }

    if(command[0] == '*'){
        com = 4;
        for(int i = 1; i < strlen(command); i++){
            numb += (double(command[i] - '0') * pow(10, strlen(command) - i - 1) + E);
        }
    } else if(command[0] >= '0' && command[0] < '9'){
        com = 4;
        for(int i = 0; i < strlen(command) - 1; i++){
            numb += ((double)(command[i] - '0') * pow(10, strlen(command) - i - 2) + E);
        }
    } else if(command[0] == 'N'){
        com = 3;
    } else if(command[0] == '-'){
        com = 2;
    } else if(command[0] == '+'){
        com = 1;
    }

    /// Perform calculation
    switch(com){
    case 1:{
        Vector3D temp;
        for(int i = 0; i < vectorCount; i++){
            temp = temp + vectors[i];
        }
        cout<<temp; break;
    }
    case 2:{
        for(int i = 1; i < vectorCount; i++){
            vectors[0] = vectors[0] - vectors[i];
        }
        cout << vectors[0]; break;
    }
    case 3:{
        for(int i = 0; i < vectorCount; i++){
            cout << -vectors[i];
        }break;
    }
    case 4:{
        for(int i = 0; i < vectorCount; i++){
            cout << vectors[i]*numb;
        }break;
    }
    }
    return 0;
}
