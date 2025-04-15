#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"
#include <iomanip>



using namespace std;

int main()
{	
	
	string NomeInFile = "./data.txt";
	double S;
	int n;
	vector<double> w;
	vector<double> r;
	
	if (!leggiInput(NomeInFile,S,n,w,r)) {
		cerr<<"Errore all'apertura!!!"<<endl;
		return 1;
	}else{
		cout<< "importato correttamente!"<<endl;
	}
	
	vector<double> vettore_tasso_e_V = TassoRitornoAndV(w,r,S);
	double tassoritorno = vettore_tasso_e_V[0];
	double V = vettore_tasso_e_V[1];
	
	string NomeOutFile = "./risultato.txt";
	if (!ExportResult(NomeOutFile,S,n,w,r,V,tassoritorno)) {
		cerr<<"Errore nella scrittura!!!"<<endl;
		return 1;
	}
	else{
		cout<< "File di output completato"<<endl;
	}
	
	return 0;
}
