class Solution {
public:

    vector<double> f( vector<double> & t1,vector<double> & t2 ){
        vector<double>ans;
        for(auto itr : t1){
            for(auto itr2 : t2){
                ans.push_back((double)itr + (double)itr2);
                ans.push_back((double)itr - (double)itr2);
                ans.push_back((double)itr * (double)itr2);
                if((double)itr2 != double(0)){
                    ans.push_back((double)itr/(double)itr2);
                }
            }
        }
        return ans;

    }

    vector<double> val(int i, int j, vector<int>& cards){
            if(j==i) return {(double)cards[i]};

            vector<double>tempRec;
            for(int k = i+1; k<=j; k++){

                vector<double>val1 = val(i,k-1,cards);
                vector<double>val2 = val(k,j,cards);
                vector<double>val3 = f(val1,val2);
                for(auto itr : val3){
                    tempRec.push_back(itr);
                } 
            }

            return tempRec;
    }

    vector<vector<int>>perma;

    void f(int mask,vector<int> & temp,vector<int>& arr){
        if(mask == (1<<4)-1){
            perma.push_back(temp);
            return ;
        }
        for(int i =0; i<4; i++){
            if(mask & (1<<i)) continue;
            temp.push_back(arr[i]);
            f(mask|(1<<i) , temp,arr);
            temp.pop_back();
        }

    }

    bool judgePoint24(vector<int>& cards) {
        vector<int>temp;
        f(0,temp,cards);
        // cout<<perma.size()<<endl;
        for(auto & itr : perma){
            vector<double>temp = val(0,3,itr);
            for(auto itr : temp){
                // cout<<itr<<endl;
                if (fabs(itr - 24.0) < 1e-6) return true;
            }
        }
        return false;

    }
};