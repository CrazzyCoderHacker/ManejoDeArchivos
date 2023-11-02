#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


    
 void generarArreglo(int arr[], int N) 
 {
    srand(time(NULL));
    for (int i = 0; i < N; ++i)
	 {
        arr[i] = (rand() % 30) + 1;
    }
}

void ordenarArreglo(int arr[], int N) 
{
    for (int i = 0; i < N - 1; i++) 
	{
        for (int j = 0; j < N - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void encontrarMinMax(int arr[], int N, int &minimo, int &maximo)
 {
    minimo = arr[0];
    maximo = arr[N - 1];
}

float calcularMedia(int arr[], int N) 
{
    int suma = 0;
    for (int i = 0; i < N; i++)
	 {
        suma += arr[i];
    }
    return static_cast<float>(suma) / N; // convertir suma total a flotantes //importante
}

int calcularMediana(int arr[], int N) 
{
    if (N % 2 == 0) 
	{
        return (arr[N / 2 - 1] + arr[N / 2]) / 2;
    } 
		else 
		{
	        return arr[N / 2];
	    }
}

int calcularModa(int arr[], int N) 
{
    int moda = 0;
    int max_frecuencia = 0;
    for (int i = 0; i < N; i++)
	 {
        int frecuencia = 0;
        for (int j = 0; j < N; j++)
		 {
            if (arr[j] == arr[i]) 
			{
                frecuencia++;
            }
        }
        if (frecuencia > max_frecuencia)
		 {
            moda = arr[i];
            max_frecuencia = frecuencia;
        }
    }
    return moda;
}

void Histograma(int arr[], int N) 
{
    printf("Histograma:\n");
    for (int i = 1; i <= 30; i++)
	 {
        int frecuencia = 0;
        for (int j = 0; j < N; j++) 
		{
            if (arr[j] == i) 
			{
                frecuencia++;
            }
        }
        printf("%2d: ", i);
        for (int p = 0; p < frecuencia; p++)
		 {
            printf("*");
        }
        printf("\n");
    }
}

int main() 
{
    int N;
    printf("tamano del arreglo: ");
    scanf("%d", &N);

    int arr[N];
    int min, max;

    printf("Elementos del arreglo:\n");
    for (int i = 0; i < N; i++) 
	{
        scanf("%d", &arr[i]);
    }

    ordenarArreglo(arr, N);
    encontrarMinMax(arr, N, min, max);

    printf("Minimo: %d\n", min);
    printf("Maximo: %d\n", max);
    printf("Media: %.2f\n", calcularMedia(arr, N));
    printf("Mediana: %d\n", calcularMediana(arr, N));
    printf("Moda: %d\n", calcularModa(arr, N));
    Histograma(arr, N);

    return 0;
}


