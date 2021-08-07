class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s=0;
        for(int i=0;i<N;i++){
            s+=arr[i];
        }
        if(s%2!=0){
            return false;
        }
        else{
            int sum=s/2;
            int t[N+1][sum+1];
            for(int i=0;i<N+1;i++){
                for(int j=0;j<sum+1;j++){
                    if(i==0){
                        t[i][j]=false;
                    }
                    if(j==0){
                        t[i][j]=true;
                    }
                }
            }
            
            for(int i=1;i<N+1;i++){
                for(int j=1;j<sum+1;j++){
                    if(arr[i-1]<=j){
                        t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
                    }
                    else{
                        t[i][j]=t[i-1][j];
                    }
                }
            }
            return t[N][sum];
        }
    }
};
