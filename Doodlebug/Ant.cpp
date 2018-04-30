#include "stdafx.h"
#include "Ant.h"


Ant::Ant(int rowVal, int colVal):Organism(rowVal, colVal, 'o', 3)
{
}

void Ant::move(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	vector<string> emptyAdjacentCoordinates = getEmptyAdjacentCoordinates(ecosystem);
	if (emptyAdjacentCoordinates.size() > 0) {
		srand(time(0));
		int randomDirection = rand() % emptyAdjacentCoordinates.size();
		int currRowVal = getRowVal();
		int currColVal = getColVal();
		int newRowVal = getRowVal();
		int newColVal = getColVal();
		updateCoordinates(emptyAdjacentCoordinates, newRowVal, newRowVal);
		setRowVal(newRowVal);
		setColVal(newColVal);
		ecosystem[currRowVal][currColVal] = NULL;
		ecosystem[newRowVal][newColVal] = this;
	}
	incrementStepsSurvived();
	breed(ecosystem);
}

void Ant::breed(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	if (getStepsSurvived() >= getStepsToBreed()) {
		vector<string> emptyAdjacentCoordinates = getEmptyAdjacentCoordinates(ecosystem);
		if (emptyAdjacentCoordinates.size() > 0) {
			int currRowVal = getRowVal();
			int currColVal = getColVal();
			updateCoordinates(emptyAdjacentCoordinates, currRowVal, currColVal);
			ecosystem[currRowVal][currColVal] = new Ant(currRowVal, currColVal);
			setStepsSurvived(0);
		}
	}
}



Ant::~Ant()
{
}
