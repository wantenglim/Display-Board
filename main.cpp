/**********|**********|**********|
Program:TC03.1181100769.LimWanTeng.cpp
Course: Programming Fundamentals (TCP1101)
Year: 2019/20 Trimester 1
Name: Lim Wan Teng
ID: 1181100769
Lecture Section: TC03
Tutorial Section: TT05
Email: 1181100769@student.mmu.edu.my
Phone: 011-33197720
**********|**********|**********/

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int charI = 7; 	// fixed array size of each character
const int charJ = 5;


void displayBoard(const vector<vector<char> > &board, int displayI, int displayJ)	// display the whole board
{
	for (int i = 0 ; i < displayI ; ++i){
		for(int j = 0 ; j < displayJ ; ++j){
			cout << board[i][j];
		}
		cout << endl;
	}
}


void fillChar(vector<vector<char> > &board, char charToFill) // fill the whole board with space first
{
	for (int i = 0; i < board.size() ; ++i){
        for (int j = 0; j < board[i].size(); ++j){
            board[i][j] = charToFill;
		}
	}
}


void textUpper(string& text)	// make the text input from user become all capital letter
{
	for (int i = 0 ; i < text.length() ; ++i){
		text[i] = toupper(text[i]);
	}
}


void effectUpper(string& effect)	// make the effects input (scrolling/wrap-around/rotation) from user become all capital letter
{
	for (int i = 0 ; i < effect.length() ; i++){
		effect[i] = toupper(effect[i]);
	}
}


int textType(string text, int k) // determine what is the value for the first [] operator of three dimensional array to know which character will used
{
	int textValue;

	if(text.at(k) >= 'A' && text.at(k) <= 'Z'){ 	// if text is between A-Z
		textValue = (text.at(k) - 'A');
		return textValue;}

	else if (text.at(k) == ' '){					// if text is a space
		textValue = (text.at(k)- ' '+ 36);
		return textValue;}

	else{											// if text is between 0-9
		textValue = ((text.at(k) - '0') + 26);
		return textValue;}
}


void changeSymbol(char arrayText[][charI][charJ], char symbol , int h) // change symbol for drawing the character
{
	for (int i = 0 ; i < charI ; ++i){
		for (int j = 0 ; j < charJ ; ++j){
			if (arrayText[h][i][j] == '#')
				arrayText[h][i][j] = symbol;
		}
	}
}

void reverse(char arr[], int n) // used to reverse the array in order to rotate
{
	reverse(arr, arr + n);
}

void rot90(vector<vector<char> > &board, char arrayText[][charI][charJ],int h, int coordinateJ, int coordinateI, int ROWS, int spaceRot90) // Rotate 90 degree clockwise
{
	char rotatedArray[5][7];

	char *array1 = rotatedArray[0];
	char *array2 = rotatedArray[1];
	char *array3 = rotatedArray[2];
	char *array4 = rotatedArray[3];
	char *array5 = rotatedArray[4];

	for (int i = 0; i < charI ; ++i){
		array1[i] = arrayText[h][i][0];
	}
	for (int i = 0; i < charI ; ++i){
		array2[i] = arrayText[h][i][1];
	}
	for (int i = 0; i < charI ; ++i){
		array3[i] = arrayText[h][i][2];
	}
	for (int i = 0; i < charI ; ++i){
		array4[i] = arrayText[h][i][3];
	}
	for (int i = 0; i < charI ; ++i){
		array5[i] = arrayText[h][i][4];
	}

	int n = 7;
	reverse(array1,n);
	reverse(array2,n);
	reverse(array3,n);
	reverse(array4,n);
	reverse(array5,n);

	for (int i = 0; i < charJ ; ++i){
		for (int j = 0; j < charI ; ++j){
			int sumCoordinateI = i + coordinateI + spaceRot90;
			if (sumCoordinateI < ROWS){
				board[i+coordinateI+spaceRot90][j+coordinateJ-6]= rotatedArray[i][j];}
		}
	}
}

