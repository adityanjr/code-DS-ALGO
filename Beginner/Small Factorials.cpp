t(t){
    	int n; cin>>n;
	    int q=2;
	    int arr[200] = {0};
	    arr[0] = 1;
	    int len = 1;
	    
	    while(q<=n){
	        int x=0;
	        int num =0;
	        while(x<len){
	            arr[x] = arr[x] *q;
	            arr[x] = arr[x]+num;
	            num = arr[x]/10;
	            arr[x] = arr[x]%10;
	            x++;
	        }
	        while(num!=0){
	            arr[len] = num%10;
	            num = num/10;
	            len++;
	        }
	        q++;
	    }
	    len--;
	    while(len>=0){
	        cout<<arr[len];
	        len--;
	    }
	    cout<<endl;
    }