#include<bits/stdc++.h>
using namespace std;
#define ll long long

int max(int arr[], int n) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    vector<ll> count;
    unordered_map<ll,ll> countIndex;
    unordered_map<ll,ll> vals;
    countIndex[0] = -1;
    vals[0]=1;
    ll val = 0;
    
    for(ll i=0;i<n;i++){
        if(arr[i])
            ++val;
        else
            --val;
        count.push_back(val);
        
        if(!vals[val])
            countIndex[val] = i;
        vals[val]=1;
    }
  //  cout<<countIndex[1]<<endl;
    ll ans = 0;
    
    for(ll i=n-1;i>=0;i--){
        ans = max(ans, i-countIndex[count[i]]);
       // cout<<"index: "<<i<<" len: "<<ans<<"count[i] "<<count[i]<<endl;
    }
    return ans;
    

}