void rotAnti90(vector<vector<char> >& board, char arrayText[][charI][charJ], int h, int coordinateJ, int coordinateI, int ROWS, int spaceRotAnti90) //Rotate 90 degree anticlockwise
{
	char rotatedArray[5][7];

	char *array1 = rotatedArray[0];
	char *array2 = rotatedArray[1];
	char *array3 = rotatedArray[2];
	char *array4 = rotatedArray[3];
	char *array5 = rotatedArray[4];

	for (int i = 0; i < charI ; ++i){
		array1[i] = arrayText[h][i][4];
	}
	for (int i = 0; i < charI ; ++i){
		array2[i] = arrayText[h][i][3];
	}
	for (int i = 0; i < charI ; ++i){
		array3[i] = arrayText[h][i][2];
	}
	for (int i = 0; i < charI ; ++i){
		array4[i] = arrayText[h][i][1];
	}
	for (int i = 0; i < charI ; ++i){
		array5[i] = arrayText[h][i][0];
	}

	for (int i = 0; i < charJ ; ++i){
		for (int j = 0; j < charI ; ++j){
			int sumCoordinateI = i + coordinateI - spaceRotAnti90;
			if (sumCoordinateI < ROWS ){
				board[i+coordinateI-spaceRotAnti90][j+coordinateJ]= rotatedArray[i][j];}
		}
	}
}

