// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <iostream>
#include <vector>
using namespace std;

struct Cell {
	int rowVal;
	int colVal;
	Cell() :rowVal(0), colVal(0)
	{
	}
};

void displayEcosystem(Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void clearEcosystem(Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void intializeEcosystem(Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
Cell getRandomCell(vector<Cell>& cellList);
void populateAnts(int count, vector<Organism*>& antList, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void populateDoodlebugs(int count, vector<Organism*>& doodlebugList, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void clearVectors(vector<Organism*> vec);
vector<Organism*> antList;
vector<Organism*> doodlebugList;
vector<Cell> cellList;

int main()
{


	Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL];
	intializeEcosystem(ecosystem);
	populateAnts(100, antList, ecosystem);
	populateDoodlebugs(5, doodlebugList, ecosystem);
	displayEcosystem(ecosystem);
	clearVectors(antList);
	clearVectors(doodlebugList);
	//clearEcosystem(ecosystem);

    return 0;
}

void displayEcosystem(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			if (ecosystem[i][j] == NULL) {
				cout << '-' << ' ';
			}
			else {
				cout << ecosystem[i][j]->getOrganismSymbol() << ' ';
			}
		}
		cout << endl;
	}
}

void clearEcosystem(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			if (ecosystem[i][j] != NULL) {
				ecosystem[i][j]->~Organism();
				delete ecosystem[i][j];
				ecosystem[i][j] = NULL;
			}
		}
	}
}



void intializeEcosystem(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			ecosystem[i][j] = NULL;
			Cell cell;
			cell.rowVal = i;
			cell.colVal = j;
			cellList.push_back(cell);
		}
	}
}

Cell getRandomCell(vector<Cell>& cellList)
{
	srand(time(0));
	int randomNum = rand() % cellList.size();
	Cell cell;
	cell.rowVal = cellList[randomNum].rowVal;
	cell.colVal = cellList[randomNum].colVal;
	cellList.erase(cellList.begin() + randomNum);
	return cell;
}

void populateAnts(int count, vector<Organism*>& antList, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < count; i++) {
		Cell cell = getRandomCell(cellList);
		ecosystem[cell.rowVal][cell.colVal] = new Ant(cell.rowVal, cell.colVal);
		antList.push_back(ecosystem[cell.rowVal][cell.colVal]);
	}
}

void populateDoodlebugs(int count, vector<Organism*>& doodlebugList, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < count; i++) {
		Cell cell = getRandomCell(cellList);
		ecosystem[cell.rowVal][cell.colVal] = new Doodlebug(cell.rowVal, cell.colVal);
		antList.push_back(ecosystem[cell.rowVal][cell.colVal]);
	}
}

void clearVectors(vector<Organism*> vec)
{
	for (int i = 0; i < vec.size(); i++) {
		delete vec[i];
		vec[i] = NULL;
	}
}
