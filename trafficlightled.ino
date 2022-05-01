#define RED D5
#define BLUE D6
#define GREEN D7

void reset_leds();
int change_light(String colour);


void setup() {
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    
    Particle.function("traffic_light", change_light);

}

void loop() {

}

void reset_leds(){
    digitalWrite(RED,LOW);
    digitalWrite(BLUE,LOW);
    digitalWrite(GREEN,LOW);
}

int change_light(String colour)
{
    
    reset_leds();
    
    Particle.publish("traffic_light", colour);
    
    if (colour.equals("red")){
        digitalWrite(RED,HIGH);
        return 1;
    } 
    else if (colour.equals("blue")){
        digitalWrite(BLUE,HIGH);
        return 1;}
    else if (colour.equals("green")){
        digitalWrite(GREEN,HIGH);
        return 1;
    }
    else if (colour.equals("off")){
        return 1;
    }
    
    return -1;
    
}