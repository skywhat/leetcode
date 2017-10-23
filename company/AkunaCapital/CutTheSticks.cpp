#include<iostream>
#include<vector>

/*
 * Complete the function below.
 */
int findCutLen(vector<int> lengths){
    int cut=INT_MAX;
    for(auto l:lengths){
        if(l!=0){
            cut=min(cut,l);
        }
    }
    return cut;
}
vector <int> cutSticks(vector <int> lengths) {
    vector<int> res;
    while(true){
        int cut=findCutLen(lengths);
        int cnt=0;
        for(auto& l:lengths){
            if(l!=0){
                l=l-cut;
                cnt++;
            }
        }
        if(cnt==0)
            break;
        res.push_back(cnt);
    }
    return res;
}

