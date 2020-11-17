class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q==0) return 0;
        
        int gcd = __gcd(p,q);
        int lcm = (p/gcd)*q;
        int topOrButton = (lcm/p)%2; //top = 1 button = 0
        int leftOrRight = (lcm/q)%2; //right = 1 left = 0
        
        
        if(topOrButton == 1 and leftOrRight==0) return 2;
        else if(topOrButton == 1 and leftOrRight==1) return 1;
        else if(topOrButton == 0 and leftOrRight==1) return 0;
        else return 3;
    }
};
