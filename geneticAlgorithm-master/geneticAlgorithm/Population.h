#pragma once
#include "Chromosome.h"
#include <time.h>

class Population
{
private:

	Chromosome** pop;
	
	int popSize;
	int max_fitness;
	Chromosome* createNewSol(Gene** genes, int noOfGenes);
public:
	Population(int size, Gene** genes, int noOfGenes,int max_fitness);
	int getPopulationSize();
	Chromosome** getPopulation();
	void printPopulation();
	~Population();
};

