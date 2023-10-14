// Generate Parentheses
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:
1 <= n <= 8


*/


class Solution {
    
    List<String> ansList = new ArrayList();
    public List<String> generateParenthesis(int n) {
        
        StringBuilder curr = new StringBuilder();
        
        
        generate(curr,0,0,n);
        
        return ansList;
    }
    
    void generate(StringBuilder curr,int openCount,int closedCount, int n){
    
        
         if(openCount == n && closedCount == n){
            ansList.add(curr.toString());
            return;
        }
        
         if(openCount > n || closedCount > n)
             return;

        
        // choice 1
          if(openCount < n){
            curr.append("(");
            generate(curr, openCount+1, closedCount, n);
            curr.deleteCharAt(curr.length()-1);
          }
        
        // choice 2
         if(openCount > closedCount){
            curr.append(")");
            generate(curr, openCount, closedCount+1, n);
            curr.deleteCharAt(curr.length()-1);
        } 
        
       
    }