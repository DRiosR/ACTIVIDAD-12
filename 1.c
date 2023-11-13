#include <stdio.h>

#define MAX_REGISTROS 50
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50

struct Registro
{
    int numero;
    int matricula;
    char nombre[MAX_NOMBRE];
    char apellido_pat[MAX_APELLIDO];
    char apellido_mat[MAX_APELLIDO];
    int edad;
    char sexo[MAX_NOMBRE];
};

void leerArchivo()
{
    struct Registro registros[MAX_REGISTROS];
    extern FILE *archivo;
    int i = 0;

    archivo = fopen("lol.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo de datos.\n");
        return;
    }

    // Leer cada campo y almacenarlo en la estructura
    while (fscanf(archivo, "%d %d %s %s %s %d %s",
                  &registros[i].numero, &registros[i].matricula, registros[i].nombre,
                  registros[i].apellido_pat, registros[i].apellido_mat,
                  &registros[i].edad, registros[i].sexo) != EOF)
    {
        i++;
        if (i >= MAX_REGISTROS)
        {
            printf("Se ha alcanzado el máximo de registros.\n");
            break;
        }
    }

    fclose(archivo);

    // Mostrar los datos almacenados en la estructura
    for (int j = 0; j < i; j++)
    {
        printf("Registro %d:\n", registros[j].numero);
        printf("Matrícula: %d\n", registros[j].matricula);
        printf("Nombre: %s %s %s\n", registros[j].nombre, registros[j].apellido_pat, registros[j].apellido_mat);
        printf("Edad: %d\n", registros[j].edad);
        printf("Sexo: %s\n", registros[j].sexo);
        printf("\n");
    }
}

int main()
{
    leerArchivo();
    return 0;
}
