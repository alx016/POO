#include <vector>
#include <iostream>
#include <exception>
using namespace std;

int main(){
  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int posicion;
  int intentos =5;
  while (true){
    cout <<"Ingrese posicion a la que desa acceder: ";
    cin >> posicion;
    try{
      if (posicion>=10 || posicion <0 ){
        intentos--;
        if (intentos==0){
          cout <<"No le quedan intentos"<<endl;
          break;
        }
        throw ("posicion invalida");
      }
      else {
        cout << arr[posicion]<<endl;
        break;
      }
    }
    catch (const char* msg){
      cout<<msg<<endl;
      cout<<"Te quedan" + to_string(intentos) + " intentos"<<endl;
    }
  }


}
