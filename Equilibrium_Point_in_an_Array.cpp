// Problem:-> You are given a 2d matrix where an equilibrium point is defined as a point (x,y) in the matrix such that:
// 1. the sum of all the elements of the rows before xth row == the sum of all the elements of the rows after xth row
// 1. the sum of all the elements of the columns before yth column == the sum of all the elements of the columns after yth column
// Find the number of equilibrium points in the matrix!!!!!!!
// This is the simplest approach to solve the given problem

int solution(vector<vector<int> >A) {
    vector<int>r;
    vector<int>c;
    for(int i=0;i<A.size();i++){
        int sum=0;
        for(int j=0;j<A[0].size();j++){
            sum+=A[i][j];
        }
        r.push_back(sum);
    }
    for(int i=0;i<A[0].size();i++){
        int sum2=0;
        for(int j=0;j<A.size();j++){
            sum2+=A[j][i];
        }
        c.push_back(sum2);
    }
    int count=0;
    for(int i=1;i<A.size()-1;i++){
        for(int j=1;j<A[0].size()-1;j++){
            int s1=0;
            int s2=0;
            int c1=0;
            int c2=0;
            for(int k=0;k<i;k++){
                s1+=r[k];
            }
            for(int k=i+1;k<A.size();k++){
                s2+=r[k];
            }
            for(int k=0;k<j;k++){
                c1+=c[k];
            }
            for(int k=j+1;k<A[0].size();k++){
                c2+=c[k];
            }
            if(s1==s2 && c1==c2){
                count++;
            }
        }
    }
    return count;
}
