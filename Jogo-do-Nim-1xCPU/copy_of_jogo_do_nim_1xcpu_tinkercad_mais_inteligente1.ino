#define TEMPO 5 //váriavel tempo que tem o valor 5. OBS: pode ser alterado caso seja um tempo muito curto para o jogador fizer sua jogada
#define motordireita A4;
#define motoresquerda A5;
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 49
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880
// frequencies for the tones we're going to use
// used http://home.mit.bme.hu/~bako/tonecalc/tonecalc.htm to get these
const int Led01 = 2,Led02 = 3,Led03 = 4,Led04 = 5, Led05 = 6;
const int Led06 = 7, Led07 = 8, Led08 = 9,Led09 = 10;
const int Led10 = 11, Led11 = 12, Led12 = 13;

int speakerPin = A3;  
int x; //linha 1
int y; //Linha 2
int z; //Linha 3

int  stb01,stb02,stb03;
int n_linha;//sorteio da linha
int n_leds;//sorteio
bool fim_jogada=false;
int tempo_jogada=0;
bool fim=false;
bool fim_arduino=false;
bool jogou=false;
// inicio config da musica take on me:

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0




// change this to make the song slower or faster
int tempo = 140;// faz parte da música takeonme()


// change this to whichever pin you want to use




// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!


  
int melody[] = {


  // Take on me, by A-ha
  // Score available at https://musescore.com/user/190926/scores/181370
  // Arranged by Edward Truong


  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,
  
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  
  };


// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;


// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;


int divider = 0, noteDuration = 0;


//fim configuração take on me
void setup(){
   pinMode(Led01,OUTPUT);//Defini as minhas saídas
  pinMode(Led02,OUTPUT);
  pinMode(Led03,OUTPUT);
  pinMode(Led04,OUTPUT);
  pinMode(Led05,OUTPUT);
  pinMode(Led06,OUTPUT);
  pinMode(Led07,OUTPUT);
  pinMode(Led08,OUTPUT);
  pinMode(Led09,OUTPUT);
  pinMode(Led10,OUTPUT);
  pinMode(Led11,OUTPUT);
  pinMode(Led12,OUTPUT);
  pinMode(speakerPin,OUTPUT);
  digitalWrite(Led01,1);//Liguei todos os leds
  digitalWrite(Led02,1);
  digitalWrite(Led03,1);
  digitalWrite(Led04,1);
  digitalWrite(Led05,1);
  digitalWrite(Led06,1);
  digitalWrite(Led07,1);
  digitalWrite(Led08,1);
  digitalWrite(Led09,1);
  digitalWrite(Led10,1);
  digitalWrite(Led11,1);
  digitalWrite(Led12,1);
  Serial.begin(9600);
}      
           
