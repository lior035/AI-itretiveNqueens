#ifndef CHECK_BOARD
#define CHECK_BOARD

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

class board
{
private:

	//int** checkBoard;
	int sizeOfBoard;
	int totalCollosion;
	int** checkBoard;

public:


	board (); // constructor
	void initializeBoard();

	void placeRandomNqueensAtBoard();
	void insertQueenAt(int row, int col);

	void moveQueenAtColToBestPlace (int col);
	int numOfCollosionByPuttingQueenAt (int row, int col);
	void updateBoardByMovingQueenAtCell(int oldRow, int newRow, int col, int removeCollosion, int addCollosion);

	int getTotalCollosion();
	void updateTotalCollosion(int newNumOfCol);

	int getSizeOfBoard();

	void printBoard();
	~board (); //destructor
};

#endif 
