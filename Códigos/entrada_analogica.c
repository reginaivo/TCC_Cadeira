void habilita_entrada_analogica()
{       //Declarando ponteiros e variáveis
        FILE *ain;
        //Habilitando porta analogica
        ain = fopen("/sys/devices/bone_capemgr.9/slots", "w");
        fseek(ain,70,SEEK_SET);
        fprintf(ain,"cape-bone-iio");
//      fflush(ain);
        fclose(ain);
}

int entrada_analogica(const char* str)
{       //Declarando ponteiros e variáveis
        FILE *ain,*aval;
        int value;
                //Habilitando as entradas analogicas
                aval = fopen(str, "r");
                fseek(aval,0,SEEK_SET);
                fscanf(aval,"%d",&value);
                fclose(aval);

        //fclose(ain);
                return value;
}

