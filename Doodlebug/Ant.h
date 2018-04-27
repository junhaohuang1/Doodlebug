#pragma once
#include "Organism.h"
class Ant :
	public Organism
{
public:
	Ant(int rowVal, int colVal);
	~Ant();
	void move(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
	void breed(Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
};

