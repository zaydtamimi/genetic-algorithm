#pragma once
#include "Gene.h"
class Chromosome
{
private:
	static int chromosID;
	int id;
	Gene** genes;
	int fitness;
	int noOfGenes;
	int maxFitness;
public:
	Chromosome( Gene** genes,int noOfGenes, int max_fitness);
	Chromosome(Chromosome const& other);
	int getID();
	int getNoGenes();
	Gene** getGenes();
	void evaluateFitness();
	int getFitness();
	void printChromosome();
	~Chromosome();
};

