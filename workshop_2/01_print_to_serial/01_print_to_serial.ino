#define BUTTON_PIN 2

void set_print();

volatile enum { IDLE, PRINT } print_state = IDLE;

int counter = 0;

void setup() {
    Serial.begin(9600);
    attachInterrupt(digitalPintoInterrupt(BUTTON_PIN), set_print, CHANGE);
}

void loop() {
    if (print_state = PRINT) {
        counter++;
        Serial.print("You have pressed the button ");
        Serial.print(counter);
        Serial.println(" times.");
    }
}

void set_print() {
    if (digitalRead(BUTTON_PIN)) {
        print_state = PRINT;        
    }
    else {
        print_state = IDLE;
    }
}
