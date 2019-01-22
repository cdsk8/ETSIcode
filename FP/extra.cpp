#include <iostream>
#include <cstring>

typedef char cad[20];

class alumno{
    cad nomb, direc;
    int edad;
public:
    alumno(){
        strcpy(nomb,"");
        strcpy(direc,"");
        edad = 0;
    }
    alumno(cad nom, cad dir, int edd){
        strcpy(nomb,nom);
        strcpy(direc,dir);
        edad = edd;
    }
    void nombre(cad nom){
        strcpy(nom,nomb);
    }
    int leeredad(){
        return edad;
    }
    void direccion(cad dir){
        strcpy(dir,direc);
    }
};

class asignatura{
    cad nomasig;
    alumno talumnos[200];
    int nalumnos;
public:
    asignatura(){
        nalumnos = 0;
        strcpy(nomasig,"");
    }
    int leern(){
        return nalumnos;
    }
    void leeralumno(int i, alumno &a){
        a = talumnos[i];
    }
    void leernomasig(cad n){
        strcpy(n,nomasig);
    }
    void setName(cad NewName){
        strcpy(nomasig,NewName);
    }
    void addAlumno(alumno a){
        talumnos[nalumnos] = a;
        nalumnos++;
    }
};

class grado{
    asignatura tasignaturas[60];
    int nasignaturas;
public:
    grado(){
        nasignaturas = 3;
        alumno alu1("Smith","c",15);
        alumno alu2("Jhon","c",15);
        alumno alu3("CaviLake","c",15);
        alumno alu4("IceLake","c",15);
        tasignaturas[0].setName("Programacion");
        tasignaturas[0].addAlumno(alu1);
        tasignaturas[0].addAlumno(alu2);
        tasignaturas[1].setName("Radiofrecuencia");
        tasignaturas[1].addAlumno(alu2);
        tasignaturas[1].addAlumno(alu3);
        tasignaturas[2].setName("Montaje");
        tasignaturas[2].addAlumno(alu1);
        tasignaturas[2].addAlumno(alu4);
    }
    void asignaturasalumno(cad nomalum);
};

void grado::asignaturasalumno(cad nomalum){
    bool matriculado;
    int j, nAlumnos;
    alumno alumnoTMP;
    cad nombreTMP;
    for(int i = 0; i < nasignaturas; i++){
        matriculado = false;
        nAlumnos = tasignaturas[i].leern();
        j = 0;
        while(j < nAlumnos && !matriculado){
            tasignaturas[i].leeralumno(j,alumnoTMP);
            alumnoTMP.nombre(nombreTMP);
            if(strcmp(nomalum,nombreTMP)==0)
                matriculado = true;
            j++;
        }
        if(matriculado){
            tasignaturas[i].leernomasig(nombreTMP);
            std::cout << "Matriculado en :" << nombreTMP << "\n";
        }
    }
}

int main(){
    grado g;
    g.asignaturasalumno("Smith");
    return 0;
}
