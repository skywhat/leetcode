#include<iostream>

#include<math.h>
/*
 * Complete the function below.
 */
double binStrToNum(const string& s){
    double res=0;
    double val=1.0;
    for(int i=s.size()-1;i>=0;--i){
        res+=double(s[i]-'0')*val;
        val*=2.0;
    }
    return res;
}
double computeDist(const string& s1,const vector<double>& v2){
    vector<double> v1;
    v1.push_back(binStrToNum(s1.substr(0,8)));
    v1.push_back(binStrToNum(s1.substr(8,8)));
    v1.push_back(binStrToNum(s1.substr(16,8)));
    double dist=0;
    for(int i=0;i<3;i++){
        dist+=(v1[i]-v2[i])*(v1[i]-v2[i]);
    }
    return sqrt(dist);
    
}
vector <string> closestColor(vector <string> pixels) {
    vector<vector<double>> p={{0,0,0},{255,255,255},{255,0,0},{0,255,0},{0,0,255}};
    vector<string> res;
    vector<string> name={"Black","White","Red","Green","Blue"};
    for(int k=0;k<pixels.size();++k){
        vector<double> dist;
        for(int i=0;i<p.size();++i){
            dist.push_back(computeDist(pixels[k],p[i]));
        }
        int ind=0;
        double closest=dist[0];
        for(int i=1;i<dist.size();++i){
            if(dist[i]<closest){
                ind=i;
                closest=dist[i];
            }
        }
        for(int i=0;i<dist.size();++i){
            if(dist[i]==closest&&ind!=i){
                res.push_back("Ambiguous");
                break;
            }
        }
        if(res.size()==(k+1))
            continue;
        res.push_back(name[ind]);
        
    }
    return res;
    
}
