class Solution {
public:
    int operationsToFormTriangle(vector<vector<int>>&grid,int y,int x){
        int operation=0,n=grid.size()-1;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n;j++){
                if(j==i || j==(n-i)){
                    if(grid[i][j]!=y){
                        operation++;
                    }
                }else{
                    if(grid[i][j]!=x){
                        operation++;
                    }
                }
            }
        }
        for(int i=(n/2)+1;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(j==(n/2)){
                    if(grid[i][j]!=y){
                        operation++;
                    }
                }else{
                    if(grid[i][j]!=x){
                        operation++;
                    }
                }
            }
        }
        return operation;
    }
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int minimumOperation=operationsToFormTriangle(grid,0,1);
        minimumOperation=min(minimumOperation,operationsToFormTriangle(grid,0,2));
        minimumOperation=min(minimumOperation,operationsToFormTriangle(grid,1,0));
        minimumOperation=min(minimumOperation,operationsToFormTriangle(grid,1,2));
        minimumOperation=min(minimumOperation,operationsToFormTriangle(grid,2,0));
        minimumOperation=min(minimumOperation,operationsToFormTriangle(grid,2,1));
        return minimumOperation;
    }
};