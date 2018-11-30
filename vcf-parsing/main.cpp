//
//  main.cpp
//  readinVCF
//
//  Created by mac on 2014-11-09.
//  Copyright © 2018 ruccizeng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int junkNum = 9;
int seqNum = 0;
vector<string> pos;
vector<string> REF;
vector<string> alt;
vector<vector<int> > spec;

int main(int argc, const char * argv[]) {
    /*if (argc!=3) {
        cout << "Argument 1 is .vcf file. Argument 2 is the command you want. Command type: 1 - only rCRS is different." << endl;
    }*/
    
    ifstream vcf;
    vcf.open(argv[1]);
    if(!vcf.is_open()){
        cout << "The file is not open." << endl;
    }
    string Case_s = argv[2];
    stringstream Case_ss;
    Case_ss << Case_s;
    int Case;
    Case_ss >> Case;
    
    // readin all data first
    string line;
    stringstream ss;
    while(!vcf.eof()) {
        getline(vcf, line);
        if (line[0]!='#') {
            break;
            // skip on #
        }
    }
    //cout << line << endl;
    ss << line;
    string s;
    vector<string> vec_s;
    while (ss >> s){
        //cout << s << endl;
        vec_s.push_back(s);
        seqNum++;
        if (seqNum==2) {
            pos.push_back(s);
        }
        if (seqNum==3) {
            REF.push_back(s);
        }
        if (seqNum==4) {
            alt.push_back(s);
        }
    }
    seqNum -= junkNum;
    //cout << seqNum << endl;
    for (int i = 0; i < seqNum; i++) {
        vector<int> cur_spec;
        stringstream cur_ss;
        cur_ss << vec_s.at(i+junkNum);
        int cur_num;
        cur_ss >> cur_num;
        //cout << cur_num <<endl;
        cur_spec.push_back(cur_num);
        spec.push_back(cur_spec);
    }
    //cout << spec.size() << endl;
    /*
    for (int i = 0; i < spec.size(); i++) {
        for (int k = 0; k < spec.at(i).size(); k++) {
            cout << spec.at(i).at(0) << endl;
        }
    }
     */
    while(!vcf.eof()) {
        getline(vcf, line);
        stringstream line_ss;
        line_ss << line;
        int cur_num;
        for(int junCount = 0; junCount < junkNum; junCount++) {
            line_ss >> s;
            if (junCount==1) {
                pos.push_back(s);
            }
            if (junCount==3) {
                REF.push_back(s);
            }
            if (junCount==4) {
                alt.push_back(s);
            }
        }
        int count = 0;
        while (line_ss >> cur_num) {
            spec.at(count).push_back(cur_num);
            count++;
        }
        
    }
    
    
    // comparison begin:
    vector<string> found_pos;
    if (Case == 1) {
        ofstream myfile;
        //myfile << "#Human being distinct.\n";
        myfile.open (argv[6]);
        for (int i = 0; i < spec.at(0).size(); i++) {
            bool others_all_one = 1;
            for (int k = 1; k < spec.size(); k++) {
                if (spec.at(k).at(i)==0) {
                    others_all_one = 0;
                }
            }
            if (spec.at(0).at(i)==0 && others_all_one == 1) {
                found_pos.push_back(pos.at(i));
                myfile << pos.at(i) << " ";
                myfile << REF.at(i) << " " << alt.at(i) << endl;
            }
        }
        myfile.close();
    }
    if (Case == 2 || Case == 3) {
        string huNum_s = argv[3];
        stringstream hu_ss;
        hu_ss << huNum_s;
        int huNum;
        hu_ss >> huNum;
        
        stringstream nean_ss;
        string neanNum_s = argv[4];
        nean_ss << neanNum_s;
        int neanNum;
        nean_ss >> neanNum;
        
        stringstream deni_ss;
        string deniNum_s = argv[5];
        deni_ss << deniNum_s;
        int deniNum;
        deni_ss >> deniNum;
        //cout << huNum <<endl;
        //cout << neanNum <<endl;
        //cout << deniNum <<endl;
        bool hu_same;
        bool nean_same;
        bool devi_same;
        
        int hu_tag = 0;
        int nean_tag = 0;
        int devi_tag = 0;
        ofstream myfile;
        myfile.open (argv[6]);
        if (Case == 3) {
            //myfile << "#Human same with Deni but different with Nean.\n";
        }
        else {
            //myfile << "#Human same with Nean but different with Deni.\n";
        }
        
        for (int i = 0; i < spec.at(0).size(); i++) {
            hu_same = 1;
            nean_same = 1;
            devi_same = 1;
            for (int k = 0; k < huNum; k++) {
                hu_tag = spec.at(0).at(i);
                if (spec.at(k).at(i)!=spec.at(0).at(i)) {
                    hu_same = 0;
                }
            }
            for (int k = huNum; k < huNum + neanNum; k++) {
                nean_tag = spec.at(huNum).at(i);
                if (spec.at(k).at(i)!=spec.at(huNum).at(i)) {
                    nean_same = 0;
                }
            }
            for (int k = huNum + neanNum; k < huNum + neanNum + deniNum; k++) {
                devi_tag = spec.at(huNum + neanNum).at(i);
                if (spec.at(k).at(i)!=spec.at(huNum + neanNum).at(i)) {
                    devi_same = 0;
                }
            }
            if (Case == 2) {
                
                //cout << hu_same << nean_same<< devi_same<< endl;
                if (hu_same==1 && nean_same==1 && devi_same==1) {
                    //cout << pos.at(i) << endl;
                    if (hu_tag == nean_tag && devi_tag != nean_tag) {
                        found_pos.push_back(pos.at(i));
                        myfile << hu_tag << nean_tag << devi_tag << " ";
                        myfile << pos.at(i) << " ";
                        myfile << REF.at(i) << " " << alt.at(i) << endl;

                    }
                }
                
            }
            if (Case == 3) {
                //cout << hu_same << nean_same<< devi_same<< endl;
                if (hu_same==1 && nean_same==1 && devi_same==1) {
                    //cout << pos.at(i) << endl;
                    if (hu_tag == devi_tag && devi_tag != nean_tag) {
                        found_pos.push_back(pos.at(i));
                        myfile << hu_tag << nean_tag << devi_tag << " ";
                        myfile << pos.at(i) << " ";
                        myfile << REF.at(i) << "->" << alt.at(i) << endl;

                    }
                }
            }
        }
        myfile.close();
    }
}






