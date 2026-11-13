//https://leetcode.com/problems/sum-of-square-numbers/submissions/2124150597/

#include<bits/stdc++.h>
using namespace std;

// brute force
class Solution {
public:

    bool isPerfectSquare(long long n) {
        long long s = sqrt(n);
        return s * s == n;
    }

    bool judgeSquareSum(int c) {

        for (long long a = 0; a * a <= c; a++) {

            long long remaining = c - a * a;

            if (isPerfectSquare(remaining))
                return true;
        }

        return false;
    }
};


class Solution {
public:
bool isPerfectSquare(int n){
    int s=sqrt(n);
    if(s*s==n) return true;
    else return false;
}
    bool judgeSquareSum(int c) {

        int a=0;
        int b=c;
        while(a<=b){
            if(isPerfectSquare(a) && isPerfectSquare(b)) return true;

            else if(!isPerfectSquare(b)){
                //b is not perfect square
            b=(int)sqrt(b)*(int)sqrt(b);  // b is updated to a largest perfect square smaller than b
            a=c-b;

            }
            else{
                //a is not perfect square

                a=(int)(sqrt(a)+1)*(int)(sqrt(a)+1); // a is updated to a largest perfect square smaller than a
                b=c-a;
            }
        }
        return false;

    }
};