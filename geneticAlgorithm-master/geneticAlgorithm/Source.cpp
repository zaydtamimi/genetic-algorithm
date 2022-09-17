#include "Knapsack.h"
#include <fstream>
#include <sstream>
Gene** readGenesFromFile(string fileName)
{
	
		// File pointer
		fstream fin;

		// Open an existing file
		fin.open(fileName.c_str(), ios::in);

		string gene[3];
		
		string temp,line;
		getline(fin, line);
		
		string word;

		Gene** genes = new Gene * [20];
		int i = 0;
		while (fin) {

			getline(fin, line);
			//cout << line<<endl;

			stringstream s(line);
			int counter = 0;
			while (getline(s, word, ',')) {

				// add all the column data
				// of a row to a vector
				gene[counter] = word;
				counter++;
			}
			if (gene[0] != "")
			{
				
				genes[i] = new Gene(gene[0], stoi(gene[1]), stoi(gene[2]));
				i++;
			}
			gene[0] = "";
			gene[1] = "";
			gene[2] = "";
			
		}
		fin.close();
		return genes;

}

int main()
{
	srand((unsigned)time(NULL));

	cout << "*** genetic knapsack ***\n";
	Knapsack prob(readGenesFromFile("resit_data_file.csv"),20);
	prob.run(300, 0.7, 0.01, 50);
	prob.getSolution()->printChromosome();
	return 0;
}