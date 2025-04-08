#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;





int main()
{	
	double S;
	int n;
	string lineafile;
	vector<string> linea_corrente;
	vector<double> w;
	vector<double> r;
	double counter = 0.0;
	double tassoritorno;

	ifstream myfile("data.txt");
	if (!myfile) {
		cerr << "Impossibile aprire il file!!!" << endl;
		return 1;
	}
	
	while (getline(myfile, lineafile)) {
		linea_corrente.clear();
		stringstream ss(lineafile);
		string valore;
		
		
		while (getline(ss, valore, ';')) {
			linea_corrente.push_back(valore);
		}
		
		
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
	
	
	ofstream outfile("result.txt");
	if (!outfile) {
		cerr << "Impossibile scrivere sul file!!!" << endl;
		return 1;
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
	
	
	for (size_t i = 0; i < w.size(); i++){
		counter = counter + (1 + r[i])*w[i];
	}
	tassoritorno = counter - 1;
	counter = counter*S;

	outfile << "Rate of return of the portfolio: " << tassoritorno << endl;

	outfile << fixed << setprecision(2);
	outfile << "V: " << counter << endl;
	outfile.close();
	
 	return 0;
}
