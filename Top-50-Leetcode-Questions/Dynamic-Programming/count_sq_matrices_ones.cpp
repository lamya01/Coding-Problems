class cell
{
    public:
    int r; // no.s 0s to the right
    int b; // no.s .....below
    cell()
    {
        this->r = 0;
        this->b = 0;
    }
   
};

class Solution {
public:
    bool isFilled(int i, int j, int s, vector<vector<int>>& mat)
    {
        int dimension = s - 2;
        int starting_i = i + 1;
        int ending_i = starting_i + dimension;
        int starting_j = j + 1;
        int ending_j = starting_j + dimension;
        
        for(int i1 = starting_i; i1 <= ending_i; ++i1)
        {
            for(int j1 = starting_j; j1 <= ending_j; ++j1)
            {
                if(mat[i1][j1] == 0)
                    return false;
            }
        }
        return true;   
    }
    void noOfSquares(int i1, int j1, vector<vector<cell>> &aux, vector<vector<int>>& mat, int &ans)
    {
        ++ans; // ele in itself is a sq of dimension 1x1
        cell &curr = aux[i1][j1];
        int nr = curr.r;
        int nb = curr.b;
        int sides = min(nr, nb);
        
        for(int s = 1; s <= sides; ++s)
        {
            // check for point 2
            int i2 = i1;
            int j2 = j1 + s;
            cell &point2 = aux[i2][j2];
            if(point2.b >= s)
            {
                // check for point4
                int i4 = i1 + s;
                int j4 = j1;
                cell &point3 = aux[i4][j4];
                if(point3.r >= s)
                {
                    cout << i1 << "," << j1 << "s = " << s << endl;
                    // if s > 1 then check if sq is filled w/ 1s
                    if(isFilled(i1, j1, s, mat))
                        ++ans;
                }  
            }
        }   
    }
    
    
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<cell>> aux(m, vector<cell>(n));
        
        // fill the aux, starting bottom right 
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(mat[i][j] == 0) continue;
                cell &curr = aux[i][j];
                
                if(j != n-1)
                {
                    if(mat[i][j + 1]) 
                    {
                        cell &right = aux[i][j + 1];
                        curr.r = right.r + 1;
                    }
                    
                }
                if(i != m - 1)
                {
                    if(mat[i+1][j])
                    {
                        cell &below = aux[i + 1][j];
                        curr.b = below.b + 1;  
                    } 
                }
            }
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                cout << aux[i][j].r << "," << aux[i][j].b << "  ";
            }
            cout << endl;
        }
        
        // 1. 2
        // .  .
        // 4. 3
        
        // iterate each cell considering it as point1 of square
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(mat[i][j])
                    noOfSquares(i, j, aux, mat, ans);
            }
        }
        return ans;     
    }
};


/*
0,0  2,2  1,0  0,2  
1,2  0,1  0,0  0,1  
3,1  2,0  1,1  0,0  
0,0  0,0  0,0  0,0  
0,1s = 2
1,0s = 1
*/