float phi1(float v, float teta, float r, float l){
        float phi1_sp,w;
        float angulo = teta/57.3;//Convertendo para radianos
        w = v*cos(angulo);
        phi1_sp = (v - w*l)/r;
        if (angulo > 3.1416){phi1_sp *= (-1);}
        if (((teta > 340) || (teta < 20)) && (teta != 0)){phi1_sp = -v;}
        if ((teta > 160) && (teta < 200)){phi1_sp = v;}

        return phi1_sp;
}

float phi2(float v, float teta, float r, float l){
        float phi2_sp,w;
        float angulo = teta/57.3;//Convertendo para radianos
        w = v*cos(angulo);
        phi2_sp = (v + w*l)/r;
        if(angulo > 3.1416){phi2_sp *= (-1); }
        if((teta > 340) || (teta < 20)){phi2_sp = v;}
        if((teta > 160) && (teta < 200)){phi2_sp = -v;}

        return phi2_sp;
}
