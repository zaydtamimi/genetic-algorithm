#include "Chromosome.h"

int Chromosome::chromosID = 1;

Chromosome::Chromosome( Gene** genes,int noOfGenes, int max_fitness)
{
	this->id = chromosID;
	chromosID++;
	this->genes = new Gene * [noOfGenes];
	for (int i = 0; i < noOfGenes; i++)
	{
		this->genes[i] = new Gene(*genes[i]);
	}
	this->fitness = 0;
	this->noOfGenes = noOfGenes;
	this->maxFitness = max_fitness;
	
}
Chromosome::Chromosome(Chromosome const& other)
{
	if (this != &other)
	{
		this->id = chromosID;
		chromosID++;
		this->noOfGenes = other.noOfGenes;
		this->genes = new Gene *[noOfGenes];
		for (int i = 0; i < noOfGenes; i++)
		{
			this->genes[i] = new Gene(*other.genes[i]);
		}
		this->fitness = other.fitness;
		this->maxFitness = other.maxFitness;

	}
}
int Chromosome::getID()
{
	return chromosID;
}
Gene** Chromosome::getGenes()
{
	return genes;
}
void Chromosome::evaluateFitness()
{
	int tweight = 0;
	int tvalue = 0;
	for (int i = 0; i < noOfGenes; i++)
	{
		tweight += genes[i]->getWeight();
		tvalue += genes[i]->getValue();
	}
	if (tweight <= maxFitness)
	{
		this->fitness = tvalue;
	}
}
int Chromosome::getFitness()
{
	return fitness;
}
int Chromosome::getNoGenes()
{
	return noOfGenes;
}
void Chromosome::printChromosome()
{
	for (int i = 0; i < noOfGenes; i++)
	{
		genes[i]->printGene();
		cout << "\n";
	}
}
Chromosome::~Chromosome()
{
	for (int i = 0; i < noOfGenes; i++)
	{
		if (genes[i])
		{
			delete genes[i];
			genes[i] = nullptr;
		}
	}
	delete[] genes;
}
