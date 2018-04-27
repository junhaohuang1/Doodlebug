#include "stdafx.h"
#include "Organism.h"


Organism::Organism(int rowVal, int colVal, char organismSymbol, int stepsToBreed):rowVal(rowVal), colVal(colVal), organismSymbol(organismSymbol), stepsToBreed(stepsToBreed), stepsSurvived(0)
{
}


Organism::~Organism()
{
}

void Organism::setOrganismSymbol(char organismSymbol)
{
	this->organismSymbol = organismSymbol;
}

void Organism::setStepsSurvived(int stepsSurvived)
{
	this -> stepsSurvived = stepsSurvived;
}

void Organism::setStepsToBreed(int stepsToBreed)
{
	this->stepsToBreed = stepsToBreed;
}

void Organism::setRowVal(int rowVal)
{
	this->rowVal = rowVal;
}

void Organism::setColVal(int colVal)
{
	this->colVal = colVal;
}

char Organism::getOrganismSymbol() const
{
	return this->organismSymbol;
}

int Organism::getStepsSurvived() const
{
	return this->stepsSurvived;
}

int Organism::getStepsToBreed() const
{
	return this->stepsToBreed;
}

int Organism::getRowVal() const
{
	return this->rowVal;
}

int Organism::getColVal() const
{
	return this->colVal;
}



void Organism::incrementStepsSurvived()
{
	this->stepsSurvived++;
}

vector<string> Organism::getEmptyAdjacentCoordinates(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	vector<string> result;
	if (rowVal + 1 < ECOSYSTEM_ROW_MAX_VAL)
		if (ecosystem[rowVal + 1][colVal] == NULL)
			result.push_back("up");
	if (rowVal - 1 > 0)
		if (ecosystem[rowVal - 1][colVal] == NULL)
			result.push_back("down");
	if (colVal + 1 < ECOSYSTEM_COL_MAX_VAL)
		if (ecosystem[rowVal][colVal + 1] == NULL)
			result.push_back("right");
	if (colVal - 1 > 0)
		if (ecosystem[rowVal][colVal - 1] == NULL)
			result.push_back("left");
	return result;
}

void Organism::updateCoordinates(vector<string> directions, int& rowVal, int& colVal)
{
	if (directions.size() > 0) {
		srand(time(0));
		int randomDirection = rand() % directions.size();
		if (directions[randomDirection] == "up")
			rowVal++;
		if (directions[randomDirection] == "down")
			rowVal--;
		if (directions[randomDirection] == "right")
			colVal++;
		if (directions[randomDirection] == "left")
			colVal--;
	}
}
