//Lowenthal Assignment 3-2
//--------------------------------------------------------------------------------
//Headers
#include <iostream>

#include <cstdlib>

#include <sstream>

#include <string>

#include <fstream>

#include <iomanip> //for double formatting

using namespace std;

//--------------------------------------------------------------------------------
//Method Prototypes
string getData(int* rows, int* columns);

void getDimensions(int* rows, int* columns, string temp);

void populateArray(string** matrix, string container, int rows, int columns);

void averageColumns(string** matrix, int rows, int columns, double* averages);

void printAverages(double* averages, int columns);

//--------------------------------------------------------------------------------
//Main Function
int main(){

int rows = 0, columns = 0;
string container =  getData(&rows, &columns);

string** matrix = new string*[rows];
for(int a = 0; a < rows; a++)
	matrix[a] = new string[columns];


double* averages = new double[columns];

populateArray(matrix, container, rows, columns);

averageColumns(matrix, rows, columns, averages);

printAverages(averages, columns);

for(int a = 0; a < rows; a++)
	delete[] matrix[a];
delete[] matrix;

//system("pause") for windows
return 0;
} 

//--------------------------------------------------------------------------------
//Retrieve Matrix Dimensions and ASCII Data in String
string getData(int* rows, int* columns){

string filename = "";
string temp = "";
string container = "";
ifstream input;

cout<<"Enter filename: \n";
while(filename == ""){
getline(cin, filename);
}

filename += ".txt";

input.open(filename.c_str());
while(getline(input, temp)){
if(*rows == 0){

getDimensions(rows, columns, temp);

}
else{
container += temp; //should return everything but top line
}
}
input.close();
return container;
}


//--------------------------------------------------------------------------------
//Retrieve and Convert ASCII Numerals for Rows and Columns

void getDimensions(int* rows, int* columns, string temp){

stringstream convert;
string strTemp = "";
int b = 0;

//Rows
for(int a = 6; a < temp.size(); a++){
if(temp[a] == '\t'){
b = (a+1);
break;
}

strTemp += temp[a];

}

convert << strTemp;
convert >> *rows;
convert.str( std::string() );
convert.clear();

strTemp = "";

for(int idx = b; idx < temp.size(); idx++){ //skip to next numeral 
if(temp[idx] == 's'){
b = (idx+3);
}
}

//Columns
for(int c = b; c < temp.size(); c++){
if(temp[c] == '\t'){
break;
}

strTemp += temp[c];

}

convert << strTemp;
convert >> *columns;

}


//--------------------------------------------------------------------------------
//Populate Matrix with Numbers

void populateArray(string** matrix, string container, int rows, int columns){
int idx = 0;
string temp = "";

for(int a = 0; a < rows; a++){

for(int b = 0; b < columns; b++){

for(int d = idx; d < container.size(); d++){
if(container[d] == '\t'){

idx = d;

break;
}
temp.push_back(container[d]);
}

idx++;

matrix[a][b] = temp;
temp = "";
}
}

}


//--------------------------------------------------------------------------------
//Average Columns and Store in Array

void averageColumns(string** matrix, int rows, int columns, double* averages){

double result = 0.0;
double divisor = 0.0;
string temp = "";
stringstream convert;

for(int a = 0; a < columns; a++){
for(int b = 0; b < rows; b++){

temp = matrix[b][a];

result += atof(temp.c_str());
divisor++;

}

result = (result / divisor);
averages[a] = result;
result = 0.0;
divisor = 0.0;

}

}

//--------------------------------------------------------------------------------
//Print Averages

void printAverages(double* averages, int columns){

cout<<"\nColumn Averages:\n\n";

for(int a = 0; a < columns; a++){

cout<<"\n"<<(a+1)<<". "<<fixed<<averages[a]<<'\n';

}

}
