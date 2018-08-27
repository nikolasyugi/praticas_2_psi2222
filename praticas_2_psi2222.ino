/*********************************************************************************
 *                ESCOLA POLITÉCNICA DA UNIVERSIDADE DE SÃO PAULO                *
 *                                                                               *
 *               PSI2222 - Práticas de Eletricidade e Eletrônica II              *
 *              Prof. Ronaldo Mansano / Prof. Julio Cesar dos Santos             *
 *                         João Otávio Ukstin - 8588115                          *
 *                         Letícia Alves Chijo - 8587837                         *
 *                         Nikolas Yugi Athanasopoulos - 8587862                 *   
 *                         Pedro Afonso Jaloto - 8588460                         *
 *                                                                               * 
 *********************************************************************************/

#include <Wire.h>

/* Função para acender o led quando o botão for pressionado e apagá-lo quando o botão for pressionado novamente */

void on_off(int *est,int *estAnt,int *saidas,int leds,int botoes, int *turno){
  
  /* foram utilizados ponteiros para chamar pelo endereço das variáveis e não o valor delas */
  // est -> lê o estado do botão, no caso est=0 significa botão apertado, pois o botão é PULL-UP
  // estAnt -> armazena o estado anterior do botão
  // saidas -> indica se o led acenderá ou apagará
  // leds -> pino do led associado ao botão
  // botoes -> pino do botão
  // turno -> contagem de turno
  
  *est=digitalRead(botoes); //lê o botão

  if ( *est==0 && *estAnt==0)   // só mudará o estado do led na transição do botão de não apertado para apertado 

  { *turno=1-*turno; //troca o turno
    *saidas=1-*saidas; //inverte o estado do led
    delay(20);  //de-bouncing
  }

  *estAnt=1-*est; //armazena o estado anterior do botão

  if( *saidas==1)

  {
    digitalWrite(leds, HIGH); // led on

  }

  else{
    digitalWrite(leds,LOW); // led off


  }}
  
/* Função utilizada para contar os pontos no display de 7 segmentos */

void comunica(byte endereco, byte digito)
{
  Wire.beginTransmission(endereco);
  Wire.write(digito);
  Wire.endTransmission();
}


/* Pinos dos pares botão-led */

#define botao 13
#define led 12

#define botao_1 11
#define led_1 10

#define botao_2 9
#define led_2 8

#define botao_3 7
#define led_3 6

#define botao_4 5
#define led_4 4

#define botao_5 3
#define led_5 2

#define botao_6 14
#define led_6 15


/*

#define botao_7 13
#define led_7 12

#define botao_8 11
#define led_8 10

#define botao_9 9
#define led_9 8

#define botao_10 7
#define led_10 6

#define botao_11 5
#define led_11 4

#define botao_12 5
#define led_12 4

#define botao_13 14
#define led_13 15

#define botao_14 13
#define led_14 12

#define botao_15 11
#define led_15 10

#define botao_16 7
#define led_16 6

#define botao_17 5
#define led_17 4

#define botao_18 14
#define led_18 15

#define botao_19 14
#define led_19 15

#define botao_20 13
#define led_20 12

#define botao_21 11
#define led_21 10

#define botao_22 7
#define led_22 6

#define botao_23 5
#define led_23 4


*/


/* Pinos dos leds que acenderão no meio dos quadrados */

#define qdo_azul 32
#define qdo_azul_1 28

/*

#define qdo_azul_2 32
#define qdo_azul_3 28
#define qdo_azul_4 32
#define qdo_azul_5 28
#define qdo_azul_6 32
#define qdo_azul_7 32
#define qdo_azul_8 32

*/


#define qdo_verm 55
#define qdo_verm_1 54


/*

#define qdo_verm_2 55
#define qdo_verm_3 54
#define qdo_verm_4 55
#define qdo_verm_5 54
#define qdo_verm_6 55
#define qdo_verm_7 54
#define qdo_verm_8 55

*/


/* Pinos dos dois leds de contagem de turnos */

#define turno1 64
#define turno2 67

/* Pino do buzzer */

#define buzzer 52

/* Sinônimos para usar na comunicação I2C */

#define expansor1 0x38 // primeiro endereço é o 38 em hexadecimal
#define expansor2 0x39 // segundo endereço é o 39 em hexadecimal

