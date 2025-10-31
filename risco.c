// Implementação de risco em C
#include <stdio.h>

// cria uma estrutura com um unico campo
struct circulo {
    float raio;
};

// cria uma estrutura com dois campos
struct retangulo {
    float largura;
    float altura;
};

// declara uma união chamada forma, podendo representar uma circulo ou um retangulo (um por vez na memoria)
union forma {
    struct circulo c;
    struct retangulo r;
};

// cria um tipo enum para indicar qual tipo de forma a união está representando no momento 
enum tipo {
    circulo, // = 0
    retangulo, // = 1
};

float area(union forma f, enum tipo t) { // union forma f: dados da forma (pode ser retangulo ou circulo)
                                         // enum tipo t: diz qual tipo é p calculo da area 
    
    // calculo da area dependendo do tipo
    if (t == circulo) {
        return 3.14 * f.c.raio * f.c.raio;
    } else if (t == retangulo) {
        return f.r.largura * f.r.altura;
    } else {
        return 0;
    }
}

int main() {

    // f1: circulo e f2: retangulo
    union forma f1, f2;

    printf("Exemplo correto - Circulo\n");
    f1.c.raio = 10.0; 
    
    // chama a funcao area 
    float area_C = area(f1, circulo);
    printf("Area do circulo: %.2f\n", area_C);
        
    printf("\nExemplo correto - Retangulo\n");
    f2.r.largura = 5.0;
    f2.r.altura = 3.0;
    
    // chama a funcao area 
    float area_R = area(f2, retangulo);
    printf("Area do retangulo: %.2f\n", area_R);
    
    //undefined behavior (comportamento indefinido em C)
    printf("\nExemplo incorreto - Erro Logico\n");
    /* 
        chama a funcao area, no entanto, no parametro real temos a f1 representando
        a união que guarda o circulo e passamos o tipo como retangulo.
    */
    float area_errada = area(f1, retangulo);
    printf("Area incorreta (erro de tipo): %.2f\n", area_errada);

    return 0;
}