void mirror(vector<vector<char> > &board, char arrayText[][charI][charJ], int h, int coordinateJ, int coordinateI, int COLUMNS, int spaceMirror) // Reflection
{
	char rotatedArray[7][5];

	char *array1 = rotatedArray[0];
	char *array2 = rotatedArray[1];
	char *array3 = rotatedArray[2];
	char *array4 = rotatedArray[3];
	char *array5 = rotatedArray[4];
	char *array6 = rotatedArray[5];
	char *array7 = rotatedArray[6];


	for (int i = 0; i < charJ ; ++i){
		array1[i] = arrayText[h][6][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array2[i] = arrayText[h][5][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array3[i] = arrayText[h][4][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array4[i] = arrayText[h][3][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array5[i] = arrayText[h][2][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array6[i] = arrayText[h][1][i];
	}
	for (int i = 0; i < charJ ; ++i){
		array7[i] = arrayText[h][0][i];
	}

	for (int i = 0; i < charI ; ++i){
		for (int j = 0; j < charJ ; ++j){
			int sumCoordinateJ = j + coordinateJ + spaceMirror;
			if (sumCoordinateJ < COLUMNS){
				board[i+coordinateI][j+coordinateJ+spaceMirror]= rotatedArray[i][j];}
		}
	}
}

void noRot(vector<vector<char> >&board, char arrayText[][charI][charJ], int h, int coordinateJ, int coordinateI, int COLUMNS, int spaceNoRot) // No rotation
{
    for (int i = 0; i < charI ; ++i){
		for (int j = 0; j < charJ ; ++j){
			int sumCoordinateJ = j + coordinateJ + spaceNoRot;
			if (sumCoordinateJ < COLUMNS){
				board[i+coordinateI][j+coordinateJ+spaceNoRot]= arrayText[h][i][j];}
		}
	}
}

void fillText(vector<vector<char> > &board, string text,int coordinateJ, int coordinateI, char symbol, int ROWS, int COLUMNS, string wrap, string rotation) // determine which text is filled into the board
{                                                                                                                                                           // started at certain coordinate(with/without rotation)
	char arrayText[37][charI][charJ] = { 	' ',' ','#',' ',' ',
											' ','#',' ','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',

											'#','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											'#','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#',' ',

											'#','#','#','#','#',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#','#',

											'#','#','#','#','#',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ',' ',
											'#',' ',' ','#','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',

											'#','#','#','#','#',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											'#','#','#','#','#',

											'#','#','#','#','#',
											' ',' ',' ','#',' ',
											' ',' ',' ','#',' ',
											' ',' ',' ','#',' ',
											'#',' ',' ','#',' ',
											'#',' ',' ','#',' ',
											' ','#','#',' ',' ',

											'#',' ',' ',' ','#',
											'#',' ',' ','#',' ',
											'#',' ','#',' ',' ',
											'#','#',' ',' ',' ',
											'#',' ','#',' ',' ',
											'#',' ',' ','#',' ',
											'#',' ',' ',' ','#',

											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#','#',

											'#',' ',' ',' ','#',
											'#','#',' ','#','#',
											'#','#',' ','#','#',
											'#',' ','#',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',

											'#',' ',' ',' ','#',
											'#','#',' ',' ','#',
											'#','#',' ',' ','#',
											'#',' ','#',' ','#',
											'#',' ',' ','#','#',
											'#',' ',' ','#','#',
											'#',' ',' ',' ','#',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											'#','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ','#',' ','#',
											' ','#',' ','#',' ',
											' ',' ',' ',' ','#',

											'#','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#','#','#','#',' ',
											'#',' ','#',' ',' ',
											'#',' ',' ','#',' ',
											'#',' ',' ',' ','#',

											' ','#','#','#','#',
											'#',' ',' ',' ',' ',
											'#',' ',' ',' ',' ',
											' ','#','#','#',' ',
											' ',' ',' ',' ','#',
											' ',' ',' ',' ','#',
											'#','#','#','#',' ',

											'#','#','#','#','#',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',

											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#',' ','#',' ',
											' ','#',' ','#',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',

											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											'#',' ','#',' ','#',
											'#',' ','#',' ','#',
											'#',' ','#',' ','#',
											' ','#',' ','#',' ',

											'#',' ',' ',' ','#',
											' ','#',' ','#',' ',
											' ','#',' ','#',' ',
											' ',' ','#',' ',' ',
											' ','#',' ','#',' ',
											' ','#',' ','#',' ',
											'#',' ',' ',' ','#',

											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#',' ','#',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',

											'#','#','#','#','#',
											' ',' ',' ',' ','#',
											' ',' ',' ','#',' ',
											' ',' ','#',' ',' ',
											' ','#',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#','#',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ','#','#',
											'#',' ','#',' ','#',
											'#','#',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											' ',' ','#',' ',' ',
											' ','#','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ',' ','#',' ',' ',
											' ','#','#','#',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											' ',' ',' ',' ','#',
											' ',' ','#','#',' ',
											' ','#',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#','#',

											'#','#','#','#','#',
											' ',' ',' ',' ','#',
											' ',' ',' ','#',' ',
											' ',' ','#','#',' ',
											' ',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#','#',

											' ',' ',' ','#',' ',
											' ',' ','#','#',' ',
											' ','#',' ','#',' ',
											'#',' ',' ','#',' ',
											'#','#','#','#','#',
											' ',' ',' ','#',' ',
											' ',' ',' ','#',' ',

											'#','#','#','#','#',
											'#',' ',' ',' ',' ',
											'#','#','#','#',' ',
											' ',' ',' ',' ','#',
											' ',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											' ',' ','#','#','#',
											' ','#',' ',' ',' ',
											'#',' ',' ',' ',' ',
											'#','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											'#','#','#','#','#',
											' ',' ',' ',' ','#',
											' ',' ',' ','#',' ',
											' ',' ','#',' ',' ',
											' ','#',' ',' ',' ',
											' ','#',' ',' ',' ',
											' ','#',' ',' ',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#',' ',

											' ','#','#','#',' ',
											'#',' ',' ',' ','#',
											'#',' ',' ',' ','#',
											' ','#','#','#','#',
											' ',' ',' ',' ','#',
											' ',' ',' ','#',' ',
											'#','#','#',' ',' ',

											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' ',
											' ',' ',' ',' ',' '};


	int spaceRot90 = 0;
	int spaceRotAnti90 = 4;
	int spaceMirror = 0;
	int spaceNoRot = 0;
	for (int k = 0 ; k < text.length() ; ++k){  // loop within the length of text input by user
		int h = textType(text,k);				// call textType() function to initialise h // h is the value for the first [] operator of arrayText
		changeSymbol(arrayText, symbol, h);
		if (rotation == "ROT90")
		{
			rot90(board, arrayText, h, coordinateJ, coordinateI, ROWS, spaceRot90);
		}
		else if (rotation == "ROT-90")
		{
			rotAnti90(board, arrayText, h, coordinateJ, coordinateI, ROWS, spaceRotAnti90);
		}
		else if (rotation == "MR")
		{
			mirror(board, arrayText, h, coordinateJ, coordinateI, COLUMNS, spaceMirror);
		}
		else
        {
            noRot(board,arrayText, h, coordinateJ, coordinateI, COLUMNS, spaceNoRot);
        }
		spaceRot90 += 6;
		spaceRotAnti90 += 6;
		spaceMirror += 6;
		spaceNoRot += 6;
	}

}


void scrollUp(vector<vector<char> > &board,int ROWS, int COLUMNS)   // scroll up row by row
{
	char temp[COLUMNS];

	for (int j = 0; j < COLUMNS; ++j)
	{
		temp[j] = board[0][j]; 		                                // store first row as temporary
	}


	for (int i = 1; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			board[i-1][j] = board[i][j]; 	                        // previous row will be assigned by current row
		}
	}

	for (int j = 0; j < COLUMNS; ++j)
	{
		board[ROWS-1][j] = temp[j];
	}

}


void scrollDown(vector<vector<char> > &board,int ROWS, int COLUMNS) // scroll down row by row
{
	char temp[COLUMNS];

	for (int j = 0; j < COLUMNS; ++j)
	{
		temp[j] = board[ROWS-1][j]; 		                        // store first row as temporary
	}


	for (int i = ROWS-1; i >= 1; --i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			board[i][j] = board[i-1][j]; 	                        // current row will be assigned by previous row
		}
	}

	for (int j = 0; j < COLUMNS; ++j)
	{
		board[0][j] = temp[j];
	}
}


void scrollLeft(vector<vector<char> > &board,int ROWS, int COLUMNS) // scroll left column by column
{
	char temp[ROWS];

	for (int i = 0; i < ROWS; ++i)
	{
		temp[i] = board[i][0];				                        // store first column as temporary
	}


	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 1; j < COLUMNS; ++j)
		{
			board[i][j-1] = board[i][j];	                        // previous column will be assigned by current column
		}
	}

	for (int i = 0; i < ROWS; ++i)
	{
		board[i][COLUMNS-1] = temp[i];		                        // last column will be assigned by the
                                                                    //first column which is stored as temporary
	}
}


void scrollRight(vector<vector<char> > &board,int ROWS, int COLUMNS) 	// scroll right column by column
{
	char temp[ROWS];

	for (int i = 0; i < ROWS; ++i)
	{
		temp[i] = board[i][COLUMNS-1];		                            // store last column as temporary
	}

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = COLUMNS-1; j >= 1; --j)
		{
			board[i][j] = board[i][j-1]; 	                            // current column will be assigned by previous column
		}
	}


	for (int i = 0; i < ROWS; ++i)
	{
		board[i][0] = temp[i];				                            // first column will be assigned by
                                                                        // the last column which is stored as temporary
	}
}


