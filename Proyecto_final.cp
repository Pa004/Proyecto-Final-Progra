#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <sstream>
#define dim 20
#define dum 2

using namespace std;
struct Nino {
  long int cedula;
  char nombre[dim];
  int edad;
};
struct Representante {
  long int cedula;
  char nombre[dim];
  long int celular;
  int edad;
  char correo[dim];
};
struct Club {
  char nombre[dim];
  char profesor[dim];
};
struct Horario {
  char Dias[dim];
  int num_horas[2];
};

struct Club_Vacacional {

  int cod_matricula; 
  int pagado;
  Nino datos_nino;
  Representante datos_representante;
  Club datos_club;
  Horario datos_horario[2];
  double precio;
};
bool validar_cedula(long int x) {
  int i, A[dim], res, mul, sumapares = 0, sumaimpares = 0, suma, s;
  long int coc;
  for (i = 9; i >= 0; i--) {
    coc = x / 10;
    res = x % 10;
    A[i] = res;
    x = coc;
  }
  for (i = 0; i < 9; i += 2) {
    mul = A[i] * 2;
    if (mul > 9)
      mul -= 9;
    sumapares += mul;
  }
  for (i = 1; i < 9; i += 2)
    sumaimpares += A[i];
  suma = sumapares + sumaimpares;
  res = suma % 10;
  s = 10 - res;
  if (s == 10)
    s = 0;
  if (s == A[9])
    return (true);
  else
    return (false);
}

bool validar_Cedularepetidan(long int cedula, Club_Vacacional a[], int n) {
	int b=n;
    for (int i = 0; i < dum; i++) {
    	if(i!=n ){
        if (a[i].datos_nino.cedula == cedula || a[i].datos_representante.cedula == cedula) {
            return false;}
        }
    if (a[i].datos_representante.cedula == cedula) {
            return false;}
    }
    return true;
}

bool validar_Cedularepetidar(long int cedula, Club_Vacacional a[], int n) {
	int b=n;
    for (int i = 0; i < dum; i++) {
    	if (a[i].datos_nino.cedula == cedula) {
            return false;
		}if(i!=n ){
        if (a[i].datos_representante.cedula == cedula) {
            return false;}
        }
    
    
}
return true;
}


bool validar_nombre(const char* nombre) {
    for (int i = 0; nombre[i] != '\0'; i++) {
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || (nombre[i] >= 'a' && nombre[i] <= 'z') || nombre[i] == ' ' || nombre[i] == '\n')) {
            return false;
        }
    }
    return true;
}







