/* twelve tone synth  by Ranjit @ moonmilk
 * output 12 tones of scale (+ high C) to digital outs 1-13
 */

const int num = 13;        
int increment = 30;

// divisors for just intonation scale on 2, 3, and 5 <http://en.wikipedia.org/wiki/Just_intonation#The_twelve_tone_scale>
//              C     Db    D     Eb    E     F     Gb     G     Ab   A     Bb     B,   CC
int tones[] = {2880, 2700, 2560, 2400, 2304, 2160, 2025, 1920, 1800, 1728, 1620, 1536, 1440};
//              C     Db    D     Eb    E     F     F#     G     Ab   A     Bb     B,   CC
//int tones[] = {2880, 2700, 2560, 2400, 2304, 2160, 2048, 1920, 1800, 1728, 1620, 1536, 1440};
int pins[] = {1, 2,3,4,5,6,7,8,9,10,11,12, 13};

int counters[num];
int states[num];

int analogSkip = 0;


void setup() {
  int i;
  for (i=0; i<num; i++) {
    pinMode(pins[i], OUTPUT);
    counters[i] = 0;
    states[i] = 0;
  } 
}

void loop() {
  int i, j;
  int t;
  /*
  if (++analogSkip > 5000) {
    i = analogRead(3);
    increment = 30 + (i-500)/50;
    
    //j = analogRead(4);
    
    analogSkip=0;
  }
  */
  
  for (i=0; i<num; i++) {
     if ((counters[i]+=increment) > tones[i]) {
       counters[i] -= tones[i];
       states[i] = !states[i];
       digitalWrite(pins[i], states[i]);
     }
  }
}
