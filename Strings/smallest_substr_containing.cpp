#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string smallestSubstringContaining(string b, string s) {
  
	// hm for small
	unordered_map<char, int> umap; 
	for(char ch : s)
	{
		++umap[ch];
	}
	int n = b.size();
	int flag = 0;
	int ans_size = INT_MAX;
    string ans;
	for(int i = 0; i < n; ++i)
	{
		if(umap.find(b[i]) != umap.end())
		{
			string substr = "";
			auto hm = umap;
			for(int j = i; j < n; ++j)
			{
				substr += b[j];
				if(hm.find(b[j]) != hm.end())
				--hm[b[j]];
				if(hm[b[j]] == 0)
				{
					// delete that key value pair
					// else use a set 
					hm.erase(b[j]);
				
				if(hm.size() == 0) // found small
				{
					flag = 1;
					break;
				}
				}
				
			}
			if(flag)
			{
                cout << substr << endl;
				if(ans_size > substr.size())
				{
					ans = substr;
                    ans_size = ans.size();
                    cout << "improved ans: " << ans << endl;
				}
                flag = 0;
			}
			else
			{
				break;
			}
		}	
	}
	return ans;	
}

int main()
{
    string b;
    string s;
    cout << "Enter big and small strings respectively: \n";
    cin >> b >> s;
    string ans = smallestSubstringContaining(b, s);
    cout << "The substr is: " << ans << endl;
    return 0;
}