void ingresar(Club_Vacacional *x, Club_Vacacional a[],int numingresos) {
int o=0,z;
	ofstream archivo;
int opcion;
 srand(time(NULL));
  x->cod_matricula = 1 + rand() % (101 - 1);
  x->pagado = 35;
  printf("Ingrese la cedula del niño: ");
  do {
    scanf("%ld", &x->datos_nino.cedula);
    fflush(stdin);
    if (!validar_Cedularepetidan(x->datos_nino.cedula,a,numingresos)) {
      printf("Cedula ya ingresada. Ingresela nuevamente: ");
    }
    else if (!validar_cedula(x->datos_nino.cedula)) {
            printf("Cedula invalida. Ingrese nuevamente: ");
        }
    else if (x->datos_nino.cedula ==NULL){
    	printf("Cedula invalida. Ingrese nuevamente: ");
	}
  } while ((!validar_cedula(x->datos_nino.cedula)) || (!validar_Cedularepetidan(x->datos_nino.cedula,a,numingresos) || x->datos_nino.cedula==NULL) );
  printf("Perfecto continuemos\n");
    
  fflush(stdin);
  printf("Ingrese el nombre del nino:");
  fgets(x->datos_nino.nombre, dim, stdin);
x->datos_nino.nombre[strcspn(x->datos_nino.nombre, "\n")] = '\0';
while(!validar_nombre(x->datos_nino.nombre)) {
    printf("!NOMBRE INVALIDO!\n");
    printf("Ingrese el nombre del estudiante nuevamente:");
    fgets(x->datos_nino.nombre, dim, stdin);
    x->datos_nino.nombre[strcspn(x->datos_nino.nombre, "\n")] = '\0';
}
  fflush(stdin);
  printf("Ingrese la edad del niño: ");
  do {
    scanf("%d", &x->datos_nino.edad);
    fflush(stdin);
    if (x->datos_nino.edad < 7 || x->datos_nino.edad > 18) {
      printf("Edad inválida. Ingrese nuevamente: ");
    }
  } while (x->datos_nino.edad < 7 || x->datos_nino.edad > 18);
  fflush(stdin);
  printf("Ingrese la cedula del representante: ");
  do {
    scanf("%ld", &x->datos_representante.cedula);
    fflush(stdin);
    if (!validar_Cedularepetidar(x->datos_representante.cedula,a,numingresos)) {
      printf("Cedula ya ingresada. Ingresela nuevamente: ");
    }
    else if (!validar_cedula(x->datos_representante.cedula)) {
            printf("Cedula invalida. Ingrese nuevamente: ");
        }
    else if (x->datos_representante.cedula ==NULL){
    	printf("Cedula invalida. Ingrese nuevamente: ");
	}
  } while ((!validar_cedula(x->datos_representante.cedula)) || (!validar_Cedularepetidar(x->datos_representante.cedula,a,numingresos)) || x->datos_representante.cedula==NULL);
  printf("Perfecto continuemos\n");
  fflush(stdin);
  printf("Ingrese el nombre del representante:");
  fgets(x->datos_representante.nombre, dim, stdin);
x->datos_representante.nombre[strcspn(x->datos_representante.nombre, "\n")] = '\0';
while(!validar_nombre(x->datos_representante.nombre)) {
    printf("!NOMBRE INVALIDO!\n");
    printf("Ingrese el nombre del representante nuevamente:");
    fgets(x->datos_representante.nombre, dim, stdin);
    x->datos_representante.nombre[strcspn(x->datos_representante.nombre, "\n")] = '\0';
}
  fflush(stdin);
  printf("Ingrese la edad del representante: ");
  do {
    scanf("%d", &x->datos_representante.edad);
    fflush(stdin);
    if (x->datos_representante.edad < 18 || x->datos_representante.edad > 85) {
      printf("Edad inválida. Ingrese nuevamente: ");
    }
  } while (x->datos_representante.edad < 18 || x->datos_representante.edad > 85);
  fflush(stdin);

    do {
      printf("Ingrese el correo del representante: ");
      scanf("%s", &x->datos_representante.correo);
      char *y = strrchr(x->datos_representante.correo, '@');
      char *w = strrchr(x->datos_representante.correo, '@');
      if (y != NULL && w != NULL)
        z = 1;
    } while (z != 1);

  printf("Perfecto continuemos\n");
  printf("--------------------Menu de clubes----------------------\n");
        printf("1. Futbol\n");
        printf("2. Basquet\n");
        printf("3. Gimnasia\n");
        printf("4. Atlestismo\n");
        printf("5. Ajedrez\n");
        printf("Seleccione un club: ");
       scanf("%d", &opcion);
	   while(opcion<1 || opcion>5){
	   	printf("Ingrese nuevamente el club: ");
		 scanf("%d", &opcion);
		 }
  
	switch (opcion) {
    case 1:
  strcpy(x->datos_club.nombre,"Futbol");
	strcpy(x->datos_club.profesor,"Pedro");
      break;
    case 2:
  strcpy(x->datos_club.nombre,"Basquet");
	strcpy(x->datos_club.profesor,"Pedro");
      break;
    case 3:
  strcpy(x->datos_club.nombre,"Gimnasia");
	strcpy(x->datos_club.profesor,"Pedro");
      break;
    case 4:
  strcpy(x->datos_club.nombre,"Atletismo");
	strcpy(x->datos_club.profesor,"Pedro");
      break;
    case 5:
  strcpy(x->datos_club.nombre,"Ajedrez");
	strcpy(x->datos_club.profesor,"Pedro");
      break;
}
int j=0;
int l;
for (int i = 0; i < 2; i++) {
	do{
  printf("--------------------Ingrese que dia quiere tener el club----------------------\n");
        printf("1. Lunes\n");
        printf("2. Martes\n");
        printf("3. Miercoles\n");
        printf("4. Jueves\n");
        printf("5. Viernes\n");
        printf("Seleccione un club: ");
       scanf("%d", &opcion);
	   while(opcion<1 || opcion>5){
	   	printf("Ingrese nuevamente el dia: ");
		 scanf("%d", &opcion);
		 }
  
	switch (opcion) {
    case 1:
  strcpy(x->datos_horario[i].Dias,"Lunes");
      break;
    case 2:
  strcpy(x->datos_horario[i].Dias,"Martes");
      break;
    case 3:
  strcpy(x->datos_horario[i].Dias,"Miercoles");
      break;
    case 4:
  strcpy(x->datos_horario[i].Dias,"Jueves");
      break;
    case 5:
  strcpy(x->datos_horario[i].Dias,"Viernes");
      break;
  }
if(j==1){
if(l == opcion)
	printf("Ingrese nuevamente el dia\n");
}}
while(l == opcion);
j=j+1;
l=opcion;
    printf("Ingrese la hora que desea recibir el club\n");
    printf("Hora valida de 8 a 16\n");
    scanf("%d",&x->datos_horario[i].num_horas[0]);
    while(x->datos_horario[i].num_horas[0]<8 || x->datos_horario[i].num_horas[0]>16){
    	printf("Ingrese nuevamente la hora que desea recibir el club");
    scanf("%d",&x->datos_horario[i].num_horas[0]);
	}
    x->datos_horario[i].num_horas[1]=x->datos_horario[i].num_horas[0]+2;
  }
  
  std::stringstream ss;
    ss << x->datos_nino.cedula;
    std::string s = ss.str();
    s.append(".txt");
    archivo.open(s.c_str(),ios::out);
  if(archivo.fail()){
  	cout <<"No se puede abrir";
  	exit(1);
  }
	archivo<<x->cod_matricula<<endl;
	archivo<<x->pagado <<endl;
  archivo<<x->datos_nino.cedula<<endl;
  archivo<<x->datos_nino.nombre<<endl;
  archivo<<x->datos_nino.edad<<endl;
  archivo<<x->datos_representante.cedula<<endl;
  archivo<<x->datos_representante.nombre<<endl;
  archivo<<x->datos_representante.edad<<endl;
  archivo<<x->datos_representante.correo<<endl;
  archivo<<x->datos_club.nombre<<endl;
  archivo<<x->datos_club.profesor<<endl;
  archivo<<x->datos_horario[0].Dias<<endl;
  archivo<<x->datos_horario[0].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo<<x->datos_horario[1].Dias<<endl;
  archivo<<x->datos_horario[1].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo.close();
}
void imprimir(Club_Vacacional x) {
  printf("Codigo matricula:%d \n ", x.cod_matricula);
	printf("Valor pagado:%d \n ", x.pagado);
  printf("cedula del niño:%ld \n ", x.datos_nino.cedula);
  printf("Nombre del niño:%s \n ", x.datos_nino.nombre);
  printf("Edad del niño:%d \n ", x.datos_nino.edad);
  printf("cedula del niño:%ld \n ", x.datos_representante.cedula);
  printf("Nombre del niño:%s \n ", x.datos_representante.nombre);
  printf("Edad del niño:%d \n ", x.datos_representante.edad);
  printf("Correo del niño:%s \n ", x.datos_representante.correo);
  printf("Club:%s \n ", x.datos_club.nombre);
  printf("Profesor:%s \n ", x.datos_club.profesor);
 
  for (int j = 0; j < 2; j++) {
    printf("Dia: %s \n ", x.datos_horario[j].Dias);
    printf("El horario de %d a %d \n", x.datos_horario[j].num_horas[0],x.datos_horario[j].num_horas[1]);
  }
}

