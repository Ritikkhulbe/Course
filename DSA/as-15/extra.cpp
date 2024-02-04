#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> ans = {"flow","fdsf","gfgdsf","khdofgk"};
    sort(ans.begin(), ans.end());
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}