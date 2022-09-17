#pragma once
#include <string>
#include <iostream>
using namespace std;
class Gene
{
private:
	string ganeName;
	int weight;
	int value;
public:
	Gene() {};
	Gene(Gene const& other);
	Gene(string name, int weight, int value);
	Gene& operator=(Gene other);
	string getName();
	int getWeight();
	void setWeight(int weight);
	int getValue();
	void setValue(int val);
	void printGene();
};

