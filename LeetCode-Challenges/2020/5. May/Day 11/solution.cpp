class Solution {
public:
    void Paint(vector<vector<int>>& image, int i,int j, int newColor,int srcColor,vector<vector<bool>>& visited)
    {
        if(i<image.size() && j<image[i].size() && visited[i][j]==false && image[i][j]==srcColor)
        {
            visited[i][j]=true;
            image[i][j]=newColor;
            if(i<image.size()-1)
            {
            Paint(image,i+1,j,newColor,srcColor,visited);
            }
            if(j<image[i].size()-1)
            {
            Paint(image,i,j+1,newColor,srcColor,visited);
            }
            if(i>0)
            {
            Paint(image,i-1,j,newColor,srcColor,visited);
            }
            if(j>0)
            {
            Paint(image,i,j-1,newColor,srcColor,visited);
            }
            return;
        }
        else
        {
            return;
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited;
        for(int i=0;i<image.size();i++)
        {
            vector <bool> str;
            for(int j=0;j<image[i].size();j++)
            {
                str.push_back(false);

            }
            visited.push_back(str);
        }
         Paint(image,sr,sc,newColor,image[sr][sc],visited);
        return image;
    }
};
