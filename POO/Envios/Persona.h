#ifndef PERSONA_H
#define PERSONA_H


class Persona{
public:
  Persona();
  Persona(string, string, string, string);
  string getNombre()const;
  string getEstado()const;
  string getCiudad()const;
  string getCodigoPostal()const;

  void setNombre(string);
  void setEstado(string);
  void setCiudad(string);
  void getCodigoPostal(string);

  void imprime();
private:
  string nombre;
  string estado;
  string ciudad;
  string codigoPostal;
};

Persona::Persona(){
  nombre="-";
  estado="-";
  ciudad="-";
  codigoPostal="-";
}

Persona::Persona(string nombre_, string estado_, string ciudad_, string codigoPostal_){
  nombre=nombre_;
  estado=estado_;
  ciudad=ciudad_;
  codigoPostal=codigoPostal_;
}
string Persona::getNombre()const{return nombre;}
string Persona::getEstado()const{return estado;}
string Persona::getCiudad()const{return ciudad;}
string Persona::getCodigoPostal()const{return codigoPostal;}

void Persona::setNombre(string nombre_){nombre=nombre_;}
void Persona::setEstado(string estado_){estado=estado_;}
void Persona::setCiudad(string ciudad_){ciudad=ciudad_;}
void Persona::getCodigoPostal(string codigoPostal_){codigoPostal=codigoPostal_;}

void Persona::imprime(){
  cout<<"Nombre: "<<nombre<<endl;
  cout<<"Dirección: "<<estado<<" "<<ciudad<<" "<<codigoPostal<<endl;
}

#endif
