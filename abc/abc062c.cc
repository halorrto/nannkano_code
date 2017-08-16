#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

ll max1(ll a,ll b){
  return a>b?a:b;
}
ll min1(ll a,ll b){
  return a>b?b:a;
}

ll max1(ll a,ll b,ll c){
  return max1(a,max1(b,c));
}
ll min1(ll a,ll b,ll c){
  return min1(a,min1(b,c));
}

int main(void){
  ll h,w;
  
  cin>>h>>w;
  if(h%3==0||w%3==0){
    cout<<0<<endl;
    return 0;
  }
  ll res,tmax,tmin,x,y,z,t;
  res=1e9;
  for(ll i=1;i<=(h/3)+1;i++){
    x=i*w;
    if((h-i)%2==0) z=y=((h-i)/2)*w;
    else {
      y=((h-i)/2)*w;
      z=(((h-i)/2)+1)*w;
    }
    res=min1(res,max1(x,y,z)-min1(x,y,z));
    if(w%2==0) z=y=(h-i)*(w/2);
    else{
      y=(h-i)*(w/2);
      z=(h-i)*((w/2)+1);
    }
    res=min1(res,max1(x,y,z)-min1(x,y,z));
  }
  t=h;h=w;w=t;
  for(ll i=1;i<=(h/3)+1;i++){
    x=i*w;
    if((h-i)%2==0) z=y=((h-i)/2)*w;
    else {
      y=((h-i)/2)*w;
      z=(((h-i)/2)+1)*w;
    }
    res=min1(res,max1(x,y,z)-min1(x,y,z));
    if(w%2==0) z=y=(h-i)*(w/2);
    else{
      y=(h-i)*(w/2);
      z=(h-i)*((w/2)+1);
    }
    res=min1(res,max1(x,y,z)-min1(x,y,z));
  }  
  cout<<res<<endl;
  return 0;
}
