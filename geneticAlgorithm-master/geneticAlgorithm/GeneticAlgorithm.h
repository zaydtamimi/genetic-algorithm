#pragma once
#include "Population.h"
class GeneticAlgorithm
{
public:
	Chromosome** crossOver(Chromosome* firstParent, Chromosome* secondParent);
	Chromosome** selectParents(Population* population);
	void mutation(Chromosome* firstOffspring, Chromosome* secondOffspring);
	void evaluateOffspring(Chromosome* firstOffspring, Chromosome* secondOffspring);
	void replace(Population*pop, Chromosome* firstOffspring, Chromosome* secondOffspring);
};

