#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h> 
using namespace std;


const char EMPTY_SPACE_CHAR = '-';
const char DOODLEBUG_CHAR = 'X';
const char ANT_CHAR = 'o';
const int ECOSYSTEM_ROW_MAX_VAL = 20;
const int ECOSYSTEM_COL_MAX_VAL = 20;

class Organism
{
	
public:
	Organism(int rowVal, int colVal, char organismSymbol, int stepsToBreed);
	virtual ~Organism();
	void setOrganismSymbol(char organismSymbol);
	void setStepsSurvived(int stepsSurvived);
	void setStepsToBreed(int stepsToBreed);
	void setRowVal(int rowVal);
	void setColVal(int colVal);
	char getOrganismSymbol() const;
	int getStepsSurvived() const;
	int getStepsToBreed() const;
	int getRowVal() const;
	int getColVal() const;
	virtual void move(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]) = 0;
	virtual void breed(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]) = 0;
	void incrementStepsSurvived();
	vector<string> getEmptyAdjacentCoordinates(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
	void updateCoordinates(vector<string> directions, int& rowVal, int& colVal);

private:
	char organismSymbol;
	int stepsToBreed;
	int stepsSurvived;
	int rowVal;
	int colVal;

};

