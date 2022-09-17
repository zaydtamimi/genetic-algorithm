#include "Population.h"


Population::Population(int size, Gene** genes, int noOfGenes, int max_fitness)
{
	this->popSize = size;
	this->max_fitness = max_fitness;
	this->pop = new Chromosome * [size];
	for (int i = 0; i < size; i++)
	{
		this->pop[i] = createNewSol(genes, noOfGenes);
		this->pop[i]->evaluateFitness();
	}
}
Chromosome** Population::getPopulation()
{
	return pop;
}
int Population::getPopulationSize()
{
	return popSize;
}
Chromosome* Population::createNewSol(Gene** genes, int noOfGenes)
{
	Gene** newGenes = new Gene * [noOfGenes];
	float random = 0;
	for (int i = 0; i < noOfGenes; i++)
	{
		random = (float)rand() / RAND_MAX;
		if (random > 0.5)
		{
			newGenes[i] = new Gene(genes[i]->getName(), genes[i]->getWeight(), genes[i]->getValue());
		}
		else
		{
			newGenes[i] = new Gene(genes[i]->getName(), 0, 0);

		}
	}
	Chromosome* temp = new Chromosome( newGenes, noOfGenes, max_fitness);
	return temp;
}
void Population::printPopulation()
{
	for (int i = 0; i < popSize; i++)
	{
		//pop[i]->printChromosome();
		cout << "fitness:" << pop[i]->getFitness() << endl;
		cout << endl;
	}
}
Population::~Population()
{
	for (int i = 0; i < popSize; i++)
	{
		pop[i]->~Chromosome();
//		delete pop[i];
		pop[i] = nullptr;
	}
	delete[] pop;
}
