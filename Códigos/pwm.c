void pwm_habilita()
{       //Declarando ponteiros e variáveis
        FILE *ain,*periodo1,*periodo2,*polaridade1,*polaridade2;
        //char str_teste[36];
        //Habilitando as saídas pwms
        ain = fopen("/sys/devices/bone_capemgr.9/slots", "w");
        fseek(ain,0,SEEK_SET);
        fprintf(ain,"am33xx_pwm");

        fseek(ain,10, SEEK_SET);
        fprintf(ain, "bone_pwm_P9_14");
        fseek(ain,25,SEEK_SET);
        fprintf(ain, "bone_pwm_P8_13");
        fclose(ain);

//Relação Direta de Duty Cycle
        polaridade1 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.12/polarity", "w");
        fseek(polaridade1,0,SEEK_SET);
        fprintf(polaridade1,"0");
        fclose(polaridade1);

        polaridade2 = fopen("/sys/devices/ocp.3/pwm_test_P8_13.13/polarity", "w");
        fseek(polaridade2,0,SEEK_SET);
        fprintf(polaridade2, "0");
        fclose(polaridade2);
//Periodo do sinal PWM
        periodo1 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.12/period", "w");
        fseek(periodo1,0,SEEK_SET);
        fprintf(periodo1,"10000000");
        fclose(periodo1);

        periodo2 = fopen("/sys/devices/ocp.3/pwm_test_P8_13.13/period", "w");
        fseek(periodo2,0,SEEK_SET);
        fprintf(periodo2,"10000000");
        fclose(periodo2);
}