void buscarninoPorCedula(Club_Vacacional a[]) {
  long int cedulaBusqueda;
  bool encontrado = false;

  printf("Ingrese la cedula a buscar: ");
  scanf("%ld", &cedulaBusqueda);

  for (int i = 0; i < dum; i++) {
    if (a[i].datos_nino.cedula == cedulaBusqueda) {
      printf("Estudiante Encontrado:\n");
      imprimir(a[i]);
      encontrado = true;
      break;
    }
  }

  if (!encontrado) {
    printf("Estudiante con cedula %ld no encontrado.\n", cedulaBusqueda);
  }
}

void Alumno(Club_Vacacional *x){
	int o, z;
	ofstream archivo;
	   printf("|---------------------------------------------------------|\n");
		printf("Que es lo que desea cambiar\n");
		printf("1.  Nombre\n");
    	printf("2.  Edad\n");
    	printf("|---------------------------------------------------------|\n");
	 do {
      scanf("%d", &o);
    } while (o < 1 || o > 2);
    switch (o) {
    case 1:
    	fflush(stdin);
       printf("Ingrese el nombre del estudiante:");
  fgets(x->datos_nino.nombre, dim, stdin);
x->datos_nino.nombre[strcspn(x->datos_nino.nombre, "\n")] = '\0';
while(!validar_nombre(x->datos_nino.nombre)) {
    printf("!NOMBRE INVALIDO!\n");
    printf("Ingrese el nombre del nino nuevamente:");
    fgets(x->datos_nino.nombre, dim, stdin);
    x->datos_nino.nombre[strcspn(x->datos_nino.nombre, "\n")] = '\0';
}


  fflush(stdin);
      break;
    case 2:
    	fflush(stdin);
    	 printf("Ingrese la edad del estudiante: ");
  do {
    scanf("%d", &x->datos_nino.edad);
    fflush(stdin);
    if (x->datos_nino.edad < 7 || x->datos_nino.edad > 18) {
      printf("Edad inválida. Ingrese nuevamente: ");
    }
  } while (x->datos_nino.edad < 7 || x->datos_nino.edad > 18);
  fflush(stdin);
      break;

}
std::stringstream ss;
    ss << x->datos_nino.cedula;
    std::string s = ss.str();
    s.append(".txt");
archivo.open(s.c_str(),ios::out);
  if(archivo.fail()){
  	cout <<"No se puede abrir";
  	exit(1);
  }
archivo<<x->cod_matricula<<endl;
archivo<<x->pagado <<endl;
  archivo<<x->datos_nino.cedula<<endl;
  archivo<<x->datos_nino.nombre<<endl;
  archivo<<x->datos_nino.edad<<endl;
  archivo<<x->datos_representante.cedula<<endl;
  archivo<<x->datos_representante.nombre<<endl;
  archivo<<x->datos_representante.edad<<endl;
  archivo<<x->datos_representante.correo<<endl;
  archivo<<x->datos_club.nombre<<endl;
  archivo<<x->datos_club.profesor<<endl;
  archivo<<x->datos_horario[0].Dias<<endl;
  archivo<<x->datos_horario[0].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo<<x->datos_horario[1].Dias<<endl;
  archivo<<x->datos_horario[1].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo.close();
}

