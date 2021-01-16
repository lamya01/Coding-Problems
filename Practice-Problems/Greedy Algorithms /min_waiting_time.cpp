using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
	sort(queries.begin(), queries.end()); // 1,2,2,3,6
	int waittime = 0;
	int total_waittime = 0;
	for(int i = 1; i < (int)queries.size(); ++i)
	{
		waittime += queries[i - 1];// 1+2 = 3 + 2 = 5 + 3 = 8
		total_waittime += waittime;// 1+ 3 = 4 + 5 = 9 + 8 = 17
	}
  return total_waittime;
}
