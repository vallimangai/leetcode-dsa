class Solution {
public:
    int maxFreqSum(string s) {
        sort(s.begin(),s.end());
        cout<<s<<"\n";
        int maxvowel=0;
        int maxconsonant=0;
        string vowel="aeiou";
        int st=0;
        while(st<s.size()){
            int count=1;
            while((st+count)<s.size() &&s[st]==s[st+count]){
                count++;
            }
            if(vowel.contains(s[st])){
                
                maxvowel=max(maxvowel,count);
            }else{
                cout<<s[st]<<" "<<count<<" ";

                maxconsonant=max(maxconsonant,count);
            }
            st=st+count;
        }
        return maxvowel+maxconsonant;
    }
};