void loop() {  
  
   // Defini os status de cada botão
   
  stb01 = analogRead(A2);
  stb02 = analogRead(A1);
  stb03 = analogRead(A0);
  
   if(stb01==1023 || stb02==1023 || stb03==1023){// se algum botao for acionado
    tempo_jogada=0;//o tempo de espera é zerado quando aperta um botão
    jogou=true;//enquanto for true ele não conta o tempo de jogada
    
    
if(stb01==1023){   
    x = x+1;
   
         if(x==1){     
        digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
         }
         else if(x==2){
        digitalWrite(Led02,0);
        tone(A3,440);  
         delay(250);
        noTone(A3);
         }
         else if(x==3){
        digitalWrite(Led03,0);
        tone(A3,440);
       delay(250);
        noTone(A3);
         }
         else if(x==4){
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
      
           }
         else if(x==5){
        digitalWrite(Led05,0);
          x=5;
           tone(A3,440);
        delay(250);
        noTone(A3);
          }
         else if(x>5){
        tone(A3,440);
        delay(900);
            noTone(A3);
            x=5;
        }
   }      
         while(stb01==1023){
        stb01 = analogRead(A2);
      
  }
  
  delay(100);
  
  
if(stb02==1023){
    y = y+1;
    
     
         if(y==1){
        digitalWrite(Led06,0);
        tone(A3,500);
        delay(300);
        noTone(A3);
        }
         else if(y==2){
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(300);
        noTone(A3);
       }
         else if(y==3){
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(300);
        noTone(A3);
       }
         else if(y==4){
        digitalWrite(Led09,0);
        tone(A3,500);
        delay(300);
        noTone(A3);
        y=4;
       }
         else if(y>4){
        tone(A3,494);
        delay(900);
           noTone(A3);
            y=4;
    }
  }
         while(stb02==1023){
        stb02 = analogRead(A1);
        
  }
    delay(100);
    
      
if(stb03==1023){
           z = z+1;
     
         if(z==1){
        digitalWrite(Led10,0);
        tone(A3,523);
        delay(300);
        noTone(A3);
        }
         else if(z==2){
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(300);
        noTone(A3);
       }
         else if(z==3){
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(300);
        noTone(A3);
           z=3;
        }
         else if(z>3){
        tone(A3,523);
        delay(900);
        noTone(A3);
            z=3;
    }
         while(stb03==1023){
        stb03 = analogRead(A0);
  }
      delay(100);
      
    }
   
  
   if((x==4 && y==4 && z==3)||(x==5 && y==3 && z==3)||(x==5 && y==4 && z==2)){
  vitoria();
     takeonme();
    
    }
   }
  
  tempo_jogada++;//vai incrementar até chegar a 5, que é o valor máximo que ta na variavel TEMPO
  Serial.print("tempo=");
  Serial.println(tempo_jogada);
  
  delay(100);
  if(tempo_jogada==TEMPO && jogou==false) // se a variavel tempo jogada atingiu o valor de TEMPO e o jogador ja fez sua jogada, tempo_jogada chega a zero e não printa mais no monitor e não incrementa
  {
   tempo_jogada=0;
  }
  
  if(tempo_jogada==TEMPO)// significa que ja foi atingido o tempo máximo de espera para o outro jogador 
  {
    Serial.println("Fim tempo jogada. Vez do Arduino");
    fim_jogada=true;// assim na próxima condição irá chamar a função arduino joga
    tempo_jogada=0;//zera o tempo_jogada para ele não incrementar 
  }
  
  if(fim_jogada==true)
  {
    fim_jogada=false;//serve para sair da condição if fim_jogada == true
    arduino_joga();//funcao que ira chamar a CPU
    jogou=false;//serve para iniciar meu contador de tempo de espera para o arduino inciar a jogada 
  } 
}


//funções : 

void vitoria(){
  analogWrite(A4, 1023);
  analogWrite(A5, 0);
  delay(250); // Wait for 1000 millisecond(s)
  analogWrite(A4, 0);
  analogWrite(A5, 0);
  
 
}

void derrota(){
  analogWrite(A5, 1023);
  analogWrite(A4, 0);
  delay(250); // Wait for 1000 millisecond(s)
  analogWrite(A5, 0);
  analogWrite(A4, 0);
  
 
}


void takeonme(){
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {


    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }


    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(speakerPin, melody[thisNote], noteDuration * 0.9);


    // Wait for the specief duration before playing the next note.
    delay(noteDuration);


    // stop the waveform generation before the next note.
    noTone(speakerPin);
     }
}
void startImperialMarch() {
    // for the sheet music see:
    // http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    // this is just a translation of said sheet music to frequencies / time in ms
    // used 500 ms for a quart note
    
   beep(speakerPin, a, 500);
    beep(speakerPin, a, 500);     
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
  
    beep(speakerPin, a, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    // first bit
    
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);
    beep(speakerPin, eH, 500);    
    beep(speakerPin, fH, 350);
    beep(speakerPin, cH, 150);
    
    beep(speakerPin, gS, 500);
    beep(speakerPin, f, 350);
    beep(speakerPin, cH, 150);
    beep(speakerPin, a, 1000);
    //second bit...
    
    beep(speakerPin, aH, 500);
    beep(speakerPin, a, 350);
    beep(speakerPin, a, 150);
    beep(speakerPin, aH, 500);
    beep(speakerPin, gSH, 350);
    beep(speakerPin, gH, 125);
    
    beep(speakerPin, fSH, 125);
    beep(speakerPin, fH, 125);    
    beep(speakerPin, fSH, 250);
    delay(250);
    beep(speakerPin, aS, 250);    
    beep(speakerPin, dSH, 500);  
    beep(speakerPin, dH, 350);  
    beep(speakerPin, cSH, 125);  
    // start of the interesting bit
    
    beep(speakerPin, cH, 125);  
    beep(speakerPin, b, 125);  
    beep(speakerPin, cH, 250);      
    delay(250);
  
    beep(speakerPin, f, 250);  
    beep(speakerPin, gS, 500);  
    beep(speakerPin, f, 375);  
    beep(speakerPin, cH, 125);
           
    beep(speakerPin, a, 500);            
    beep(speakerPin, f, 375);            
    beep(speakerPin, cH, 125);            
    beep(speakerPin, a, 1000);        
    // and we're done \ó/
  
}








