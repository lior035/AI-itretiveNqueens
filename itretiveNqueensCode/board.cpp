
#include "board.h" 

#include <stdlib.h>

board::board()
{
	int i;

	//initializing objects member

	cout<<"Enter size of the check board please"<<endl; 
	cin>>this->sizeOfBoard;

	int bSize = this->sizeOfBoard;

	this->checkBoard = new int * [bSize];
		
	for(i=0;i<bSize;i++)
	{
		this->checkBoard[i] = new int [bSize];
	}

	this->initializeBoard();

	totalCollosion = 0;
}

//==============================================================================

void board::initializeBoard()
{
	int i, j;

	for (i=0; i<this->sizeOfBoard; i++)
	{
		for (j =0 ; j<this->sizeOfBoard; j++)
			this->checkBoard[i][j] = 1 ;//legal
	}
}

//==============================================================================

void board::placeRandomNqueensAtBoard()
{
	int currColToPlaceQueen; 
	int randomPlaceAtCol;

	for (currColToPlaceQueen = this->sizeOfBoard-1; currColToPlaceQueen>=0;currColToPlaceQueen--)
	{
		srand(time(NULL));
		randomPlaceAtCol =  rand()%this->sizeOfBoard;
		this->insertQueenAt(randomPlaceAtCol,currColToPlaceQueen);
	}

}

//==============================================================================

void board::insertQueenAt(int row, int col)
{
	int i, j;

	this->checkBoard[row][col] = 2; //this cell is assaignd with a queen

	//adding - number of queen threaten at this row of the assigment by this queen ( starting from the current column ) - to the total collosion
	for (j = col+1; j<this->sizeOfBoard; j++)
	{
		if (this->checkBoard[row][j] == 2)
			this->totalCollosion ++;
	}

	i = row+1;
	j = col+1;

	while ((i<this->sizeOfBoard)&&(j<this->sizeOfBoard))
	{
		if (this->checkBoard[i][j] == 2)
			this->totalCollosion ++;
			
		i++;
		j++;
		
	}

	i = row-1;
	j = col+1;

	while ((i>=0)&&(j<this->sizeOfBoard))
	{
		if (this->checkBoard[i][j] == 2)
			this->totalCollosion ++;
			
		i--;
		j++;
	}
}

//==============================================================================

void board::moveQueenAtColToBestPlace (int col)
{
	int i, j;
	int row;

	for (i=0;i<this->sizeOfBoard;i++)
	{
		if (this->checkBoard[i][col] == 2)
			row = i;
	}

	if (numOfCollosionByPuttingQueenAt(row,col) == 0)
		return;

	int * collosionByPutQueenAtCell = new int [this->sizeOfBoard]; // n-1 places else then original place as options

	j=0;

	for (i=0;i<this->sizeOfBoard; i++)
	{
		if (i !=row)
			collosionByPutQueenAtCell[j] = numOfCollosionByPuttingQueenAt(i,col);
		else
			collosionByPutQueenAtCell[j]=-1;
		j++;
	}

	int minInd = 0;
	int minVal = collosionByPutQueenAtCell[0];

	for (j = 1; j<this->sizeOfBoard; j++)
	{
		if ((collosionByPutQueenAtCell[j]<minVal)&&(collosionByPutQueenAtCell [j]!=-1))
		{
			minVal = collosionByPutQueenAtCell[j];
			minInd = j;
		}
	}

	int removeCollosion = numOfCollosionByPuttingQueenAt(row,col);
	int addCollosion = collosionByPutQueenAtCell[minInd];

	this->updateBoardByMovingQueenAtCell(row,minInd,col, removeCollosion, addCollosion);
	
	delete collosionByPutQueenAtCell;
}

//==============================================================================

int board::numOfCollosionByPuttingQueenAt (int row, int col)
{
	int counter = 0;
	
	int i, j;


	//countin how many queens at the same row as the input row
	for (j = 0; j<this->sizeOfBoard; j++)
	{
		if ((this->checkBoard[row][j] == 2)&&(j!=col))
			counter++;
	}
	
	//countin how many queens at the same hypotenuse of the cell mention

	i = row-1;
	j = col-1;

	while ((i>=0)&&(j>=0))
	{
		if (this->checkBoard[i][j] == 2)
			counter++;
			
		i--;
		j--;	
	}

	i = row+1;
	j = col+1;

	while ((i<this->sizeOfBoard)&&(j<this->sizeOfBoard))
	{
		if (this->checkBoard[i][j] == 2)
			counter++;
			
		i++;
		j++;
		
	}

	i = row-1;
	j = col+1;

	while ((i>=0)&&(j<this->sizeOfBoard))
	{
		if (this->checkBoard[i][j] == 2)
			counter++;
			
		i--;
		j++;
		
	}

	i = row+1;
	j = col-1;

	while ((i<this->sizeOfBoard)&&(j>=0))
	{
		if (this->checkBoard[i][j] == 2)
			counter++;
			
		i++;
		j--;
		
	}

	return counter;
}

//==============================================================================

void board::updateBoardByMovingQueenAtCell(int oldRow, int newRow, int col, int removeCollosion, int addCollosion)
{
	this->totalCollosion -= removeCollosion;
	this->totalCollosion += addCollosion;

	this->checkBoard[oldRow][col]=1;
	this->checkBoard[newRow][col] =2;
}

//==============================================================================

int board::getTotalCollosion()
{
	return this->totalCollosion;
}

//==============================================================================

void board::updateTotalCollosion(int newNumOfCol)
{
	this->totalCollosion = newNumOfCol;
}

//================================================================================

int board::getSizeOfBoard()
{
	return this->sizeOfBoard;
}
//=================================================================================
void board::printBoard ()
{
	int i, j;
	
	cout<<"Here is the assigment : "<<endl;

	for (i=0;i<this->sizeOfBoard;i++)
	{
		for (j=0; j<this->sizeOfBoard;j++)
		{
			if (this->checkBoard[i][j] == 2)
				cout<<"Q  ";

			else
				cout<<"E  ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"Shell you prefer the assgiment as a list: "<<endl;
	
	int q = 1;

	for (i=0;i<this->sizeOfBoard;i++)
	{
		for (j=0; j<this->sizeOfBoard;j++)
		{
			if (this->checkBoard[i][j] == 2)
			{
				cout<<"Queen "<<q<<" : ("<<i<<","<<j<<")"<<endl;
				q++;
			}
		}
	}
}

//=============================================================================

board::~board()
{
	int i;

	for(i=0;i<this->sizeOfBoard;i++)
		delete this->checkBoard[i];
	
	delete this->checkBoard;
}