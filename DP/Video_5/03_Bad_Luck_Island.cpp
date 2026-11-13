#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
 
double dp1[102][102][102];
double dp2[102][102][102];
double dp3[102][102][102];
 
double fr(int r, int s, int p){
    if(p==0) return 1.0;
    
    if(r==0 or s==0) return 0.0;
    
    if(dp1[r][s][p]> -0.9) return dp1[r][s][p];
    
    int totalComb = (r*s +s*p + p*r);

    double p1 = ((double)s*p)/totalComb;
    double p2 = ((double)s*r)/totalComb;
    double p3 = ((double)r*p)/totalComb;
    
    double totalAns = fr(r, s, p-1)*p1
                    + fr(r, s-1, p)*p2
                    + fr(r-1, s, p)*p3;
 
    return dp1[r][s][p] = totalAns;
}
 
double fs(int r, int s, int p){
    if(r==0) return 1.0;
    
    if(s==0 or p==0) return 0.0;
    
    if(dp2[r][s][p]> -0.9) return dp2[r][s][p];
    
    int totalComb = (r*s +s*p + p*r);
     double p1 = ((double)s*p)/totalComb;
    double p2 = ((double)s*r)/totalComb;
    double p3 = ((double)r*p)/totalComb;
    
    double totalAns = fs(r, s, p-1)*p1 + fs(r,s-1, p)*p2 + fs(r-1, s, p)*p3;
 
    return dp2[r][s][p] = totalAns;
}
 
double fp(int r, int s, int p){
    if(s==0) return 1.0;
    
    if(r==0 or p==0) return 0.0;
    
    if(dp3[r][s][p]> -0.9) return dp3[r][s][p];
    
    int totalComb = (r*s +s*p + p*r);
     double p1 = ((double)s*p)/totalComb;
    double p2 = ((double)s*r)/totalComb;
    double p3 = ((double)r*p)/totalComb;
    
    double totalAns = fp(r, s, p-1)*p1 + fp(r,s-1, p)*p2 + fp(r-1, s, p)*p3;
 
    return dp3[r][s][p] = totalAns;
}
 
int  main (){
    int r,s, p;
    cin>>r>>s>>p;
    
    memset(dp1, -1.0, sizeof dp1);
    memset(dp2, -1.0, sizeof dp2);
    memset(dp3, -1.0, sizeof dp3);
    
    cout<<fixed<<setprecision(9)<<fr(r,s,p)<<" ";
    cout<<fixed<<setprecision(9)<<fs(r,s,p)<<" ";
    cout<<fixed<<setprecision(9)<<fp(r,s,p)<<" ";
    
}