void Representante(Club_Vacacional *x){
	int o, z;
	ofstream archivo;
	   printf("|---------------------------------------------------------|\n");
		printf("Que es lo que desea cambiar\n");
		printf("1.  Nombre\n");
    	printf("2.  Edad\n");
    	printf("3.  Correo\n");
    	printf("|---------------------------------------------------------|\n");
	 do {
      scanf("%d", &o);
    } while (o < 1 || o > 3);
    switch (o) {
    case 1:
    	fflush(stdin);
      printf("Ingrese el nombre del representante:");
  fgets(x->datos_representante.nombre, dim, stdin);
x->datos_representante.nombre[strcspn(x->datos_representante.nombre, "\n")] = '\0';
while(!validar_nombre(x->datos_nino.nombre)) {
    printf("!NOMBRE INVALIDO!\n");
    printf("Ingrese el nombre del estudiante nuevamente:");
    fgets(x->datos_nino.nombre, dim, stdin);
    x->datos_representante.nombre[strcspn(x->datos_representante.nombre, "\n")] = '\0';
}

  fflush(stdin);
      break;
    case 2:
    	fflush(stdin);
    	 printf("Ingrese la edad del estudiante: ");
  do {
    scanf("%d", &x->datos_representante.edad);
    fflush(stdin);
    if (x->datos_representante.edad < 18 || x->datos_representante.edad > 25) {
      printf("Edad inválida. Ingrese nuevamente: ");
    }
  } while (x->datos_representante.edad < 18 || x->datos_representante.edad > 25);
  fflush(stdin);
      break;
    case 3:
    	fflush(stdin);
    printf("Ingrese el correo del estudiante: ");
  scanf("%s", &x->datos_representante.correo);
  char *y = strrchr(x->datos_representante.correo, '@');
  char *w = strrchr(x->datos_representante.correo, '.com');
  if ((y == NULL) || (w == NULL)) {
    do {
      printf("Correo no valido, Ingrese nuevamente: ");
      scanf("%s", &x->datos_representante.correo);
 char *y = strrchr(x->datos_representante.correo, '@');
  char *w = strrchr(x->datos_representante.correo, '.com');
      if (y != NULL && w != NULL)
        z = 1;
    } while (z != 1);
  }
      break;

}
std::stringstream ss;
    ss << x->datos_nino.cedula;
    std::string s = ss.str();
    s.append(".txt");
archivo.open(s.c_str(),ios::out);
  if(archivo.fail()){
  	cout <<"No se puede abrir";
  	exit(1);
  }
archivo<<x->cod_matricula<<endl;
archivo<<x->pagado <<endl;
  archivo<<x->datos_nino.cedula<<endl;
  archivo<<x->datos_nino.nombre<<endl;
  archivo<<x->datos_nino.edad<<endl;
  archivo<<x->datos_representante.cedula<<endl;
  archivo<<x->datos_representante.nombre<<endl;
  archivo<<x->datos_representante.edad<<endl;
  archivo<<x->datos_representante.correo<<endl;
  archivo<<x->datos_club.nombre<<endl;
  archivo<<x->datos_club.profesor<<endl;
  archivo<<x->datos_horario[0].Dias<<endl;
  archivo<<x->datos_horario[0].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo<<x->datos_horario[1].Dias<<endl;
  archivo<<x->datos_horario[1].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo.close();
}

