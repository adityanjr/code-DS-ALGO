class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
        {
            return true;
        }
        if((coordinates[1][0]-coordinates[0][0])==0)
        {
            for(int i=0;i<coordinates.size();i++)
            {
                if((coordinates[i][0]-coordinates[0][0])!=0)
                {
                    return false;
                }
            }
        }
        float m=(((float)(coordinates[1][1]-coordinates[0][1]))/(coordinates[1][0]-coordinates[0][0]));
        int c=coordinates[0][1]-m*coordinates[0][0];
        for(int i=0;i<coordinates.size();i++)
        {
            if((coordinates[i][1]-m*coordinates[i][0]-c)!=0)
            {
                return false;
            }
        }
        return true;
    }
};
