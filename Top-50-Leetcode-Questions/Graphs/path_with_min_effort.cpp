class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        if (row == 1 && col == 1) return 0;
        UnionFind unionFind(heights);
        vector<Edge> edgeList = unionFind.edgeList;
        sort(edgeList.begin(), edgeList.end(), compareInterval);

        for (int i = 0; i < edgeList.size(); i++) {
            int x = edgeList[i].x;
            int y = edgeList[i].y;
            unionFind.makeUnion(x, y);
            if (unionFind.find(0) == unionFind.find(row * col - 1))
                return edgeList[i].difference;
        }
        return -1;
    }

    class Edge {
    public:
        int x, y;
        int difference;

        Edge(int x, int y, int difference) {
            this->x = x;
            this->y = y;
            this->difference = difference;
        }
    };

    static bool compareInterval(const Edge& p1, const Edge& p2) {
        return (p1.difference < p2.difference);
    }

    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        vector<Edge> edgeList;

        UnionFind(vector<vector<int>>& heights) {
            int row = heights.size();
            int col = heights[0].size();
            parent.assign(row * col, 0);
            rank.assign(row * col, 0);
            for (int currentRow = 0; currentRow < row; currentRow++) {
                for (int currentCol = 0; currentCol < col; currentCol++) {
                    if (currentRow > 0) {
                        edgeList.push_back(
                            Edge(currentRow * col + currentCol,
                                 (currentRow - 1) * col + currentCol,
                                 abs(heights[currentRow][currentCol] -
                                     heights[currentRow - 1][currentCol])));
                    }
                    if (currentCol > 0) {
                        edgeList.push_back(
                            Edge(currentRow * col + currentCol,
                                 currentRow * col + currentCol - 1,
                                 abs(heights[currentRow][currentCol] -
                                     heights[currentRow][currentCol - 1])));
                    }
                    parent[currentRow * col + currentCol] =
                        currentRow * col + currentCol;
                }
            }
        }

        int find(int i) {
            if (parent[i] != i) parent[i] = find(parent[i]);
            return parent[i];
        }

        void makeUnion(int x, int y) {
            int parentX = find(x);
            int parentY = find(y);
            if (parentX != parentY) {
                if (rank[parentX] > rank[parentY])
                    parent[parentY] = parentX;
                else if (rank[parentX] < rank[parentY])
                    parent[parentX] = parentY;
                else {
                    parent[parentY] = parentX;
                    rank[parentX] += 1;
                }
            }
        }
    };
};
