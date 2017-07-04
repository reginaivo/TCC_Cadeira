float pid(float k_p, float k_d, float k_i, float phi_sp, float phi, int t){
        float u,e_n,e_a; e_n = 0; e_a = 0;
        int u_int;//Saída do controlador
        e_n = phi_sp - phi;//Calculo do novo valor de erro
        u = k_p*e_n + k_d*(e_n - e_a)*t  + k_i*(e_n + e_a)/t;
        e_a = e_n;
        //u_int = round(u);//Arredondar para um numero inteiro
        return u;
        //return u_int; Retorna o valor arredondado
}
