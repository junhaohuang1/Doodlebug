// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <iostream>
#include <vector>
#include <string>
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
void populateAnts(int count, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void populateDoodlebugs(int count, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
void nextTimeStep(Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
int getPopulation(char organismSymbol, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL]);
vector<Cell> cellList;

int main()
{	
	Organism* ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL];
	int antCount = 100;
	int doodleBugCount = 5;
	string temp;
	intializeEcosystem(ecosystem);
	populateAnts(antCount, ecosystem);
	populateDoodlebugs(doodleBugCount, ecosystem);
	cout << "Initial ecosystem." << endl;
	displayEcosystem(ecosystem);
	
	while (antCount > 0 || doodleBugCount > 0) {
		getline(cin, temp);
		if (temp.empty()) {
			nextTimeStep(ecosystem);
			antCount = getPopulation('o', ecosystem);
			doodleBugCount = getPopulation('X', ecosystem);
			cout << "Ant count is " << antCount << endl;
			cout << "Doodlebug count is " << doodleBugCount << endl;
			displayEcosystem(ecosystem);	
		}
	}

	clearEcosystem(ecosystem);

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

void populateAnts(int count, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < count; i++) {
		Cell cell = getRandomCell(cellList);
		ecosystem[cell.rowVal][cell.colVal] = new Ant(cell.rowVal, cell.colVal);
	}
}

void populateDoodlebugs(int count, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < count; i++) {
		Cell cell = getRandomCell(cellList);
		ecosystem[cell.rowVal][cell.colVal] = new Doodlebug(cell.rowVal, cell.colVal);
	}
}

void nextTimeStep(Organism * ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			if (ecosystem[i][j] != NULL && ecosystem[i][j]->getOrganismSymbol() == DOODLEBUG_CHAR) {
				ecosystem[i][j]->move(ecosystem);
			}
		}
	}
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			if (ecosystem[i][j] != NULL && ecosystem[i][j]->getOrganismSymbol() == ANT_CHAR) {
				ecosystem[i][j]->move(ecosystem);
			}
		}
	}
}

int getPopulation(char organismSymbol, Organism *ecosystem[ECOSYSTEM_ROW_MAX_VAL][ECOSYSTEM_COL_MAX_VAL])
{	
	int result = 0;
	for (int i = 0; i < ECOSYSTEM_ROW_MAX_VAL; i++) {
		for (int j = 0; j < ECOSYSTEM_COL_MAX_VAL; j++) {
			cout << i << endl;
			cout << j << endl;
			if (ecosystem[i][j] != NULL && ecosystem[i][j]->getOrganismSymbol() == organismSymbol) {
				result++;
			}
		}
	}
	return result;
}
