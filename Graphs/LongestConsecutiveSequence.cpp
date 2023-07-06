class DSU{
private:
    int size=0;
    vector<int> par;
    vector<int> parSize;
public:
    DSU(int _size) {
        size = _size;
        par.resize(size+2);
        parSize.resize(size+2,1);
        for(int i=0;i<par.size();i++){
            par[i] = i;
        }
    }    

    int findPar(int node){
        if(par[node]==node)
            return node;
        return par[node] = findPar(par[node]);
    }

    int getParSize(int node){
        int par = findPar(node);
        return parSize[par];
    }

    void unionNodes(int a, int b){
        a = findPar(a);
        b = findPar(b);


        if(a!=b){
            if(parSize[a] > parSize[b]){
                par[b] = a;
                parSize[a] += parSize[b];
            }else{
                par[a] = b;
                parSize[b] += parSize[a];
            }
        }

    }

};

class Solution {
private:
    int findLargestComponent(DSU* &dsu, int nodes) {
        int mx=0;
        for(int i=0;i<nodes;i++){
            if(dsu->findPar(i) == i){
                mx = max(mx, dsu->getParSize(i));
            }
        }
        return mx;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        DSU* dsu = new DSU(nums.size());

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }

            if(mp.find(nums[i]-1) != mp.end()){
                dsu->unionNodes(i, mp[nums[i]-1]);
            }

            if(mp.find(nums[i]+1) != mp.end()){
                dsu->unionNodes(i, mp[nums[i]+1]);
            }

            mp[nums[i]] = i;
        }

        return findLargestComponent(dsu, nums.size());
    }
};