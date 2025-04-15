#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;


bool leggiInput(const string& InFilePath, double& S, int& n, vector<double>& w, vector<double>& r);

vector<double> TassoRitornoAndV(vector<double>& w, vector<double>& r, double& S);

bool ExportResult(const string& OutFilePath, double S, int n, vector<double>& w, vector<double>& r, double V, double tassoritorno);