/* Variáveis para utilizar na função on_off */

int estado= 0;
int estado_Anterior = 0;
int saida=0;


int estado_1= 0;
int estado_Anterior_1 = 0;
int saida_1=0;

int estado_2= 0;
int estado_Anterior_2 = 0;
int saida_2=0;

int estado_3= 0;
int estado_Anterior_3 = 0;
int saida_3=0;

int estado_4= 0;
int estado_Anterior_4 = 0;
int saida_4=0;

int estado_5= 0;
int estado_Anterior_5 = 0;
int saida_5=0;

int estado_6= 0;
int estado_Anterior_6 = 0;
int saida_6=0;

/*

int estado_7= 0;
int estado_Anterior_7 = 0;
int saida_7=0;


int estado_8= 0;
int estado_Anterior_8 = 0;
int saida_8=0;

int estado_9= 0;
int estado_Anterior_9 = 0;
int saida_9=0;

int estado_10= 0;
int estado_Anterior_10 = 0;
int saida_10=0;

int estado_11= 0;
int estado_Anterior_11 = 0;
int saida_11=0;

int estado_12= 0;
int estado_Anterior_12 = 0;
int saida_12=0;

int estado_13= 0;
int estado_Anterior_13 = 0;
int saida_13=0;

int estado_14= 0;
int estado_Anterior_14 = 0;
int saida_14=0;


int estado_15= 0;
int estado_Anterior_15 = 0;
int saida_15=0;

int estado_16= 0;
int estado_Anterior_16 = 0;
int saida_16=0;

int estado_17= 0;
int estado_Anterior_17 = 0;
int saida_17=0;

int estado_18= 0;
int estado_Anterior_18 = 0;
int saida_18=0;

int estado_19= 0;
int estado_Anterior_19 = 0;
int saida_19=0;

int estado_20= 0;
int estado_Anterior_20 = 0;
int saida_20=0;

int estado_21= 0;
int estado_Anterior_21 = 0;
int saida_21=0;

int estado_22= 0;
int estado_Anterior_22 = 0;
int saida_22=0;

int estado_23= 0;
int estado_Anterior_23 = 0;
int saida_23=0;

*/

/* Booleans para saber se já fechou o quadrado x */

boolean flag=false;
boolean flag_1=false;

/*

boolean flag_2=false;
boolean flag_3=false;
boolean flag_4=false;
boolean flag_5=false;
boolean flag_6=false;
boolean flag_7=false;
boolean flag_8=false;

*/

/* Contador para saber de quem é a vez, vale 1 ou 0 */

int turno=0;

/* Contadores para saber se fechou algum quadrado na rodada ou não */

int i=0;
int j=0;

/* Contagem de Pontos */

int player_1=0;
int player_2=0;

int a=5; //inteiro para usar como contador no final do jogo

