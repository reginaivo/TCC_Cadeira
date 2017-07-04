//Sintonia do controlador PID utilizando PSO

#include"fitness.c"

float * pso(float phi_sp, float phi){

int n,dim,i,j,k,bird_step,threshold;//threshold - valor aceitavel para a função fitness
float w,c1,c2,err,r1,r2;
float x[n][dim], v[n][dim], fitness_atual[n][dim],local_best_fitness[n][dim],gbest[n][dim],pbest[n][dim];

//-------------Inicialização------------------------//
n = 10;           //Tamanho da população
bird_step  = 100;  //Maximo numero de iterações
c2 =2.05;          //constante do componente cognitivo
c1 = 2.05;         //constante do componente social
dim = 3; //Dimensão do problema

//Geração da população
srand(time(NULL));

//Inicializa a posição e a velocidade das partículas com valores aleatórios
for ( i=0; i<n; i++ ){
    for ( j=0; j<dim; j++ )
    {
        v[i][j] = (rand() % 1000);//Matriz de valores aleatórios de 0 a 1000
        v[i][j] /= 1000;
        x[i][j] = (rand() % 1000);//Matriz de valores aleatórios de 0 a 1000
        x[i][j] /= 1000;

        }
}

//pbest[j] = x[j];

//gbest[j] = pbest[j];

//---------------Programa Principal-----------------------------//
k = 0;
//for ( k=0; k<bird_step; k++ ){
//while((k < bird_step) && (fitness < threshold)){
while(k < bird_step){

        //Calcula a função custo para todas as partículas
        for(i = 0; i < n; i++){
             for(j = 0; j < dim; j++){
                        fitness_atual[i][j] = fitness(x[i][j],phi_sp,phi);
                }
        }

        //Calcula se a nova posição melhora a função custo anterior
        for(i = 0; i < n; i++){
                for(j = 0; j < dim; j++){
                        if (fitness_atual[i][j] < local_best_fitness[i][j]){
                                local_best_fitness[i][j]  = fitness_atual[i][j];
                                pbest[i][j] = x[i][j];
                        }
                }
        }
        //Calcula a posição do melhor indivíduo do enxame
        for(i = 0; i < n; i++){
                for(j = 0; j < dim; j++){
                        if ( gbest[i][j] > local_best_fitness[i][j]){
                                gbest[i][j] = local_best_fitness[i][j];//verificar dimensoes do gbest
                        }
                }
        }


        w = (0.8/bird_step*k + 0.9);//Momento de inercia do sistema

        //Atualização da velocidade e da posição
        for(i = 0; i < n; i++){
                for(j = 0; j < dim; j++){

                        r1 = (rand() % 100);
                        r2 = (rand() % 100);
                        r1 /=100;
                        r2 /=100;
                        v[i][j] = (w*v[i][j] + c1*r1*(pbest[i][j]-x[i][j]) + c2*r2*(gbest[i][j]-x[i][j]));
                        x[i][j] +=  v[i][j];
                }
        }
k++;
}

return *gbest;// Contém os valores otimizados de kp,ki,kd;
}
