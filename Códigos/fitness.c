//CALCULA A FUNÇÃO FITNESS DE CADA PARTICULA
float fitness(float x, float phi_sp, float phi){
        float beta,alfa,F,e, sys_overshoot;

        e=phi_sp - phi ;  //Calcula o Erro
        //sys_overshoot=max(yout)-1; // Calcula o overshoot

        alfa=10;
        beta=10;
        F = (e*beta + sys_overshoot*alfa);
        return F;
}