void Materia(Club_Vacacional *x){
	int o;
	ofstream archivo;
	printf("Por cual cual desea cambiar\n");
      printf("--------------------Menu de clubes----------------------\n");
        printf("1. Futbol\n");
        printf("2. Basquet\n");
        printf("3. Gimnasia\n");
        printf("4. Atlestismo\n");
        printf("5. Ajedrez\n");
        printf("Seleccione un club: ");
      scanf("%d", &o);
	   while(o<1 || o>5){
	   	printf("Ingrese nuevamente el club: ");
		 scanf("%d", &o);
		 }
		 switch (o) {
    case 1:
  strcpy(x->datos_club.nombre,"Futbol");
	strcpy(x->datos_club.profesor,"Marcelo");
      break;
    case 2:
  strcpy(x->datos_club.nombre,"Basquet");
	strcpy(x->datos_club.profesor,"Freddy");
      break;
    case 3:
  strcpy(x->datos_club.nombre,"Gimnasia");
	strcpy(x->datos_club.profesor,"Patricio");
      break;
    case 4:
  strcpy(x->datos_club.nombre,"Atletismo");
	strcpy(x->datos_club.profesor,"Carlos");
      break;
    case 5:
  strcpy(x->datos_club.nombre,"Ajedrez");
	strcpy(x->datos_club.profesor,"Juan");
      break;
    }
    std::stringstream ss;
    ss << x->datos_nino.cedula;
    std::string s = ss.str();
    s.append(".txt");
    archivo.open(s.c_str(),ios::out);
  if(archivo.fail()){
  	cout <<"No se puede abrir";
  	exit(1);
  }
   archivo<<x->cod_matricula<<endl;
   archivo<<x->pagado <<endl;
  archivo<<x->datos_nino.cedula<<endl;
  archivo<<x->datos_nino.nombre<<endl;
  archivo<<x->datos_nino.edad<<endl;
  archivo<<x->datos_representante.cedula<<endl;
  archivo<<x->datos_representante.nombre<<endl;
  archivo<<x->datos_representante.edad<<endl;
  archivo<<x->datos_representante.correo<<endl;
  archivo<<x->datos_club.nombre<<endl;
  archivo<<x->datos_club.profesor<<endl;
  archivo<<x->datos_horario[0].Dias<<endl;
  archivo<<x->datos_horario[0].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo<<x->datos_horario[1].Dias<<endl;
  archivo<<x->datos_horario[1].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo.close(); 
}


  
void Horario(Club_Vacacional *x){
	int opcion,z,o,y,v;
	ofstream archivo;
	printf("Ingrese que horario desea ambiar\n");
	    printf("|---------------------------------------------------------|\n");
    	printf("0.  %s\n",x->datos_horario[0].Dias);
    	printf("1.  %s\n",x->datos_horario[1].Dias);
    	printf("|---------------------------------------------------------|\n");
		scanf("%d", &z);
		while (z < 0 || z > 1){
	printf("Ingrese nuevamente: ");
      scanf("%d", &z);
      }
      fflush(stdin);
      printf("Ingrese que desea cambiar\n");
	    printf("|---------------------------------------------------------|\n");
    	printf("1. El dia\n"); 
    	printf("2. La hora\n");
    	printf("|---------------------------------------------------------|\n");
		 scanf("%d", &o);
		while (o < 1 || o > 2){
			printf("Ingrese nuevamente: ");
      scanf("%d", &o);
      } 
      switch(o){
      	case 1:
      		
    do{
    	fflush(stdin);
      		printf("Ingrese que dia quiere tener el club\n");
        printf("1. Lunes\n");
        printf("2. Martes\n");
        printf("3. Miercoles\n");
        printf("4. Jueves\n");
        printf("5. Viernes\n");
        printf("Seleccione un club: ");
        scanf("%d", &opcion);
       while(opcion<1 || opcion>5){
		printf("Ingrese nuevamente: ");
		scanf("%d", &opcion);
		 }
  
	switch (opcion) {
    case 1:
  strcpy(x->datos_horario[z].Dias,"Lunes");
      break;
    case 2:
  strcpy(x->datos_horario[z].Dias,"Martes");
      break;
    case 3:
  strcpy(x->datos_horario[z].Dias,"Miercoles");
      break;
    case 4:
  strcpy(x->datos_horario[z].Dias,"Jueves");
      break;
    case 5:
  strcpy(x->datos_horario[z].Dias,"Viernes");
      break;
  }
  v=1;
  y = strcmp(x->datos_horario[0].Dias,x->datos_horario[1].Dias);
  if (y == 0) {
    printf("Dia ya ingresado. Escoga otro dia \n");
    v=0;}
	}while(v==0);
fflush(stdin);
      break;
	  case 2:
	  	fflush(stdin);
	  	  printf("Ingrese la hora que desea recibir el club\n");
    printf("Hora valida de 8 a 16\n");
    scanf("%d",&x->datos_horario[z].num_horas[z]);
    while(x->datos_horario[z].num_horas[0]<8 || x->datos_horario[z].num_horas[0]>16){
    	printf("Ingrese nuevamente la hora que desea recibir el club");
    scanf("%d",&x->datos_horario[z].num_horas[0]);
	}
    x->datos_horario[z].num_horas[1]=x->datos_horario[z].num_horas[0]+2;
    break;
	  }
	std::stringstream ss;
    ss << x->datos_nino.cedula;
    std::string s = ss.str();
    s.append(".txt");
    archivo.open(s.c_str(),ios::out);
  if(archivo.fail()){
  	cout <<"No se puede abrir";
  }
	archivo<<x->cod_matricula<<endl;
	archivo<<x->pagado <<endl;
  archivo<<x->datos_nino.cedula<<endl;
  archivo<<x->datos_nino.nombre<<endl;
  archivo<<x->datos_nino.edad<<endl;
  archivo<<x->datos_representante.cedula<<endl;
  archivo<<x->datos_representante.nombre<<endl;
  archivo<<x->datos_representante.edad<<endl;
  archivo<<x->datos_representante.correo<<endl;
  archivo<<x->datos_club.nombre<<endl;
  archivo<<x->datos_club.profesor<<endl;
  archivo<<x->datos_horario[0].Dias<<endl;
  archivo<<x->datos_horario[0].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo<<x->datos_horario[1].Dias<<endl;
  archivo<<x->datos_horario[1].num_horas[0]<<endl;
  archivo<<x->datos_horario[0].num_horas[1]<<endl;
  archivo.close();
	  }


