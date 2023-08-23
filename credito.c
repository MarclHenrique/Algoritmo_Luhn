#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int card_1, card_2, card_3, card_4, card_5, card_6, card_7, card_8;
    int card_9, card_10, card_11, card_12, card_13, card_14, card_15, card_16;
    long valor;
    long cartao = 0; // Inicializando cartao com 0

    // SOLICITANDO OS DíGITOS DO CARTÃO E IMPEDINDO NÚMEROS NEGATIVOS
    do
    {
        printf("%s\n", "Digite o número");
        if (scanf("%ld", &valor) != 1)
        {
            printf("%s\n", "Entrada inválida. Tente novamente.");
            while (getchar() != '\n'); // Clear input buffer
        }
        else
        {
            cartao = valor;
        }
    } while (valor < 1);

// COMEÇANDO PELO PENÚLTIMO NÚMERO E MULTIPLICANDO POR 2

    card_1 = ((valor % 100)/10 * 2);
    card_2 = ((valor % 10000)/1000 * 2);
    card_3 = ((valor % 1000000)/100000 * 2);
    card_4 = ((valor % 100000000)/10000000 * 2);
    card_5 = ((valor % 10000000000)/1000000000 * 2);
    card_6 = ((valor % 1000000000000)/100000000000 * 2);
    card_7 = ((valor % 100000000000000)/10000000000000 * 2);
    card_8 = ((valor % 10000000000000000)/1000000000000000 * 2);

//TRANSFORMANDO OS NÚMEROS DECIMAIS EM UNIDADE E SOMANDO

    card_1 = (card_1 % 100)/10 + (card_1 % 10);
    card_2 = (card_2 % 100)/10 + (card_2 % 10);
    card_3 = (card_3 % 100)/10 + (card_3 % 10);
    card_4 = (card_4 % 100)/10 + (card_4 % 10);
    card_5 = (card_5 % 100)/10 + (card_5 % 10);
    card_6 = (card_6 % 100)/10 + (card_6 % 10);
    card_7 = (card_7 % 100)/10 + (card_7 % 10);
    card_8 = (card_8 % 100)/10 + (card_8 % 10);

    int sum_one = card_1 + card_2 + card_3 + card_4 + card_5 + card_6 + card_7 + card_8;

// PEGANDO OS VALORES QUE NÃO FORAM SOMADOS E SOMANDO ELES A SI MESMOS

    card_9 = (valor % 10);
    card_10 = ((valor % 1000)/100);
    card_11 = ((valor % 100000)/10000);
    card_12 = ((valor % 10000000)/1000000);
    card_13 = ((valor % 1000000000)/100000000);
    card_14 = ((valor % 100000000000)/10000000000);
    card_15 = ((valor % 10000000000000)/1000000000000);
    card_16 = ((valor % 1000000000000000)/100000000000000);

    int sum_two = card_9 + card_10 + card_11 + card_12 + card_13 + card_14 + card_15 + card_16;
    int sum_final = (sum_one + sum_two);

// ANALISAMOS SE O CARTÃO TEM O FINAL 0
    int validacao = sum_final % 10;

// INICIALIZANDO VARIÁVEIS UTILIZADAS A SEGUIR
    int tam = 0;
    long visa = valor;
    long amex = cartao;
    long master = cartao;

// Estrtura para descobrir a quantidade de dígitos
    while (cartao > 0)
    {
    cartao = cartao/10;
    tam ++;
    }

// IDENTIFICANDO CARTÃO VISA
    while (visa >= 10)
    {
       visa /= 10;
    }

    if (visa == 4 && (tam == 13 || tam == 16))
    {
        printf("%s\n", "Cartão VISA");
        return 0;
    }
// IDENTIFICANDO CARTÃO AMEX
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (tam == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "Cartão AMEX");
        return 0;
    }
// IDENTIFICANDO CARTÃO MASTER
    while (master >= 10000000000000)
    {
        master /= 10000000000000;
    }
    if (tam == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55 ))
    {
        printf("%s\n", "Cartão MASTER");
        return 0;
    }
    else
    {
        printf("%s\n", "Cartão inválido");
        return 0;
    }
}
