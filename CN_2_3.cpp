using namespace std;
#include <bits/stdc++.h>
#define ll long long 

long maxPathSum(int ar1[], int ar2[], int m, int n)
{
    vector<ll> diff1;
    vector<ll> diff2;
    
    map<ll,ll> commonElements1;
    map<ll,ll> commonElements2;
    
    
    for(ll i=0;i<m;i++)
        ++commonElements1[ar1[i]];
    for(ll i=0;i<n;i++){
        ++commonElements2[ar2[i]];
    }
    
	for(ll i=0;i<m;i++){
        commonElements1[ar1[i]] = min(commonElements1[ar1[i]], commonElements2[ar1[i]]);
    }
	for(ll i=0;i<n;i++){
        commonElements2[ar2[i]] = min(commonElements1[ar2[i]], commonElements2[ar2[i]]);
    }
    
    ll sum1 = 0,sum2 = 0;
    for(ll i=0;i<m;i++){
        if(commonElements1[ar1[i]]){
          //  cout<<"sum1: "<<sum1+ar1[i]<<endl;
        	diff1.push_back(sum1+ar1[i]);
            sum1=0;
            --commonElements1[ar1[i]];
            continue;
        }
        sum1+=ar1[i];
    }diff1.push_back(sum1);
    
    for(ll i=0;i<n;i++){
        if(commonElements2[ar2[i]]){
        //    cout<<"sum2: "<<sum2+ar2[i]<<endl;
        	diff2.push_back(sum2+ar2[i]);
            sum2=0;
            --commonElements2[ar2[i]];
            continue;
        }
        sum2+=ar2[i];
    }diff2.push_back(sum2);
 
    ll ans = 0;
    for(ll i=0;i<diff1.size();i++){
        ans+=max(diff1[i],diff2[i]);
    }
    return ans;
}