void Busquedav(Club_Vacacional a[]) {
  long int cedulaBusqueda;
  bool encontrado = false;
int o;
  printf("Ingrese la cedula a buscar: ");
  scanf("%ld", &cedulaBusqueda);

  for (int i = 0; i < dum; i++) {
    if (a[i].datos_nino.cedula == cedulaBusqueda) {
      printf("Nino Encontrado:\n");
      printf("%d",a[i].datos_nino.cedula);
  printf("Codigo matricula:%d \n ", a[i].cod_matricula);
  printf("cedula del niño:%ld \n ", a[i].datos_nino.cedula);
  printf("Nombre del niño:%s \n ", a[i].datos_nino.nombre);
  printf("Edad del niño:%d \n ", a[i].datos_nino.edad);
      bool encontrado = true;
  }
}
if (encontrado && false){
	printf("Cedula no encontrada");
}
}

void Borrar(Club_Vacacional *x){
	x->datos_nino.cedula=0;
		x->datos_representante.cedula=0;
}

void Eliminar (Club_Vacacional a[]){
	long int cedulaBusqueda;
int o;
  printf("Ingrese la cedula a buscar: ");
  scanf("%ld", &cedulaBusqueda);

  for (int i = 0; i < dum; i++) {
    if (a[i].datos_nino.cedula == cedulaBusqueda) {
      printf("Nino Encontrado:\n");
      printf("%d",a[i].datos_nino.cedula);
       printf("|---------------------------------------------------------|\n");
		printf("Seguro desea eliminarlo\n");
		printf("1.  Si\n");
    	printf("2.  No\n");
    	 do {
      scanf("%d", &o);
    } while (o < 1 || o > 2);
    if(o==1){
    	Borrar(&a[i]);
    	printf("Nino eliminado");
	}
}}}



