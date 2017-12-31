#include<iostream>
using namespace std;
 
int main(){
 
    int maxS = 0,S = 0 ,s = 0, co = 0, cu = 0, I = 0, n = 0;
    cin >> maxS >> co >> cu >> I >> n; 
    int num[10000] = {0};
    int mins = 0,minS = 0;
    long long mincost = 2223372775807;
	long long cost = 0;
    int count_day = 0;
    for(int i = 0;i < n ; i++){
        cin >> num[i];
    }
     
    int Itemp = 0;
    Itemp = I;
     
     
    for(int S = 1; S <= maxS; S++){
         
         
         
        for(int s = 0; s < S; s++){
            I = Itemp;
            cost = 0;
            for(int i = 0 ;i < n; i++){          
                if(I > num[i]){
                    I -= num[i];
                    cost += (I * co);
                    if(I <= s){
                        I = S;
                    }
                }else if(I < num[i]){
                    I = num[i] - I;
                    cost += (I * cu);
                    I = S;
                    count_day ++;
                }else if(I == num[i]){
                    I = S;
                }
            }
            
			
//			cout << S  << " " << s << " " << cost << endl;
             
            if(cost <= mincost){
                if(cost < mincost){
                    mincost = cost;
                    minS = S;
                    mins = s;
                }else if(cost == mincost && (S-s) < (minS-mins)){
                    minS = S;
                    mins = s;
                    mincost = cost;
                }else if(cost == mincost && (S-s) == (minS-mins) && mins < s){
                    minS = S;
                    mins = s;
                    mincost = cost;
                }
            }
        }
 
    }
     
    cout << minS << " " << mins << " " << mincost;
 
    return 0;
     
}