void setup()
{ 
  // inicializar comunicação I2C
  Wire.begin();
  comunica(expansor1, 0xFF);
  comunica(expansor2, 0xFF);
  
  // declarar pinos dos botões como entrada-pull-up
  pinMode(botao, INPUT_PULLUP);
  pinMode(botao_1, INPUT_PULLUP);
  pinMode(botao_2, INPUT_PULLUP);
  pinMode(botao_3, INPUT_PULLUP);
  pinMode(botao_4, INPUT_PULLUP);
  pinMode(botao_5, INPUT_PULLUP);
  pinMode(botao_6, INPUT_PULLUP);
  
  /*
  
  pinMode(botao_7, INPUT_PULLUP);
  pinMode(botao_8, INPUT_PULLUP);
  pinMode(botao_9, INPUT_PULLUP);
  pinMode(botao_10, INPUT_PULLUP);
  pinMode(botao_11, INPUT_PULLUP);
  pinMode(botao_12, INPUT_PULLUP);
  pinMode(botao_13, INPUT_PULLUP);
  pinMode(botao_14, INPUT_PULLUP);
  pinMode(botao_15, INPUT_PULLUP);
  pinMode(botao_16, INPUT_PULLUP);
  pinMode(botao_17, INPUT_PULLUP);
  pinMode(botao_18, INPUT_PULLUP);
  pinMode(botao_19, INPUT_PULLUP);
  pinMode(botao_20, INPUT_PULLUP);
  pinMode(botao_21, INPUT_PULLUP);
  pinMode(botao_22, INPUT_PULLUP);
  pinMode(botao_23, INPUT_PULLUP);
  
  */
  
  //declarar pinos dos leds associados aos botões como saída
  pinMode(led, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  
  /*
  
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);
  pinMode(led_9, OUTPUT);
  pinMode(led_10, OUTPUT);
  pinMode(led_11, OUTPUT);
  pinMode(led_12, OUTPUT);
  pinMode(led_13, OUTPUT);
  pinMode(led_14, OUTPUT);
  pinMode(led_15, OUTPUT);
  pinMode(led_16, OUTPUT);
  pinMode(led_17, OUTPUT);
  pinMode(led_18, OUTPUT);
  pinMode(led_19, OUTPUT);
  pinMode(led_20, OUTPUT);
  pinMode(led_21, OUTPUT);
  pinMode(led_22, OUTPUT);
  pinMode(led_23, OUTPUT);
  
  */
  
  //declarar pinos dos leds que acenderão no meio dos quadrados como saída
  pinMode(qdo_azul, OUTPUT);
  pinMode(qdo_azul_1, OUTPUT);
  
  /*
  
  pinMode(qdo_azul_2, OUTPUT);
  pinMode(qdo_azul_3, OUTPUT);
  pinMode(qdo_azul_4, OUTPUT);
  pinMode(qdo_azul_5, OUTPUT);
  pinMode(qdo_azul_6, OUTPUT);
  pinMode(qdo_azul_7, OUTPUT);
  pinMode(qdo_azul_8, OUTPUT);
  
  */
  
  pinMode(qdo_verm, OUTPUT);
  pinMode(qdo_verm_1, OUTPUT);
  
  /*
  
  pinMode(qdo_verm_2, OUTPUT);
  pinMode(qdo_verm_3, OUTPUT);
  pinMode(qdo_verm_4, OUTPUT);
  pinMode(qdo_verm_5, OUTPUT);
  pinMode(qdo_verm_6, OUTPUT);
  pinMode(qdo_verm_7, OUTPUT);
  pinMode(qdo_verm_8, OUTPUT);
  
  */

  //inicializar com todos leds apagados
  digitalWrite(led,LOW);
  digitalWrite(led_1,LOW);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
  digitalWrite(led_5,LOW);
  digitalWrite(led_6,LOW);
  
  /*
  
  digitalWrite(led_7,LOW);
  digitalWrite(led_8,LOW);
  digitalWrite(led_9,LOW);
  digitalWrite(led_10,LOW);
  digitalWrite(led_11,LOW);
  digitalWrite(led_12,LOW);
  digitalWrite(led_13,LOW);
  digitalWrite(led_14,LOW);
  digitalWrite(led_15,LOW);
  digitalWrite(led_16,LOW);
  digitalWrite(led_17,LOW);
  digitalWrite(led_18,LOW);
  digitalWrite(led_19,LOW);
  digitalWrite(led_20,LOW);
  digitalWrite(led_21,LOW);
  digitalWrite(led_22,LOW);
  digitalWrite(led_23,LOW);
  
  */

  digitalWrite(qdo_azul,LOW);
  digitalWrite(qdo_azul_1,LOW);
  
  /*
  
  digitalWrite(qdo_azul_2,LOW);
  digitalWrite(qdo_azul_3,LOW);
  digitalWrite(qdo_azul_4,LOW);
  digitalWrite(qdo_azul_5,LOW);
  digitalWrite(qdo_azul_6,LOW);
  digitalWrite(qdo_azul_7,LOW);
  digitalWrite(qdo_azul_8,LOW);
  
  */
  
  digitalWrite(qdo_verm, LOW);
  digitalWrite(qdo_verm_1, LOW);
  
  /*
  
  digitalWrite(qdo_verm_2, LOW);
  digitalWrite(qdo_verm_3, LOW);
  digitalWrite(qdo_verm_4, LOW);
  digitalWrite(qdo_verm_5, LOW);
  digitalWrite(qdo_verm_6, LOW);
  digitalWrite(qdo_verm_7, LOW);
  digitalWrite(qdo_verm_8, LOW);
  
  */
  
  //iniciar com led azul de turno aceso, ou seja, player 1 sempre começa
  pinMode(turno1,OUTPUT);
  digitalWrite(turno1,HIGH);
  pinMode(turno2,OUTPUT);
  digitalWrite(turno2,LOW);

  //declarar buzzer como saída e inicializar com ele desligado
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
}

void loop()
{  
    if (turno==1){                        //LEDs de Contagem de Turnos
  digitalWrite(turno2,HIGH); //vermelho liga
  digitalWrite(turno1,LOW);  //azul apaga
  }
  
  else{
  digitalWrite(turno1,HIGH); //azul liga
  digitalWrite(turno2,LOW);  //vermelho apaga
  }
  
  /* Chamar a função on_off para quando for apertado qualquer botão, acender o led associado, ou apagá-lo */
  
  on_off(&estado,&estado_Anterior,&saida,led,botao,&turno);
  on_off(&estado_1,&estado_Anterior_1,&saida_1,led_1,botao_1,&turno);
  on_off(&estado_2,&estado_Anterior_2,&saida_2,led_2,botao_2,&turno);
  on_off(&estado_3,&estado_Anterior_3,&saida_3,led_3,botao_3,&turno);
  on_off(&estado_4,&estado_Anterior_4,&saida_4,led_4,botao_4,&turno);
  on_off(&estado_5,&estado_Anterior_5,&saida_5,led_5,botao_5,&turno);
  on_off(&estado_6,&estado_Anterior_6,&saida_6,led_6,botao_6,&turno);
  
  /*
  
  on_off(&estado_7,&estado_Anterior_7,&saida_7,led_7,botao_7,&turno);
  on_off(&estado_8,&estado_Anterior_8,&saida_8,led_8,botao_8,&turno);
  on_off(&estado_9,&estado_Anterior_9,&saida_9,led_9,botao_9,&turno);
  on_off(&estado_10,&estado_Anterior_10,&saida_10,led_10,botao_10,&turno);
  on_off(&estado_11,&estado_Anterior_11,&saida_11,led_11,botao_11,&turno);
  on_off(&estado_12,&estado_Anterior_12,&saida_12,led_12,botao_12,&turno);
  on_off(&estado_13,&estado_Anterior_13,&saida_13,led_13,botao_13,&turno);
  on_off(&estado_14,&estado_Anterior_14,&saida_14,led_14,botao_14,&turno);
  on_off(&estado_15,&estado_Anterior_15,&saida_15,led_15,botao_15,&turno);
  on_off(&estado_16,&estado_Anterior_16,&saida_16,led_16,botao_16,&turno);
  on_off(&estado_17,&estado_Anterior_17,&saida_17,led_17,botao_17,&turno);
  on_off(&estado_18,&estado_Anterior_18,&saida_18,led_18,botao_18,&turno);
  on_off(&estado_19,&estado_Anterior_19,&saida_19,led_19,botao_19,&turno);
  on_off(&estado_20,&estado_Anterior_20,&saida_20,led_20,botao_20,&turno);
  on_off(&estado_21,&estado_Anterior_21,&saida_21,led_21,botao_21,&turno);
  on_off(&estado_22,&estado_Anterior_22,&saida_22,led_22,botao_22,&turno);
  on_off(&estado_23,&estado_Anterior_23,&saida_23,led_23,botao_23,&turno);
  */


  
 /*   QUADRADO 0   */
 
//quadrado(&saida,&saida_4,&saida_5, &saida_6,&turno, flag,buzzer,qdo_azul,qdo_verm,&j,&player_1,&player_2);
 
  if (saida==1 && saida_4==1 && saida_5==1 && saida_6==1 && turno==1 && flag==false){ //se os 4 botoes estiverem ligados e o flag, que indica se já foi fechado esse quadrado, estiver em false, o if é executado
    digitalWrite(qdo_azul,HIGH); // quadrado fechado -> acende led no meio
    flag=true; // flag fica true pois o quadrado já foi fechado
    j+=1; // como um quadrado foi fechado, o contador é incrementado
    player_1+=1; // player ganha 1 ponto
    digitalWrite(buzzer,HIGH); //buzzer emite um som
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida==1 && saida_4==1 && saida_5==1 && saida_6==1 && turno==0 && flag==false){
    digitalWrite(qdo_verm,HIGH);
    flag=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida==0 || saida_4==0 || saida_5==0 || saida_6==0){ //se algum dos 4 botoes for apagado, é necessário voltar o flag para false e apagar os leds que acendem no meio dos quadrados
    digitalWrite(qdo_azul,LOW);
    digitalWrite(qdo_verm,LOW);
    flag=false;
  }

/*   QUADRADO 1   */

//quadrado(&saida_1, &saida_2,&saida_3, &saida_6,&turno, flag_1,buzzer,qdo_azul_1, qdo_verm_1,&j,&player_1,&player_2);

  if (saida_1==1 && saida_2==1 && saida_3==1 && saida_6==1 && turno==1 && flag_1==false){
    digitalWrite(qdo_azul_1,HIGH);
    flag_1=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_1==1 && saida_2==1 && saida_3==1 && saida_6==1 && turno==0 && flag_1==false){
    digitalWrite(qdo_verm_1,HIGH);
    flag_1=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_1==0 || saida_2==0 || saida_3==0 || saida_6==0){
    digitalWrite(qdo_azul_1,LOW);
    digitalWrite(qdo_verm_1,LOW);
    flag_1=false; 
  }
  
/* *   QUADRADO 2   *

  if (saida_3==1 && saida_4==1 && saida_20==1 && saida_13==1 && turno==1 && flag_2==false){
    digitalWrite(qdo_azul_2,HIGH);
    flag_2=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_3==1 && saida_4==1 && saida_20==1 && saida_13==1 && turno==0 && flag_2==false){
    digitalWrite(qdo_verm_2,HIGH);
    flag_2=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_3==0 || saida_4==0 || saida_20==0 || saida_13==0){
    digitalWrite(qdo_azul_2,LOW);
    digitalWrite(qdo_verm_2,LOW);
    flag_2=false;
  }

   *   QUADRADO 3   *

  if (saida_20==1 && saida_5==1 && saida_14==1 && saida_21==1 && turno==1 && flag_3==false){
    digitalWrite(qdo_azul_3,HIGH);
    flag_3=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_20==1 && saida_5==1 && saida_14==1 && saida_21==1 && turno==0 && flag_3==false){
    digitalWrite(qdo_verm_3,HIGH);
    flag_3=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_20==0 || saida_5==0 || saida_14==0 || saida_21==0){
    digitalWrite(qdo_azul_3,LOW);
    digitalWrite(qdo_verm_3,LOW);
    flag_3=false;
  }
  

 *   QUADRADO 4   *

  if (saida_14==1 && saida_15==1 && saida_19==1 && saida_22==1 && turno==1 && flag_4==false){
    digitalWrite(qdo_azul_4,HIGH);
    flag_4=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_14==1 && saida_15==1 && saida_19==1 && saida_22==1 && turno==0 && flag_4==false){
    digitalWrite(qdo_verm_4,HIGH);
    flag_4=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_14==0 || saida_15==0 || saida_19==0 || saida_22==0){
    digitalWrite(qdo_azul_4,LOW);
    digitalWrite(qdo_verm_4,LOW);
    flag_4=false;
  }
  

*   QUADRADO 5   *

  if (saida_11==1 && saida_15==1 && saida_18==1 && saida_23==1 && turno==1 && flag_5==false){
    digitalWrite(qdo_azul_5,HIGH);
    flag_5=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_11==1 && saida_15==1 && saida_18==1 && saida_23==1 && turno==0 && flag_5==false){
    digitalWrite(qdo_verm_5,HIGH);
    flag_5=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_11==0 || saida_15==0 || saida_18==0 || saida_23==0){
    digitalWrite(qdo_azul_5,LOW);
    digitalWrite(qdo_verm_5,LOW);
    flag_5=false;
  }
  

*   QUADRADO 6   *

  if (saida_9==1 && saida_10==1 && saida_16==1 && saida_23==1 && turno==1 && flag_6==false){
    digitalWrite(qdo_azul_6,HIGH);
    flag_6=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_9==1 && saida_10==1 && saida_16==1 && saida_23==1 && turno==0 && flag_6==false){
    digitalWrite(qdo_verm_6,HIGH);
    flag_6=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_9==0 || saida_10==0 || saida_16==0 || saida_23==0){
    digitalWrite(qdo_azul_6,LOW);
    digitalWrite(qdo_verm_6,LOW);
    flag_6=false;
  }
  

*   QUADRADO 7   *

  if (saida_8==1 && saida_16==1 && saida_17==1 && saida_22==1 && turno==1 && flag_7==false){
    digitalWrite(qdo_azul_7,HIGH);
    flag_7=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_8==1 && saida_16==1 && saida_17==1 && saida_22==1 && turno==0 && flag_7==false){
    digitalWrite(qdo_verm_7,HIGH);
    flag_7=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_8==0 || saida_16==0 || saida_17==0 || saida_22==0){
    digitalWrite(qdo_azul_7,LOW);
    digitalWrite(qdo_verm_7,LOW);
    flag_7=false;
  }
  

*   QUADRADO 8   *

  if (saida_6==1 && saida_7==1 && saida_17==1 && saida_21==1 && turno==1 && flag_8==false){
    digitalWrite(qdo_azul_8,HIGH);
    flag_8=true;
    j+=1;
    player_1+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if (saida_6==1 && saida_7==1 && saida_17==1 && saida_21==1 && turno==0 && flag_8==false){
    digitalWrite(qdo_verm_8,HIGH);
    flag_8=true;
    j+=1;
    player_2+=1;
    digitalWrite(buzzer,HIGH);
    delay(200);
    digitalWrite(buzzer,LOW);
  }
  if(saida_6==0 || saida_7==0 || saida_17==0 || saida_21==0){
    digitalWrite(qdo_azul_8,LOW);
    digitalWrite(qdo_verm_8,LOW);
    flag_8=false;
  }
  
*/

if (i!=j){                  // se fechou algum quadrado, o jogador continua jogando
    turno=1-turno;
  }
  
j=i; // atualizar o valor de j para fazer de novo a comparação no próxima vez que rodar o laço


/* Contagem de Pontos no display de 7 segmentos */

/* Jogador 2 */

if (player_1==0)
  {
  comunica(expansor1,B10000001); // O binário dentro dos parênteses representa respectivamente os leds (g,f,a,b,e,d,c,ponto) do display de 7 segmentos
  }

  if (player_1==1)
  {
  comunica(expansor1,B11101101);
  }

  if (player_1==2)
  {
  comunica(expansor1,B01000011);
  }

  if (player_1==3)
  {
  comunica(expansor1,B01001001);
  }

  if (player_1==4)
  {
  comunica(expansor1,B00101101);
  }

  if (player_1==5)
  {
  comunica(expansor1,B00011001);
  }

  if (player_1==6)
  {
  comunica(expansor1,B00010001);
  }

  if (player_1==7)
  {
  comunica(expansor1,B11001101);
  }

  if (player_1==8)
  {
  comunica(expansor1,0x01);
  }

  if (player_1==9)
  {
  comunica(expansor1,B00001001);
  }
  

/* Jogador 2 */

if (player_2==0)
  {
  comunica(expansor1,B10000001); // O binário dentro dos parênteses representa respectivamente os leds (g,f,a,b,e,d,c,ponto) do display de 7 segmentos
  }

  if (player_2==1)
  {
  comunica(expansor1,B11101101);
  }

  if (player_2==2)
  {
  comunica(expansor1,B01000011);
  }

  if (player_2==3)
  {
  comunica(expansor1,B01001001);
  }

  if (player_2==4)
  {
  comunica(expansor1,B00101101);
  }

  if (player_2==5)
  {
  comunica(expansor1,B00011001);
  }

  if (player_2==6)
  {
  comunica(expansor1,B00010001);
  }

  if (player_2==7)
  {
  comunica(expansor1,B11001101);
  }

  if (player_2==8)
  {
  comunica(expansor1,0x01);
  }

  if (player_2==9)
  {
  comunica(expansor1,B00001001);
  }
  
if (player_1+player_2==9 && a>0) // no fim do jogo piscar todos os leds do jogo
  { if (a==5)
    {
      delay(500); // na primeira vez demorar um pouco para começar a piscar os leds
    } 
    digitalWrite(led,LOW);
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
    digitalWrite(led_4,LOW);
    digitalWrite(led_5,LOW);
    digitalWrite(led_6,LOW);
    
      /*
    
    digitalWrite(led_7,LOW);
    digitalWrite(led_8,LOW);
    digitalWrite(led_9,LOW);
    digitalWrite(led_10,LOW);
    digitalWrite(led_11,LOW);
    digitalWrite(led_12,LOW);
    digitalWrite(led_13,LOW);
    digitalWrite(led_14,LOW);
    digitalWrite(led_15,LOW);
    digitalWrite(led_16,LOW);
    digitalWrite(led_17,LOW);
    digitalWrite(led_18,LOW);
    digitalWrite(led_19,LOW);
    digitalWrite(led_20,LOW);
    digitalWrite(led_21,LOW);
    digitalWrite(led_22,LOW);
    digitalWrite(led_23,LOW);
    
    */
    
    digitalWrite(qdo_azul,LOW);
    digitalWrite(qdo_azul_1,LOW);
    
    /*
    
    digitalWrite(qdo_azul_2,LOW);
    digitalWrite(qdo_azul_3,LOW);
    digitalWrite(qdo_azul_4,LOW);
    digitalWrite(qdo_azul_5,LOW);
    digitalWrite(qdo_azul_6,LOW);
    digitalWrite(qdo_azul_7,LOW);
    digitalWrite(qdo_azul_8,LOW);
    
    */
    
    digitalWrite(qdo_verm,LOW);
    digitalWrite(qdo_verm_1,LOW);
      
    /*
    
    digitalWrite(qdo_verm_2, LOW);
    digitalWrite(qdo_verm_3, LOW);
    digitalWrite(qdo_verm_4, LOW);
    digitalWrite(qdo_verm_5, LOW);
    digitalWrite(qdo_verm_6, LOW);
    digitalWrite(qdo_verm_7, LOW);
    digitalWrite(qdo_verm_8, LOW);
    
    */
    
    digitalWrite(buzzer,LOW);
    
    digitalWrite(turno1,LOW);
    digitalWrite(turno2,LOW);
    
    delay(500);
    
    digitalWrite(turno1,HIGH);
    digitalWrite(turno2,HIGH);
    
    digitalWrite(buzzer,HIGH);
    
    digitalWrite(led,HIGH);
    digitalWrite(led_1,HIGH);
    digitalWrite(led_2,HIGH);
    digitalWrite(led_3,HIGH);
    digitalWrite(led_4,HIGH);
    digitalWrite(led_5,HIGH);
    digitalWrite(led_6,HIGH);
     
      /*
    
    digitalWrite(led_7,HIGH);
    digitalWrite(led_8,HIGH);
    digitalWrite(led_9,HIGH);
    digitalWrite(led_10,HIGH);
    digitalWrite(led_11,HIGH);
    digitalWrite(led_12,HIGH);
    digitalWrite(led_13,HIGH);
    digitalWrite(led_14,HIGH);
    digitalWrite(led_15,HIGH);
    digitalWrite(led_16,HIGH);
    digitalWrite(led_17,HIGH);
    digitalWrite(led_18,HIGH);
    digitalWrite(led_19,HIGH);
    digitalWrite(led_20,HIGH);
    digitalWrite(led_21,HIGH);
    digitalWrite(led_22,HIGH);
    digitalWrite(led_23,HIGH);
    
    */
    
    if (player_1>player_2){          // se o jogador 1 ganhar
    digitalWrite(qdo_azul,HIGH);
    digitalWrite(qdo_azul_1,HIGH);
    /*
    
    digitalWrite(qdo_azul_2,HIGH);
    digitalWrite(qdo_azul_3,HIGH);
    digitalWrite(qdo_azul_4,HIGH);
    digitalWrite(qdo_azul_5,HIGH);
    digitalWrite(qdo_azul_6,HIGH);
    digitalWrite(qdo_azul_7,HIGH);
    digitalWrite(qdo_azul_8,HIGH);
    
    */}
    
    if (player_2>player_1){          // se o jogador 2 ganhar
    digitalWrite(qdo_verm,HIGH);
    digitalWrite(qdo_verm_1,HIGH);     
    /*
    
    digitalWrite(qdo_verm_2, HIGH);
    digitalWrite(qdo_verm_3, HIGH);
    digitalWrite(qdo_verm_4, HIGH);
    digitalWrite(qdo_verm_5, HIGH);
    digitalWrite(qdo_verm_6, HIGH);
    digitalWrite(qdo_verm_7, HIGH);
    digitalWrite(qdo_verm_8, HIGH);
    
    */}
    
    delay(500);
    
    if (a==1) // na última vez desligar o buzzer
    {
    digitalWrite(buzzer,LOW);
    }
    a-=1;
  }

}

