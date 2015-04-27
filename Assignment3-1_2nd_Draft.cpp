//Lowenthal Assignment 3-1
//--------------------------------------------------------------
//Headers
#include <iostream> //cin and cout

#include <cstdlib>  //rand() and srand()

#include <ctime>    //srand(time(NULL))

#include <sstream>  //stringstream for type conversion

#include <fstream>  //ofstream for file out

#include <string>   //string arrays

using namespace std;//don't need std::

//--------------------------------------------------------------
//Method Prototypes

void defineDimensions(int* rows, int* columns);

void populateMatrix(string **matrix, int rows, int columns);

void writeMatrix(string **matrix, int rows, int columns);

//--------------------------------------------------------------
//Main

int main(){

int rows = 0, columns = 0;

defineDimensions(&rows, &columns);

string** matrix = new string*[rows]; //first initialize as array
for(int a = 0; a < rows; a++)  //of pointers then populate 
	matrix[a] = new string[columns];

populateMatrix(matrix, rows, columns); //put random numbers in 
				       //matrix

writeMatrix(matrix, rows, columns);

for(int a = 0; a < rows; a++)
	delete[] matrix[a];

delete[] matrix;
//system("pause") for windows
return 0;

} 

//--------------------------------------------------------------
//Define Dimensions

void defineDimensions(int* rows, int* columns){

cout<<"Please enter number of rows for matrix: \n";
cin>>*rows;

cout<<"PLease enter number of columns for matrix: \n";
cin>>*columns;

}

//--------------------------------------------------------------
//Populate Matrix

void populateMatrix(string **matrix, int rows, int columns){
string temp = "";
int temprand = 0;
srand(time(NULL));    

for(int a = 0; a < rows; a++){
for(int b = 0; b < columns; b++){

ostringstream convert; 
convert << rand(); //store random int in buffer
temp = convert.str();   //retrieve string value from buffer

matrix[a][b] = temp; //populate array
}

}


}

//--------------------------------------------------------------
//Write Matrix To File

void writeMatrix(string **matrix, int rows, int columns){
ofstream output;
string filename = "";


cout<<"Please enter file name\n";
while(filename == ""){
getline(cin, filename);
}

filename+=".txt"; //add file extension

output.open(filename.c_str());  //need to append .c_str() to open

output<<"Rows: "<<rows<<'\t'<<"Columns: "<<columns<<'\t'<<'\n'; //this is so program 2 knows how many rows/columns

for(int a = 0; a < rows; a++){
for(int b = 0; b < columns; b++){

output<<matrix[a][b]<<'\t';
}

output<<'\n';
}
output.close();

}
