//Programa principal do sistema de controle da cadeira

//Definindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//Declaração de variaveis globais
        //Valores iniciais para o filtro de kalman
        float x_kalman = 24.5; // Valor inicial de temperatura
        float P_kalman = 13;//Valor inicial alto de covariancia


//Inserindo os arquivos com as funcoes
#include "entrada_analogica.c"//Programa para habilitar pinos analógicos
#include "pwm.c"
#include "cinematica.c"//Bloco cinemático
#include "lm35.c"//Leitura da temperatura dos motores
//#include "PID.c"//Bloco do PID
//#include "PSO.c"//Bloco de sintonia do PID usando PSO
#include "joystick.c"
#include "logica.c"
#include "entrada_digital.c"
main(){

//Rotinas de inicializacao
                int value_x, value_y,t;
                float temp_MD,temp_ME,v,teta,phi1_sp,phi2_sp;
                t = 1; //Tempo de amostragem de 1 segundo.
                float r = 0.6;//raio das rodas com pneu
                float l = 0.27;//distancia ate P do bloco de cinematica
                float kp = 1.0982;// Constante proporcional do PID
                float ki = 10.02;//Constante integrativa do PID
                float kd = 0.052; //Constante derivativa do PID 
        //Inicializacao dos PWMs
                pwm_habilita();
        //Inicialização  das saídas digitais
                habilita_entradas_digitais();
        //Inicializacao das Entradas Analogicas
                char str_A0[] = "/sys/devices/ocp.3/helper.14/AIN5";//eixo x
                char str_A1[] = "/sys/devices/ocp.3/helper.14/AIN3";//eixo y
                char str_A2[] = "/sys/devices/ocp.3/helper.14/AIN1";//temp M.D.
                char str_A3[] = "/sys/devices/ocp.3/helper.14/AIN0";//temp M.E.
                habilita_entrada_analogica();

        while(1){
                //Bloco Conversor AD para o Joystick
                value_y = entrada_analogica(str_A1);//Leitura analógica do eixo x
                value_x = entrada_analogica(str_A0);//Leitura analógica do eixo y

                //Aferindo a temperatura dos motores
                temp_MD = lm35(entrada_analogica(str_A2));//Faz a leitura do sensor de temperatura
                temp_ME = lm35(entrada_analogica(str_A3));//Faz a leitura do sensor de temperatura

                v = joystick_modulo(value_x, value_y);//Bloco de condicionamento do Joystick - Setpoint de Velocidade Linear
                teta = joystick_direcao(value_x, value_y,v);//Bloco de condicionamento do Joystick - Setpoint de velocidade tangencial

                phi1_sp = phi1(v,teta,r,l);//v e teta da saida da cinematica
                phi2_sp = phi2(v,teta,r,l);
                u1 = pid(kp,ki,kd,phi1_sp,phi1,t);//t é o tempo de amostragem
                u2 = pid(kp,ki,kd,phi2_sp,phi2,t);//t é o tempo de amostragem
                logica(phi1_sp,phi2_sp);
                usleep(t*1000000);//Produz um Delay de 1 segundo,valor em microssegundos
}
        return 0;
}
