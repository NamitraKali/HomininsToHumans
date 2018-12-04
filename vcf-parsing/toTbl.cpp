//
//  toTbl.cpp
//  readinVCF
//
//  Created by mac on 2014-11-12.
//  Copyright © 2018 ruccizeng. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    ifstream vcf;
    vcf.open(argv[1]);
    if(!vcf.is_open()){
        cout << "The file is not open." << endl;
    }
    ofstream myfile;
    myfile.open(argv[2]);
    // readin all data first
    string line;
    string prev;
    stringstream ss;
    while(!vcf.eof()) {
        prev = line;
        getline(vcf, line);
        if (line[0]!='#') {
            break;
            // skip on #
        }
    }
    myfile << prev << endl;
    myfile << line << endl;
    while(!vcf.eof()) {
        getline(vcf, line);
        myfile << line << endl;
    }
    myfile.close();
}
