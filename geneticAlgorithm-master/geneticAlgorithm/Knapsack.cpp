#include "Knapsack.h"
#include <fstream>
Knapsack::Knapsack(Gene** genes, int noOfGenes)
{
	this->genes = genes;
	this->noOfGenes = noOfGenes;
	this->pop = nullptr;
}
void Knapsack::run(int noOfGenerations, float crossOverT, float mutationT, int popSize)
{
	this->pop = new Population(popSize, genes, noOfGenes, 3000);
	GeneticAlgorithm ga;
	Chromosome** parents,**offsprings;
	// File pointer
	fstream fin;

	// Open an existing file
	fin.open("run.csv", ios::out);

	float* result;
	for (int i = 0; i < noOfGenerations; i++)
	{
		 //this->pop->printPopulation();
		 parents = ga.selectParents(pop);
		 offsprings = ga.crossOver(parents[0], parents[1]);
		 ga.mutation(offsprings[0], offsprings[1]);
		 ga.evaluateOffspring(offsprings[0], offsprings[1]);
		 ga.replace(pop, offsprings[0], offsprings[1]);
		 result = metrics();
		 fin << result[1] << "," << result[2] << "," << result[0] << endl;
	}
	fin.close();
}
Chromosome* Knapsack::getSolution()
{
	Chromosome* fitest = pop->getPopulation()[0];
	for (int i = 1; i < this->pop->getPopulationSize(); i++)
	{
		if (pop->getPopulation()[i]->getFitness()>fitest->getFitness())
		{
			fitest = pop->getPopulation()[i];
		}
	}
	return new Chromosome(*fitest);
}
Knapsack::~Knapsack()
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
	genes = nullptr;
	pop->~Population();
//	delete pop;
	pop = nullptr;
}

float* Knapsack::metrics()
{
	int size = pop->getPopulationSize();
	float maxfitness = INT16_MIN , minfitness = INT16_MAX, averagefitness = 0;
	Chromosome** popl = pop->getPopulation();
	for (int i = 0; i < size; i++)
	{
		if (popl[i]->getFitness() > maxfitness)
		{
			maxfitness = popl[i]->getFitness();
		}
		if (popl[i]->getFitness()< minfitness)
		{
			minfitness = popl[i]->getFitness();
		}
		averagefitness += popl[i]->getFitness();
	}
	averagefitness = averagefitness / size;
	float* temp = new float[3];
	temp[0] = maxfitness;
	temp[1] = minfitness;
	temp[2] = averagefitness;
	return temp;
}