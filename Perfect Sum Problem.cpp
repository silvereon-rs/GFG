class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        const unsigned int m= 1000000007;
         unsigned int t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%m;
                }
                else{
                    t[i][j]=(t[i-1][j])%m;
                }
            }
        }
        return t[n][sum];
	}
};
