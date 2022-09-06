class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //solving this first using brute force approach.
        //Here basically first traverse the matrix find the element which is Zero
        //After finding the index of zero element then make row elements -1
        //After that make column elements -1
        //And then finally traverse matrix and make all -1 elements as zero 
        //this is final answer with T(n) = O(m*n) X O(m+n)
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    //do for row and column 
                    int index = i - 1;
                    while(index >= 0) {
                        if(matrix[index][j] != 0) {
                            matrix[index][j] = -999;
                        }
                        index--;
                    }
                    //left ele of row done
                    index = i + 1;
                    while(index < matrix.size()) {
                        if(matrix[index][j] != 0) {
                            matrix[index][j] = -999;
                        }
                        index++;
                    }
                    //right ele of row done
                    //Now for columns
                    index = j - 1;
                    while(index >= 0) {
                        if(matrix[i][index] != 0) {
                            matrix[i][index] = -999;
                        }
                        index--;
                    }
                    //top col ele done
                    index = j + 1;
                     while(index < matrix[0].size()) {
                        if(matrix[i][index] != 0) {
                            matrix[i][index] = -999;
                        }
                        index++;
                    }
                }
            }
        }
        //Now traverse the matrix and make the -1 elements Zero
         for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == -999) {
                    matrix[i][j] = 0;
                }
            }
             
        }
    }
};