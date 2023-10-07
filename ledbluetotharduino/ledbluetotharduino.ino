// Definindo a porta digital do LED
int ledPin = 13;
// Definindo o caractere de ativação do LED
char ledOn = '1';
// Definindo o caractere de desativação do LED
char ledOff = '0';
// Definindo a variável para armazenar o caractere recebido via Bluetooth
char incomingData;

void setup() {
  // Configurando a porta digital como saída
  pinMode(ledPin, OUTPUT);
  // Iniciando a comunicação serial a uma taxa de 9600 bps
  Serial.begin(9600);
}

void loop() {
  // Verificando se há dados disponíveis para leitura na porta serial
  if (Serial.available() > 0) {
    // Lendo o caractere recebido via Bluetooth
    incomingData = Serial.read();
    // Verificando se o caractere é igual ao caractere de ativação do LED
    if (incomingData == ledOn) {
      // Acionando o LED
      digitalWrite(ledPin, HIGH);
    }
    // Verificando se o caractere é igual ao caractere de desativação do LED
    else if (incomingData == ledOff) {
      // Desligando o LED
      digitalWrite(ledPin, LOW);
    }
  }
}