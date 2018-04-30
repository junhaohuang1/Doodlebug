#include "stdafx.h"
#include "Doodlebug.h"


Doodlebug::Doodlebug(int rowVal, int colVal) :Organism(rowVal, colVal, DOODLEBUG_CHAR, 8)
{
}

void Doodlebug::move(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{	
	int currRowVal = getRowVal();
	int currColVal = getColVal();
	int newRowVal = getRowVal();
	int newColVal = getColVal();
	vector<string> antAdjacentCoordinates = getAdjacentAntCoordinates(ecosystem);
	if (antAdjacentCoordinates.size() > 0) {
		setStepsWithoutFood(0);
		starve(ecosystem);
		updateCoordinates(antAdjacentCoordinates, newRowVal, newColVal);
		setRowVal(newRowVal);
		setColVal(newColVal);
		delete ecosystem[newRowVal][newColVal];
		ecosystem[currRowVal][currColVal] = NULL;
		ecosystem[newRowVal][newColVal] = this;
		
	}
	else {
		vector<string> emptyAdjacentCoordinates = getEmptyAdjacentCoordinates(ecosystem);
		if (emptyAdjacentCoordinates.size() > 0) {
			incrementstepsWithoutFood();
			updateCoordinates(emptyAdjacentCoordinates, newRowVal, newColVal);
			setRowVal(newRowVal);
			setColVal(newColVal);
			ecosystem[newRowVal][newColVal] = new Doodlebug(newRowVal, newColVal);
			*(ecosystem[newRowVal][newColVal]) = *(this);
			ecosystem[currRowVal][currColVal] = NULL;
		}
	}
	if (ecosystem[getRowVal()][getColVal()] != NULL) {
		ecosystem[getRowVal()][getColVal()] ->incrementStepsSurvived();
		ecosystem[getRowVal()][getColVal()] ->breed(ecosystem);
	}
}



Doodlebug::~Doodlebug()
{
}

void Doodlebug::setStepsWithoutFood(int stepsWithoutFood)
{
	this->stepsWithoutFood = stepsWithoutFood;
}

int Doodlebug::getStepsWithoutFood() const
{
	return this->stepsWithoutFood;
}

void Doodlebug::incrementstepsWithoutFood()
{
	this->stepsWithoutFood++;
}

void Doodlebug::breed(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	if (getStepsSurvived() >= getStepsToBreed()) {
		vector<string> emptyAdjacentCoordinates = getEmptyAdjacentCoordinates(ecosystem);
		if (emptyAdjacentCoordinates.size() > 0) {
			srand(time(0));
			int randomDirection = rand() % emptyAdjacentCoordinates.size();
			int currRowVal = getRowVal();
			int currColVal = getColVal();
			updateCoordinates(emptyAdjacentCoordinates, currRowVal, currColVal);
			ecosystem[currRowVal][currColVal] = new Doodlebug(currRowVal, currColVal);
			setStepsSurvived(0);
			cout << getStepsSurvived();
		}
	}
}

vector<string> Doodlebug::getAdjacentAntCoordinates(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	vector<string> result;
	int rowVal = getRowVal();
	int colVal = getColVal();
	if (rowVal + 1 < ECOSYSTEM_ROW_MAX_VAL)
		if (ecosystem[rowVal + 1][colVal] != NULL && ecosystem[rowVal + 1][colVal]->getOrganismSymbol() == 'o')
			result.push_back("up");
	if (rowVal - 1 > 0)
		if (ecosystem[rowVal - 1][colVal] != NULL && ecosystem[rowVal - 1][colVal]->getOrganismSymbol() == 'o')
			result.push_back("down");
	if (colVal + 1 < ECOSYSTEM_COL_MAX_VAL)
		if (ecosystem[rowVal][colVal + 1] != NULL && ecosystem[rowVal][colVal + 1]->getOrganismSymbol() == 'o')
			result.push_back("right");
	if (colVal - 1 > 0)
		if (ecosystem[rowVal][colVal - 1] != NULL && ecosystem[rowVal][colVal - 1]->getOrganismSymbol() == 'o')
			result.push_back("left");
	return result;
}

void Doodlebug::starve(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	if (stepsWithoutFood >= 3) {
		int currRowVal = getRowVal();
		int currColVal = getColVal();
		Doodlebug::~Doodlebug();
		delete ecosystem[currRowVal][currColVal];
		ecosystem[currRowVal][currColVal] = NULL;
	}
}
