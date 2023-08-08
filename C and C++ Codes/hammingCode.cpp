//AYUSH SHARMA 21BDS0058 HAMMING CODE
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,n1;
    // Enter the number of bits for both sender's and receiver's side and put the data as well
    cout<<"Enter number of bits on sender's side:"<<endl;
    cin>>n;
    int senDers[n],reciEver[n];
    for(int i=n-1;i>=0;i--)
    {
        cin>>senDers[i];
    }
    cout<<"Enter number of bits on receiver's side:"<<endl;
    cin>>n1;
    for(int i=n1-1;i>=0;i--)
    {
        cin>>reciEver[i];
    }
    int p[4];
    p[0]=senDers[0] xor senDers[1] xor senDers[3] xor senDers[4] xor senDers[6];
    p[1]=senDers[0] xor senDers[2] xor senDers[3] xor senDers[5] xor senDers[6];
    p[2]=senDers[1] xor senDers[2] xor senDers[3] xor senDers[7];
    p[3]=senDers[4] xor senDers[5] xor senDers[6] xor senDers[7];
    int p1[4];
    p1[0]=reciEver[0] xor reciEver[1] xor reciEver[3] xor reciEver[4] xor reciEver[6];
    p1[1]=reciEver[0] xor reciEver[2] xor reciEver[3] xor reciEver[5] xor reciEver[6];
    p1[2]=reciEver[1] xor reciEver[2] xor reciEver[3] xor reciEver[7];
    p1[3]=reciEver[4] xor reciEver[5] xor reciEver[6] xor reciEver[7];
    cout<<"Parity bits on sender's side:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Parity bits on receiver's side:"<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<p1[i]<<" ";
    }
    cout<<endl;
    int synd1=p[0]xor p1[0];
    int synd2=p[1]xor p1[1];
    int synd3=p[2]xor p1[2];
    int synd4=p[3]xor p1[3];
    int answer=synd4*8+synd3*4+synd2*2+synd1*1;
    cout<<"Error at position or Syndrome is :"<<answer<<endl;
    //initalize the postion and parityPostion both as -1 and then we can change them accordingly to the syndrome value
    int position = -1;
    int parityPosition = -1;
    if(answer==1)
    {
        position = -2;
        parityPosition = 1; 
    }
    else if(answer==2)
    {
        position = -2;
        parityPosition = 2; 
    }
    else if(answer==3)
    {
        position = 1;
    }
    else if(answer==4)
    {
        position = -1;
        parityPosition = 3; 
    }
    else if(answer==5)
    {
        position = 2;
    }
    else if(answer==6)
    {
        position = 3;
    }
    else if(answer==7)
    {
        position = 4;
    }
    else if(answer==8)
    {
        position = -1;
        parityPosition = 4; 
    }
    else if(answer==9)
    {
        position = 5;
    }
    else if(answer==10)
    {
        position = 6;
    }
    else if(answer==11)
    {
        position = 7;
    }    
    else if(answer==12)
    {
        position = 8;
    }
    else
    {
        position = -1;
        parityPosition = -1;
    }
    if(position == -1 && parityPosition == -1)
    {
        cout<<"No Error is prsent there in data."<<endl;
    }
    if(parityPosition != -1)
    {
        cout<<"Parity is wrong at position: "<<parityPosition<<endl;
    }
    else
    {
        cout<<"Data bit  at wrong position is: "<<position<<endl;
        cout<<"The receiver's side bits before were: ";
        for(int i = n-1; i>=0; i--){
            cout<<reciEver[i];
        }
        cout<<endl;
        if(reciEver[position-1] == 1)
        {
            reciEver[position-1] = 0;
        }
        else
        {
            reciEver[position-1] = 1;
        }
        cout<<"The corrected receiver bits or the receiver's bits after change are: ";
        for(int i = n-1; i>=0; i--)
        {
            cout<<reciEver[i];
        }
        cout<<endl;
    }

    return 0;
}
