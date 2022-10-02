int maxPalindrome = 0;
    for(int i=0;i<n;){
        int j = n-1;
        int count = 0;
        int temp = i;
        
        while(temp<j){
            cout<<temp<<endl;
            if(a[temp]!=a[j]){
               count = 1;
               temp = i;
               j--;
               //break;

            }
            else{
                count++;
                temp++;
                j--;
            }
        }
        maxPalindrome = max(maxPalindrome,count);
        cout<<maxPalindrome<<endl;

    }
