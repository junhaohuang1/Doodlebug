#pragma once
#include "Organism.h"
class Doodlebug :
	public Organism
{
public:
	Doodlebug(int rowVal, int colVal);
	void move(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
	~Doodlebug();
	void setStepsWithoutFood(int stepsWithoutFood);
	int getStepsWithoutFood() const;
	void incrementstepsWithoutFood();
	void breed(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
	vector<string> getAdjacentAntCoordinates(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
	void starve(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);

private:
	int stepsWithoutFood;

};

