 void logica(float v1, float v2){
        FILE *d1,*d2,*pwm1,*pwm2;
        float val1,val2;
        int duty1,duty2;
        char p1[10],p2[10];
        val1 = abs(v1)*100000/14;//Convertendo em valores de duty cycle
        val2 = abs(v2)*100000/14;//Convertendo em valores de duty cycle
        duty1 = (int)val1;//Truncando o float em int
        duty2 = (int)val2;//Truncando o float em int
        snprintf(p1, 10 ,"%d", duty1);
        snprintf(p2, 10, "%d", duty2);

        pwm1 = fopen("/sys/devices/ocp.3/pwm_test_P9_14.12/duty","w");
        fseek(pwm1,0,SEEK_SET);
        fprintf(pwm1,"%s",p1);
        fclose(pwm1);

        pwm2 = fopen("/sys/devices/ocp.3/pwm_test_P8_13.13/duty","w");
        fseek(pwm2,0,SEEK_SET);
        fprintf(pwm2,"%s",p2);
     fclose(pwm2);


        d1 = fopen("/sys/class/gpio/gpio48/value","w");
        fseek(d1,0,SEEK_SET);
        if(v1 > 0){     fprintf(d1,"1");}
        else {          fprintf(d1,"0");}
        fclose(d1);

        d2 = fopen("/sys/class/gpio/gpio26/value","w");
        fseek(d2,0,SEEK_SET);
        if (v2 > 0 ){   fprintf(d2,"1");}
        else{           fprintf(d2,"0");}
        fclose(d2);
}
