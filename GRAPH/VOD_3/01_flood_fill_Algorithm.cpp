//leetCode - 713


#include<iostream>
#include<vector>
using namespace std;

// function below perform dfs on the neighbour of curr element containing the initial color

void dfs(vector<vector<int>> & image, int currCol, int currRow, int initialColor, int newColor){
    int n = image.size(), m = image[0].size();

    // you are outside of the grid

    if(currRow<0 || currCol<0 || currRow>=n || currCol>=m) return ;

    if(image[currRow][currCol]!=initialColor) return ;

    image[currRow][currCol] = newColor;

    dfs(image, currCol+1, currRow, initialColor, newColor ); // right Call
    dfs(image, currCol-1, currRow, initialColor, newColor );// left Call
    dfs(image, currCol, currRow+1, initialColor, newColor );// downward Call
    dfs(image, currCol, currRow-1, initialColor, newColor );//upward Call
}
vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int newColor){
    if(image[sr][sc]==newColor) return image;

    dfs(image, sr,sc,image[sr][sc], newColor);

    return image;


}

int main (){

    int n, m;
    cout<<"enter the dimensions of the grid:"<<endl;
    cin>>n>>m;
    vector<vector<int>> img(n, vector<int> (m));
    int sr, sc, newColor;

    cout<<"Enter the pixels of image:"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){



            
            cin>>img[i][j];
        }
    }

    cout<<"enter the starting indices:"<<endl;
    cin>>sr>>sc;

    cout<<"enter the new Color:";
    cin>>newColor;

    img = floodFill(img, sr,sc,newColor);



}