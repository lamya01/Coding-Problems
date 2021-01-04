bool isValid(int i, int j, int rows, int cols)
{
	if(i < rows && j < cols && i >= 0 && j >= 0) 
		return true;
	else
		return false;
}

void dfs(int i, int j, int &size, vector<vector<int>>&matrix, vector<vector<int>>&vis)
{
	//cout << i << " " << j << endl;
	vis[i][j] = 1;
	int x[] = {-1, 0, 0, 1};
	int y[] = {0, 1, -1, 0};
	int x1, y1;
	for(int k = 0; k < 4; ++k)
	{
		x1 = x[k] + i;
		y1 = y[k] + j;
        //cout << " x1 anf y1 are " << x1 << " " << y1 << endl;
		if(isValid(x1, y1, matrix.size(), matrix[0].size()) && !vis[x1][y1] && matrix[x1][y1])
		{
			
			++size;
            //cout << "i and j are:" << i << " " << j << " size=" << size << endl;
			dfs(x1, y1, size, matrix, vis);
		}
	}
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int>ans;
	vector<vector<int>>vis(rows, {0});
	for(int i = 0; i < rows; ++i)
		for(int j = 0; j < cols; ++j)
			vis[i].push_back(0);
	
	int count = 0;
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			if(matrix[i][j] == 1 && !vis[i][j])
			{

				
				++count;
                //cout << "i and j are:" << i << " " << j << " size=" << count << endl;
				dfs(i, j, count, matrix, vis);
				ans.push_back(count);
				count = 0;
			}
		}
	}
  return ans;
}

