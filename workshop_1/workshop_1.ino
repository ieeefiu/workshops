#define LED_PIN 13
#define BUTTON_PIN 2

int button_state = 0;
int previous_state = 0;

void change_button_state();
void toggle_led();

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), change_button_state, CHANGE);
    Serial.begin(9600);
}

void loop() {
    if (previous_state != button_state) {
        toggle_led();
    }
}

void change_button_state() {
    int button = digitalRead(BUTTON_PIN);
    if (button) {
        button_state = 1;
    }
    else {
        button_state = 0;
    }
}

void toggle_led() {
    switch(button_state) {
    case 0:
        digitalWrite(LED_PIN, LOW);
        Serial.println("Button off");
        break;
    case 1:
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Button on");
        break;
    default:
        digitalWrite(LED_PIN, LOW);
        break;
    }

    previous_state = button_state;
}
