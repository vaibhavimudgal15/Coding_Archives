class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        reverse(energy.begin(),energy.end());

        int n = energy.size();
        vector<int> pre(n,0);
        for(int i=0;i<k;i++){
            pre[i]=energy[i];
        }
        int i=k;
        while(i<n)
        {
            int j = i;
            while(j<min(i+k,n))
            {
                pre[j]=energy[j]+pre[j-k];
                j++;
            }
            i+=k;
        }

        int mxval=pre[0];
        for(int i=1;i<n;i++)
        {
            mxval = max(mxval,pre[i]);
        }

        return mxval;
    }
};