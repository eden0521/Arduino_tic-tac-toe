#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
int counter=0;
char input;	// input: 1 ~ 9
int innum=-1;

int tempstate[]={0,0,0,0,0,0,0,0,0,0};
Adafruit_NeoPixel strip888 = Adafruit_NeoPixel(1, 12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(1, 3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(1, 4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(1, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(1, 7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip9 = Adafruit_NeoPixel(1, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip10 = Adafruit_NeoPixel(1, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip11 = Adafruit_NeoPixel(1, 11, NEO_GRB + NEO_KHZ800);

int checkwin(int num){
	int boo=0;
	if( tempstate[0]==num && (tempstate[0]==tempstate[1] && tempstate[1]==tempstate[2]) ){boo=1;}
	else if( tempstate[3]==num && (tempstate[3]==tempstate[4] && tempstate[4]==tempstate[5]) ){boo=1;}
	else if( tempstate[6]==num && (tempstate[6]==tempstate[7] && tempstate[7]==tempstate[8]) ){boo=1;}
	else if( tempstate[0]==num && (tempstate[0]==tempstate[3] && tempstate[3]==tempstate[6]) ){boo=1;}
	else if( tempstate[1]==num && (tempstate[1]==tempstate[4] && tempstate[4]==tempstate[7]) ){boo=1;}
	else if( tempstate[2]==num && (tempstate[2]==tempstate[5] && tempstate[5]==tempstate[8]) ){boo=1;}
	else if( tempstate[0]==num && (tempstate[0]==tempstate[4] && tempstate[4]==tempstate[8]) ){boo=1;}
	else if( tempstate[2]==num && (tempstate[2]==tempstate[4] && tempstate[4]==tempstate[6]) ){boo=1;}
	return boo;
}
int check(int num){
	if(tempstate[num]!=1 && tempstate[num]!=2){
		num=1;
	}else{
		num=0;
	}
	return num;
}
void setup(){
	counter=0;
    strip888.begin();	// start library
	strip3.begin();
    strip4.begin();
	strip5.begin();
    strip6.begin();
	strip7.begin();
    strip8.begin();
	strip9.begin();
    strip10.begin();
	strip11.begin();
		
	Serial.begin(9600);
		
	// let LED start with it is off
    strip888.setPixelColor(1, 0, 0, 0);
	strip888.show();
	strip3.setPixelColor(1, 0, 0, 0);
	strip3.show();
    strip4.setPixelColor(1, 0, 0, 0);
	strip4.show();
	strip5.setPixelColor(1, 0, 0, 0);
	strip5.show();
    strip6.setPixelColor(1, 0, 0, 0);
	strip6.show();
	strip7.setPixelColor(1, 0, 0, 0);
	strip7.show();
    strip8.setPixelColor(1, 0, 0, 0);
	strip8.show();
	strip9.setPixelColor(1, 0, 0, 0);
	strip9.show();
    strip10.setPixelColor(1, 0, 0, 0);
	strip10.show();
	strip11.setPixelColor(1, 0, 0, 0);
	strip11.show();
}

//player1 ---->red
//player2 ---->blue

void loop(){	//game detail
	
	if(counter<=9)
	{
		while( Serial.available() ){
			input = Serial.read();  // get input from bluetooth app
            if(input=='h'){innum =100;}
            else if (input=='1'){innum =9;}
            else if (input=='2'){innum =1;}
            else if (input=='3'){innum =2;}
            else if (input=='4'){innum =3;}
            else if (input=='5'){innum =4;}
            else if (input=='6'){innum =5;}
            else if (input=='7'){innum =6;}
            else if (input=='8'){innum =7;}
            else if (input=='9'){innum =8;}
		}
                Serial.println(innum);
		if(check(innum)==1){
			if(counter%2==0){
				tempstate[innum]=1;
                if(innum==1000){Serial.println("xx");}
                
                else if (innum == 1){colorWipe3(strip3.Color(0, 255, 0), 50);Serial.println("z1");}	 
                else if (innum == 2){colorWipe4(strip4.Color(0, 255, 0), 50); Serial.println("z2");}	
                else if (innum == 3){colorWipe5(strip5.Color(0, 255, 0), 50);Serial.println("z3"); }
                else if (innum == 4){colorWipe6(strip6.Color(0, 255, 0), 50);Serial.println("z4"); }	
                else if (innum == 5){colorWipe7(strip7.Color(0, 255, 0), 50); Serial.println("z5");}	
                else if (innum == 6){colorWipe8(strip8.Color(0, 255, 0), 50); Serial.println("z6");}	
                else if (innum == 7){colorWipe9(strip9.Color(0, 255, 0), 50);Serial.println("z7");}	
                else if (innum == 8){colorWipe10(strip10.Color(0, 255, 0), 50); Serial.println("z8");}
                else if (innum == 9){colorWipe888(strip888.Color(0, 255, 0), 50);Serial.println("z0"); }
                //else Serial.println("cc");
				if(checkwin(1)==1){colorWipe(strip11.Color(0, 255, 0), 50);}                        
			}else{
				tempstate[innum]=2;
                if(innum==1000){Serial.println("xx");}
	         
                else if (innum == 1){colorWipe3(strip3.Color(0, 0, 255), 50);Serial.println("x1");}	 
                else if (innum == 2){colorWipe4(strip4.Color(0, 0, 255), 50);Serial.println("x2"); }
                else if (innum == 3){colorWipe5(strip5.Color(0, 0, 255), 50);Serial.println("x3");} 
                else if (innum == 4){colorWipe6(strip6.Color(0, 0, 255), 50); Serial.println("x4");}	
                else if (innum == 5){colorWipe7(strip7.Color(0, 0, 255), 50);Serial.println("x5"); }	
                else if (innum == 6){colorWipe8(strip8.Color(0, 0, 255), 50);Serial.println("x6"); }
                else if (innum == 7){colorWipe9(strip9.Color(0, 0, 255), 50); Serial.println("x7");}
                else if (innum == 8){colorWipe10(strip10.Color(0, 0, 255), 50);Serial.println("x8"); }
                else if (innum == 9colorWipe888(strip888.Color(0, 0, 255), 50);Serial.println("x0");}	
                if(checkwin(2)==1){colorWipe(strip11.Color(0, 0, 255), 50); }
			}
		}else{
			counter--;	// 'for' temp counter again   
		}  
		counter++;
	}
}
void colorWipe888(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip888.numPixels(); i++) {
      strip888.setPixelColor(i, c);
      strip888.show();
      delay(wait);
  }
}
void colorWipe3(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip3.numPixels(); i++) {
      strip3.setPixelColor(i, c);
      strip3.show();
      delay(wait);
  }
}
void colorWipe4(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip4.numPixels(); i++) {
      strip4.setPixelColor(i, c);
      strip4.show();
      delay(wait);
  }
}
void colorWipe5(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip5.numPixels(); i++) {
      strip5.setPixelColor(i, c);
      strip5.show();
      delay(wait);
  }
}
void colorWipe6(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip6.numPixels(); i++) {
      strip6.setPixelColor(i, c);
      strip6.show();
      delay(wait);
  }
}
void colorWipe7(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip7.numPixels(); i++) {
      strip7.setPixelColor(i, c);
      strip7.show();
      delay(wait);
  }
}
void colorWipe8(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip8.numPixels(); i++) {
      strip8.setPixelColor(i, c);
      strip8.show();
      delay(wait);
  }
}
void colorWipe9(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip9.numPixels(); i++) {
      strip9.setPixelColor(i, c);
      strip9.show();
      delay(wait);
  }
}
void colorWipe10(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip10.numPixels(); i++) {
      strip10.setPixelColor(i, c);
      strip10.show();
      delay(wait);
  }
}
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip11.numPixels(); i++) {
      strip11.setPixelColor(i, c);
      strip11.show();
      delay(wait);
  }
}

