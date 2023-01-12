/*
Platform :- Leetcode
Approach :- We will do dfs and we want a frequency array which store the frequency of characters in subtree of ith node,
            since there are 26 characters only it will be fine .
            So we get the fequency array from each of the child and now we sum those frequencies into a common frequency array and 
            store the fequency of ith node character in answer.
            
 Time Complexity :- O(n+e)
 Space Coplexity :- O(n+e+26)
*/
class Solution {

    public int[] find(int node,List<List<Integer>>tree,String labels,int ans[],int parent){
        int fre[] = new int[26];
        for(int x:tree.get(node)){
            if(x == parent)continue;
            int temp[] = find(x,tree,labels,ans,node);
            for(int i=0;i<26;++i){
                fre[i] += temp[i];
            }
        } 

        fre[labels.charAt(node)-'a']++;
        ans[node] = fre[labels.charAt(node)-'a'];
        return fre;

    }
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        int ans[]= new int[n];
        List<List<Integer>> tree = new ArrayList<>();
        for(int i=0;i<n;++i)tree.add(new ArrayList<>());

        for(int []x:edges){
            tree.get(x[0]).add(x[1]);
            tree.get(x[1]).add(x[0]);
        }

        int temp[] = find(0,tree,labels,ans,0);

        return ans;
    }
}
