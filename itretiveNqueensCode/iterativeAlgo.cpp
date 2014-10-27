#include "iterativeAlgo.h"

void iterativeAlgo::runAlgo ()
{
	board * br = new board;

	int numOfCollosion, colToFix;

	br->placeRandomNqueensAtBoard();

	numOfCollosion = br->getTotalCollosion();
	this->addres = br;

	while (numOfCollosion!=0)
	{
		srand(time(NULL));
		colToFix =  rand()%(br->getSizeOfBoard());
		br->moveQueenAtColToBestPlace(colToFix);

		numOfCollosion = br->getTotalCollosion();
		this->addres = br;
		cout<<numOfCollosion<<endl;
	}

	cout<<"final board:"<<endl;
	this->getAdd()->printBoard();
	delete br;
}

board * iterativeAlgo::getAdd()
{
	return this->addres;
}

void iterativeAlgo::updateAdd(board* curr)
{
	this->addres = curr;
}