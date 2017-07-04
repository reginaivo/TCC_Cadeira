float  joystick_modulo(int x1, int y1){
//Rotina de calibração;
        float x,y;
        x = (x1 - 430);
        y = (y1 - 465);
//Calculo da intensidade
        float modulo;//vetor de setpoint para o módulo de cinemática
        modulo = sqrt(pow(x,2)+ pow(y,2));//Define o setpoint de velocidade
        if (modulo < 20){modulo = 0;};
        return modulo;
}

float  joystick_direcao(int x1, int y1, float modulo){


//Rotina de calibração;
        float x,y,argumento;
        x = (x1 - 430);
        y = (y1 - 465);
        float direcao,angulo;//vetor de setpoint para o módulo de cinemática
//Calculo da direcao
        argumento = (x/modulo);
        direcao = acos(argumento);//Define o setpoint angular
        angulo = direcao*57.3;//Tranforma de radianos para graus

        if (y < 0) {angulo = (360 - angulo);}
        if (modulo == 0){angulo = 0;};

        return angulo;
}
