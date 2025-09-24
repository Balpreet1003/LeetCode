class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>arr1;
        vector<int>arr2;
        int num1=0,num2=0;
        //for version1
        for(int i=0;i<version1.length();i++){
            if(version1[i]=='.'){
                arr1.push_back(num1);
                num1=0;
            }
            else
                num1=num1*10+(version1[i]-'0');
            
            if(i==version1.length()-1)
                arr1.push_back(num1);
        }

        //for version2
        for(int i=0;i<version2.length();i++){
            if(version2[i]=='.'){
                arr2.push_back(num2);
                num2=0;
            }
            else
                num2=num2*10+(version2[i]-'0');

            if(i==version2.length()-1)
                arr2.push_back(num2);
        }

        int i=0,j=0;
        //comparing arr1 & arr2
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]>arr2[j])
                return 1;
            if(arr1[i]<arr2[j])
                return -1;
            i++;j++;
        }
        while(i<arr1.size()){
            if(arr1[i]>0)
                return 1;
            i++;
        }
        while(j<arr2.size()){
            if(arr2[j]>0)
                return -1;
            j++;
        }
        return 0;
    }
};