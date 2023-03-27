#include <iostream>

using namespace std;

int main(){
  int x,y;

  cin>>x;
  cin>>y;
while (y==0){
  try {
    if (y== 0){
    throw "División por cero, no valido";
  }
  }
    catch (const char* msg ){
      cerr<<msg<<endl;
      cin>>y;
    }
}
cout << x/y<<endl;
  return 0;
}
