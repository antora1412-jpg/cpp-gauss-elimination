#include<bits/stdc++.h>
 using namespace std;
 
 int main()
 {
 	int n,i,j,k;
 	cout.precision(4);
	cout.setf(ios::fixed);
	
	a: 
	cout<<"Enter the size of  system"<<endl;
		cin>>n;
		
	float a[n][n+1],x[n];
		 
		cout<<"Enter the elements of augmented matrix row wise"<<endl;
		for(i=0;i<n;i++)
		for(j=0;j<=n;j++)
		cin>>a[i][j];
		
		//pivotisation
		for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
		if(abs(a[i][i])<abs(a[k][i]))
		{
			
	
		for(j=0;j<=n;j++)
		{
			double temp =a[i][j];
			a[i][j]=a[k][j];
			a[k][j]=temp;
		}
		}
		
		
		cout<<"The matrix after pivotaisation"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
			cout<<a[i][j]<<"     ";
			
			cout<<endl;
		}
	 
	//Gaussian elimination
	for(i=0;i<n;i++)
	{
	for(k=i+1;k<n;k++)
	{	 	
	 	double t=a[k][i]/a[i][i];
	 	
	 	for(j=0;j<=n;j++)
	 	a[k][j]=a[k][j]-t*a[i][j];
	}
    }
	 
	 cout<<"The new matrix after gauss elimination"<<endl;
	 
	 	for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
			cout<<a[i][j]<<setw(16);
			
			cout<<"\n";
		}
	
		//back substitution 
		for(i=n-1;i>=0;i--)
		{
			
			if(a[i][i]==0)
			{
			cout<<"Inconsistency detected, calculation another system"<<endl;
			goto a;
		    }
		    			
				x[i]=a[i][n];
				
				for(j=i+1;j<n;j++)
				{
					
				if(j!=i)
			    	{ 
				    x[i]=x[i]-a[i][j]*x[j];
			    	}
				
			    }
			    
			    x[i]=x[i]/a[i][i];
			
		}
		
	 cout<<"Values"<<endl;
	 for(i=0;i<n;i++)
	 cout<<x[i]<<endl;
	 return 0;
	  }