void scrollChoice(string scroll,vector<vector<char> > &board,int ROWS,int COLUMNS)
{
	if (scroll == "LR" ){						// identify the type of scrolling based on
		scrollRight(board,ROWS,COLUMNS);}       // user input and call that particular scrolling function
	else if (scroll == "RL")
		scrollLeft(board,ROWS,COLUMNS);
	else if (scroll == "UD")
		scrollDown(board,ROWS,COLUMNS);
	else if (scroll == "DU")
		scrollUp(board,ROWS,COLUMNS);
}


void delay(int speed)
{
	for( int i = 0; i < (300000000/speed); ++i ){	// delay the refresh cycle

	}
}


void clearScreen()  // clear screen for scrolling effect
{
	system("cls");
}


bool verifyDigit(string rate)
{
	bool digit = true;
	for (int i = 0 ; i < rate.length() ; ++i )
	{
		if (digit ==true)
		{
			if (isdigit(rate.at(i)))	// Use isdigit() to determine if
				digit = true;           // the character is a digit
			else
				digit = false;
		}
	}
	return digit;
}


bool verifyDigitWithSpace(string input)
{
	bool digit = true;
	for (int i = 0 ; i < input.length() ; ++i )
	{
		if (digit ==true)
		{
			if (isdigit(input.at(i)) || input.at(i)==' ')	// Use isdigit() to determine if
				digit = true;                               // the character is a digit or space
			else
				digit = false;
		}
	}
	return digit;
}

bool verifyAlphaNumWithSpace(string text)
{
	bool alnum = true;
	for (int i = 0 ; i < text.length() ; ++i )
	{
		if (alnum ==true)
		{
			if (isalnum(text.at(i)) || text.at(i)==' ')	// Use isalnum() to determine if
				alnum = true;                           // the character is a digit or letter or space
			else
				alnum = false;
		}
	}
	return alnum;
}