void beep (int speakerPin, int frequencyInHertz, long timeInMilliseconds) {
   
    // use led to visualize the notes being played
       
    long delayAmount = (long)(1000000/frequencyInHertz);
    // the lesser delay the higher the note
  
    long timeInSeconds = timeInMilliseconds*1000;
  
    long beepDuration = (long)(timeInSeconds / (delayAmount*2));








    for (int i=0; i < beepDuration; i++) {
        analogWrite(speakerPin,1023);
        delayMicroseconds(delayAmount);
        analogWrite(speakerPin,0);
        delayMicroseconds(delayAmount);
    }      
    
   
    
    delay(20);
    // a little delay to make all notes sound separate
}      



void apaga_led1()
{
  digitalWrite(Led01,0);
  tone(A3,440);
  delay(250);
  noTone(A3);   
}




void apaga_led5()
{
  digitalWrite(Led05,0);
  tone(A3,440);
  delay(250);
  noTone(A3);   
}




void apaga_led9()
{
  digitalWrite(Led09,0);
  tone(A3,440);
  delay(250);
  noTone(A3);   
}




void apaga_led12()
{
  digitalWrite(Led12,0);
  tone(A3,440);
  delay(250);
  noTone(A3);   
}


void arduino_joga()
{
  fim_arduino=false;
  while (fim_arduino==false)//enquanto fim_arduino for false ele vai rodar seu esquema de decisões no jogo, caso seja true ele vai sair desse while
  {
      n_linha = random(1,4);//sorteia a linha 1 a 3, exclui o 4
      Serial.print("escolhi linha=");
      Serial.println(n_linha);

    
   
     if ((n_linha==1&&x==4&&y==3&&z==2)||(n_linha==2&&x==4&&y==3&&z==2)||(n_linha==3&&x==4&&y==3&&z==2)) {//QUARTA CONDIÇÃO ( fim do aleatório e começo da lógica implementada) -lembrar de testar essa lógica
    Serial.println("Vou decidir qual linha!");
    n_linha = random(1,4);
      Serial.print("Escolhi linha=");
      Serial.println(n_linha);
    
    if(n_linha==1)
    {
      apaga_led5();
      x=5;
    }
    else if(n_linha==2)
    {
      apaga_led9();
      y=4;
    }
    else
    {
      apaga_led12();
      z=3;
    }
    fim_arduino=true;
  }



//parte nova de analise: (pedro alterações)

 else if(x<4&&y==3&&z==3){//QUINTA CONDIÇÃO (não seria assim?: else if((n_linha==1||n_linha==2||n_linha==3)&&x==5&&y==3&&z==2)){
 
    if(x==0){
      //apaga 5 leds da primeria linha
        digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
      x=5;
      }
   
   else if(x==1){
      //apaga 4 leds da primeria linha
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
      x=5;
      }
    else if(x==2){
      //apaga 3 leds da primeira linha
      
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
      x=5;
      }  
      else if(x==3){
        //apaga 2 leds da primeria linha
         digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
        x=5;
        }
   
    
    fim_arduino=true;     
  }

  //2o
  else if(x<4&&y==4&&z==2){//QUINTA CONDIÇÃO (não seria assim?: else if((n_linha==1||n_linha==2||n_linha==3)&&x==5&&y==3&&z==2)){
 
    if(x==0){
      //apaga 5 leds da primeria linha
        digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
      x=5;
      }
   
   else if(x==1){
      //apaga 4 leds da primeria linha
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
      x=5;
      }
    else if(x==2){
      //apaga 3 leds da primeira linha
      
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
      x=5;
      }  
      else if(x==3){
        //apaga 2 leds da primeria linha
         digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3); 
        delay(250);
       
        digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
        x=5;
        }
   
    
    fim_arduino=true;     
  }

   else if(x==5&&y<3&&z==2){//QUINTA CONDIÇÃO (não seria assim?: else if((n_linha==1||n_linha==2||n_linha==3)&&x==5&&y==3&&z==2)){
 
    if(y==0){
      //apaga 4 leds da segunda linha
        digitalWrite(Led06,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3); 
        delay(250);
       
        
      y=4;
      }
   
   else if(y==1){
        
       //apaga 3 leds da segunda linha
        
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3); 
        delay(250);
       
        
      y=4;
      }
    else if(y==2){
       //apaga 2 leds da segunda linha
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3); 
        delay(250);
       
        
      y=4;
      }  
    
    fim_arduino=true;     
  }

