#define LED_PIN 13

volatile enum menu_states { IDLE,
                            MENU,
                            LIGHT,
                            GARBAGE,
                            GREETING } menu_state = MENU;

void print_menu();

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        char input = (char)Serial.parseInt();
        while (Serial.available() > 0);
        menu_state = (menu_states)input;
    }
    switch (menu_state) {
    case IDLE:
        break;
    case MENU:
        print_menu();
        menu_state = IDLE;
        break;
    case LIGHT:
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
        menu_state = MENU;
        break;
    case GARBAGE:
        Serial.println("a;fkjaldfjhasjkdfh");
        menu_state = MENU;
        break;
    case GREETING:
        Serial.println("Hello!");
        menu_state = MENU;
    default:
        break;
    }
}

void print_menu() {
    Serial.println("Please make a selection.");
    Serial.println("1. Turn light on/off");
    Serial.println("2. Print garbage");
    Serial.println("3. Greeting");
}