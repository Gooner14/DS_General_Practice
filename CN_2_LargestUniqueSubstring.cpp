// input - given string
// output - output string that contains largest unique substring
#include<bits/stdc++.h>
using namespace std;
string out="";
unordered_map<char,int> m;
void findLargestUniqueSubstring(char input[], char output[]){
	// Write your code here
    string s(input);
    string ans="";
    int n=s.size();
    int i=0,j=0;
    while(i<n && j<n)
    {
       // cout<<"ans is "<<ans<<endl;
        if(m[s[j]])
        {
        	//cout<<"char: "<<s[j]<<endl;
            m.clear();
            string an="";
            for(int k=ans.size()-1;k>=0;k--)
            {
            	//cout<<"ans: "<<ans<<endl;
                if(ans[k]!=s[j])
                {
                //	cout<<"k is:"<<k<<endl;
                    an+=ans[k];
                    ++m[ans[k]];
                }
                else
                {
                    reverse(an.begin(),an.end());
                    ans=an+s[j];
                    ++m[s[j]];
                    break;
                }
            }
            ++j;
            continue;
        }
        ++m[s[j]];
        ans+=s[j];
        ++j;
        if(out.size()<ans.size())
            out=ans;
    }
    strcpy(output,out.c_str());
}
