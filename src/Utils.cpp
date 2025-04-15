#include "Utils.hpp"

#include "vector"
#include "string"
#include "iostream"
#include "fstream"
#include "sstream"

#include <iomanip>

using namespace std;



bool leggiInput(const string& InFilePath, double& S, int& n, vector<double>& w, vector<double>& r)
{
	
	vector<string> linea_corrente;
	string lineafile;
	
	ifstream myfile(InFilePath);
	if (!myfile) {
		return false;
	}
	
	
	while (getline(myfile, lineafile)) {
		linea_corrente.clear();
		stringstream ss(lineafile);
		string valore;
		
		
		while (getline(ss, valore, ';')) {
			linea_corrente.push_back(valore);
		}
		
		
		if (linea_corrente.size() < 2){ continue; };
		if (linea_corrente[0]=="S") {
			S = stod(linea_corrente[1]);
		}else if (linea_corrente[0]=="n") {
			n = stoi(linea_corrente[1]);
		}else if (isdigit(linea_corrente[0][0])) {
			w.push_back(stod(linea_corrente[0]));
			r.push_back(stod(linea_corrente[1]));
		}
	}
	myfile.close();
	return true;
}


vector<double> TassoRitornoAndV(vector<double>& w, vector<double>& r, double& S){
	vector<double> vec;
	double V = 0.0;

	for (size_t i = 0; i < w.size(); i++){
		V = V + (1 + r[i])*w[i];
	}
	
	vec.push_back(V - 1);
	vec.push_back(V*S);
	return vec;
}


bool ExportResult(const string& OutFilePath, double S, int n, vector<double>& w, vector<double>& r, double V, double tassoritorno)
{
	ofstream outfile(OutFilePath);
	if (!outfile) {
		return false;
	}
	
	
	outfile << fixed << setprecision(2);
	outfile<<"S = "<<S<<", "<<"n = "<<n<<endl;
	outfile << defaultfloat;
	
	outfile<<"w = [ ";
	
	for (auto itor = w.begin(); itor != w.end(); itor++) {
		outfile<<*itor<<' ';
	}
	
	
	outfile<<"]"<<endl<<"r = [ ";
	
	for (auto itor = r.begin(); itor != r.end(); itor++) {
		
		outfile<<*itor<<' ';
	}
	outfile<<"]"<<endl;

	outfile << "Rate of return of the portfolio: " << tassoritorno << endl;

	outfile << fixed << setprecision(2);
	outfile << "V: " << V << endl;
	outfile.close();
	
	return true;
}

	