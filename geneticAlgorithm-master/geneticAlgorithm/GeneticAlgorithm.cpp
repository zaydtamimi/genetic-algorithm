#include "GeneticAlgorithm.h"
Chromosome** GeneticAlgorithm::crossOver(Chromosome* firstParent, Chromosome* secondParent)
{
	
	float random = (float)rand() / RAND_MAX;
	Chromosome** crossover = new Chromosome * [2];
	int noOfGenes = (*firstParent).getNoGenes();
	if (random <= 0.7)
	{
		Gene** firstOffspring = new Gene * [noOfGenes];
		Gene** secondOffspring = new Gene * [noOfGenes];
		for (int i = 0; i < noOfGenes; i++)
		{
			random = (float)rand() / RAND_MAX;
			if (random >= 0.5)
			{
				 
				firstOffspring[i] = new Gene(*(firstParent->getGenes()[i]));
				secondOffspring[i] = new Gene(*secondParent->getGenes()[i]);
			}
			else
			{
				firstOffspring[i] = new Gene(*(secondParent->getGenes()[i]));
				secondOffspring[i] = new Gene(*firstParent->getGenes()[i]);
			}
		}
		crossover[0] = new Chromosome(firstOffspring, noOfGenes, 3000);
		crossover[1] = new Chromosome(secondOffspring, noOfGenes, 3000);
	}
	else {
		crossover[0] = new Chromosome(*firstParent);
		crossover[1] = new Chromosome(* secondParent);
	}
	return crossover;
}
Chromosome** GeneticAlgorithm::selectParents(Population* population)
{
	Chromosome** parents = new Chromosome * [2];
	int half = population->getPopulationSize() / 2;
	
	int random = rand() % half;
	parents[0] = new Chromosome(*population->getPopulation()[random]);
	int second = (random + half);
	parents[1] = new Chromosome(*population->getPopulation()[second]);
	return parents;
}
void GeneticAlgorithm::mutation(Chromosome* firstOffspring, Chromosome* secondOffspring)
{
	float random1 = 0;
	float random2 = 0;
	for (int i = 0; i < firstOffspring->getNoGenes(); i++)
	{
		random1 = (float)rand() / RAND_MAX;
		random2 = (float)rand() / RAND_MAX;
		if (random1 <= 0.01)
		{
			firstOffspring->getGenes()[i]->setValue(0);
			firstOffspring->getGenes()[i]->setWeight(0);
		}
		if (random2 <= 0.01)
		{
			secondOffspring->getGenes()[i]->setValue(0);
			secondOffspring->getGenes()[i]->setWeight(0);
		}

	}
}
void GeneticAlgorithm::evaluateOffspring(Chromosome* firstOffspring, Chromosome* secondOffspring)
{
	firstOffspring->evaluateFitness();
	secondOffspring->evaluateFitness();
}
void GeneticAlgorithm::replace(Population*pop, Chromosome* firstOffspring, Chromosome* secondOffspring)
{
	int half = pop->getPopulationSize() / 2;

	int random = rand() % half;

	delete pop->getPopulation()[random];
	pop->getPopulation()[random] = nullptr;

	pop->getPopulation()[random] = new Chromosome(*firstOffspring);
	int second = (half + random) ;
	delete pop->getPopulation()[second];
	pop->getPopulation()[second] = new Chromosome(*secondOffspring);


}

