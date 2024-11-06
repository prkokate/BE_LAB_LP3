#include <bits/stdc++.h>
using namespace std;

vector<int>fibo={0,1,1};


int recur_fibonacci(int n){

    if (n <= 1){
        //if(fibo.size()<=3) fibo.push_back(n);
        return n;
    }

    int num=recur_fibonacci(n-1) + recur_fibonacci(n-2);

    if(num>fibo[fibo.size()-1]) fibo.push_back(num);

    return num;  

}

int non_recur_fibonacci(int n){
    if(n<=1) return n;
    int a=fibo[fibo.size()-1];
    int b=fibo[fibo.size()-2];
    int c=0;

    for(int i=fibo.size();i<=n;i++){
        c=a+b;
        fibo.push_back(c);
        a=b;
        b=c;

    }

    return c;
}

int  main(){
    int n;
    int k=1;
    while(k){
        cout<<"\nEnter  the number of terms you want in the Fibonacci sequence: ";
        cin>>n;
        cout<<"Enter the choice of function:\n1. Recursive\n2. Non-recursive\n==> ";
        cin>>k;
        if(k==1){
            int num;
           
            num=recur_fibonacci(n-1);
            
            cout<<"Fibonacci sequence using recursive function: ";
            for(int i=0;i<n;i++ ){
                cout<<fibo[i]<<" ";
            }
            cout<<endl;
            cout<<n<<"th term in the series = "<<num<<endl;
        }
        else if(k==2){
            int num = non_recur_fibonacci(n-1);

            cout<<"Fibonacci sequence using non-recursive function: ";
            for(int i=0;i<n;i++ ){
                cout<<fibo[i]<<" ";
            }
            cout<<endl;
            cout<<n<<"th term in the series = "<<num<<endl;
        }
        else{
            cout<<"Invalid choice. Please choose 1 or 2.\n";
            break;
        }

    }
    return 0;
}
