vector<vector<int> > Solution::generateMatrix(int N) {
    vector<vector<int> > result(N, vector<int>(N));
    // Corner case
    if (N <= 0) {
        return result;
    }
    int top = 0, bottom = N - 1, left = 0, right = N - 1, dir = 0, putValue = 1;
    
    while ( top <= bottom && left <= right ) {
        if (dir == 0) {
            for (int j = left; j <= right; j++) {
                result[top][j] = putValue;
                putValue++;
            }
            top++;
            if (top <= bottom) {
                dir++;
            } else
                break;
        }
        if (dir == 1) {
            for (int i = top; i <= bottom; i++) {
                result[i][right] = putValue;
                putValue++;
            }
            right--;
            if (left <= right) {
                dir++;
            } else
                break;
        }
        if (dir == 2) {
            for (int j = right; j >= left; j--) {
                result[bottom][j] = putValue;
                putValue++;
            }
            bottom--;
            if (top <= bottom) {
                dir++;
            } else
                break;
        }
        if (dir == 3) {
            for (int i = bottom; i >= top; i--) {
                result[i][left] = putValue;
                putValue++;
            }
            left++;
            if (left <= right) {
                dir++;
            } else
                break;
        }
        dir = 0;
    }
    return result;
}
