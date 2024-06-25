class Solution {
public:
    int findTheWinner(int n, int k) {
        //All players should go into the queue
        queue<int> q;
        for(int i=1;i<=n;i++)
            q.push(i);
        
        
        while(q.size()>1){
            //remaining 1 player is winner
            //simulate the game
            for(int i=1;i<k;i++){
                auto player = q.front();
                q.pop();
                //player not to be eliminated yet
                q.push(player);
                
            }
            
            //kth player must be eliminated
            q.pop();
        }
        return q.front();
    }
};