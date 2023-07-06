class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses+5];
        vector<int> indegree(numCourses+1);
        for(vector<int> edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        int count=0;

        while(q.size()){
            int node = q.front();
            q.pop();
            count+=1;

            for(int neighbor: adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        return count==numCourses;
    }
};