else if(x==5&&y==3&&z<2){//QUINTA CONDIÇÃO (não seria assim?: else if((n_linha==1||n_linha==2||n_linha==3)&&x==5&&y==3&&z==2)){
 
    if(z==0){
      //apaga 3 leds da terceira linha
        digitalWrite(Led10,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);   
        delay(250);
        
      
       
        
      z=3;
      }
   
   else if(z==1){
        
       //apaga 2 leds da terceira linha
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);   
        delay(250);
        
      
       
        
      z=3;
      }
    
    fim_arduino=true;     
  }
    
    //parte nova
    else if(x==4&&y<3&&z==3){
 
    if(y==0){
      //apaga 4 leds da segunda linha
        digitalWrite(Led06,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);

        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
       
       
        
      y=4;
      }
   
   else if(y==1){
      //apaga 3 leds da segunda linha
        
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);

        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
       
       
        
      y=4;
      }

       else if(y==2){
      //apaga 2 leds da segunda linha
        
        
       
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);

        digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        delay(250);
        
       
       
        
      y=4;
      }
    
    fim_arduino=true;     
  }
  

  else if(x==4&&y==4&&z<2){
 
    if(z==0){
      //apaga 3 leds da terceira linha
        digitalWrite(Led10,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);   
        delay(250);
        
      
       
        
      z=3;
      }
   
   else if(z==1){
      //apaga 2 leds da terceira linha
        
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        delay(250);
        
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);   
        delay(250);
        
      
       
        
      z=3;
      }
    
    fim_arduino=true;     
  }
    
    
    //fim parte nova
  
    
   else if(x==5&&y==3&&z==2){//QUINTA CONDIÇÃO (não seria assim?: else if((n_linha==1||n_linha==2||n_linha==3)&&x==5&&y==3&&z==2)){
    
    Serial.println("Vou decidir qual linha!");
    n_linha = 3; //força tirar da linha 3
      Serial.print("Escolhi linha=");
      Serial.println(n_linha);
   
    apaga_led12();
    z=3;
    
    fim_arduino=true;     
  }
  
  else if(x==4&&y==4&&z==2){///SEXTA CONDIÇÃO    if((n_linha==1&&x==4)&&(n_linha==2&&y==4)&&(n_linha==3&&z==2))
  
    Serial.println("Vou decidir qual linha!");
    n_linha = 1; //força tirar da linha 1
      Serial.print("Escolhi linha=");
      Serial.println(n_linha);
   
    apaga_led5();
    x=5;
    
    fim_arduino=true;     
  }          
   else if(x==4&&y==3&&z==3){//SÉTIMA CONDIÇÃO   else if((n_linha==1&&x==4)&&(n_linha==2&&y==3)&&(n_linha==3&&z==3))
  
    Serial.println("Vou decidir qual linha!");
    n_linha = 2; //força tirar da linha 2
      Serial.print("Escolhi linha=");
      Serial.println(n_linha);
   
    apaga_led9();
    y=4;
    
    fim_arduino=true;     
  }
  
  else if(x==4&&y==4&&z==2)//NONA CONDIÇÃO
  {
    //escolhe entre as linhas 1 e 3
     apaga_led12();
    z=3;
    fim_arduino=true;
  }  
  
  else if(x==4&&y==4&&z==3) //DÉCIMA PRIMEIRA CONDIÇÃO
  {
    apaga_led5();
    x=5;
    //toca a musica que o jogador ganhou
  }    
  else if(x==5&&y==3&&z==3)//DÉCIMA SEGUNDA CONDIÇÃO
  {
    apaga_led9();
    y=4;
    //toca a musica
  }
  else if(x==5&&y==4&&z==2)//DÉCIMA TERCEIRA CONDIÇÃO
  {
    apaga_led12();
    z=3;
    //toca a musica
     }

     

     
  
  //se n_linha=1 e x<4
  //se n_linha=2 e y<3
  //se n_linha=3 e z<2
    
    //>> nesse próximo else if, se x for igual a 4 ele não pode sortear a primeira linha, porque tem um único led ! 
    
  else if(n_linha==1 && x<4)// <4 para a linha ser válida (PRIMEIRA CONDIÇÃO) CASO O SORTEIO GERE A PRIMEIRA LINHA ==> 
  {
    fim_arduino=true;//vai sair do while do sorteio da linha
    
    Serial.println("tirando leds da linha1");
    fim=false;
    while(fim==false)
    {
      n_leds = random(1,5-x); //sorteia até 4 no máximo
        Serial.print("n_leds:");
        Serial.println(n_leds);
        if(n_leds<(5-x)) //x=0: n_leds<5 x=1: n_leds<4  (serve para ele não tirar a linha inteira)
        {
          fim=true;
        }//fecha o if
    }//fecha o While
   
    Serial.print("vou tirar ");
    Serial.println(n_leds);
    //JÁ SABE QUANTOS LEDS PRECISA TIRAR!
    if(n_leds==1)
    {
      if(x==0)
      {
           apaga_led1();   
        x=1;
      }//fecha o if x==0
      else if(x==1)
      {
    digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        x=2;
      }//fecha o else if x==1
      else if(x==2)
      {
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        x=3;
      } //fecha o else if x==2
      else if(x==3)
      {
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        x=4;
      }  //fecha o else if x==3
      else if(x==4)
      {
    digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        x=5;
      }//fecha o else if x==4     
    }//fecha n_leds==1
    
    else if(n_leds==2)
    {
      if(x==0)
      {
    digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        x=2;
      }//fecha o if x==0
      else if(x==1)
      {
    digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        
        x=3;
      }  //fecha o else if x==1
      else if(x==2)
      {
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        
        delay(250);
        
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
        
        x=4;
      } //fecha o else if x==2
      else if(x==3)
      {
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        
        delay(250);
        
    digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        x=5;  
      }   //fecha o else if x==3       
    }//fecha n_leds==2
    else if(n_leds==3)
    {
      if(x==0)
      {
    digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        
        x=3;
      }//fecha o if x==0
      else if(x==1)
      {
    digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    




        delay(250);
        
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        x=4;
      }  //fecha o else if x==1
      else if(x==2)
      {
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   
        
        delay(250);
        
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
        
        delay(250);
        
    digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);          
        x=5;
      } //fecha o else if x==2
    } //fecha n_leds==3
  else if(n_leds==4)
    {
      if(x==0)
      {
    digitalWrite(Led01,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);   




        delay(250);
        
        digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);  
        
        x=4;
      }// fecha o if x==0
      else if(x==1)
      {
    digitalWrite(Led02,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led03,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        delay(250);
        
    digitalWrite(Led04,0);
        tone(A3,440);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led05,0);
        tone(A3,440);
        delay(250);
        noTone(A3);    
        
        x=5;
      }  //fecha o else if x==1
    }//fecha o else if n_leds==4     
  }//fecha o if n_linha==1 && x<4
    
    //>> nesse próximo else if, se y for igual a 3 ele não pode sortear a segunda linha, porque tem um único led ! 
  else if(n_linha==2 && y<3)//SEGUNDA CONDIÇÃO (caso a segunda linha seja escolhida)
  {
    fim_arduino=true;
    
    Serial.println("tirando leds da linha2");
    fim=false;
    while(fim==false)
    {
      n_leds = random(1,4-y); //1 a 4
        Serial.print("n_leds:");
        Serial.println(n_leds);
        if(n_leds<(4-y)) //y=0: n_leds<4 y=1: n_leds<3 (serve para ele não tirar a linha inteira)
        {
          fim=true;
        }//fecha o if
    }//fecha o While
   
    Serial.print("vou tirar ");
    Serial.println(n_leds);
    //já sabe quantos leds precisa tirar
    if(n_leds==1)
    {
      if(y==0)
      {
    digitalWrite(Led06,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        y=1;
      }//fecha o if y==0
      else if(y==1)
      {
    digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        y=2;
      }//fecha o else if y==1
      else if(y==2)
      {
    digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        y=3;
      } //fecha o else if y==2
      else if(y==3)
      {
    digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        y=4;
      }  //fecha o else if y==3
      else if(y==4)
      {
    digitalWrite(Led10,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        y=5;
      }//fecha o else if y==4     
    }//fecha n_leds==1
    else if(n_leds==2)
    {
      if(y==0)
      {
    digitalWrite(Led06,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
       y=2;
      }//fecha o if y==0
      else if(y==1)
      {
    digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        
        y=3;
      }  //fecha o else if y==1
      else if(y==2)
      {
    digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        
        delay(250);
        
    digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);  
        
        y=4;
      } //fecha o else if y==2       
    }//fecha n_leds==2
    else if(n_leds==3)
    {
      if(y==0)
      {
    digitalWrite(Led06,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);   
        
        y=3;
      }//fecha o if y==0
      else if(y==1)
      {
    digitalWrite(Led07,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led08,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    




        delay(250);
        
    digitalWrite(Led09,0);
        tone(A3,494);
        delay(250);
        noTone(A3);
        
        y=4;
      }  //fecha o else if y==1
    } //fecha n_leds==3   
  }//fecha o if n_linha==2 && y<4
    
    //>> nesse próximo else if, se z for igual a 2 ele não pode sortear a primeira linha, porque tem um único led ! 
  else if(n_linha==3 && z<2)//TERCEIRA CONDIÇÃO(caso a terceira linha seja escolhida)
  {
    fim_arduino=true;
    
    Serial.println("tirando leds da linha3");
    fim=false;
    while(fim==false)
    {
      n_leds = random(1,3-z); //1 a 3
        Serial.print("n_leds:");
        Serial.println(n_leds);
        if(n_leds<(3-z)) //z=0: n_leds<3 y=1: n_leds<2 (serve para ele não tirar a linha inteira)
        {
          fim=true;
        }//fecha o if
    }//fecha o While
   
    Serial.print("vou tirar ");
    Serial.println(n_leds);
    //já sabe quantos leds precisa tirar
    if(n_leds==1)
    {
      if(z==0)
      {
    digitalWrite(Led10,0);
        tone(A3,523);
        delay(250);
        noTone(A3);    
        z=1;
      }//fecha o if z==0
      else if(z==1)
      {
    digitalWrite(Led11,0);
        tone(A3,494);
        delay(250);
        noTone(A3);    
        z=2;
      }//fecha o else if z==1
      else if(z==2)
      {
    digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);    
        y=3;
      } //fecha o else if z==2
     
    }//fecha n_leds==1
    else if(n_leds==2)
    {
      if(z==0)
      {
    digitalWrite(Led10,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        
       z=2;
      }//fecha o if z==0
      else if(z==1)
      {
    digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        
        delay(250);
        
    digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);    
        
        z=3;
      }  //fecha o else if z==1
           
    }//fecha n_leds==2
    else if(n_leds==3)
    {
      if(z==0)
      {
    digitalWrite(Led10,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led11,0);
        tone(A3,523);
        delay(250);
        noTone(A3);
        
        delay(250);
        
        digitalWrite(Led12,0);
        tone(A3,523);
        delay(250);
        noTone(A3);   
        
        z=3;
      }//fecha o if z==0
    } //fecha n_leds==3      
  } //fecha n_linha==3 && z<3
  

  
  }//fecha o while fim_arduino
  
  if((x==4 && y==4 && z==3)||(x==5 && y==3 && z==3)||(x==5 && y==4 && z==2)){//Pessoa perdeu
  derrota();
    startImperialMarch();
    }
}//fecha arduino joga