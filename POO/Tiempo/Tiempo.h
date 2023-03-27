
/*
 Implementa los funciones faltantes de la Clase Tiempo
 El valor de hora puede ser cualquier valor positivo
 El valor de minutos debe ser un valor entre 0 y 59
 Al realizar cualquier operación, el tiempo (hora y minutos) debe quedar con valores válidos
 */
class Tiempo {

public:
    Tiempo();
    Tiempo(int h, int m);
    void setHora(int h);
    void setMinu(int m);
    int getHora() const;
    int getMinu() const;
    /*1. Agrega las definiciones de los métodos siguientes:*/
    // Miembro de la clase. operador ++ incrementa el Tiempo en 1 minuto y regresa el tiempo
    Tiempo operator ++ ();
    //Friend. operador -- decrementa el Tiempo en 1 minuto y regresa el tiempo
    // si la hora es 0:0 y se pide decrementar, regresa 0:0
    friend Tiempo operator -- (Tiempo&);
    // Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
    bool operator > (const Tiempo&);
    // Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
    Tiempo operator + (int );
    // Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
    friend Tiempo operator + ( int , const Tiempo& );//const Tiempo&
    // Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
    Tiempo operator + (const Tiempo&);
    // Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
    friend void operator += (Tiempo&, const Tiempo&);//,const Tiempo&
    // Sobrecarga el operador de salida
    friend ostream& operator<< (ostream &, const Tiempo&);

private:
    int hora;
    int minu;
};

Tiempo::Tiempo() {
    hora = 0;
    minu = 0;
}

Tiempo::Tiempo(int h, int m) {
    hora = h;
    minu = m;
}

void Tiempo::setHora(int h) {
    hora = h;
}

void Tiempo::setMinu(int m) {
    minu = m;
}

int Tiempo::getHora() const{
    return hora;
}

int Tiempo::getMinu() const{
    return minu;
}

// Escribe TODOS los métodos que faltan.
// Miembro de la clase. operador ++ incrementa el Tiempo en 1 minuto y regresa el tiempo
Tiempo Tiempo::operator ++ (){
  if (minu==59){
    hora=hora+1;
    minu=0;
  }
  else{
    minu = minu + 1;
  }
  return *this;
}
//Friend. operador -- decrementa el Tiempo en 1 minuto y regresa el tiempo
// si la hora es 0:0 y se pide decrementar, regresa 0:0
Tiempo operator -- (Tiempo& n){
  if (n.hora== 0 && n.minu==0){
  }
  else if(n.minu==0){
    n.hora=n.hora-1;
    n.minu=59;
  }
  else{
    n.minu = n.minu - 1;
  }
  return n;
}
// Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
bool Tiempo::operator > (const Tiempo& t1){
  if (hora>t1.hora){
    return true;
  }
  else if (hora==t1.hora && minu>t1.minu){
    return true;
  }
  return 0;
}
// Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
Tiempo Tiempo::operator + (int n){
  int h1, m1;
  if ((minu+n)>60){
    h1= hora + ((minu+n)/60);
    m1=((minu+n)%60);
  }
  else{
    h1=hora;
    m1=minu+n;
  }
  return Tiempo(h1,m1);
}
// Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
Tiempo operator + (int n, const Tiempo& t1){//,const Tiempo& t2
  int h1,m1;
  if ((n + t1.minu)>60){
    h1= t1.hora + ((n + t1.minu)/60);
    m1=((n + t1.minu)%60);
  }
  else{
    m1=t1.minu+n;
  }
  return Tiempo (h1,m1);
//si se empieza con algo que no es miembro de la clase debe de ser friend
}
// Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
Tiempo Tiempo::operator + (const Tiempo& t1){
  int h1, m1;
  if ((minu + t1.minu)>=60){
    h1=hora +t1.hora+((minu+t1.minu)/60);
    m1=((minu+t1.minu)%60);
  }
  else{
    h1=hora +t1.hora;
    m1=minu+t1.minu;
  }
  return Tiempo(h1,m1);
}
// Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
void operator += (Tiempo& t1, const Tiempo& t2){// el primero no es const debido a que se esta modificando
  t1 = t1 + t2;//aqui se esta usando el operador suma'+'
}

//Escribe el encabezado de esta función, es la que sobrecarga al operador <<
ostream& operator << (ostream & salida, const Tiempo& t){
    salida <<t.hora<<":";
    if (t.minu<10)
        salida << "0" <<t.minu;
    else
        salida << t.minu;
    return salida;
}