int main()
{
	vector <vector <char> > board;

	char symbol;
	int speed;
	string text;
	int coordinateJ, coordinateI;
	int ROWS, COLUMNS;
	string scroll, wrap, rotation;

	bool flagDigitSpeed = false;
	bool flagDigitOffset = false;
	bool flagAlphaNumText = false;
	bool flagDigitSize = false;
	bool flagScroll = false;
	bool flagWrap = false;
	bool flagRotation = false;

	ifstream inFile;
	string fileName;
	cout << "Enter filename (Enter exit to terminate) : ";
	cin >> fileName;

	// Sentinel to exit program
	if (fileName == "exit")
	{
		cout << "*Program is terminated*";
		exit(1);
	}
	else
		inFile.open(fileName,ios::in);

    // If file is opened
	if (inFile)
	{
	    // symbol
		string oneSymbol;
		getline(inFile,oneSymbol);
		if (oneSymbol.length() < 0 || oneSymbol.length() > 1)
		{
			cout << "Symbol should contain only 1 character." << endl;
			cout << "Example =># ";
			exit(1);
		}

		if (oneSymbol=="")
        {
            symbol = '#';
        }
		else
		{
			stringstream ss;
			ss << oneSymbol;
			ss >> symbol;
		}

		// speed
		string rate;
		getline(inFile,rate);
		flagDigitSpeed = verifyDigit(rate);
		if (flagDigitSpeed == false)
		{
			cout << "Speed input contains non-digit." << endl;
			cout << "Digits only." << endl;
			cout << "Example =>10 ";
			exit(1);
		}
		else
		{
			stringstream ss0;
			ss0 << rate;
			ss0 >> speed;
		}

		if (speed < 1 || speed > 10)
		{
			cout << "Invalid speed." << endl;
			cout << "1 - 10 only." << endl;
			cout << "Example =>10 ";
			exit(1);
		}

		// character string
		getline(inFile,text);
		textUpper(text);
		flagAlphaNumText = verifyAlphaNumWithSpace(text);
		if (flagAlphaNumText == false)
		{
			cout << "Invalid string character."  << endl;
			cout << "A-Z and 0-9 characters only." << endl;
			cout << "Example =>TCP1101";
			exit(1);

		}
		if (text.length()>25)
		{
			cout << "Length of string character is exceeded."  << endl;
			cout << "Not longer than 25 characters." << endl;
			cout << "Example =>TCP1101 Programming Funda";
			exit(1);
		}

		// coordinate
		string coordinate;
		getline(inFile,coordinate);
		flagDigitOffset = verifyDigitWithSpace(coordinate);
		if (flagDigitOffset == false)
		{
			cout << "Coordinate input contains non-digits." << endl;
			cout << "Digits only and separated by a whitespace." << endl;
			cout << "Format =>offsetJ offsetI" << endl;
			cout << "Example =>6 18";
			exit(1);
		}
		else
		{
			stringstream ss1;
			ss1 << coordinate;
			ss1 >> coordinateJ >> coordinateI;
		}

		// board size
		string boardSize;
		getline(inFile,boardSize);
		flagDigitSize = verifyDigitWithSpace(boardSize);
		if (flagDigitSize == false)
		{
			cout << "Board size input contains non-digits."  << endl;
			cout << "Digits only and separated by a whitespace." << endl;
			cout << "Format =>Row Column" << endl;
			cout << "Example =>30 50";
			exit(1);
		}

		if (boardSize == "")
		{
			ROWS = 20;
			COLUMNS = 40;
		}
		else
		{
			stringstream ss2;
			ss2 << boardSize;
			ss2 >> ROWS >> COLUMNS;
		}

		if (coordinateJ < 0 || coordinateJ > (COLUMNS-1) || coordinateI < 0 || coordinateI > (ROWS-1))
		{
			cout << "Invalid coordinate or format."<< endl;
			cout << "***Based on your board size input***" << endl;
			cout << "Coordinate X => 0 - " << (COLUMNS-1) << endl;
			cout <<	"Coordinate Y => 0 - " << (ROWS-1) << endl;
			cout << "Format =>offsetJ offsetI" << endl;
			cout << "Example =>6 18 (with board size 20 40)";
			exit(1);
		}
		else
		{
			coordinateI = (ROWS-1) - coordinateI;
		}

		// rotation, scrolling, wrap-around
		string effect;
		getline(inFile,effect);
		stringstream ss3;
		ss3 << effect;

		string word;
		int sentenceLength = 0;
		while(ss3 >> word) {
            sentenceLength++;
            if(sentenceLength == 1) {
                if(word == "rot90" || word == "rot-90"|| word == "mr") {
                   rotation = word;
                }
                else if(word == "lr" || word == "rl" || word == "du" || word == "ud" || word == "st") {
                   scroll = word;
                }
                else if(word == "wr") {
                   wrap = word;
                }
            }
            if(sentenceLength == 2) {
                if(word == "rot90" || word == "rot-90"|| word == "mr") {
                   rotation = word;
                }
                else if(word == "lr" || word == "rl" || word == "du" || word == "ud" || word == "st") {
                   scroll = word;
                }
                else if(word == "wr") {
                   wrap = word;
                }
            }
            if(sentenceLength == 3) {
                if(word == "rot90" || word == "rot-90"|| word == "mr") {
                   rotation = word;
                }
                else if(word == "lr" || word == "rl" || word == "du" || word == "ud" || word == "st") {
                   scroll = word;
                }
                else if(word == "wr") {
                   wrap = word;
                }
            }
		}

		effectUpper(rotation);
        effectUpper(scroll);
		effectUpper(wrap);

		if (rotation == "ROT90" || rotation == "ROT-90" || rotation == "MR" || rotation == "")
		{
			flagRotation = true;
		}
		else
		{
			cout << "Invalid rotation effect or format.";
			cout << "Valid rotation effect => rot90 / rot-90 / mr" << endl;
			cout << "Format =>rotation scrolling wrap-around " << endl;
			cout << "Example =>rot90(opt) lr wr(opt)";
			exit(1);
		}

		if (scroll == "LR" || scroll == "RL" || scroll == "UD" || scroll == "DU" || scroll == "ST" )
		{
			flagScroll = true;
		}
		else
		{
			cout << "Invalid scrolling effect or format." << endl;
			cout << "Valid scrolling effect => lr / rl / du / ud / st" << endl;
			cout << "Format =>rotation scrolling wrap-around " << endl;
			cout << "Example =>rot90 lr wr";
			exit(1);
		}

		if (wrap == "WR" || wrap == "")
		{
		    flagWrap = true;
        }
        else
        {
			cout << "Invalid wrap-around effect or format."<< endl;
			cout << "Valid wrap-around effect => wr" << endl;
			cout << "Format =>rotation scrolling wrap-around " << endl;
			cout << "Example =>rot90 lr wr";
			exit(1);
		}


		int displayI = ROWS;
		int displayJ = COLUMNS;
		int textDimI = text.length()*(charI+1) + coordinateI;
        int textDimJ = text.length()*(charJ+1) + coordinateJ;
        //Determine the board size based on length of text
		if ( textDimI > ROWS)
		{
			ROWS = textDimI;
		}
		else
		{
			ROWS = ROWS;
		}

		if ( textDimJ > COLUMNS)
		{
			COLUMNS = textDimJ;
		}
		else
		{
			COLUMNS = COLUMNS;
		}

        // Resize the board
		board.resize(ROWS);
		for (int i = 0; i < ROWS; ++i)
		{
			board[i].resize(COLUMNS);
		}

        fillChar(board,' '); // fill board with space first
		fillText(board,text,coordinateJ,coordinateI,symbol,ROWS,COLUMNS,wrap,rotation); // determine which text is filled into the board
                                                                                        // started at certain coordinate(with/without rotation)

		if (scroll != "ST") // for scrolling display
		{
            while (true)
            {
                clearScreen();                              // clear screen for scrolling effect
                displayBoard(board,displayI,displayJ);      // display the board
                scrollChoice(scroll,board,ROWS,COLUMNS);    // to choose which scrolling should be displayed
                delay(speed);                               // delay the refresh cycle
            }
		}
		else // for stationary display
            displayBoard(board,displayI,displayJ);
	}

    // If file is failed to open
	else
	{
		cout << "File open failure!" ;
		exit(1);
	}
}
