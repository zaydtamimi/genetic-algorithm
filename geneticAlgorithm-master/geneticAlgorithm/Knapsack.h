#pragma once
#include "GeneticAlgorithm.h"
class Knapsack
{
	Gene** genes;
	int noOfGenes;
	Population* pop;
public:
	Knapsack(Gene** genes, int noOfGenes);
	void run( int noOfGenerations,float crossOverT,float mutationT, int popSize );
	Chromosome* getSolution();
	float* metrics();
	~Knapsack();

};