void Busqueda(Club_Vacacional a[]) {
  long int cedulaBusqueda;
int o;
  printf("Ingrese la cedula a buscar: ");
  scanf("%ld", &cedulaBusqueda);

  for (int i = 0; i < dum; i++) {
    if (a[i].datos_nino.cedula == cedulaBusqueda) {
      printf("Nino Encontrado:\n");
      printf("%d",a[i].datos_nino.cedula);
       printf("|---------------------------------------------------------|\n");
		printf("Que es lo que desea cambiar\n");
		printf("1.  Datos Nino\n");
    	printf("2.  Datos Representante\n");
    	printf("3.  Datos Club\n");
    	printf("4.  Datos Horario\n");
    	printf("|---------------------------------------------------------|\n");
	 do {
      scanf("%d", &o);
    } while (o < 1 || o > 4);
    switch (o) {
    case 1:
      Alumno(&a[i]);
      break;
    case 2:
    Representante(&a[i]);
      break;
    case 3:
    	Materia(&a[i]);
      break;
      case 4:
    	Horario(&a[i]);
      break;
    }
    }

  }}

int Verificacion(Club_Vacacional a[]) {
int o,i;
  for (i = 0; i < dum; i++) {
    if (a[i].datos_nino.cedula == 0) {
    	return i ;}
		}
	if(i=dum){
		return 4;
	}
	}

bool Verificacion_i(Club_Vacacional *a) {
    if ((a->datos_nino.cedula) == 0) {
    	return false ;}
		else{
		return true;
	}
	}

void Poner (Club_Vacacional *a){
	a->datos_nino.cedula=0;
}

bool validar (Club_Vacacional a1[]){
  for (int i = 0; i < dum; i++) {
    if (a1[i].datos_nino.cedula != 0) 
    	return false;
		}
    		return true;
	
}


int main() {
	int z,w;
  char celular[11];
  Club_Vacacional a1[dum];
  int o;
  for (int z = 0; z < dum; z++){
  Poner(&a1[z]);}
  do{
  do {
    printf("Elija una opcion: \n");
    printf("|---------------------------------------------------------|\n");
    printf("1.  Matricula\n");
    printf("2.  Modificar\n");
    printf("3.  Eliminar nino\n");
    printf("4.  Buscar nino\n");
    printf("5.  Imprimir Individual\n");
    printf("6.  Imprimir todo\n");
    printf("7.  Salir\n");
    printf("|---------------------------------------------------------|\n");
    scanf("%d", &o);
  } while (o < 0 || o > 7);
system("cls");
  switch (o) {
  case 1:
  	z= Verificacion (a1);
    if (z < dum) {
	ingresar(&a1[z],a1,z);
    } else {
      printf("SISTEMA LLENO\n");
    }
    break;
 case 2:
   if(validar(a1)){
     printf("No hay datos");
   }else
    Busqueda(a1);
    break;
  case 3:
    if(validar(a1)){
     printf("No hay datos");
   }else
  	Eliminar(a1);
    break;
  case 4:
  if(validar(a1)){
     printf("No hay datos");
   }else
    Busquedav(a1);
    break;
  case 5:
    if(validar(a1)){
     printf("No hay datos");
   }else
  	buscarninoPorCedula(a1);
    break;
  case 6:
    if(validar(a1)){
     printf("No hay datos");
   }else{
    for (int i = 0; i < dum; i++) {
		if (Verificacion_i(&a1[i])){
      imprimir(a1[i]);}
    }}
    break;
    case 7:
     exit(0);
  }
  printf("\n---------------------- Desea continuar ---------------------------\n");
    printf("1.  Si\n");
    printf("2.  No\n");
    do{
	scanf("%d",&w);
	}while(w<1 || w>2);
    if(w==2)
    exit(0);
    system("cls");
  }while(0==0);
  return (0);
}
