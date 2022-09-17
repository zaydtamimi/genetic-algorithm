#include "Gene.h"
Gene::Gene(string name, int weight, int value)
{
	this->ganeName = name;
	this->weight = weight;
	this->value = value;
}
Gene::Gene(Gene const& other)
{
	if (this != &other)
	{
		this->ganeName = other.ganeName;
		this->weight = other.weight;
		this->value = other.value;

	}
}
string Gene::getName()
{
	return ganeName;
}
int Gene::getWeight()
{
	return weight;
}
void Gene::setWeight(int weight)
{
	this->weight = weight;
}
void Gene::setValue(int val)
{
	this->value = val;
}
int Gene::getValue()
{
	return value;
}
void Gene::printGene()
{
	cout << ganeName<<" " << weight<<" " << value;
}
Gene& Gene::operator=(Gene other)
{
	if (this!=&other)
	{
		this->ganeName = other.getName();
		this->weight = other.getWeight();
		this->value = other.getValue();
		
	}
	return *this;
}
