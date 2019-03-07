/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **ans = (int**)malloc(sizeof(int*)*numRows);
    (*columnSizes) = (int*)malloc(sizeof(int*)*numRows);
    
    ans[0] = (int*)malloc(sizeof(int));
    ans[0][0] = 1;
    (*columnSizes)[0] = 1;
    for(int i = 1; i < numRows; i++){
        (*columnSizes)[i] = i+1;
        ans[i] = (int*)malloc( sizeof(int)*(i+1) );
        ans[i][0]=1;
        for(int j=1; j < i; j++){
            ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
        }
        ans[i][i]=1;
    }
    columnSizes = ans;
    return columnSizes;
}
