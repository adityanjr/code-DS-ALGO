    int n; cin>>n;
    float balance; cin>>balance;
    float transact = balance-n-0.5;
    if(n%5==0 && transact>0){
        cout<<transact;
    }
    else {
    printf("%0.2f",balance);
