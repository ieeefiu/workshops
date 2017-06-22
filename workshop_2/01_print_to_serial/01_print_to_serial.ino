#define BUTTON_PIN 2

void set_print();
void count_presses();

volatile enum states { IDLE, PRINT } print_state = IDLE;
volatile enum states previous_state = IDLE;

int counter = 0;

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), set_print, CHANGE);
}

void loop() {
    if (previous_state != print_state) {
        count_presses();
    }
}

void count_presses() {
    switch(print_state) {
    case IDLE:
        break;
    case PRINT:
        counter++;
        Serial.print("You have pressed the button ");
        Serial.print(counter);
        Serial.println(" times.");
        delay(100);
        break;
    default:
        break;
    }

    previous_state = print_state;
}

void set_print() {
    int button = !digitalRead(BUTTON_PIN);
    if (button) {
        print_state = PRINT;        
    }
    else {
        print_state = IDLE;
    }
}
