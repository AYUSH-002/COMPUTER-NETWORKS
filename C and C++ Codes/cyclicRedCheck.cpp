#include <bits/stdc++.h>
using namespace std;
void division (int temp[],int gen[],int n,int r)
{
    for(int i=0;i<n;i++)
    {
        if(gen[0]==temp[i])
        {
            for(int j=0,k=i;j<r+1;j++,k++)
            {
                if(!(temp[k]^gen[j]))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
}
int main()
{
    int n,r,message[50],temp[50],gen[50];
    cout<<"At the sender's side: "<<endl;
    cout<<"Enter the number of message bits:"<<endl;
    cin>>n;
    cout<<"Enter the number of generator bits:"<<endl;
    cin>>r;
    cout << "Enter the message: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>message[i];
    }
    cout << "Enter the generator bits: "<<endl;
    for(int i=0;i<r;i++)
    {
        cin>>gen[i];
    }
    r=r-1;
    for(int i=0;i<r;i++)
    {
        message[n+i]=0;
    }
    for (int i = 0; i < n + r; i++)
    {
        temp[i] = message[i];
    }
    division(temp,gen,n,r);
    cout<<"CRC: "<<endl;
    for(int i=0;i<r;i++)
    {
        cout << temp[n + i] << " ";
        message[n+i]=temp[n+i];
    }
    cout<<endl;
    cout<<"Transmitted message:"<<endl;
    for(int i=0;i<n+r;i++)
    {
        cout<<message[i]<<" ";
    }
    cout<<endl;
    cout<<"At the receiver's side: "<<endl;
    cout << "Enter the received message : ";
    for(int i=0;i<n+r;i++)
    {
        cin>>message[i];
    }
    for(int i=0;i<n+r;i++)
    {
        temp[i]=message[i];
    }
    division(temp,gen,n,r);
     for (int i = 0; i < r; i++)
    {
        if (temp[n + i])
        {
            cout << "Error detected in received message.";
            return 0;
        }
    }
    cout << "No error in received Message.\nReceived Message : ";
    for (int i = 0; i < n; i++)
        cout << message[i] << " ";
    return 0;
}