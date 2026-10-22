#include <stdio.h>
#include <stdlib.h>
#include "armazenamento.h"

void programa(){
    while (1){

        limparTela();


        printf("tabela de opcoes: \n"\
               "tecla 1: alcool, 3.80.\n"\
               "tecla 2: gasolina, 5.50.\n"\
               "tecla 3: disel, 6.20.\n"\
               "tecla 0: ecerrar expediente.\n");
        scanf("%i", &opcao);

        if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0){
            comandoInvalido();
            continue;
        }
        
        if (opcao == 0){
            printf("Encerrando\n");
            break;
        }
        
        
        switch (opcao){
        case 1:
            printf("digite o valor ou litros que deseja e especifique qual exemplo(20 V(Valor) ou 20 L(Litros))\n");
            scanf("%lf %c", &quant, &tipo);
            if((tipo == 'V' || tipo == 'v') && quant > 0){
                valor = quant;
                litros = valor / alcool;
                Valor_final = valor;
                Litros_T_Alcool += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();

            }
            else if ((tipo == 'L' || tipo == 'l') && quant > 0){
                litros = quant;
                valor = litros * alcool;
                Valor_final = valor;
                Litros_T_Alcool += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();              
            }         
            break;
        case 2:
            printf("digite o valor ou litros que deseja e especifique qual exemplo(20 V(Valor) ou 20 L(Litros))\n");
            scanf("%lf %c", &quant, &tipo);

            if((tipo == 'V' || tipo == 'v') && quant > 0){
                valor = quant;
                litros = valor / gasolina;
                Valor_final = valor;
                Litros_T_gasolina += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();
            }
            else if((tipo == 'L' || tipo == 'l') && quant > 0){
                litros = quant;
                valor = litros * gasolina;
                Valor_final = valor;
                Litros_T_gasolina += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();
            }
        break;
        case 3:
            printf("digite o valor ou litros que deseja e especifique qual exemplo(20 V(Valor) ou 20 L(Litros))\n");
            scanf("%lf %c", &quant, &tipo);
            if((tipo == 'V' || tipo == 'v') && quant > 0){
                valor = quant;
                litros = valor / disel;
                Valor_final = valor;
                Litros_T_disel += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();
            }
            else if ((tipo == 'L' || tipo == 'l') && quant > 0){
                litros = quant;
                valor = litros * disel;
                Valor_final = valor;
                Litros_T_disel += litros;
                faturamento_B += Valor_final;
                printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
                scanf(" %c", &pagamento);

                Verificacao_pagamento();              
            }
            break;
        }

        printf("Digite qualquer tecla e aperte enter para continuar.");
        scanf(" %c", &espaco_vazio);
        clientes++; 
    }
    Litros_T = Litros_T_Alcool + Litros_T_gasolina + Litros_T_disel;
    if (Litros_T > 0) {
    Percentual_A = (Litros_T_Alcool / Litros_T) * 100;
    Percentual_G = (Litros_T_gasolina / Litros_T) * 100;
    Percentual_D = (Litros_T_disel / Litros_T) * 100;
    }
    limparTela();
    Print_Final(); 
}

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void comandoInvalido(){
    printf("Conmando invalido digite qualquer tecla e aperte enter para reiniciar.");
    scanf(" %c", &espaco_vazio);
}

void Verificacao_pagamento(){
    while (1){
        if (pagamento == 'A' || pagamento == 'a' || pagamento == 'b' || pagamento == 'B'){
            break;
            }
        comandoInvalido();
        printf("qual a forma de pagamento? \n Digite A(Dinheiro/Debito/Pix 3%% de desconto) \n Digite B(Cartao De Credito +5%% de acrescimo) \n");
        scanf(" %c", &pagamento);    
    }

    if(pagamento == 'A' || pagamento == 'a'){
        desconto = Valor_final * 0.03;
        Valor_final = Valor_final - desconto;
        printf("Desconto aplicado valor final: %.2lf \n", Valor_final);
        faturamento_L += Valor_final;
        }
    else if(pagamento == 'B' || pagamento == 'b'){
        acrescimo = Valor_final * 0.05;
        Valor_final = Valor_final + acrescimo;
        printf("Acrescimo aplicado valor final: %.2lf \n", Valor_final);
        faturamento_L += Valor_final;
    }
        
}

void Print_Final(){
    printf("=====FINAL DO EXPEDIENTE===== \n");
    printf("Total de Clientes Atendidos: %i \n", clientes);
    printf("<Litros Vendidos> \n"
       "Alcool: %.2lf \n"
       "Gasolina: %.2lf \n"
       "Disel: %.2lf \n", 
       Litros_T_Alcool, Litros_T_gasolina, Litros_T_disel);
       printf("<Porcentagem de Litros Vendidos> \n");
    if (Percentual_A > 0){
        printf("Alcool: %.2lf%%\n", Percentual_A);
    }
    if (Percentual_G > 0){
        printf("Gasolina: %.2lf%% \n", Percentual_G);
    }
    if (Percentual_D > 0){
        printf("Disel: %.2lf%% \n", Percentual_D);
    }
    printf("Faturamento Bruto: %.2lf \n", faturamento_B);
    printf("Faturamento Liquido: %.2lf \n", faturamento_L);
    
}