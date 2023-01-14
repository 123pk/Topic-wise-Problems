/*
Platform :- Leetcode
Approach :- If you will analyse the problem well you will find that there is connected graph is formed out of all equivalence relations and for each character we want to 
            find the smallest character in Disjoint-set they form .
            We will replace all the characters of Base String with their smallest possible character values in Disjoint set
            We will create graph of connections and relations then we will find the smallest character for each value.
Time Complexity :- O(n+e)
*/
class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        String ans="";
        int vis[] = new int[26];
        int score[] = new int[26];
        List<List<Integer>> dsu = new ArrayList<>();
        
        for(int i=0;i<26;++i){
            dsu.add(new ArrayList<>());
        }
         
        for(int i=0;i<s1.length();++i){
            char x = s1.charAt(i);
            char y = s2.charAt(i);
            dsu.get(x-'a').add(y-'a');
            dsu.get(y-'a').add(x-'a');
        }

        for(int i=0;i<26;++i){
            if(vis[i]>1)continue;

            LinkedList<Integer>queue = new LinkedList<Integer>();
            LinkedList<Integer>arr = new LinkedList<Integer>();;
            queue.add(i);
            vis[i]++;
            int mn = 27;
            while(queue.size()>0){
                int node = queue.poll();
                 
                mn = Math.min(mn,node);
                arr.add(node);

                for(int x:dsu.get(node)){
                    if(vis[x]>1)continue;
                    queue.add(x);
                    vis[x]++;
                }
            }

            while(arr.size()>0){
                int node = arr.poll();
                 
                score[node] = mn;
            }
        }
         
         for(int i=0;i<baseStr.length();++i){
             char x = baseStr.charAt(i);
             int sc = score[x-'a'];
             char val = 'a';
             val += sc;
             ans += val;
         }
         return ans;

    }
}
