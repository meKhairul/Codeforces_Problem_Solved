#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;

 int l,r;
 map<int,int>counts;
 vector<int> prime(MAX);

int add(int num)
{
	int j,sum=0;
	//cin >> num;


	for(;num!=0;)
	{
		j = num%10;
		sum += j;
		num/=10;
		//cout << j << " ";
	}

	return sum;
}



 void fu()
 {
    //for(int i=0;i<MAX;i++)cout<<prime[i];
    prime[0]=1;prime[1]=1;
	for(int i=2;i<=sqrt(MAX);i++)
	{
		if(prime[i] == 1) continue;
		else{
			for(int j=i*i;j<=MAX;j+=i)
				prime[j] = 1;
		}
	}
 	counts[1]=0;
	for(int i=2;i<=MAX;i++)
	{
		if(prime[i] == 0&& prime[add(i)] == 0)
		{
			counts[i]=1+counts[i-1];
			//cout << i << endl;
		}
		else counts[i]=counts[i-1];

		//cout<<counts[i]<<" ";
	}
 }

int main()
{


	int t;

	cin >> t;
 	fu();
	while(t--){


	cin >> l >> r;

	//algorithm

//	&& prime[add(i)] == 1
    if(l==r && (prime[l] || prime[add(l)]))cout<<"0\n";
	else cout << counts[r]-counts[l]+(!prime[l] && !prime[add(l)]) << endl;

	}


}
