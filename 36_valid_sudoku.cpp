class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            map<char,int>mp;
            map<char,int>mp1;
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.'){
                    if(mp.find(board[i][j])!=mp.end()){
                        // cout<<i<<" "<<j<<" "<<board[i][j]<<"\n";
                        return false;
                    }
                    mp[board[i][j]]=1;
                }
                if(board[j][i]!='.'){
                    if(mp1.find(board[j][i])!=mp1.end())
                        return false;
                    mp1[board[j][i]]=1;
                 }
            }
        }
        for(int k=0;k<board.size();k=k+3){
            for(int l=0;l<board.size();l=l+3){
            cout<<k<<" **"<<l<<" "<<"****\n";

                map<char,int>mp;
                 for(int i=k;i<k+3;i++){
                    for(int j=l;j<l+3;j++){
                     if(board[i][j]!='.'){
                        cout<<i<<" "<<j<<" "<<board[i][j]<<"\n";

                        if(mp.find(board[i][j])!=mp.end()){
                            cout<<i<<" "<<j<<" "<<board[i][j]<<"\n";
                            return false;
                        }
                        mp[board[i][j]]=1;
                        }
                    }
                 }
            }
        }
        return true;
    }
};