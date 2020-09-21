class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()==0)
        {
            return true;
        }
        int j=0,i=0,init=0;
        int arr[26];
        for(i=0;i<26;i++)
        {
          arr[i]=0;

        }
        for(i=0;i<magazine.size();i++)
        {
          arr[int(magazine[i])-int('a')]++;    
        }
        for(i=0;i<ransomNote.size();i++)
        {
            if(arr[int(ransomNote[i])-int('a')]==0)
            {
                return false;
            }
            arr[int(ransomNote[i])-int('a')]--;
        }

        return true;
    }
};
