#include <iostream>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>

int main()
{
    //GAME MATH!!!

    //COLORS: RGBA

    int color = 0xf00;
    std::cout << std::hex << color << "\n";

    //D = Entity - Player;

    // vetor diferença 
    // diferenca = (entity.x - player.x, entity.y - player.y)
    // distancia ( a raiz quadrada da hipotenusa )
    // distancia = sqrtf(distancia.x * distancia.x + distancia.y * distancia.y)

    // Angulo do jogador em relação ao objeto
    // tangente do angulo x = Y / X = D.y / D.X
    // angulo = atan2f(D.y, D.X);

    // NORMALIZAÇÃO DE VETORES
    // ----------------------------------------------------------------------------
    // tamanho do vetor: a distancia que ele viaja
    // distancia a partir da origem (0,0) (mais uma vez, a raiz quadrada da hipotenuza)
    // normalizar um vetor é manter seu angulo, reduzindo somente seu tamanho a 1 ( vetor unitário )


    // distancia = (mouse.x - jogador.x, mouse.y - jogador.y)
    // distancia tem algum valor, agora queremos que seja um S qualquer
    //
    // vetorNormalizado = (D.x / distancia, D.y /distancia) => agora a distancia é 1
    // Vec2 velocity = (S * vetorNormalizado.x, S * vetorNormalizado.y) 
    // ----------------------------------------------------------------------------
    // ----------------------------------------------------------------------------

    // segunda forma:
    //sendo D  = (mouse.x - player.x, mouse.y - player.y)
    // anguloThetaD = atan2f(D.y, D.x);
    // velocidade = (S * cos(angulo), S * sin(angulo))

    // COLISÃO ENTRE CIRCULOS



    

}