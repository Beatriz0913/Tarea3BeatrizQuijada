// Beatriz Quijada 61851282

class Led{
public:
  Led(int _pin){
  	pin=_pin;
    pinMode(pin, OUTPUT);
  }

  bool cambiarEstado(bool estado){
    if(estado){
    	digitalWrite(pin, HIGH);
      	delay(70);
    }else{
    	digitalWrite(pin,LOW);
      	delay(50);
    }
  }
private:
  int pin;
};

class Botton{
	public:
  	  Botton(int _pin){
  		pin=_pin;
  	  }
  

  bool tocarbotton(){
    if(digitalRead(pin)){     
      return 1;
    }else{
      return 0;
    }
  
  
 
  }
  private:
  	int pin;
};

Led luzVerde(13);
Led luzRoja(7);
Botton bottonIncremento(4);
Botton bottonDecremento(2);
int cont =0; 

void setup()
{
Serial.begin(9600); 

}


void loop()
{
	
   if(bottonIncremento.tocarbotton()){
  		luzVerde.cambiarEstado(1);
     		cont ++;
    		 Serial.println(cont);
     			delay(100);
  	}else if(bottonDecremento.tocarbotton()){
    		luzRoja.cambiarEstado(1);
    		 cont --;
    		  Serial.println(cont);
     			delay(100);
  		}else{ 			
     		  luzRoja.cambiarEstado(0);
    			luzVerde.cambiarEstado(0);
     				Serial.println(cont);
    				
  }
}

