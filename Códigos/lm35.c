float lm35(int valor_digital){
        //Rotina de inicialização deve ser executada apenas uma vez
        //Variaveis do modelo do sistema
        int A = 1;
        int H = 1;
        int Q = 0;
        int R = 5;
        float Xp, Pp, k,z;

//      z = (valor_digital*1.8*100/4096);//Precisão do conversor AD
        z = (valor_digital/10);
        //z = valor_digital;
        //Utiliza algoritmo de filtro de kalman para filtrar os valores de temperatura
        //Rotina de estimação
        Xp = x_kalman;
        Pp = P_kalman;

        //Calculando o ganho de Kalman
        k = Pp/(Pp + R);

        //Rotina de predição
        x_kalman = (Xp + k*(z -Xp));
        P_kalman = Pp - k*Pp;
        //printf("z = %.2f k = %.2f x_kalman = %.2f p_kalman = %.2f\n", z,k,x_kalman,P_kalman);
        return z;
}

