// Otra forma de trabajar con el ADC usando la funcion map() y el switch-case

int potPIN0 = A0; // Renombramos el Pin A0
int potValue = 0; // Para almacenar el valor de voltaje obtenido
int ledBar = 0;   // Valor escalado de 0 a 7 para usar en el switch-case


void setup() {
    
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    PORTD = 0;
}

void loop() {
  
  potValue = analogRead(potPIN0);  // Leemos el valor de voltaje que hay en el Pin A0

  ledBar = map(potValue, 0, 1023, 0, 7);  // Escalamos el valor que esta entre 0 y 1023 a 0 y 7
  switch(ledBar){
    case 0:
      PORTD = 0b00000001;
      break;
    case 1:
      PORTD = 0b00000010;
      break;
    case 2:
      PORTD = 0b00000100;
      break;
    case 3:
      PORTD = 0b00001000;
      break;
    case 4:
      PORTD = 0b00010000;
      break;
    case 5:
      PORTD = 0b00100000;
      break;
    case 6:
      PORTD = 0b01000000;
      break;
    case 7:
      PORTD = 0b10000000;
      break;
    default:
      break;
  }

}
